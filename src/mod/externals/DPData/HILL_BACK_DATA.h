#pragma once

#include <cstdint>

namespace DPData {
    struct HILL_BACK_DATA : ILStruct<HILL_BACK_DATA> {
        struct Fields {
            bool TalkFlg;
            uint16_t EncTblIdx1;
            uint16_t EncTblIdx2;
        };
    };
}
