#pragma once

#include "externals/il2cpp.h"

namespace Dpr {
    namespace UI {
        struct UIManager;
    }
}

namespace SmartPoint::AssetAssistant {
    struct SingletonMonoBehaviour : IlClass<SingletonMonoBehaviour, 0x04c59b28> {
        static inline StaticILMethod<0x04c67700, Dpr::UI::UIManager> Method$$UIManager$$get_Instance {};

        template <typename T>
        static inline T::Object* get_Instance(ILMethod<T>& method) {
            return external<typename T::Object*>(0x02322450, *method);
        }
    };
}
