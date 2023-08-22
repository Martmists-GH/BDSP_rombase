#pragma once

#include "externals/il2cpp-api.h"

#include "externals/System/Primitives.h"

namespace System {
    struct String;
}

namespace System::Text {
    struct UnicodeEncoding : ILClass<UnicodeEncoding> {
        inline uint32_t GetByteCount(System::String* str) {
            return external<uint32_t>(0x0258cb20, this, str);
        }

        inline int32_t GetBytes(System::String* str, int32_t charIndex, int32_t charCount, System::Byte_array* bytes, int32_t byteIndex) {
            return external<int32_t>(0x0258cce0, this, str, charIndex, charCount, bytes, byteIndex);
        }

        inline System::String* GetString(System::Byte_array* bytes, int32_t index, int32_t count) {
            return external<System::String*>(0x0258da20, this, bytes, index, count);
        }
    };
}
