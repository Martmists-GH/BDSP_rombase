#pragma once

#include "externals/il2cpp-api.h"

namespace Dpr::Battle::View::Systems {
    struct BTLV_ATTR_EFF_PARAM : ILStruct<BTLV_ATTR_EFF_PARAM> {
        struct Fields {
            int32_t attrEffectID;
            int32_t streamLineEffectID;
        };
    };
}