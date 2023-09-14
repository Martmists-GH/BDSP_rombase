#pragma once

#include "externals/il2cpp-api.h"
#include "externals/UnityEngine/MonoBehaviour.h"
#include "externals/UnityEngine/Transform.h"

namespace Dpr::Battle::View {
    struct BtlvBehaviour : ILClass<BtlvBehaviour> {
        struct Fields : UnityEngine::MonoBehaviour::Fields {
            UnityEngine::Transform::Object* _cachedTransform;
        };
    };
}