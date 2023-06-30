#pragma once

#include "externals/il2cpp-api.h"

#include "externals/System/MulticastDelegate.h"

namespace System {
    struct Action : ILClass<Action> {
        struct Fields : System::MulticastDelegate::Fields {

        };

        static const inline long void_TypeInfo = 0x04c56040;

        template <typename T, typename... Args>
        inline void ctor(T* owner, ILMethod<T, Args...>& mi) {
            ctor(owner, *mi);
        }

        inline void ctor(void* owner, MethodInfo* delegate) {
            external<void>(0x023feb30, this, owner, delegate);
        }
    };
}
