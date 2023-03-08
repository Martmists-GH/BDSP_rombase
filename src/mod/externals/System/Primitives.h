#pragma once

#include "externals/il2cpp-api.h"
#include <cstdint>

typedef bool System_Boolean;
typedef uint8_t System_Byte;
typedef uint16_t System_Char;
typedef int32_t System_Int32;
typedef uint32_t System_UInt32;
typedef int64_t System_Int64;

PRIMITIVE_ARRAY(System_Boolean);
PRIMITIVE_ARRAY(System_Byte);
PRIMITIVE_ARRAY(System_Char);
PRIMITIVE_ARRAY(System_Int32);
PRIMITIVE_ARRAY(System_UInt32);
PRIMITIVE_ARRAY(System_Int64);

static_assert(sizeof(System_Byte_array) == 0x10020);
