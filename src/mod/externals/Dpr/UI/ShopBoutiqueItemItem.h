#pragma once

#include "externals/il2cpp-api.h"
#include "externals/System/Collections/Generic/List.h"
#include "externals/XLSXContent/ShopTable.h"
#include "externals/XLSXContent/CharacterDressData.h"
#include "ShopItemItem.h"

namespace Dpr::UI {
    struct ShopBoutiqueItemItem : ILClass<ShopBoutiqueItemItem, 0x04c62438> {
        struct Param : ILClass<Param, 0x04c62470> {
            struct Fields{
                XLSXContent::ShopTable::SheetBoutiqueShop::Object* data;
                XLSXContent::CharacterDressData::SheetData::Object* dressData;
            };

            inline void ctor() {
                external<void>(0x01d45cc0, this);
            }

        };

        struct Fields : Dpr::UI::ShopItemItem::Fields {
            UnityEngine::UI::Image::Object* _waredIcon;
            void* _purchased; //Dpr_UI_ShopBoutiqueItemItem_Purchased_o*
            void* _colors; //UnityEngine_Color_array*
            Dpr::UI::ShopBoutiqueItemItem::Param::Object* _param;
            XLSXContent::CharacterDressData::SheetData::Object* _characterDressData;
            int32_t _boutiqueType;
        };
    };
}


namespace System::Collections::Generic {
    struct List$$ShopBoutiqueItemItem_Param : List<List$$ShopBoutiqueItemItem_Param, Dpr::UI::ShopBoutiqueItemItem::Param> {
        static inline StaticILMethod<0x04c89920, Dpr::UI::ShopBoutiqueItemItem::Param> Method$$Add {};
    };
}