#pragma once

#include "externals/il2cpp-api.h"

#include "externals/DPData/GMTIME.h"
#include "externals/System/Primitives.h"

namespace DPData {
    struct SYSTEMDATA : ILStruct<SYSTEMDATA> {
        #pragma pack(push, 4)
        struct Fields {
            DPData::GMTIME::Object StartTime;
            DPData::GMTIME::Object SaveTime;
            DPData::GMTIME::Object PenaltyTime;
            DPData::GMTIME::Object DailyEventLastTime;
            System::Byte_array* nxSnapshot;
            uint32_t fd_bgmEvnet;
            int64_t reserved_long0;
            int64_t reserved_long1;
            int64_t reserved_long2;
            int64_t reserved_long3;
            int64_t reserved_long4;
            int64_t reserved_long5;
        };
        #pragma pack(pop)
    };
}
