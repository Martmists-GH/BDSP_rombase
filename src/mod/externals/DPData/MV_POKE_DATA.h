#pragma once

#include "externals/il2cpp-api.h"

namespace DPData {
    struct MV_POKE_DATA : ILStruct<MV_POKE_DATA> {
        struct Fields {
            int32_t ZoneIDIndex;
            uint32_t RndSeed1;
            uint32_t RndSeed2; // Had to split RndSeed into two to fix alignment, this one seems to always be 0
            uint32_t MonsNo;
            uint32_t Hp;
            uint8_t Lv;
            uint32_t Sick;
            uint8_t EncountStatus;
            char padding[8]; // For the proper size
        };

        static_assert(offsetof(Fields, MonsNo) == 0xc);
        static_assert(offsetof(Fields, Lv) == 0x14);
        static_assert(sizeof(Fields) == 0x28);
    };
}
