#pragma once

#include "externals/Dpr/Item/SaveItem.h"

template <int32_t size>
struct ItemSaveData {
    Dpr::Item::SaveItem::Object items[size];
};
