#pragma once

#include "externals/il2cpp-api.h"

namespace Dpr::Battle::Logic {
    enum class BtlRule : int32_t {
        BTL_RULE_SINGLE = 0,
        BTL_RULE_DOUBLE = 1,
        BTL_RULE_RAID = 2,
        BTL_RULE_SAFARI = 3,
    };
}