#pragma once

#include <cstdint>

namespace DPData {
    struct TOPMENU_WORK : ILStruct<TOPMENU_WORK> {
        struct Fields {
            void* items;
            int32_t selectType;
        };
    };
}
