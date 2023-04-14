#pragma once

#include <cstdint>

namespace Pml::PokePara {
    struct SavePokeParty : ILStruct<SavePokeParty> {
        struct Fields {
            void* members;
            uint8_t memberCount;
            uint8_t markingIndex;
        };
    };
}

