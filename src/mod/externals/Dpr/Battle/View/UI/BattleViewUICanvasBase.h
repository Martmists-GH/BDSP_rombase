#pragma once

#include "externals/il2cpp-api.h"
#include "externals/UnityEngine/MonoBehaviour.h"
#include "externals/UnityEngine/Vector2.h"
#include "externals/UnityEngine/RectTransform.h"
#include "externals/System/Action.h"

namespace Dpr::Battle::View::UI {
    struct BattleViewUICanvasBase : ILClass<BattleViewUICanvasBase> {
        struct TransitionParams : ILStruct<TransitionParams> {
            struct Fields {
                UnityEngine::Vector2::Object HideAnchorPosition;
                UnityEngine::Vector2::Object ShowAnchorPosition;
                int32_t Ease;
                float Duration;
                float Delay;
            };
        };

        struct Fields : public UnityEngine::MonoBehaviour::Fields {
            uint8_t _transitionType;
            TransitionParams::Object _transitionParams;
            UnityEngine::RectTransform::Object* _cachedRectTransform;
            void* _canvasGroup;
            System::Action::Object* _onShowComplete;
            System::Action::Object* _onHideComplete;
            int32_t _MaxIndex_k__BackingField;
            int32_t _CurrentIndex_k__BackingField;
            bool _IsFocus_k__BackingField;
            bool _IsShow_k__BackingField;
            bool _IsValid_k__BackingField;
            bool _IsTransition_k__BackingField;
            int32_t _animationState_k__BackingField;
        };
    };
}
