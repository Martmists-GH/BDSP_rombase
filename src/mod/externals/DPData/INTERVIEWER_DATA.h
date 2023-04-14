#pragma once

namespace DPData {
    struct INTERVIEWER_DATA : ILStruct<INTERVIEWER_DATA> {
        struct Fields {
            void* program_data;
            void* int_data;
            void* str_data;
        };
    };
}
