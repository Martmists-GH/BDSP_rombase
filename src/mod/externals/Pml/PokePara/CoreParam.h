#pragma once

#include "externals/Pml/PokePara/Accessor.h"

namespace Pml::PokePara {
    struct CoreParam : ILClass<CoreParam> {
        struct Fields {
            void* m_coreData;
            void* m_calcData;
            Pml::PokePara::Accessor* m_accessor;
        };

        inline void SetWaza(uint32_t index, uint32_t wazaId) {
            external<void>(0x020464e0, this, index, wazaId);
        }

        inline uint32_t GetLangId() {
            return external<uint32_t>(0x0204b810, this);
        }
    };
}
