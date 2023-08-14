#pragma once

#include "externals/il2cpp-api.h"

namespace UnityEngine {
    struct Time : ILClass<Time> {
        static inline float get_deltaTime() {
            return external<float>(0x0299c220);
        }
    };
}