#pragma once

#include "externals/il2cpp-api.h"

namespace System {
    template <typename T>
    struct NullablePrimitive : IlStruct<NullablePrimitive<T>> {
        struct Fields {
            T value;
            bool has_value;
        };
    };

    template <typename T>
    struct Nullable : IlStruct<Nullable<T>> {
        struct Fields {
            T::Object value;
            bool has_value;
        };
    };
}
