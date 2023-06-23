#pragma once

#include "externals/il2cpp-api.h"

#include "externals/UnityEngine/Component.h"

namespace UnityEngine {
    struct Collider : ILClass<Collider, 0x04c57608> {
        struct Fields : UnityEngine::Component::Fields {

        };

        inline void set_enabled(bool value) {
            external<void>(0x02c1c600, this, value);
        }
    };
}
