#pragma once

#include "externals/DPData/GET_STATUS.h"
#include "externals/System/Primitives.h"

template <int32_t size>
struct DexSaveData {
    DPData::GET_STATUS get_status[size];
    System_Boolean male_color_flag[size];
    System_Boolean female_color_flag[size];
    System_Boolean male_flag[size];
    System_Boolean female_flag[size];
};
