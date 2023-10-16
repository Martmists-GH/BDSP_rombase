#pragma once

#include "externals/il2cpp-api.h"

#include "externals/DG/Tweening/TweenCallback.h"

namespace DG::Tweening::Core {
    struct ABSSequentiable : ILClass<ABSSequentiable> {
        struct Fields {
            int32_t tweenType;
            float sequencedPosition;
            float sequencedEndPosition;
            DG::Tweening::TweenCallback::Object* onStart;
        };
    };
}
