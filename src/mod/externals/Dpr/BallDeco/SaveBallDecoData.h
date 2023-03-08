#pragma once

#include <cstdint>

namespace Dpr::BallDeco {
    struct SaveBallDecoData : IlStruct<SaveBallDecoData> {
        struct Fields {
            uint8_t CapsuleCount;
            void* CapsuleDatas;
        };
    };
}
