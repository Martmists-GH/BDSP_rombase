#pragma once

#include "externals/il2cpp-api.h"
#include "externals/Dpr/Battle/View/Objects/BattleObject.h"

namespace Dpr::Battle::View::Objects {
    struct BattleViewCharacter : ILClass<BattleViewCharacter> {
        struct Fields : Dpr::Battle::View::Objects::BattleObject::Fields {
            int32_t m_vPos;
            int32_t m_type;
            bool _isSickSpeedSuspend;
            float m_adjustHeight;
            float m_cameraAdjustHeight;
            bool m_disableSleepEye;
            bool _isEnableWaitB;
            int32_t _waitBCheckCnt;
        };
    };
}