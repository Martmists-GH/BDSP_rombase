#pragma once

#include "externals/il2cpp-api.h"
#include "externals/UnityEngine/SceneManagement/Scene.h"

namespace UnityEngine::SceneManagement {
    struct SceneManager : ILClass<SceneManager> {
        struct Fields {
            // Seems to be empty
        };

        static inline Scene::Object GetActiveScene() {
            return external<Scene::Object>(0x02994bf0);
        }
    };
}
