#pragma once

#include "externals/il2cpp-api.h"
#include "externals/Dpr/Battle/Logic/BTL_POKEPARAM.h"

namespace Dpr::Battle::Logic {
    enum CantEscapeCode {
        CANTESC_START = 0,
        CANTESC_KAGEFUMI = 0,
        CANTESC_ARIJIGOKU = 1,
        CANTESC_JIRYOKU = 2,
        CANTESC_TOOSENBOU = 3,
        CANTESC_FAIRY_LOCK = 4,
        CANTESC_MAX = 5,
        CANTESC_NULL = 5
    };

    struct BTL_CLIENT : IlClass<BTL_CLIENT> {
        inline int32_t checkForbidChangeEscapeCommon(BTL_POKEPARAM *procPoke, uint8_t *pokeID, uint16_t *tokuseiID) {
            return external<int32_t>(0x01f574e0, this, procPoke, pokeID, tokuseiID);
        }
    };
}
