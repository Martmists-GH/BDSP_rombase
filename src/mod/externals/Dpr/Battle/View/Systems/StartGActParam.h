#pragma once

#include "externals/il2cpp-api.h"

namespace Dpr::Battle::View::Systems {
    struct StartGActParam : ILStruct<StartGActParam> {
        struct Fields {
            int32_t vpos;
        };
    };
}