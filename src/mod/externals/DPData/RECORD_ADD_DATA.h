#pragma once

namespace DPData {
    struct RECORD_ADD_DATA : ILStruct<RECORD_ADD_DATA> {
        struct Fields {
            void* head;
            void* rankingFlag;
        };
    };
}
