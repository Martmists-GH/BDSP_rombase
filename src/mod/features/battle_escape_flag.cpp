#include "exlaunch.hpp"

#include "externals/Dpr/Battle/Logic/BtlCompetitor.h"
#include "externals/Dpr/Battle/Logic/BtlEscapeMode.h"
#include "externals/Dpr/Battle/Logic/BtlRule.h"
#include "externals/Dpr/Battle/Logic/EventFactor.h"
#include "externals/Dpr/Battle/Logic/MainModule.h"
#include "externals/Dpr/Battle/Logic/Section_UseItem_Core.h"
#include "externals/FlagWork.h"

#include "logger/logger.h"

using namespace Dpr::Battle::Logic;

bool CanRunFromBattle(BtlRule rule, BtlCompetitor competitor)
{
    // Disallow escaping if can't escape flag is on
    if (FlagWork::GetFlag(FlagWork_Flag::FLAG_CANT_ESCAPE))
    {
        Logger::log("  Can't Escape!\n");
        return false;
    }

    if (rule != BtlRule::BTL_RULE_RAID)
    {
        switch (competitor)
        {
            case BtlCompetitor::BTL_COMPETITOR_WILD:
                return true;
            case BtlCompetitor::BTL_COMPETITOR_TRAINER:
                return false;
            case BtlCompetitor::BTL_COMPETITOR_INST:
                return true;
            case BtlCompetitor::BTL_COMPETITOR_COMM:
                return true;
            default:
                return false;
        }
    }

    return false;
}

bool CanUseEscapeItemInBattle(BtlRule rule, BtlCompetitor competitor)
{
    // Disallow escaping if can't escape flag is on
    if (FlagWork::GetFlag(FlagWork_Flag::FLAG_CANT_ESCAPE))
    {
        Logger::log("  Can't Escape!\n");
        return false;
    }

    if (rule != BtlRule::BTL_RULE_RAID)
    {
        switch (competitor)
        {
            case BtlCompetitor::BTL_COMPETITOR_WILD:
                return true;
            case BtlCompetitor::BTL_COMPETITOR_TRAINER:
                return false;
            case BtlCompetitor::BTL_COMPETITOR_INST:
                return false;
            case BtlCompetitor::BTL_COMPETITOR_COMM:
                return false;
            default:
                return false;
        }
    }

    return false;
}

BtlEscapeMode GetBattleEscapeMode(BtlRule rule, BtlCompetitor competitor)
{
    // Disallow escaping if can't escape flag is on
    if (FlagWork::GetFlag(FlagWork_Flag::FLAG_CANT_ESCAPE))
    {
        Logger::log("  Can't Escape!\n");
        return BtlEscapeMode::BTL_ESCAPE_MODE_NG;
    }

    if (rule != BtlRule::BTL_RULE_RAID)
    {
        switch (competitor)
        {
            case BtlCompetitor::BTL_COMPETITOR_WILD:
                return BtlEscapeMode::BTL_ESCAPE_MODE_WILD;
            case BtlCompetitor::BTL_COMPETITOR_TRAINER:
                return BtlEscapeMode::BTL_ESCAPE_MODE_NG;
            case BtlCompetitor::BTL_COMPETITOR_INST:
                return BtlEscapeMode::BTL_ESCAPE_MODE_CONFIRM;
            case BtlCompetitor::BTL_COMPETITOR_COMM:
                return BtlEscapeMode::BTL_ESCAPE_MODE_CONFIRM;
            default:
                return BtlEscapeMode::BTL_ESCAPE_MODE_NG;
        }
    }

    return BtlEscapeMode::BTL_ESCAPE_MODE_NG;
}

HOOK_DEFINE_REPLACE(MainModule_IsEscapeEnableBattle) {
    static bool Callback(MainModule::Object* __this) {
        Logger::log("MainModule_IsEscapeEnableBattle\n");
        return CanRunFromBattle(__this->fields.m_rule, __this->fields.m_setupParam->fields.competitor);
    }
};

HOOK_DEFINE_REPLACE(MainModule_GetEscapeMode) {
    static BtlEscapeMode Callback(MainModule::Object* __this) {
        Logger::log("MainModule_GetEscapeMode\n");
        return GetBattleEscapeMode(__this->fields.m_rule, __this->fields.m_setupParam->fields.competitor);
    }
};

HOOK_DEFINE_REPLACE(MainModule_CanUseEscapeItem) {
    static bool Callback(MainModule::Object* __this) {
        Logger::log("MainModule_CanUseEscapeItem\n");
        return CanUseEscapeItemInBattle(__this->fields.m_rule, __this->fields.m_setupParam->fields.competitor);
    }
};

HOOK_DEFINE_REPLACE(Section_UseItem_Core_canUseEscapeItem) {
    static bool Callback(Section_UseItem_Core::Object* __this) {
        Logger::log("Section_UseItem_Core_canUseEscapeItem\n");
        auto section = (Section::Object*)__this;
        return CanUseEscapeItemInBattle(section->GetRule(), section->GetCompetitor());
    }
};

HOOK_DEFINE_INLINE(Section_UseItem_Core_Execute_EscapeItem) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        Logger::log("Section_UseItem_Core_Execute_EscapeItem\n");
        auto section = (Section::Object*)ctx->X[0];

        bool canEscape = CanUseEscapeItemInBattle(section->GetRule(), section->GetCompetitor());

        if (!canEscape) // Set to 2 when CAN'T escape
            ctx->X[0] = (uint64_t)2;
        else // Set to anything that's not 2 when CAN escape
            ctx->X[0] = (uint64_t)0;
    }
};



HOOK_DEFINE_TRAMPOLINE(Common_CanForceEscape) {
    static bool Callback(EventFactor::EventHandlerArgs::Object** args, void** desc) {
        Logger::log("Common_CanForceEscape\n");
        return Orig(args, desc);
    }
};

HOOK_DEFINE_TRAMPOLINE(Section_UseItem_Core_escape) {
    static bool Callback(void* __this, BTL_POKEPARAM::Object* escapePoke) {
        Logger::log("Section_UseItem_Core_escape\n");
        return Orig(__this, escapePoke);
    }
};

void exl_battle_escape_flag_main() {
    MainModule_IsEscapeEnableBattle::InstallAtOffset(0x02034b70);
    MainModule_GetEscapeMode::InstallAtOffset(0x02034bb0);
    MainModule_CanUseEscapeItem::InstallAtOffset(0x02035040);
    Section_UseItem_Core_canUseEscapeItem::InstallAtOffset(0x021774d0);
    Section_UseItem_Core_Execute_EscapeItem::InstallAtOffset(0x02175c00);

    Common_CanForceEscape::InstallAtOffset(0x01d0d270);
    Section_UseItem_Core_escape::InstallAtOffset(0x02175900);
}
