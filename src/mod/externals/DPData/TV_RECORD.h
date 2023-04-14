#pragma once

namespace DPData {
    struct TV_RECORD : ILStruct<TV_RECORD> {
        struct Fields {
            void* int_data;
            void* str_data;
        };
    };
}
