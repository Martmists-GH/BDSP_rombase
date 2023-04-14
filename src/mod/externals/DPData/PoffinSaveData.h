#pragma once

#include <cstdint>

namespace DPData {
    struct PoffinSaveData : ILStruct<PoffinSaveData> {
        struct Fields {
            void* Poffins;
            int32_t CookingCount;
        };
    };
}
