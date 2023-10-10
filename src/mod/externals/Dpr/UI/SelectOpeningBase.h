#pragma once

#include "externals/il2cpp-api.h"
#include "externals/Dpr/UI/SelectLanguageItem.h"
#include "externals/Dpr/UI/UIWindow.h"
#include "externals/UnityEngine/UI/Image.h"

namespace Dpr::UI {
    struct SelectOpeningBase : ILClass<SelectOpeningBase> {
        struct Fields : Dpr::UI::UIWindow::Fields {
            UnityEngine::UI::Image::Object* _imageBg;
            UnityEngine::UI::Image::Object* _imageBgBody;
            void* _spriteBgs; // UnityEngine_Sprite_array*
        };
    };
}