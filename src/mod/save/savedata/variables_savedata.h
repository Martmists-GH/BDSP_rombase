#pragma once

#include "externals/System/Primitives.h"

template <int32_t workSize, int32_t flagSize, int32_t sysFlagSize>
struct VariablesSaveData {
    System::Int32 works[workSize];
    System::Boolean flags[flagSize];
    System::Boolean sysflags[sysFlagSize];

    long GetByteCount() {
        return sizeof(VariablesSaveData<workSize, flagSize, sysFlagSize>);
    }

    long ToBytes(char* buffer, long index) {
        memcpy((void*)(buffer+index), &works, sizeof(System::Int32)*workSize);
        index += sizeof(System::Int32)*workSize;
        memcpy((void*)(buffer+index), &flags, sizeof(System::Boolean)*flagSize);
        index += sizeof(System::Boolean)*flagSize;
        memcpy((void*)(buffer+index), &sysflags, sizeof(System::Boolean)*sysFlagSize);
        index += sizeof(System::Boolean)*sysFlagSize;

        return index;
    }

    long FromBytes(char* buffer, long buffer_size, long index) {
        if (buffer_size >= GetByteCount() + index)
        {
            memcpy(&works, (void*)(buffer+index), sizeof(System::Int32)*workSize);
            index += sizeof(System::Int32)*workSize;
            memcpy(&flags, (void*)(buffer+index), sizeof(System::Boolean)*flagSize);
            index += sizeof(System::Boolean)*flagSize;
            memcpy(&sysflags, (void*)(buffer+index), sizeof(System::Boolean)*sysFlagSize);
            index += sizeof(System::Boolean)*sysFlagSize;

            return index;
        }

        return index + GetByteCount();
    }
};
