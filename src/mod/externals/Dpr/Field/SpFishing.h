#pragma once

#include "externals/il2cpp-api.h"

#include "externals/UnityEngine/Vector2Int.h"

namespace Dpr::Field {
    struct SpFishing : ILClass<SpFishing> {
        static inline bool CheckPoint(UnityEngine::Vector2Int::Object *position) {
            struct { int32_t x; int32_t y; } positionProxy = { position->fields.m_X, position->fields.m_Y };
            return external<bool>(0x019b55c0, &positionProxy);
        }
    };
}
