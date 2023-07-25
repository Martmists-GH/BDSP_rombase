#pragma once

#include "externals/DPData/TR_BATTLE_DATA.h"

template <int32_t size>
struct TrainerSaveData {
    DPData::TR_BATTLE_DATA::Object trainers[size];
};
