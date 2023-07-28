#pragma once

#include "externals/il2cpp-api.h"
#include "externals/UnityEngine/MonoBehaviour.h"
#include "externals/UnityEngine/UI/Image.h"
#include "externals/Dpr/UI/UIText.h"
#include "externals/Dpr/Item/ItemInfo.h"

namespace Dpr::UI {
    struct ShopItemItem : ILClass<ShopItemItem> {
        struct Fields : UnityEngine::MonoBehaviour::Fields {
            UnityEngine::UI::Image::Object* _icon;
            Dpr::UI::UIText::Object* _name;
            Dpr::UI::UIText::Object* _price;
            int32_t _shopType;
            int32_t _index;
            Dpr::Item::ItemInfo::Object* _itemInfo;
            void * _sealInfo; //Dpr_UI_SealInfo_o*
            void * _ugItemInfo; //Dpr_Item_UgItemInfo_o*
        };
    };
}