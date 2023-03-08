#pragma once

#include "externals/il2cpp.h"
#include "externals/Dpr/Item/ItemInfo.h"
#include "UIWindow.h"

namespace Dpr::UI {
    struct UIBag : IlClass<UIBag> {
        struct __c__DisplayClass127_0 : IlClass<__c__DisplayClass127_0> {
            struct Fields {
                Dpr::UI::UIBag::Object* __4__this;
                Dpr::Item::ItemInfo::Object* item;
                void* useItemAction;
                void* equipItemAction;
                void* __9__12;
                void* __9__17;
                void* __9__13;
                void* __9__19;
            };
        };

        struct __c__DisplayClass127_1 : IlClass<__c__DisplayClass127_1> {
            struct Fields {
                uint32_t fieldFuncType;
                Dpr::UI::UIBag::__c__DisplayClass127_0::Object* CS___8__locals1;
            };
        };

        struct __c__DisplayClass134_0 : IlClass<__c__DisplayClass134_0> {
            inline void _UseWazaMachine_b__3(int32_t index) {
                external<void>(0x01be0fa0, this, index);
            }
        };

        struct Fields : Dpr::UI::UIWindow::Fields {
            // TODO
        };

        inline void Close(void* onClosed, int32_t nextWindowId, bool isPlayCloseSe) {
            external<void>(0x01859870, this, onClosed, nextWindowId, isPlayCloseSe);
        }
    };
}
