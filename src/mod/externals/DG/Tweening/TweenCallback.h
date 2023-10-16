#pragma once

#include "externals/il2cpp-api.h"

#include "externals/System/MulticastDelegate.h"

namespace DG::Tweening {
    struct TweenCallback : ILClass<TweenCallback> {
        struct Fields : System::MulticastDelegate::Fields {};
    };
}
