#pragma once

#include "externals/il2cpp-api.h"
#include "externals/Dpr/Battle/View/Objects/BOPokemon.h"

namespace Dpr::Battle::View {
    struct PokeFollowInfo : ILClass<PokeFollowInfo> {
        struct Fields {
            Dpr::Battle::View::Objects::BOPokemon::Object* _Pokemon_k__BackingField;
            int32_t _Node_k__BackingField;
            bool _IsFollowPos_k__BackingField;
            bool _IsFollowRot_k__BackingField;
            bool _IsFollowScl_k__BackingField;
            bool _IsFollowAnimRot_k__BackingField;
        };
    };
}