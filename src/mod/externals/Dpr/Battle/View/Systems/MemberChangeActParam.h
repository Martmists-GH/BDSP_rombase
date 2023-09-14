#pragma once

#include "externals/il2cpp-api.h"

namespace Dpr::Battle::View::Systems {
    struct MemberChangeActParam : ILStruct<MemberChangeActParam> {
        struct Fields {
            int32_t vpos;
            uint8_t clientID;
        };
    };
}