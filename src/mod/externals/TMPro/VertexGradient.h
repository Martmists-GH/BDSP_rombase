#pragma once

#include "externals/il2cpp-api.h"

#include "externals/UnityEngine/Color.h"

namespace TMPro {
    struct VertexGradient : ILStruct<VertexGradient> {
        struct Fields {
            UnityEngine::Color::Object topLeft;
            UnityEngine::Color::Object topRight;
            UnityEngine::Color::Object bottomLeft;
            UnityEngine::Color::Object bottomRight;
        };
    };
}
