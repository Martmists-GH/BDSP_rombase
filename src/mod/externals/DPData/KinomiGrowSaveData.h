#pragma once

#include <cstdint>

namespace DPData {
    struct KinomiGrowSaveData : ILStruct<KinomiGrowSaveData> {
        struct Fields {
            void* kinomiGrows;
            int64_t LastUpdateMinutes;
        };
    };
}
