#pragma once

#include <cstdint>

namespace DPData {
    struct HONEY_TREE : ILStruct<HONEY_TREE> {
        struct Fields {
            int64_t LastUpdateMinutes;
            uint8_t TreeNo;
            void* HoneyData;
        };
    };
}
