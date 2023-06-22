#pragma once

#include "externals/il2cpp-api.h"

#include "externals/EvData/Script.h"
#include "externals/System/String.h"
#include "externals/UnityEngine/ScriptableObject.h"

struct _EvData : ILClass<_EvData, 0x04c5f100> {
    struct Fields : UnityEngine::ScriptableObject::Fields {
        System::Collections::Generic::List$$Script::Object* Scripts;
        System::Collections::Generic::List$$String::Object* StrList;
    };
    
    inline System::String::Object * GetString(int32_t index) {
        return external<System::String::Object *>(0x01f115b0, this, index);
    }
};
