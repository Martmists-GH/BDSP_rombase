#pragma once

#include "externals/il2cpp-api.h"
#include <cstdint>

namespace System {
    typedef bool Boolean;
    typedef uint8_t Byte;
    typedef uint16_t Char;
    typedef int32_t Int32;
    typedef uint32_t UInt32;
    typedef int64_t Int64;

    PRIMITIVE_ARRAY(Boolean);
    static Il2CppClass* Boolean_array_TypeInfo() {
        return *reinterpret_cast<Il2CppClass**>(exl::util::modules::GetTargetOffset(0x04c55920));
    }
    PRIMITIVE_ARRAY(Byte);
    PRIMITIVE_ARRAY(Char);
    PRIMITIVE_ARRAY(Int32);
    PRIMITIVE_ARRAY(UInt32);
    PRIMITIVE_ARRAY(Int64);
}
