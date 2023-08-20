#pragma once

#include "externals/il2cpp-api.h"

#include "externals/UnityEngine/Component.h"

namespace UnityEngine {
    struct Renderer : ILClass<Renderer> {
        struct Fields : UnityEngine::Component::Fields {
        };
    };
}
