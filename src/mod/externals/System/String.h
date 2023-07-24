#pragma once

#include "externals/il2cpp-api.h"

#include "externals/System/Collections/Generic/List.h"
#include "externals/System/Primitives.h"
#include "externals/System/Text/Encoding.h"

namespace System {
    struct String : ILClass<String> {
        struct Fields {
            int32_t m_stringLength;
            int16_t m_firstChar;
        };

        static String::Object* Create(const char* value) {
            return external<String::Object*>(0x026fb3e0, nullptr, (int8_t*)value);
        }

        static String::Object* Create(const std::string& value) {
            return Create(value.c_str());
        }

        static inline bool op_Equality(String::Object* a, String::Object* b) {
            return external<bool>(0x026f05c0, a, b);
        }

        static inline bool IsNullOrEmpty(String::Object* value) {
            return external<bool>(0x026f3810, value);
        }

        std::string asCString() {
            System::String::Object* str = this->instance();
            System::Text::UTF8Encoding::Object* encoding = System::Text::Encoding::get_UTF8();
            uint32_t size = encoding->GetByteCount(str);
            auto arr = reinterpret_cast<System::Byte_array *>(system_array_new(*(Il2CppClass**)exl::util::modules::GetTargetOffset(0x04c552e0), size+1));
            encoding->GetBytes(str, 0, str->fields.m_stringLength, arr, 0);
            arr->m_Items[size] = 0;
            auto res = std::string((char*)&arr->m_Items[0]);
            return res;
        }
    };
}

namespace System::Collections::Generic {
    struct List$$String : List<List$$String, System::String> {
        
    };
}
