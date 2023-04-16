#pragma once

namespace Dpr::BallDeco {
    struct SaveBallDecoExtraData : ILStruct<SaveBallDecoExtraData> {
        struct Fields {
            void* AttachCapsuleTrays;
            void* AttachCapsulePositions;
        };
    };
}
