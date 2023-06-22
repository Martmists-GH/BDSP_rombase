#pragma once

#include "externals/il2cpp-api.h"

#include "externals/EvData/Command.h"
#include "externals/System/Collections/Generic/List.h"
#include "externals/System/String.h"

namespace EvData {
    struct Script : ILClass<Script> {
        struct Fields {
            System::String::Object* Label;
            System::Collections::Generic::List$$Command::Object* Commands;
        };
    };
}

namespace System::Collections::Generic {
    struct List$$Script : List<List$$Script, EvData::Script> {
        
    };
}
