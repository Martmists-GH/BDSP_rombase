#pragma once

#include "externals/il2cpp-api.h"

namespace Dpr::Battle::Logic {
    enum class BtlCompetitor : int32_t {
        BTL_COMPETITOR_WILD = 0,
        BTL_COMPETITOR_TRAINER = 1,
        BTL_COMPETITOR_INST = 2,
        BTL_COMPETITOR_COMM = 3,
        BTL_COMPETITOR_DEMO_CAPTURE = 4,
        BTL_COMPETITOR_MAX = 5,
    };
}