#pragma once

#include "externals/il2cpp-api.h"
#include "externals/UnityEngine/YieldInstruction.h"

namespace UnityEngine {
    struct Coroutine : ILClass<Coroutine, 0x04c5f540> {
        struct Fields : UnityEngine::YieldInstruction::Fields {
            intptr_t m_Ptr;
        };
    };
}
