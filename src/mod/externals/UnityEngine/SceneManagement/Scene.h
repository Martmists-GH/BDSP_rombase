#pragma once

#include "externals/il2cpp-api.h"
#include "externals/UnityEngine/GameObject.h"

namespace UnityEngine::SceneManagement {
    struct Scene : ILStruct<Scene> {
        struct Fields {
            int32_t m_Handle;
        };

        inline UnityEngine::GameObject::Array* GetRootGameObjects() {
            return external<UnityEngine::GameObject::Array*>(0x029947e0, this);
        }

        inline System::String::Object* get_name() {
            return external<System::String::Object*>(0x029946f0, this);
        }
    };
}
