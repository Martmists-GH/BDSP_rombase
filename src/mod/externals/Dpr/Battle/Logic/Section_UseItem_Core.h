#pragma once

#include "externals/il2cpp-api.h"

#include "externals/Dpr/Battle/Logic/Section.h"

namespace Dpr::Battle::Logic {
    struct Section_UseItem_Core : ILClass<Section_UseItem_Core> {
        struct ItemEffectInfo : ILClass<ItemEffectInfo> {
            int32_t effect;
            uint8_t range;
            void* func; // Dpr_Battle_Logic_Section_UseItem_Core_ItemEffectFuncPtr_o*
        };

        struct Fields : Dpr::Battle::Logic::Section::Fields {
            Dpr::Battle::Logic::Section_UseItem_Core::ItemEffectInfo::Array* s_itemEffectTableInstance;
        };
    };
}
