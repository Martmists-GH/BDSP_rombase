#pragma once

#include <cstdint>

namespace DPData {
    struct BTLTOWER_SAVEWORK : IlStruct<BTLTOWER_SAVEWORK> {
        struct Fields {
            uint32_t max_master_rank;
            int32_t play_mode;
            int32_t old_playmode;
            uint32_t btl_point;
            uint32_t day_challeng_cnt;
            void* class_data;
            uint32_t challenge_cnt;
        };
    };
}
