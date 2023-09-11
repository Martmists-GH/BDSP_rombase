#pragma once

#include "externals/il2cpp-api.h"

namespace Pml::PokePara {
    enum class EggCheckType : int32_t {
        ONLY_LEGAL_EGG = 0,
        ONLY_ILLEGAL_EGG = 1,
        BOTH_EGG = 2,
    };
}