#pragma once

#include "externals/il2cpp-api.h"
#include "externals/Dpr/Battle/Logic/BTL_POKEPARAM.h"

namespace Dpr::Battle::Logic {
    struct BTL_CLIENT : ILClass<BTL_CLIENT> {
        inline int32_t checkForbidChangeEscapeCommon(BTL_POKEPARAM *procPoke, uint8_t *pokeID, uint16_t *tokuseiID) {
            return external<int32_t>(0x01f574e0, this, procPoke, pokeID, tokuseiID);
        }
    };
}
