#pragma once

#include "externals/il2cpp.h"
#include "externals/UnityEngine/Behaviour.h"

namespace UnityEngine {
    struct MonoBehaviour : ILClass<MonoBehaviour> {
        struct Fields : public UnityEngine::Behaviour::Fields {

        };
    };
}
