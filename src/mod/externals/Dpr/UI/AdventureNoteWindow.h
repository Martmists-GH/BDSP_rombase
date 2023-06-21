#pragma once

#include "externals/il2cpp-api.h"
#include "externals/Dpr/UI/UIWindow.h"
#include "externals/Dpr/UI/AdventureNoteItem.h"
#include "externals/Dpr/UI/AdventureBase.h"
#include "externals/Dpr/UI/UIScrollView.h"


namespace Dpr::UI {
    struct AdventureNoteWindow : ILClass<AdventureNoteWindow> {
        struct _OpOpen_d__6 : ILClass<_OpOpen_d__6> {
            struct Fields {
                int32_t __1__state;
                Il2CppObject* __2__current;
                Dpr::UI::AdventureNoteWindow::Object* __4__this;
                int32_t prevWindowId;
            };
        };

        struct Fields : Dpr::UI::AdventureBase::Fields {
            Dpr::UI::UIScrollView::Object* _itemListScrollView;
            void* _cursor;
            System::Collections::Generic::List$$AdventureNoteItem_Param::Object* _itemParams;
            Dpr::UI::AdventureNoteItem::Object* _selectItem;
        };
    };
}
