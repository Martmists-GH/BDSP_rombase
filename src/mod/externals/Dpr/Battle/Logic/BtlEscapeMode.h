#pragma once

#include "externals/il2cpp-api.h"

namespace Dpr::Battle::Logic {
    enum class BtlEscapeMode : int32_t {
        BTL_ESCAPE_MODE_WILD = 0,
        BTL_ESCAPE_MODE_NG = 1,
        BTL_ESCAPE_MODE_CONFIRM = 2,
        BTL_ESCAPE_MODE_MAX = 3,
    };
}