#pragma once

#include "externals/il2cpp-api.h"

#include "externals/Dpr/UI/UIWazaManage.h"
#include "externals/SmartPoint/AssetAssistant/SingletonMonoBehaviour.h"
#include "externals/UIWindowID.h"
#include "externals/UnityEngine/Transform.h"

namespace Dpr {
    namespace UI {
        struct ShopBoutiqueChange;
    }
}

namespace Dpr::UI {
    struct UIManager : ILClass<UIManager, 0x04c5cc28> {
        struct Fields : public SmartPoint::AssetAssistant::SingletonMonoBehaviour::Fields {
            UnityEngine::Transform::Object* _activeRoot;
            char todo[264];
        };

        struct StaticFields {
            int32_t StickLLeft;
            int32_t StickLRight;
            int32_t StickLUp;
            int32_t StickLDown;
            int32_t ButtonA;
            int32_t ButtonB;
            int32_t ButtonX;
            int32_t ButtonY;
            int32_t ButtonPlusMinus;
            // ...
        };

        static inline Dpr::UI::UIManager::Object* instance() {
            return SmartPoint::AssetAssistant::SingletonMonoBehaviour::get_Instance(SmartPoint::AssetAssistant::SingletonMonoBehaviour::Method$$UIManager$$get_Instance);
        }

        static inline StaticILMethod<0x04c8ffe8, Dpr::UI::ShopBoutiqueChange> Method$$CreateUIWindow_ShopBoutiqueChange_ {};
        static inline StaticILMethod<0x04c90098, Dpr::UI::UIWazaManage> Method$$CreateUIWindow_UIWazaManage_ {};

        template <typename T>
        inline T::Object* CreateUIWindow(UIWindowID windowId, ILMethod<T>& method) {
            return external<typename T::Object*>(0x01cf9f20, this, (int32_t)windowId, *method);
        }
    };
}

static_assert(sizeof(Dpr::UI::UIManager::Fields) == 280);
