#pragma once

#include "externals/il2cpp-api.h"

#include "externals/Pml/Personal/EvolveCond.h"
#include "externals/XLSXContent/EvolveTable.h"

namespace Pml::Personal {
    struct EvolveTableExtensions : ILClass<EvolveTableExtensions> {
        static inline Pml::Personal::EvolveCond GetEvolutionCondition(XLSXContent::EvolveTable::SheetEvolve::Object* self, int32_t index) {
            return external<Pml::Personal::EvolveCond>(0x024a0560, self, index);
        }

        static inline uint16_t GetEvolutionParam(XLSXContent::EvolveTable::SheetEvolve::Object* self, int32_t index) {
            return external<uint16_t>(0x024a0730, self, index);
        }

        static inline int32_t GetEvolvedMonsNo(XLSXContent::EvolveTable::SheetEvolve::Object* self, int32_t index) {
            return external<uint32_t>(0x024a06e0, self, index);
        }

        static inline uint8_t GetEvolveEnableLevel(XLSXContent::EvolveTable::SheetEvolve::Object* self, int32_t index) {
            return external<uint8_t>(0x024a0830, self, index);
        }
    };
}