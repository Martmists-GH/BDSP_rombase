#pragma once

#include <cstdint>

namespace DPData {
    struct KinomiGrowSaveData : IlStruct<KinomiGrowSaveData> {
        struct Fields {
            void* kinomiGrows;
            int64_t LastUpdateMinutes;
        };
    };
}
