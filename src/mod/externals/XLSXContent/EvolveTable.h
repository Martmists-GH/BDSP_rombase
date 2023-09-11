#pragma once

#include "externals/il2cpp-api.h"

#include "externals/System/Primitives.h"
#include "externals/UnityEngine/ScriptableObject.h"

namespace XLSXContent {
    struct EvolveTable : ILClass<EvolveTable> {
        struct SheetEvolve : ILClass<SheetEvolve> {
            struct Fields {
                int32_t id;
                System::UInt16_array* ar;
            };
        };

        struct Fields : UnityEngine::ScriptableObject::Fields {
            XLSXContent::EvolveTable::SheetEvolve::Array* Evolve;
        };
    };
}