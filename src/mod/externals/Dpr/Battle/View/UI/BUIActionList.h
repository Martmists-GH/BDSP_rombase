#pragma once

#include "externals/il2cpp-api.h"
#include "externals/Dpr/Battle/View/UI/BattleViewUICanvasBase.h"
#include "externals/UnityEngine/GameObject.h"

namespace Dpr::Battle::View::UI {
    struct BUIActionList : ILClass<BUIActionList> {
        struct Fields : Dpr::Battle::View::UI::BattleViewUICanvasBase::Fields {
            UnityEngine::GameObject::Object* _xyButtonFrame;
            UnityEngine::GameObject::Object* _yButtonFrame;
            void* _pokeBallButton;
            void* _situationButton;
            void* _buttonLayout;
            void* _actionButtons;
            bool _isBallEnable;
            bool _needOpenBallWindow;
            bool _isSafari;
            bool isButtonAction;
            int32_t _minIndex;
            int32_t _maxIndex;
            bool _IsReturnable_k__BackingField;
            int32_t _Result_k__BackingField;
        };
    };
}
