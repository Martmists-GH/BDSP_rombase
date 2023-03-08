#pragma once

#include <cstdint>

namespace Pml::PokePara {
    struct SavePokeParty : IlStruct<SavePokeParty> {
        struct Fields {
            void* members;
            uint8_t memberCount;
            uint8_t markingIndex;
        };
    };
}

