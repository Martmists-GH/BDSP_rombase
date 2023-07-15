#pragma once

#include "externals/il2cpp-api.h"

namespace Dpr::Battle::View {
    struct BtlvBallInfo : ILStruct<BtlvBallInfo> {
        struct Fields {
            uint8_t ballId;
            bool hasCapsule;
            bool isStrangeBall;
            void* affixSealDatas;
            uint8_t sealCnt;
        };
    };
}
