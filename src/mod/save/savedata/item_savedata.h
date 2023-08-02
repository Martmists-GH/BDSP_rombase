#pragma once

#include "externals/Dpr/Item/SaveItem.h"

template <int32_t size>
struct ItemSaveData {
    Dpr::Item::SaveItem::Object items[size];

    long GetByteCount() {
        return sizeof(ItemSaveData<size>);
    }

    long ToBytes(char* buffer, long index) {
        memcpy((void*)(buffer+index), &items, sizeof(Dpr::Item::SaveItem::Object)*size);
        index += sizeof(Dpr::Item::SaveItem::Object)*size;

        return index;
    }

    long FromBytes(char* buffer, long buffer_size, long index) {
        if (buffer_size >= GetByteCount() + index)
        {
            memcpy(&items, (void*)(buffer+index), sizeof(Dpr::Item::SaveItem::Object)*size);
            index += sizeof(Dpr::Item::SaveItem::Object)*size;

            return index;
        }

        return index + GetByteCount();
    }
};
