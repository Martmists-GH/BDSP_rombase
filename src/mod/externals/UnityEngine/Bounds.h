#pragma once

#include "externals/il2cpp-api.h"
#include "Vector3.h"

namespace UnityEngine {
    struct Bounds : IlStruct<Bounds> {
        struct Fields {
            UnityEngine::Vector3::Object m_Center;
            UnityEngine::Vector3::Object m_Extents;
        };
    };
}
