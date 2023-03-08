#pragma once

#include "externals/il2cpp-api.h"

namespace EvData {
    struct Aregment : IlStruct<Aregment> {
        struct Fields {
            int32_t argType;
            int32_t data;
        };
    };
}
