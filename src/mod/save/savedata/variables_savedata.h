#pragma once

#include "externals/System/Primitives.h"

template <int32_t workSize, int32_t flagSize, int32_t sysFlagSize>
struct VariablesSaveData {
    System::Int32 works[workSize];
    System::Boolean flags[flagSize];
    System::Boolean sysflags[sysFlagSize];
};
