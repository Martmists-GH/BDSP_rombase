#include "exlaunch.hpp"
#include "externals/PlayerWork.h"
#include "externals/FlagWork.h"
#include "externals/Dpr/Battle/Logic/MainModule.h"

HOOK_DEFINE_REPLACE(ObedienceMax) {
    static uint8_t Callback(Dpr::Battle::Logic::MainModule *__this) {
        return 100;
    }
};

HOOK_DEFINE_INLINE(CheckSurfFlags) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        bool result = true;
        result &= PlayerWork::GetSystemFlag((int32_t)FlagWork_SysFlag::BADGE_ID_C06);
        result &= PlayerWork::GetBool((int32_t)FlagWork_Flag::FE_HIDEN_03_GET);

        ctx->X[0] = result ? 1 : 0;
    }
};

void exl_badge_check_main() {
    ObedienceMax::InstallAtOffset(0x020349e0);
    CheckSurfFlags::InstallAtOffset(0x01daca9c);

    using namespace exl::armv8::inst;
    using namespace exl::armv8::reg;
    exl::patch::CodePatcher p(0);
    auto inst = std::vector {
        std::make_pair<uint32_t, Instruction>(0x01dbc4cc, Movz(W1, (int32_t)FlagWork_SysFlag::BADGE_ID_C05)),
        std::make_pair<uint32_t, Instruction>(0x01dbc4f8, Movz(W1, (int32_t)FlagWork_SysFlag::BADGE_ID_C06)),
    };
    p.WriteInst(inst);
}
