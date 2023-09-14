#pragma once

#include "externals/il2cpp-api.h"

namespace Pml::Personal {
    enum class SexVector : int32_t {
        ONLY_MALE = 0,
        RANDOM_MIN = 1,
        RANDOM_FEMALE_MIN = 1,
        RANDOM_MAX = 253,
        RANDOM_MALE_MAX = 253,
        ONLY_FEMALE = 254,
        UNKNOWN = 255,
    };
}