#pragma once

#include "externals/il2cpp-api.h"
#include "externals/UnityEngine/MonoBehaviour.h"
#include "UIWindow.h"

namespace Dpr::UI {
    struct ShopBase : ILClass<ShopBase> {
        struct Fields : Dpr::UI::UIWindow::Fields {
            void* _itemListScrollView;
            void* _cursor;
            void* _itemDescriptionPanel;
            void* _selectAmount;
            int32_t _wazaItemDescriptionType;
        };
    };
}
