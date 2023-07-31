#pragma once

#include "externals/il2cpp-api.h"
#include "externals/Pml/PokePara/CoreParam.h"
#include "externals/Dpr/UI/PokemonStatusPanelAbility.h"

namespace Dpr::UI {
    struct StatusPanelLocals : ILClass<StatusPanelLocals> {
        struct Fields {
            Pml::PokePara::CoreParam * pokemonParam;
            struct Dpr::UI::PokemonStatusPanelAbility::Object* __4__this;
            int32_t tokuseiNo;
        };
    };
}