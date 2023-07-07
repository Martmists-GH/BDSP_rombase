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
            struct { float x; float y; float z; } posProxy = { pos->fields.x, pos->fields.y, pos->fields.z };
            return external<bool>(0x019b4fa0, info, &posProxy, size);
        }
    };
}
