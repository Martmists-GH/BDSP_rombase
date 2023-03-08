#pragma once

#include <cstdint>

namespace DPData {
    struct HONEY_TREE : IlStruct<HONEY_TREE> {
        struct Fields {
            int64_t LastUpdateMinutes;
            uint8_t TreeNo;
            void* HoneyData;
        };
    };
}
