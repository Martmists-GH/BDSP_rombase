#pragma once

#include "externals/DPData/KinomiGrow.h"
#include "externals/PlayerWork.h"

template <int32_t size>
struct BerrySaveData {
    DPData::KinomiGrow::Object items[size];

    long GetByteCount() {
        return sizeof(BerrySaveData<size>);
    }

    long ToBytes(char* buffer, long index) {
        memcpy((void*)(buffer+index), &items, sizeof(DPData::KinomiGrow::Object)*size);
        index += sizeof(DPData::KinomiGrow::Object)*size;

        return index;
    }

    long FromBytes(char* buffer, long buffer_size, long index) {
        if (buffer_size >= GetByteCount() + index)
        {
            memcpy(&items, (void*)(buffer+index), sizeof(DPData::KinomiGrow::Object)*size);
            index += sizeof(DPData::KinomiGrow::Object)*size;

            return index;
        }

        return index + GetByteCount();
    }
};

void loadBerries(PlayerWork::Object* playerWork);
void saveBerries(PlayerWork::Object* playerWork);
void restoreBerries(PlayerWork::Object* playerWork);