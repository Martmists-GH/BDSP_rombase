#pragma once

#include "externals/il2cpp-api.h"

namespace Dpr::Battle::View::Systems {
    struct DeadActParam : ILStruct<DeadActParam> {
        struct Fields {
            int32_t vpos;
        };
    };
}