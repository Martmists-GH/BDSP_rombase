#pragma once

#include "externals/il2cpp-api.h"

namespace UnityEngine {
    struct Random : ILClass<Random> {
        static inline int32_t Range(int32_t min, int32_t max) {
            return external<int32_t>(0x026941e0, min, max);
        }
    };
}
