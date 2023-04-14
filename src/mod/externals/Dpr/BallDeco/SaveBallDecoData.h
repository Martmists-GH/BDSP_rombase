#pragma once

#include <cstdint>

namespace Dpr::BallDeco {
    struct SaveBallDecoData : ILStruct<SaveBallDecoData> {
        struct Fields {
            uint8_t CapsuleCount;
            void* CapsuleDatas;
        };
    };
}
