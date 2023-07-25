#pragma once

#include "externals/il2cpp-api.h"
#include "externals/System/String.h"

namespace XLSXContent {
    struct CharacterDressData : ILClass<CharacterDressData> {
        struct SheetData : ILClass<SheetData> {
            struct Fields {
                int32_t Index;
                System::String::Object * ID;
                void * BattleGraphic; //System_String_o *
                void * FieldGraphic; //System_String_o *
                int32_t Scale;
                void * MSLabel; //System_String_o *
            };
        };
    };
}