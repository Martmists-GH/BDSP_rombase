#pragma once

#include <cstdint>

namespace DPData {
    struct PLAYTIME : IlStruct<PLAYTIME> {
        struct Fields {
            uint16_t hour;
            uint8_t minute;
            uint8_t second;
        };
    };
}
