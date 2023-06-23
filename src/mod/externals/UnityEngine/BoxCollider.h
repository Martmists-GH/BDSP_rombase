#pragma once

#include "externals/il2cpp-api.h"

#include "externals/UnityEngine/Collider.h"

namespace UnityEngine {
    struct BoxCollider : ILClass<BoxCollider, 0x04c63d58> {
        struct Fields : UnityEngine::Collider::Fields {

        };
    };
}
