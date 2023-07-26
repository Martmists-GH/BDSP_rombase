#pragma once

#include "externals/System/Primitives.h"

template <int32_t size>
struct BadgeSaveData {
    System::Byte items[size];
};
