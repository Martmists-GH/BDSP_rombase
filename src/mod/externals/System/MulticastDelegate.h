#pragma once

#include "externals/il2cpp-api.h"
#include "externals/System/Delegate.h"

namespace System {
    struct MulticastDelegate : ILClass<MulticastDelegate> {
        struct Fields : System::Delegate::Fields {
            System::Delegate::Array* delegates;
        };
    };
}
