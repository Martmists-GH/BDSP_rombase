#pragma once

#include "externals/il2cpp-api.h"

namespace Dpr::Battle::Logic {
    struct ExpCalculator : ILClass<ExpCalculator, 0x04c5b098> {
        struct CalcExpWork : ILClass<CalcExpWork> {
            struct Fields {
                uint32_t exp;
                uint8_t hp;
                uint8_t pow;
                uint8_t def;
                uint8_t agi;
                uint8_t sp_pow;
                uint8_t sp_def;
                uint8_t g;
                bool fBonus;
                bool bGakusyuSouti;
                bool bGakusyuSoutiOnly;
            };
        };
    };
}
