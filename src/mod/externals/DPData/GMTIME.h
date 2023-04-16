#pragma once

#include <cstdint>

namespace DPData {
    struct GMTIME : ILStruct<GMTIME> {
        struct Fields {
            uint32_t saveCount;
            int64_t timestmp;
        };
    };
}
