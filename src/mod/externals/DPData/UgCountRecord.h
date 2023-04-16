#pragma once

#include <cstdint>

namespace DPData {
    struct UgCountRecord : ILStruct<UgCountRecord> {
        struct Fields {
            int16_t DigFossilPlayCount;
            int16_t NumStatueBroadcastOnTV;
            int32_t NumTimesSecretBaseBroadcastOnTVWereLiked;
            int32_t SomeoneSecretBaseLikeCount;
            int32_t NumSuccessfulLightStoneSearches;
            int64_t reserved_long01;
            int64_t reserved_long02;
        };
    };
}
