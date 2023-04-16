#pragma once

#include "externals/il2cpp-api.h"
#include "externals/System/String.h"


namespace UnityEngine {
    struct _Object : ILClass<_Object> {
        struct Fields {
            intptr_t m_CachedPtr;
        };

        template <typename T>
        static inline T::Object* Instantiate(T* original) {
            return external<typename T::Object*>(0x0268aa90, original);
        }

        System::String::Object* GetName() {
            return external<System::String::Object*>(0x0268a940, this);
        }
    };
}
