#pragma once

namespace DPData {
    struct TV_RECORD : IlStruct<TV_RECORD> {
        struct Fields {
            void* int_data;
            void* str_data;
        };
    };
}
