#pragma once

#include "externals/il2cpp-api.h"

#include "externals/Pml/PokePara/SerializedPokemonFull.h"

namespace Dpr::Box {
    struct SaveBoxTrayData : ILStruct<SaveBoxTrayData> {
        struct Fields {
            Pml::PokePara::SerializedPokemonFull::Array* pokemonParam;
        };

        static long GetByteCount() {
            return Pml::PokePara::SerializedPokemonFull::GetByteCount()*30;
        }
    };

    static Il2CppClass* SaveBoxTrayData_array_TypeInfo() {
        return *reinterpret_cast<Il2CppClass**>(exl::util::modules::GetTargetOffset(0x04c64da0));
    }
}