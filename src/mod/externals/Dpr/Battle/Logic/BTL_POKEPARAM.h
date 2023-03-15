#pragma once

#include "externals/il2cpp-api.h"
#include "externals/System/Primitives.h"
#include "externals/Pml/PokePara/PokemonParam.h"

namespace Dpr::Battle::Logic {
    struct BTL_POKEPARAM : IlClass<BTL_POKEPARAM> {
        struct Fields {
            void* m_coreParam;
            void* m_baseParam;
            void* m_varyParam;
            void* m_doryokuParam;
            void* m_waza;
            uint16_t m_tokusei;
            uint16_t m_weight;
            uint8_t m_wazaCnt;
            uint8_t m_formNo;
            uint8_t m_friendship;
            uint8_t m_criticalRank;
            uint8_t m_usedWazaCount;
            uint8_t m_prevWazaType;
            uint8_t m_spActPriority;
            uint16_t m_turnCount;
            uint16_t m_appearedTurn;
            uint16_t m_wazaContCounter;
            uint8_t m_prevTargetPos;
            int32_t m_prevActWazaID;
            int32_t m_prevSelectWazaID;
            int32_t m_prevDamagedWaza;
            System_Byte_array * m_turnFlag;
            System_Byte_array * m_contFlag;
            System_Byte_array * m_permFlag;
            System_Byte_array * m_counter;
            System_UInt32_array * m_permCounter;
            void * m_wazaDamageRec;
            System_Byte_array * m_dmgrecCount;
            uint8_t m_dmgrecTurnPtr;
            uint8_t m_dmgrecPtr;
            uint16_t m_migawariHP;
            int32_t m_combiWazaID;
            uint8_t m_combiPokeID;
            void * m_fldSim;
        };

        inline bool IsFightEnable() {
            return external<bool>(0x01fd9750, this);
        }

        inline Pml::PokePara::PokemonParam* GetSrcDataConst() {
            return external<Pml::PokePara::PokemonParam*>(0x01fdd5c0, this);
        }

        inline uint16_t GetMonsNo() {
            return external<uint16_t>(0x01fdcfb0, this);
        }

        inline int32_t GetValue(int32_t vid) {
            return external<int32_t>(0x01fdd010, this, vid);
        }

        inline int32_t GetID() {
            return external<int32_t>(0x01fd8a50, this);
        }

        inline bool CONFRONT_REC_IsMatch(int32_t pokeID) {
            return external<bool>(0x01fe39f0, this, pokeID);
        }

        inline uint16_t GetItem() {
            return external<uint16_t>(0x01fdfd50, this);
        }
    };
}
