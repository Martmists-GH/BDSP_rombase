#pragma once

#include <cstdint>

namespace DPData {
    struct GMTIME : IlStruct<GMTIME> {
        struct Fields {
            uint32_t saveCount;
            int64_t timestmp;
        };
    };
}
