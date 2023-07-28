#pragma once

#include "externals/il2cpp-api.h"

#include "externals/System/_Object.h"
#include "externals/System/Primitives.h"
#include "externals/System/String.h"
#include "externals/System/Type.h"

namespace System::Runtime::Serialization {
    struct SerializationInfo : ILClass<SerializationInfo> {
        struct Fields {
            System::String::Array* m_members;
            System::_Object::Array* m_data;
            System::Type::Array* m_types;
            void* m_nameToIndex; // System_Collections_Generic_Dictionary_string__int__o
            int32_t m_currMember;
            void* m_converter; // System_Runtime_Serialization_IFormatterConverter_o
            System::String::Object* m_fullTypeName;
            System::String::Object* m_assemName;
            System::Type::Object* objectType;
            bool isFullTypeNameSetExplicit;
            bool isAssemblyNameSetExplicit;
            bool requireSameTokenInPartialTrust;
        };
    };
}
