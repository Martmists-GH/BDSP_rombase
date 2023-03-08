#pragma once

#include "externals/il2cpp-api.h"
#include "externals/Dpr/UI/UIWindow.h"
#include "externals/Dpr/UI/UIText.h"
#include "externals/UnityEngine/UI/Image.h"
#include "externals/UnityEngine/RectTransform.h"

namespace Dpr::UI {
    struct AdventureNote : IlClass<AdventureNote> {
        struct TypeParam : IlClass<TypeParam> {
            struct Fields {
                UnityEngine::RectTransform::Object* root;
                Dpr::UI::UIText::Object* detail;
                UnityEngine::UI::Image::Object* image;
            };
        };

        struct Fields : UnityEngine::MonoBehaviour::Fields {
            Dpr::UI::UIText::Object* _title;
            Dpr::UI::UIText::Object* _page;
            UnityEngine::UI::Image::Array* _arrows;
            Dpr::UI::AdventureNote::TypeParam::Array* _typeParams;
        };
    };
}
