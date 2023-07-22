#pragma once

#include "externals/il2cpp-api.h"

namespace UnityEngine {
    struct Vector4 : ILStruct<Vector4> {
        struct Fields {
            float x;
            float y;
            float z;
            float w;
        };
    };
}
