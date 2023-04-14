#pragma once

#include "externals/il2cpp-api.h"

namespace UnityEngine {
    struct Color32 : ILStruct<Color32> {
        struct Fields {
            int32_t rgba;
            uint8_t r;
            uint8_t g;
            uint8_t b;
            uint8_t a;
        };
    };
}
