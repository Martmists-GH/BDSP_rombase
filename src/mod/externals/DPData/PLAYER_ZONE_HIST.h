#pragma once

#include <cstdint>

namespace DPData {
    struct PLAYER_ZONE_HIST : IlStruct<PLAYER_ZONE_HIST> {
        struct Fields {
            int32_t BeforeZone;
            int32_t OldZone;
        };
    };
}
