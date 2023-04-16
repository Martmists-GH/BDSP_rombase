#pragma once

#include "externals/UnityEngine/_Object.h"

namespace UnityEngine {
    struct GameObject : ILClass<GameObject> {
        struct Fields : UnityEngine::_Object::Fields {

        };

        inline UnityEngine::Transform::Object* get_transform() {
            return external<UnityEngine::Transform::Object*>(0x026b18d0, this);
        }
    };
}
