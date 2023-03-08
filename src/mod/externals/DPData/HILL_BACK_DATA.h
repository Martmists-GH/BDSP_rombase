#pragma once

#include <cstdint>

namespace DPData {
    struct HILL_BACK_DATA : IlStruct<HILL_BACK_DATA> {
        struct Fields {
            bool TalkFlg;
            uint16_t EncTblIdx1;
            uint16_t EncTblIdx2;
        };
    };
}
