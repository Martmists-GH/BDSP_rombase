#pragma once

#include "externals/il2cpp-api.h"

#include "externals/Dpr/Battle/Logic/BTL_CLIENT.h"
#include "externals/Dpr/Battle/Logic/MainModule.h"

namespace Dpr::Battle::Logic {
    struct BattleViewBase : ILClass<BattleViewBase> {
        struct Fields {
            Dpr::Battle::Logic::MainModule::Object* m_pMainModule;
            Dpr::Battle::Logic::BTL_CLIENT::Object* m_iPtrClient;
            void* m_pBattleEnv;
            int32_t m_bagMode;
            int32_t m_msgSpeed;
            void* m_battleSimulator;
        };

        inline int32_t BtlPosToViewPos(uint8_t pos) {
            external<int32_t>(0x01888200, this, pos);
        }
    };
}
