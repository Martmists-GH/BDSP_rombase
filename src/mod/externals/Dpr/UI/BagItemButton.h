#pragma once

#include "externals/il2cpp-api.h"
#include "externals/UnityEngine/MonoBehaviour.h"
#include "externals/Dpr/Item/ItemInfo.h"

namespace Dpr::UI {
    struct BagItemButton : ILClass<BagItemButton> {
        struct Fields : UnityEngine::MonoBehaviour::Fields {
            // Fields
            UnityEngine::UI::Image::Object* iconImage;
            Dpr::UI::UIText::Object* nameText;
            UnityEngine::UI::Image::Object* newIconImage;
            UnityEngine::UI::Image::Object* favoriteIconImage;
            Dpr::UI::UIText::Object* stockCountLabelText;
            Dpr::UI::UIText::Object* stockCountValueText;
            UnityEngine::UI::Image::Object* registerButtonImage;
            void * shortcutButonSprites; //UnityEngine::Sprite::array*
            int32_t index;
            UnityEngine::RectTransform::Object* rectTransform;
            Dpr::Item::ItemInfo::Object* item;
        };
    };
}