#pragma once

#include <cstdint>

namespace DPData {
    struct LOCATION_WORK : ILStruct<LOCATION_WORK> {
        struct Fields {
            int32_t zoneID;
            float posX;
            float posY;
            float posZ;
            int32_t dir;
        };
    };
}
