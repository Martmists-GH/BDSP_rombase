#pragma once

#include "externals/il2cpp-api.h"

#include "externals/EvData/Aregment.h"
#include "externals/System/Collections/Generic/List.h"

namespace EvData {
    struct Command : ILClass<Command> {
        struct Fields {
            System::Collections::Generic::List$$Aregment::Object* Arg;
        };
    };
}

namespace System::Collections::Generic {
    struct List$$Command : List<List$$Command, EvData::Command> {
        
    };
}
