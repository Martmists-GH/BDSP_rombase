#pragma once

#include "externals/il2cpp-api.h"

namespace DPData {
    struct _FIELDOBJ_SAVE : IlStruct<_FIELDOBJ_SAVE> {
        struct Fields {
            void* fldobj_sv;
        };
    };
}
