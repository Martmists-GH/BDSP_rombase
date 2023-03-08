#pragma once

#include <cstdint>

namespace DPData {
    struct PoffinSaveData : IlStruct<PoffinSaveData> {
        struct Fields {
            void* Poffins;
            int32_t CookingCount;
        };
    };
}
