#pragma once

#include <cstdint>

namespace DPData {
    struct POKETCH_DATA : IlStruct<POKETCH_DATA> {
        struct Fields {
            bool get_flag;
            bool pedometer_flag;
            bool dotart_modified_flag;
            int32_t color_type;
            int8_t app_count;
            int8_t app_index;
            void* app_flag;
            uint32_t pedometer;
            void* dotart_data;
            void* calendar_markbit;
            void* mark_map_pos;
            void* poke_history;
        };
    };
}
