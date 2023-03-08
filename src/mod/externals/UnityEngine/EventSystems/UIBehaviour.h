#pragma once

#include "externals/il2cpp-api.h"
#include "externals/UnityEngine/MonoBehaviour.h"

namespace UnityEngine::EventSystems {
    struct UIBehaviour : IlClass<UIBehaviour> {
        struct Fields : UnityEngine::MonoBehaviour::Fields {

        };
    };
}
