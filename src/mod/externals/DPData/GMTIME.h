#pragma once

#include <cstdint>

namespace DPData {
    struct GMTIME : ILStruct<GMTIME> {
        #pragma pack(push, 4)
        struct Fields {
            uint32_t saveCount;
            int64_t timestmp;
        };
        #pragma pack(pop)
    };
}
