#pragma once

#include "externals/il2cpp-api.h"
#include "externals/Dpr/UI/UIWindow.h"
#include "externals/Dpr/UI/AdventureNote.h"
#include "externals/UnityEngine/UI/Image.h"

namespace Dpr::UI {
    struct AdventureBase : IlClass<AdventureBase> {
        struct Fields : Dpr::UI::UIWindow::Fields {
            Dpr::UI::AdventureNote::Object* _note;
            UnityEngine::UI::Image::Object* _imageBg;
            void* _spriteBgs;
            void* _currentDatas;
            int32_t _pageIndex;
        };
    };
}
