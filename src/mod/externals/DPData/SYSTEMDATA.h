#pragma once

#include "GMTIME.h"

namespace DPData {
    struct SYSTEMDATA : IlStruct<SYSTEMDATA> {
        struct Fields {
            DPData::GMTIME::Object StartTime;
            DPData::GMTIME::Object SaveTime;
            DPData::GMTIME::Object PenaltyTime;
            DPData::GMTIME::Object DailyEventLastTime;
            void* nxSnapshot;
            uint32_t fd_bgmEvnet;
            int64_t reserved_long0;
            int64_t reserved_long1;
            int64_t reserved_long2;
            int64_t reserved_long3;
            int64_t reserved_long4;
            int64_t reserved_long5;
        };
    };
}
