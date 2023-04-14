#pragma once

#include "externals/il2cpp.h"
#include "externals/il2cpp-api.h"

namespace Dpr::Item {
    struct ItemInfo : ILClass<ItemInfo> {
        struct Fields {
            // TODO
        };

        inline int32_t get_Id() {
            return external<int32_t>(0x01ca61f0, this);
        }
    };
}
