#include "exlaunch.hpp"
#include "externals/Pml/PokeParty.h"
#include "logger/logger.h"
#include "helpers/InputHelper.h"
#include "externals/FieldCanvas.h"

static bool enabled = false;
static int id = 1;

HOOK_DEFINE_TRAMPOLINE(ArenaHook) {
    static void Callback(void *battleSetupParam, Pml::PokeParty *iPtrEnemyParty,int32_t arenaID,int32_t mapAttrib,int32_t weatherType,bool isSwim,bool isFishing,int32_t partnerID,bool isCaptureDemo,int32_t safariBallNum,bool isSymbol,bool isMitu,void *overlapBgm,int32_t overlapSetupEffectId,bool isCantUseBall,MethodInfo *method) {
        if (enabled) {
            arenaID = id;
        }
        return Orig(battleSetupParam, iPtrEnemyParty, arenaID, mapAttrib, weatherType, isSwim, isFishing, partnerID, isCaptureDemo, safariBallNum, isSymbol, isMitu, overlapBgm, overlapSetupEffectId, isCantUseBall, method);
    }
};

void setArenaSettings(bool e, int i) {
    enabled = e;
    id = i;
}

HOOK_DEFINE_TRAMPOLINE(CollissionOverride) {
    static uint32_t Callback(void* outVelocity, void* outHitNormal, float* outHitAngle, void* worldPosition, void* worldVelocity, float entityRadius, void* checkGridFunc, uint32_t ignoreDir) {
        if (InputHelper::isHoldL()) {
            return 0;
        }
        return Orig(outVelocity, outHitNormal, outHitAngle, worldPosition, worldVelocity, entityRadius, checkGridFunc, ignoreDir);
    }
};

HOOK_DEFINE_TRAMPOLINE(CollissionOverride2) {
    static bool Callback(void* origin, float radius, void* direction, void* hitInfo, float maxDistance, int32_t layerMask) {
        if (InputHelper::isHoldL()) {
            return false;
        }
        return Orig(origin, radius, direction, hitInfo, maxDistance, layerMask);
    }
};

static System::String* lastString = nullptr;

HOOK_DEFINE_TRAMPOLINE(LastAreaName) {
    static void* Callback(System::String* string) {
        lastString = string;
        return Orig(string);
    }
};

void showAreaName() {
    if (lastString != nullptr) {
        FieldCanvas::ResetAreaNameWindow();
        FieldCanvas::OpenAreaNameWindow(lastString);
    }
}

static bool flyOverride = false;

void setFlyOverride(bool b) {
    flyOverride = b;
}

HOOK_DEFINE_TRAMPOLINE(FlyOverride) {
    static bool Callback(void* __this, bool useArrive) {
        if (flyOverride) {
            return true;
        }
        return Orig(__this, useArrive);
    }
};

HOOK_DEFINE_TRAMPOLINE(FlyOverride2) {
    static bool Callback(void* __this, void* cell) {
        if (flyOverride) {
            return true;
        }
        return Orig(__this, cell);
    }
};

void exl_debug_menu_main() {
    ArenaHook::InstallAtOffset(0x02c3abc0);
    CollissionOverride::InstallAtOffset(0x01a763a0);
    CollissionOverride2::InstallAtOffset(0x02c1dd80);
    LastAreaName::InstallAtOffset(0x01786970);
    FlyOverride::InstallAtOffset(0x0184e780);
    FlyOverride2::InstallAtOffset(0x01850250);
}
