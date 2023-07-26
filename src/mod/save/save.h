#pragma once

#include "externals/PlayerWork.h"
#include "save/savedata/badge_savedata.h"
#include "save/savedata/berry_savedata.h"
#include "save/savedata/box_savedata.h"
#include "save/savedata/dex_savedata.h"
#include "save/savedata/item_savedata.h"
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
constexpr int32_t BoxCount = 40;
constexpr int32_t BadgeCount = 80;

struct CustomSaveData {
    bool initialized;
    ModVersion version;
    // ONLY MAKE MODIFICATIONS TO SAVE FORMAT BELOW HERE, OTHERWISE YOU WILL BREAK SAVE COMPATIBILITY
    DexSaveData<DexSize> dex;
    VariablesSaveData<WorkCount, FlagCount, SysFlagCount> variables;
    TrainerSaveData<TrainerCount> trainers;
    ItemSaveData<SaveItemCount> items;
    BerrySaveData<BerryCount> berries;
    BoxSaveData<BoxCount> boxes;
    BadgeSaveData<BadgeCount> badges_polish;
};

void migrate(CustomSaveData* data, PlayerWork::Object* playerWork);
CustomSaveData* getCustomSaveData();
void exl_save_main();

#if NDEBUG
constexpr ModVersion CURRENT_VERSION = ModVersion::Release_001;
#else
constexpr ModVersion CURRENT_VERSION = ModVersion::Dev;
#endif
