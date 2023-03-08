#pragma once

#include "externals/il2cpp-api.h"
#include "Transform.h"


namespace UnityEngine {
    struct RectTransform : IlClass<RectTransform> {
        struct Fields : UnityEngine::Transform::Fields {

        };
    };
}

namespace System::Collections::Generic {
    struct List$$RectTransform : List<List$$RectTransform, UnityEngine::RectTransform> {
        static ILMethod<0x04c8ad78, UnityEngine::RectTransform> Method$$Add;
    };
}
