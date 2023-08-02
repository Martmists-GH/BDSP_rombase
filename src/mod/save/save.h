#pragma once

#include "externals/PlayerWork.h"
#include "save/savedata/badge_savedata.h"
#include "save/savedata/berry_savedata.h"
#include "save/savedata/box_savedata.h"
#include "save/savedata/dex_savedata.h"
#include "save/savedata/item_savedata.h"
#include "save/savedata/string_savedata.h"
#include "save/savedata/trainer_savedata.h"
#include "save/savedata/variables_savedata.h"

enum class ModVersion : int32_t {
    // Base game
    Vanilla,

    // Mod releases (in order!)
    Release_001,

    // Development version, always after the latest release
    Dev,
};

constexpr int32_t DexSize = 1010;
constexpr int32_t WorkCount = 5000;
constexpr int32_t FlagCount = 15000;
constexpr int32_t SysFlagCount = 15000;
constexpr int32_t TrainerCount = 10000;
constexpr int32_t SaveItemCount = 10000;
constexpr int32_t BerryCount = 1000;
constexpr int32_t StringCount = 10;

struct CustomSaveData {
    bool initialized;
    ModVersion version;
    // ONLY MAKE MODIFICATIONS TO SAVE FORMAT BELOW HERE, OTHERWISE YOU WILL BREAK SAVE COMPATIBILITY
    DexSaveData<DexSize> dex;
    VariablesSaveData<WorkCount, FlagCount, SysFlagCount> variables;
    TrainerSaveData<TrainerCount> trainers;
    ItemSaveData<SaveItemCount> items;
    BerrySaveData<BerryCount> berries;
    StringSaveData<StringCount> strings;

    long GetByteCount() {
        long count = 0;
        count += sizeof(bool);
        count += sizeof(ModVersion);
        count += dex.GetByteCount();
        count += variables.GetByteCount();
        count += trainers.GetByteCount();
        count += items.GetByteCount();
        count += berries.GetByteCount();
        count += strings.GetByteCount();
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
        index = strings.ToBytes(buffer, index);
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
            index = strings.FromBytes(buffer, buffer_size, index);
        }
    }
};

void migrate(PlayerWork::Object* playerWork);
CustomSaveData* getCustomSaveData();
void exl_save_main();

#if NDEBUG
constexpr ModVersion CURRENT_VERSION = ModVersion::Release_001;
#else
constexpr ModVersion CURRENT_VERSION = ModVersion::Dev;
#endif
