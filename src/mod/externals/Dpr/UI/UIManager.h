#pragma once

#include "externals/il2cpp-api.h"
#include "externals/SmartPoint/AssetAssistant/SingletonMonoBehaviour.h"
#include "externals/UnityEngine/Transform.h"

namespace Dpr {
    namespace UI {
        struct ShopBoutiqueChange;
    }
}


namespace Dpr::UI {
    struct UIManager : ILClass<UIManager> {
        struct Fields : public SmartPoint::AssetAssistant::SingletonMonoBehaviour::Fields {
            UnityEngine::Transform::Object* _activeRoot;
            char todo[264];
        };

        static inline Dpr::UI::UIManager::Object* instance() {
            return SmartPoint::AssetAssistant::SingletonMonoBehaviour::get_Instance(SmartPoint::AssetAssistant::SingletonMonoBehaviour::Method$$UIManager$$get_Instance);
        }

        static inline StaticILMethod<0x04c8ffe8, Dpr::UI::ShopBoutiqueChange> Method$$CreateUIWindow_ShopBoutiqueChange_ {};

        template <typename T>
        inline T::Object* CreateUIWindow(int32_t windowId, ILMethod<T>& method) {
            return external<typename T::Object*>(0x01cf9f20, this, windowId, *method);
        }
    };
}

static_assert(sizeof(Dpr::UI::UIManager::Fields) == 280);
