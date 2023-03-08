#pragma once

#include <cstdint>


namespace DPData {
    struct MysteryGiftSaveData : IlStruct<MysteryGiftSaveData> {
        struct Fields {
            void* recvDatas;
            void* receiveFlag;
            void* oneDayDatas;
            int64_t serialLockTimestamp;
            bool ngFlag;
            uint8_t ngCounter;
            void* reserved_ushorts;
            void* reserve;
        };
    };
}
