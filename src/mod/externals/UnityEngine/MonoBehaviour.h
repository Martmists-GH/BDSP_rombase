#pragma once

#include "externals/il2cpp-api.h"
#include "externals/UnityEngine/Behaviour.h"

namespace UnityEngine {
    struct MonoBehaviour : ILClass<MonoBehaviour> {
        struct Fields : public UnityEngine::Behaviour::Fields {

        };
    };
}
