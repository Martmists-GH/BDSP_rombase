#pragma once

#include "externals/il2cpp-api.h"

namespace System
{
    template <typename T>
    struct Array
    {
        Il2CppObject obj;
        Il2CppArrayBounds *bounds;
        uint64_t max_length;
        T m_Items[65535];
    };

}