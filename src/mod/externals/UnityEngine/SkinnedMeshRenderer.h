#pragma once

#include "externals/il2cpp-api.h"

#include "externals/UnityEngine/Renderer.h"

namespace UnityEngine {
    struct SkinnedMeshRenderer : ILClass<SkinnedMeshRenderer, 0x04c63d68> {
        struct Fields : UnityEngine::Renderer::Fields {
        };
    };
}
