#pragma once

#include "externals/il2cpp-api.h"

namespace UnityEngine {
    struct Vector3 : ILStruct<Vector3> {
        struct Fields {
            float x;
            float y;
            float z;
        };

        inline void ctor(float x, float y, float z) {
            external<void>(0x0299e850, this, x, y, z);
        }
    };
}
