#pragma once

#include "externals/il2cpp-api.h"

namespace Dpr::UI {
    struct BoxStatusPanelUI : ILClass<BoxStatusPanelUI> {
        struct Fields {
            Pml::PokePara::CoreParam * pokemonParam;
            int32_t zukanNo;
            uint16_t haveItem;
        };
    };
}