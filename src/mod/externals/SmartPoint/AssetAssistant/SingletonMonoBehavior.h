#pragma once

#include "externals/il2cpp.h"

namespace Dpr {
    namespace UI {
        struct UIManager;
    }
}

namespace SmartPoint::AssetAssistant {
    struct SingletonMonoBehaviour : IlClass<SingletonMonoBehaviour, 0x04c59b28> {
        static ILMethod<0x04c67700, Dpr::UI::UIManager> Method$$UIManager$$get_Instance;

        template <intptr_t A, typename T>
        static inline T::Object* get_Instance(ILMethod<A, T>& method) {
            return external<typename T::Object*>(0x02322450, *method);
        }
    };
}
