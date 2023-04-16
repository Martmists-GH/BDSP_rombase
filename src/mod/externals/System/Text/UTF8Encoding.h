#pragma once

#include "externals/il2cpp-api.h"

namespace System {
    struct String;
}

namespace System::Text {
    struct UTF8Encoding : ILClass<UTF8Encoding> {
        inline uint32_t GetByteCount(System::String* str) {
            return external<uint32_t>(0x02588990, this, str);
        }

        inline int32_t GetBytes(System::String* str, int32_t charIndex, int32_t charCount, System::Byte_array* bytes, int32_t byteIndex) {
            return external<int32_t>(0x02588b50, this, str, charIndex, charCount, bytes, byteIndex);
        }
    };
}
