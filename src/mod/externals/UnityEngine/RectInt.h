#pragma once

#include "externals/il2cpp-api.h"

namespace UnityEngine {
    struct RectInt : ILStruct<RectInt> {
        struct Fields {
            int32_t m_XMin;
            int32_t m_YMin;
            int32_t m_Width;
            int32_t m_Height;
        };
    };
}
