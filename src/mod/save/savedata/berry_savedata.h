#pragma once

#include "externals/DPData/KinomiGrow.h"

template <int32_t size>
struct BerrySaveData {
    DPData::KinomiGrow::Object items[size];
};
