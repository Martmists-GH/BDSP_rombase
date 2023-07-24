#pragma once

#include "externals/il2cpp-api.h"

#include "externals/UnityEngine/ScriptableObject.h"

namespace XLSXContent {
    struct ItemTable : ILClass<ItemTable> {
        struct SheetItem : ILClass<SheetItem> {
            struct Fields {
                int16_t no;
                uint8_t type;
                int32_t iconid;
                int32_t price;
                int32_t bp_price;
                uint8_t eqp;
                uint8_t atc;
                uint8_t nage_atc;
                uint8_t sizen_atc;
                uint8_t sizen_type;
                uint8_t tuibamu_eff;
                uint8_t sort;
                uint8_t group;
                uint8_t group_id;
                uint8_t fld_pocket;
                uint8_t field_func;
                uint8_t battle_func;
                uint8_t wk_cmn;
                uint8_t wk_critical_up;
                uint8_t wk_atc_up;
                uint8_t wk_def_up;
                uint8_t wk_agi_up;
                uint8_t wk_hit_up;
                uint8_t wk_spa_up;
                uint8_t wk_spd_up;
                uint8_t wk_prm_pp_rcv;
                int8_t wk_prm_hp_exp;
                int8_t wk_prm_pow_exp;
                int8_t wk_prm_def_exp;
                int8_t wk_prm_agi_exp;
                int8_t wk_prm_spa_exp;
                int8_t wk_prm_spd_exp;
                int8_t wk_friend1;
                int8_t wk_friend2;
                int8_t wk_friend3;
                uint8_t wk_prm_hp_rcv;
                uint32_t flags0;
            };
        };

        struct SheetWazaMachine : ILClass<SheetWazaMachine> {
            struct Fields {
                int32_t itemNo;
                int32_t machineNo;
                int32_t wazaNo;
            };
        };

        struct Fields : UnityEngine::ScriptableObject::Fields {
            XLSXContent::ItemTable::SheetItem::Array* Item;
            XLSXContent::ItemTable::SheetWazaMachine::Array* WazaMachine;
        };
    };
}
