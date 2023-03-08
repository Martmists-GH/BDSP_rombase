#pragma once

#include <cstdint>

namespace DPData {
    struct GMS_DATA : IlStruct<GMS_DATA> {
        struct Fields {
            void* pointDatas;
            uint16_t tradeListIndex;
            uint16_t browsingListIndex;
            uint8_t achievementStep;
        };
    };
}
