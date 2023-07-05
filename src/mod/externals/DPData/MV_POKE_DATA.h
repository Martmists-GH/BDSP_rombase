#pragma once

#include "externals/il2cpp-api.h"

namespace DPData {
    struct MV_POKE_DATA : ILStruct<MV_POKE_DATA> {
        struct Fields {
            int32_t ZoneIDIndex;
            uint64_t RndSeed;
            uint32_t MonsNo;
            uint32_t Hp;
            uint8_t Lv;
            uint32_t Sick;
            uint8_t EncountStatus;
        };
    };
}
