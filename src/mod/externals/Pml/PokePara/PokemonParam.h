#pragma once

#include "CoreParam.h"
#include "externals/il2cpp-api.h"

namespace Pml::PokePara {
    struct PokemonParam : ILClass<PokemonParam, 0x04c59c10> {
        struct Fields : public CoreParam::Fields {
            // TODO
        };

        inline void ctor(uint32_t species, uint16_t level, uint64_t id) {
            external<void>(0x0205a4a0, this, species, level, id);
        }
    };
}
