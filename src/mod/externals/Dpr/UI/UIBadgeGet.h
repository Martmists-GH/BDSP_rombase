#pragma once

#include "externals/il2cpp-api.h"

#include "externals/Dpr/UI/UIWindow.h"
#include "externals/UnityEngine/GameObject.h"

namespace Dpr::UI {
    struct UIBadgeGet : ILClass<UIBadgeGet> {
        struct Fields : Dpr::UI::UIWindow::Fields {
            UnityEngine::GameObject::Object* modelViewPrefab;
            void* modelViewRawImage; // UnityEngine_UI_RawImage_o
            UnityEngine::GameObject::Object* modelViewObject;
            void* modelViewController; // Dpr_UI_BadgeGetViewController_o
            int32_t badgeNo;
        };
    };
}