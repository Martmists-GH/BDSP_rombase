#pragma once

#include "externals/DPData/GET_STATUS.h"
#include "externals/PlayerWork.h"
#include "externals/System/Primitives.h"

template <int32_t size>
struct DexSaveData {
    DPData::GET_STATUS get_status[size];
    System::Boolean male_color_flag[size];
    System::Boolean female_color_flag[size];
    System::Boolean male_flag[size];
    System::Boolean female_flag[size];

    long GetByteCount() {
        return sizeof(DexSaveData<size>);
    }

    long ToBytes(char* buffer, long index) {
        memcpy((void*)(buffer+index), &get_status, sizeof(DPData::GET_STATUS)*size);
        index += sizeof(DPData::GET_STATUS)*size;
        memcpy((void*)(buffer+index), &male_color_flag, sizeof(System::Boolean)*size);
        index += sizeof(System::Boolean)*size;
        memcpy((void*)(buffer+index), &female_color_flag, sizeof(System::Boolean)*size);
        index += sizeof(System::Boolean)*size;
        memcpy((void*)(buffer+index), &male_flag, sizeof(System::Boolean)*size);
        index += sizeof(System::Boolean)*size;
        memcpy((void*)(buffer+index), &female_flag, sizeof(System::Boolean)*size);
        index += sizeof(System::Boolean)*size;

        return index;
    }

    long FromBytes(char* buffer, long buffer_size, long index) {
        if (buffer_size >= GetByteCount() + index)
        {
            memcpy(&get_status, (void*)(buffer+index), sizeof(DPData::GET_STATUS)*size);
            index += sizeof(DPData::GET_STATUS)*size;
            memcpy(&male_color_flag, (void*)(buffer+index), sizeof(System::Boolean)*size);
            index += sizeof(System::Boolean)*size;
            memcpy(&female_color_flag, (void*)(buffer+index), sizeof(System::Boolean)*size);
            index += sizeof(System::Boolean)*size;
            memcpy(&male_flag, (void*)(buffer+index), sizeof(System::Boolean)*size);
            index += sizeof(System::Boolean)*size;
            memcpy(&female_flag, (void*)(buffer+index), sizeof(System::Boolean)*size);
            index += sizeof(System::Boolean)*size;

            return index;
        }

        return index + GetByteCount();
    }
};

void loadZukan(PlayerWork::Object* playerWork);
void saveZukan(PlayerWork::Object* playerWork);
void restoreZukan(PlayerWork::Object* playerWork);