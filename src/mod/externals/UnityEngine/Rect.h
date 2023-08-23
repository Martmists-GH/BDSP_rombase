#pragma once

#include "externals/il2cpp-api.h"

namespace UnityEngine {
    struct Rect : ILStruct<Rect> {
        struct Fields {
            float m_XMin;
            float m_YMin;
            float m_Width;
            float m_Height;
        };
    };
}