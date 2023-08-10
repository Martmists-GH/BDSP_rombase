#pragma once

#include "CoreParam.h"
#include "externals/il2cpp-api.h"

namespace Pml::PokePara {
    struct PokemonParam : ILClass<PokemonParam, 0x04c59c10> {
        struct Fields : public CoreParam::Fields {
            //TODO
        };

        inline void ctor(int32_t monsno, uint16_t level, uint64_t id) {
            external<void>(0x02054fe0, this, monsno, level, id);
        }
    };
}
