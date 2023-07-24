#pragma once

#include "externals/PlayerWork.h"
#include "save/savedata/dex_savedata.h"
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
constexpr int32_t SysFlagCount = 5000;

struct CustomSaveData {
    bool initialized;
    ModVersion version;
    // ONLY MAKE MODIFICATIONS TO SAVE FORMAT BELOW HERE, OTHERWISE YOU WILL BREAK SAVE COMPATIBILITY
    DexSaveData<DexSize> dex;
    VariablesSaveData<WorkCount, FlagCount, SysFlagCount> variables;
};

void migrate(CustomSaveData* data, PlayerWork::Object* playerWork);
CustomSaveData* getCustomSaveData();
void exl_save_main();

#if NDEBUG
constexpr ModVersion CURRENT_VERSION = ModVersion::Release_001;
#else
constexpr ModVersion CURRENT_VERSION = ModVersion::Dev;
#endif
