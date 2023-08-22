#pragma once

#include "externals/il2cpp-api.h"
#include "externals/UnityEngine/MonoBehaviour.h"
#include "externals/UnityEngine/UI/Image.h"
#include "externals/UnityEngine/Vector2.h"
#include "externals/UnityEngine/Events/UnityAction.h"

namespace Dpr::UI {
    struct PoketchButton : ILClass<PoketchButton> {
        struct Fields : public UnityEngine::MonoBehaviour::Fields {
            UnityEngine::UI::Image::Object* _image;
            void* _pressedSprite;
            UnityEngine::Vector2::Object _pressedOffset;
            UnityEngine::Vector2::Object _pressedTransform;
            float _pressedScale;
            bool _canDrag;
            bool _disablePressedOffset;
            bool _enableRepeat;
            float _firstRepeatTime;
            float _repeatTime;
            UnityEngine::Vector3::Object _basePosition;
            UnityEngine::Vector3::Object _pressedPosition;
            UnityEngine::Vector2::Object _baseDeltaSize;
            UnityEngine::Vector2::Object _pressedDeltaSize;
            UnityEngine::Vector2::Object _baseScaleVector;
            UnityEngine::Vector2::Object _pressedScaleVector;
            bool _onRepeat;
            float _repeatTimeCount;
            int32_t _repeatCount;
            uint32_t _seEventId;
            bool _IsInitialized_k__BackingField;
            UnityEngine::Events::UnityAction::Object* _onButtonAction;
            UnityEngine::Events::UnityAction::Object* _OnTouchAction_k__BackingField;
            UnityEngine::Events::UnityAction::Object* _OnReleaseAction_k__BackingField;
        };

        static_assert(sizeof(Fields) == 160);

        inline void OnPush() {
            external<void>(0x01e622c0, this);
        }

        inline void Initialize(UnityEngine::Events::UnityAction* callback, int32_t seEventId) {
            external<void>(0x01e5e060, this, callback, seEventId);
        }

        inline void SetRelease() {
            external<void>(0x01e66280, this);
        }

        inline void SetTouch() {
            external<void>(0x01e65f60, this);
        }
    };
}
