#pragma once

#include "externals/il2cpp-api.h"

namespace System {
    struct RuntimeTypeHandle : ILStruct<RuntimeTypeHandle> {
        struct Fields {
            Il2CppType* value;
        };
    };
}
