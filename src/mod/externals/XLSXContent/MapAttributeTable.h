#pragma once

#include "externals/il2cpp-api.h"

#include "externals/System/String.h"
#include "externals/UnityEngine/ScriptableObject.h"

namespace XLSXContent {
    struct MapAttributeTable : ILClass<MapAttributeTable> {
        struct SheetData : ILClass<SheetData> {
            struct Fields {
                int32_t Code;
                int32_t Attribute;
                bool Entry;
                bool Water;
                bool Encount;
                System::String::Object* FieldEncount;
            };
        };

        struct Fields : UnityEngine::ScriptableObject::Fields {
            XLSXContent::MapAttributeTable::SheetData::Array* Data;
        };
    };
}
