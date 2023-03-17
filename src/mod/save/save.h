#pragma once

#include "externals/PlayerWork.h"
#include "dex_savedata.h"

enum ModVersion : int32_t {
    // Base game
    Vanilla,

    // Mod releases (in order!)
    Release_001,

    // Development version, always after the latest release
    Dev,
};

constexpr int32_t DexSize = 905;

struct CustomSaveData {
    bool initialized;
    ModVersion version;
    // ONLY MAKE MODIFICATIONS TO SAVE FORMAT BELOW HERE, OTHERWISE YOU WILL BREAK SAVE COMPATIBILITY
    DexSaveData<DexSize> dex;  // start at 0
};

void migrate(CustomSaveData* data, PlayerWork::Object* playerWork);
CustomSaveData* getCustomSaveData();
void exl_save_main();

#if NDEBUG
constexpr ModVersion CURRENT_VERSION = ModVersion::Release_001;
#else
constexpr ModVersion CURRENT_VERSION = ModVersion::Dev;
#endif
