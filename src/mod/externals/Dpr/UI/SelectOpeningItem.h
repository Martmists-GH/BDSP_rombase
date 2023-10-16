#pragma once

#include "externals/il2cpp-api.h"
#include "externals/UnityEngine/MonoBehaviour.h"
#include "externals/UnityEngine/Color.h"
#include "externals/UnityEngine/UI/Image.h"

namespace Dpr::UI {
    struct SelectOpeningItem : ILClass<SelectOpeningItem> {
        struct Fields : UnityEngine::MonoBehaviour::Fields {
            UnityEngine::UI::Image::Object* _imageBody;
            void* _sprites; // UnityEngine_Sprite_array*
            UnityEngine::UI::Image::Object* _imageText;
            UnityEngine::Color::Array* _colors;
        };
    };
}