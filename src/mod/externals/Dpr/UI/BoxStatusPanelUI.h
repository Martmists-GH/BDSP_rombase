#pragma once

#include "externals/il2cpp-api.h"
#include "externals/Pml/PokePara/CoreParam.h"

namespace Dpr::UI {
    struct BoxStatusPanelUI : ILClass<BoxStatusPanelUI> {
        struct Fields {
            Pml::PokePara::CoreParam * pokemonParam;
            int32_t zukanNo;
            uint16_t haveItem;
        };
    };
}