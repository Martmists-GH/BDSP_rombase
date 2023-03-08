#pragma once

namespace DPData {
    struct INTERVIEWER_DATA : IlStruct<INTERVIEWER_DATA> {
        struct Fields {
            void* program_data;
            void* int_data;
            void* str_data;
        };
    };
}
