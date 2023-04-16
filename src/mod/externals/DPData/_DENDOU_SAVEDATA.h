#pragma once

#include <cstdint>
#include "externals/il2cpp-api.h"

namespace DPData {
    struct _DENDOU_SAVEDATA : ILStruct<_DENDOU_SAVEDATA> {
        struct Fields {
            void* record;
            uint32_t savePoint;
            uint32_t latestNumber;
        };
    };
}
