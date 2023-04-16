#pragma once

#include "externals/il2cpp-api.h"
#include "externals/UnityEngine/Transform.h"


namespace UnityEngine {
    struct RectTransform : ILClass<RectTransform> {
        struct Fields : UnityEngine::Transform::Fields {

        };
    };
}

namespace System::Collections::Generic {
    struct List$$RectTransform : List<List$$RectTransform, UnityEngine::RectTransform> {
        static inline StaticILMethod<0x04c8ad78, UnityEngine::RectTransform> Method$$Add {};
    };
}
