#pragma once

#include <cstdint>

namespace DPData {
    struct UgSecretBase : IlStruct<UgSecretBase> {
        struct Fields {
            int16_t zoneID;
            int16_t posX;
            int16_t posY;
            uint8_t direction;
            uint8_t expansionStatus;
            int32_t goodCount;
            void* ugStoneStatue;
            bool isEnable;
        };
    };
}
