#pragma once

#include "externals/il2cpp-api.h"

namespace Dpr::Battle::Logic {
    struct PokeResult : ILClass<PokeResult> {
        struct Fields {
            uint16_t totalTurnCount;
            uint16_t criticalCount;
            uint16_t totalDamageRecieved;
            uint16_t deadCount;
        };
    };
}
