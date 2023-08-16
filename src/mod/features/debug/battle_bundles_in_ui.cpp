#include "exlaunch.hpp"

#include "externals/FlagWork.h"
#include "externals/System/String.h"

#include "logger/logger.h"

HOOK_DEFINE_INLINE(ChangeUIModels) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        auto fieldStr = (System::String::Object*)ctx->X[0];
        auto monStr = (System::String::Object*)ctx->X[1];

        if (FlagWork::GetSysFlag(FlagWork_SysFlag::SYSFLAG_999))
            ctx->X[0] = (uint64_t)System::String::Concat(System::String::Create("pokemons/battle/"), monStr);
        else
            ctx->X[0] = (uint64_t)System::String::Concat(fieldStr, monStr);
    }
};

void exl_battle_bundles_in_ui_main() {
    ChangeUIModels::InstallAtOffset(0x017c2014);
}
