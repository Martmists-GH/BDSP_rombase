#pragma once

#include "externals/il2cpp-api.h"

#include "externals/Dpr/Field/FieldEncount.h"
#include "externals/UnityEngine/Vector3.h"

namespace Dpr::Field {
    struct SwayGrass : ILClass<SwayGrass> {
        static inline void StopSE() {
            external<void>(0x019b4fa0);
        }

        static inline bool SwayGrass_CheckSpEncount(Dpr::Field::FieldEncount::SWAY_ENC_INFO::Object *info, UnityEngine::Vector3::Object *pos, float size) {
            UnityEngine::Vector3::Fields posProxy = { .x = pos->fields.x, .y = pos->fields.y, .z = pos->fields.z };
            return external<bool>(0x019b43d0, info, &posProxy, size);
        }
    };
}
