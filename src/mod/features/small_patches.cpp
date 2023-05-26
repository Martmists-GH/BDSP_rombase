#include "exlaunch.hpp"
#include "externals/FlagWork.h"

HOOK_DEFINE_REPLACE(FriendshipFlag) {
    static bool Callback() {
        return FlagWork::GetFlag(FLAG_DISABLE_AFFECTION);
    }
};

HOOK_DEFINE_REPLACE(ExpShareFlag) {
    static bool Callback() {
        return FlagWork::GetFlag(FLAG_DISABLE_EXP_SHARE);
    }
};

void exl_patches_main() {
    FriendshipFlag::InstallAtOffset(0x020378d0);
    ExpShareFlag::InstallAtOffset(0x020397f0);

    // Assembly Patches
    using namespace exl::armv8::inst;
    using namespace exl::armv8::reg;
    exl::patch::CodePatcher p(0);
    auto inst = std::vector {
        std::make_pair<uint32_t, Instruction>(0x02177394, Branch(0x44)),            // Catch Rate fix (No high level debuff)
        std::make_pair<uint32_t, Instruction>(0x02053b24, CmpImmediate(W8, 0x7)),   // Allow 6IV Pokémon
    };
    p.WriteInst(inst);
}
