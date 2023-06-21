#pragma once

#include "externals/il2cpp-api.h"

namespace Dpr::Box {
    struct BoxPokemonWork : ILClass<BoxPokemonWork> {
        struct Fields {

        };

        static inline void ClearPokemon(int32_t tray, int32_t pos) {
            external<void>(0x01d30e80, tray, pos);
        }
    };
}
