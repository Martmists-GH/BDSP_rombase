#include "exlaunch.hpp"
#include "save/save.h"
#include "externals/FlagWork.h"
#include "externals/FlagWork_Enums.h"

HOOK_DEFINE_REPLACE(OverrideAgbMode) {
    static int Callback() {
        if (FlagWork::GetFlag(FLAG_UNOVA_SOUNDS)) {
            return 1;
        }
        if (FlagWork::GetFlag(FLAG_KALOS_SOUNDS)) {
            return 2;
        }
        if (FlagWork::GetFlag(FLAG_ALOLA_SOUNDS)) {
            return 3;
        }
        if (FlagWork::GetFlag(FLAG_GALAR_SOUNDS)) {
            return 4;
        }
        if (FlagWork::GetFlag(FLAG_MYSTERY_BOX)) {
            return 5;
        }
        return 0;
    }
};

void exl_sounds_main() {
    OverrideAgbMode::InstallAtOffset(0x02cf2e30);
}
