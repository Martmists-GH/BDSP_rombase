#pragma once

#include "externals/il2cpp-api.h"

#include "externals/DPData/KinomiGrow.h"

namespace DPData {
    struct KinomiGrowSaveData : ILStruct<KinomiGrowSaveData> {
        struct Fields {
            DPData::KinomiGrow::Array* kinomiGrows;
            int64_t LastUpdateMinutes;
        };
    };
}
