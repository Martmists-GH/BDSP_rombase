#pragma once

#include "externals/il2cpp-api.h"

#include "externals/System/Collections/Generic/List.h"
#include "externals/System/String.h"
#include "externals/UnityEngine/ScriptableObject.h"

struct EvData : ILClass<EvData, 0x04c5f100> {
    struct Fields : UnityEngine::ScriptableObject::Fields {
        System::Collections::Generic::List$$String::Object* StrList;
    };

    struct Script : ILClass<Script> {
        struct Fields {
            System::String::Object* Label;
            System::Collections::Generic::List$$Command::Object* Commands;
        };
    };

    struct Command : ILClass<Command> {
        struct Fields {
            System::Collections::Generic::List$$Aregment::Object* Arg;
        };
    };

    struct Aregment : ILStruct<Aregment> {
        struct Fields {
            int32_t argType;
            int32_t data;
        };
    };

    enum class ArgType {
        Command = 0,
        Float = 1,
        Work = 2,
        Flag = 3,
        SysFlag = 4,
        String = 5
    };
    
    inline System::String::Object * GetString(int32_t index) {
        external<System::String::Object *>(0x01f115b0, this, index);
    }
};

namespace System::Collections::Generic {
    struct List$$Command : List<List$$Command, EvData::Command> {
        
    };

    struct List$$Aregment : List<List$$Aregment, EvData::Aregment> {
        
    };
}
