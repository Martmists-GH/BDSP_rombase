#pragma once

#include "externals/il2cpp-api.h"

namespace EvData {
    enum class ArgType : int32_t {
        Command = 0,
        Float = 1,
        Work = 2,
        Flag = 3,
        SysFlag = 4,
        String = 5
    };
}
