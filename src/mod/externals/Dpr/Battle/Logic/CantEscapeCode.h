#pragma once

#include "externals/il2cpp-api.h"

namespace Dpr::Battle::Logic {
    enum class CantEscapeCode : int32_t {
        CANTESC_START = 0,
        CANTESC_KAGEFUMI = 0,
        CANTESC_ARIJIGOKU = 1,
        CANTESC_JIRYOKU = 2,
        CANTESC_TOOSENBOU = 3,
        CANTESC_FAIRY_LOCK = 4,
        CANTESC_MAX = 5,
        CANTESC_NULL = 5
    };
}
