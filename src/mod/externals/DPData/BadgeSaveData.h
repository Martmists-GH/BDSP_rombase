#pragma once

#include "externals/il2cpp-api.h"

#include "externals/System/Primitives.h"

namespace DPData {
    struct BadgeSaveData : ILStruct<BadgeSaveData> {
        struct Fields {
            System::Byte_array* CleanValues;
        };
    };
}
