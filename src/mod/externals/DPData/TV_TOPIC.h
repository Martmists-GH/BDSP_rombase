#pragma once

#include <cstdint>

namespace DPData {
    struct TV_TOPIC : ILStruct<TV_TOPIC> {
        struct Fields {
            void* int_data;
            int32_t reserved_int1;
            int32_t reserved_int2;
            int32_t reserved_int3;
            void* view_flag;
            uint8_t reserved_byte1;
            uint8_t reserved_byte2;
            uint8_t reserved_byte3;
        };
    };
}
