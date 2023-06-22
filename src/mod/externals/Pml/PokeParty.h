#pragma once

#include "externals/Pml/PokePara/PokemonParam.h"
#include "externals/il2cpp-api.h"

namespace Pml {
    struct PokeParty : ILClass<PokeParty> {
        struct Fields {
            Pml::PokePara::PokemonParam::Array* m_member;
            uint32_t m_memberCount;
            uint8_t markingIndex;
        };

        inline void ReplaceMember(uint32_t idx, Pml::PokePara::PokemonParam* param) {
            external<void>(0x020560a0, this, idx, param);
        }

        inline Pml::PokePara::PokemonParam::Object* GetMemberPointer(uint32_t idx) {
            return external<Pml::PokePara::PokemonParam::Object*>(0x020556f0, this, idx);
        }
    };
}
