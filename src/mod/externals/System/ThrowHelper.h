#pragma once

#include "externals/il2cpp-api.h"

#include "externals/UnityEngine/Touch.h"

namespace System {
    struct ThrowHelper : ILClass<ThrowHelper> {
        static inline void ThrowArgumentOutOfRangeException() {
            external<void>(0x02305100);
        }
    };
}
