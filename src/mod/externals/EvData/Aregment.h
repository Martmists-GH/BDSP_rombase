#pragma once

#include "externals/il2cpp-api.h"

#include "externals/System/Collections/Generic/List.h"

namespace EvData {
    struct Aregment : ILStruct<Aregment> {
        struct Fields {
            int32_t argType;
            int32_t data;
        };
    };
}

namespace System::Collections::Generic {
    struct List$$Aregment : List<List$$Aregment, EvData::Aregment> {
        
    };
}
