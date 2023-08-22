#pragma once

#include "externals/il2cpp-api.h"

#include "externals/System/String.h"
#include "externals/UnityEngine/MonoBehaviour.h"

namespace Dpr::UI {
    struct UIModelViewController : ILClass<UIModelViewController> {
        struct Fields : UnityEngine::MonoBehaviour::Fields {
            // TODO
        };

        inline void PlayAnimation(int32_t anim, bool forceLoop) {
            external<void>(0x01a10810, this, anim, forceLoop);
        }

        inline int32_t GetAnimationIndexByClipName(System::String::Object* clipName) {
            return external<int32_t>(0x01a0e950, this, clipName);
        }
    };
}