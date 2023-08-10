#pragma once

#include "externals/il2cpp-api.h"

namespace UnityEngine {
    struct Vector2 : ILStruct<Vector2> {
        struct Fields {
            float x;
            float y;
        };

        static inline Vector2::Object get_zero() {
            return {
                .fields = external<Vector2::Fields>(0x029a1670)
            };
        }

        static inline bool op_Equality(Vector2::Object lhs, Vector2::Object rhs) {
            return external<bool>(0x029a1d00, lhs, rhs);
        }

        static inline bool op_Inequality(Vector2::Object lhs, Vector2::Object rhs) {
            return external<bool>(0x029a1d30, lhs, rhs);
        }
    };
}

static_assert(sizeof(UnityEngine::Vector2::Object) == 0x8);
