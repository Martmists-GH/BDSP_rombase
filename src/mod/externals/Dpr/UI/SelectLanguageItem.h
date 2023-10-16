#pragma once

#include "externals/il2cpp-api.h"
#include "externals/Dpr/UI/SelectOpeningItem.h"

namespace Dpr::UI {
    struct SelectLanguageItem : ILClass<SelectLanguageItem> {
        struct Fields : Dpr::UI::SelectOpeningItem::Fields {
            int32_t _langId;
            bool _useKanji;
        };
    };
}

namespace System::Collections::Generic {
    struct List$$SelectLanguageItem : List<List$$SelectLanguageItem, Dpr::UI::SelectLanguageItem> {
        static inline StaticILMethod<0x04c898c8> Method$$Add {};
    };
}