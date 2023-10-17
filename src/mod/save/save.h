#pragma once

#include "externals/PlayerWork.h"

#include "save/data/badge/badge.h"
#include "save/data/berry/berry.h"
#include "save/data/box/box.h"
#include "save/data/color_variation/color_variation.h"
#include "save/data/dex/dex.h"
#include "save/data/item/item.h"
#include "save/data/string/string.h"
#include "save/data/trainer/trainer.h"
#include "save/data/variables/variables.h"

#include "logger/logger.h"

enum class ModVersion : int32_t {
    // Base game
    Vanilla,

    // Mod releases (in order!)
    Release_3_0,

    // Development version, always after the latest release
    Dev,
};

constexpr int32_t DexSize = 1017;
constexpr int32_t WorkCount = 5000;
constexpr int32_t FlagCount = 15000;
constexpr int32_t SysFlagCount = 15000;
constexpr int32_t TrainerCount = 10000;
constexpr int32_t SaveItemCount = 10000;
constexpr int32_t BerryCount = 1000;
constexpr int32_t ColorVariationCount = 1;

struct CustomSaveData {
    bool initialized;
    ModVersion version;
    // ONLY MAKE MODIFICATIONS TO SAVE FORMAT BELOW HERE, OTHERWISE YOU WILL BREAK SAVE COMPATIBILITY
    DexSaveData<DexSize> dex;
    VariablesSaveData<WorkCount, FlagCount, SysFlagCount> variables;
    TrainerSaveData<TrainerCount> trainers;
    ItemSaveData<SaveItemCount> items;
    BerrySaveData<BerryCount> berries;
    ColorVariationSaveData<ColorVariationCount> colorVariations;

    long GetByteCount() {
        long count = 0;
        count += sizeof(bool);
        count += sizeof(ModVersion);
        count += dex.GetByteCount();
        count += variables.GetByteCount();
        count += trainers.GetByteCount();
        count += items.GetByteCount();
        count += berries.GetByteCount();
        count += colorVariations.GetByteCount();
        return count;
    }

    void ToBytes(char* buffer, long index) {
        *(bool*)(buffer+index) = initialized;
        index += sizeof(bool);
        *(ModVersion*)(buffer+index) = version;
        index += sizeof(ModVersion);

        index = dex.ToBytes(buffer, index);
        index = variables.ToBytes(buffer, index);
        index = trainers.ToBytes(buffer, index);
        index = items.ToBytes(buffer, index);
        index = berries.ToBytes(buffer, index);
        index = colorVariations.ToBytes(buffer, index);
    }

    void FromBytes(char* buffer, long buffer_size, long index) {
        Logger::log("TOTAL BYTE COUNT: %d vs BUFFER SIZE: %d\n", GetByteCount(), buffer_size);
        if (buffer_size >= GetByteCount() + index)
        {
            initialized = *(bool*)(buffer+index);
            index += sizeof(bool);
            version = *(ModVersion*)(buffer+index);
            index += sizeof(ModVersion);

            index = dex.FromBytes(buffer, buffer_size, index);
            index = variables.FromBytes(buffer, buffer_size, index);
            index = trainers.FromBytes(buffer, buffer_size, index);
            index = items.FromBytes(buffer, buffer_size, index);
            index = berries.FromBytes(buffer, buffer_size, index);
            index = colorVariations.FromBytes(buffer, buffer_size, index);
        }
    }
};

CustomSaveData* getCustomSaveData();
void exl_save_main();

#if NDEBUG
constexpr ModVersion CURRENT_VERSION = ModVersion::Release_3_0;
#else
constexpr ModVersion CURRENT_VERSION = ModVersion::Dev;
#endif
