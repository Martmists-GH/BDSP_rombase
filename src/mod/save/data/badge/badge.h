#pragma once

#include "externals/PlayerWork.h"
#include "externals/System/Primitives.h"

template <int32_t size>
struct BadgeSaveData {
    System::Byte items[size];

    long GetByteCount() {
        return sizeof(BadgeSaveData<size>);
    }

    long FromBytes(char* buffer, long buffer_size, long index) {
        if (buffer_size >= GetByteCount() + index)
        {
            memcpy(&items, (void*)(buffer+index), sizeof(System::Byte)*size);
            index += sizeof(System::Byte)*size;

            return index;
        }

        return index + GetByteCount();
    }
};

void loadBadges(PlayerWork::Object* playerWork);
void saveBadges(PlayerWork::Object* playerWork);
void restoreBadges(PlayerWork::Object* playerWork);