#pragma once

#include "externals/il2cpp.h"
#include "externals/UnityEngine/Component.h"
#include "Component.h"

namespace UnityEngine {
    struct Behaviour : ILClass<Behaviour> {
        struct Fields : public UnityEngine::Component::Fields {

        };

        inline void set_enabled(bool value) {
            external<void>(0x026a3450, this, value);
        }
    };
}
