#pragma once

#include "externals/il2cpp-api.h"

#include "externals/System/MulticastDelegate.h"

namespace System {
    struct Action : ILClass<Action, 0x04c56040> {
        struct Fields : System::MulticastDelegate::Fields {

        };

        template <typename T, typename... Args>
        inline void ctor(T* owner, ILMethod<T, Args...>& mi) {
            ctor(owner, *mi);
        }

        inline void ctor(void* __this, MethodInfo* delegate) {
            external<void>(0x023feb30, this, __this, delegate);
        }
    };
}
