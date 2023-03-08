#include "exlaunch.hpp"
#include "externals/FlagWork.h"

HOOK_DEFINE_REPLACE(FriendshipFlag) {
    static bool Callback() {
        return FlagWork::GetFlag(FLAG_AFFECTION_ENABLED);
    }
};

void exl_patches_main() {
    FriendshipFlag::InstallAtOffset(0x020378d0);
}
