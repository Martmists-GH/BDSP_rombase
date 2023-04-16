#pragma once

#include <cstdint>

namespace DPData {
    struct PLAYTIME : ILStruct<PLAYTIME> {
        struct Fields {
            uint16_t hour;
            uint8_t minute;
            uint8_t second;
        };
    };
}
