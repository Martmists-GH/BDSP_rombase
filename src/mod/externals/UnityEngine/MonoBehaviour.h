#pragma once

#include "externals/il2cpp.h"
#include "externals/UnityEngine/Behaviour.h"

namespace UnityEngine {
    struct MonoBehaviour : IlClass<MonoBehaviour> {
        struct Fields : public UnityEngine::Behaviour::Fields {
            // TODO
        };
    };
}
