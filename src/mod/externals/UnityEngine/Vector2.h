#pragma once

#include "externals/il2cpp-api.h"

namespace UnityEngine {
    struct Vector2 : ILStruct<Vector2> {
        struct Fields {
            float x;
            float y;
        };
    };
}

static_assert(sizeof(UnityEngine::Vector2::Object) == 0x8);
