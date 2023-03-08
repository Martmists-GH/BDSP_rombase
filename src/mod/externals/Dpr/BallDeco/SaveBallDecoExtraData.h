#pragma once

namespace Dpr::BallDeco {
    struct SaveBallDecoExtraData : IlStruct<SaveBallDecoExtraData> {
        struct Fields {
            void* AttachCapsuleTrays;
            void* AttachCapsulePositions;
        };
    };
}
