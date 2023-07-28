#pragma once

#include "externals/il2cpp-api.h"

#include "externals/Dpr/UI/UIWindow.h"
#include "externals/UnityEngine/RectTransform.h"

namespace Dpr::UI {
    struct PokemonWindowBase : ILClass<PokemonWindowBase> {
        struct BaseParam : ILClass<BaseParam> {
            struct Fields {
                int32_t selectIndex;
            };
        };

        struct Fields : Dpr::UI::UIWindow::Fields {
            void* _party; // Dpr_UI_PokemonParty_o*
            UnityEngine::RectTransform::Object* _messageWindowRoot;
        };
    };
}