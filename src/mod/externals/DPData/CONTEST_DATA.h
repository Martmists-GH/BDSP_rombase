#pragma once

#include <cstdint>

namespace DPData {
    struct CONTEST_DATA : ILStruct<CONTEST_DATA> {
        struct Fields {
            void* photoDatas;
            uint32_t contestRankPoint;
        };
    };
}
