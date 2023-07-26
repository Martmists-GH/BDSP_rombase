#pragma once

#include "externals/il2cpp-api.h"

#include "externals/System/Primitives.h"

namespace Pml::PokePara {
    struct SerializedPokemonFull : ILStruct<SerializedPokemonFull> {
        struct Fields {
            System::Byte_array* buffer;
        };
    };
}