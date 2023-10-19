#pragma once

#include "externals/System/Primitives.h"

#include "logger/logger.h"

template <int32_t workSize, int32_t flagSize, int32_t sysFlagSize>
struct VariablesSaveData {
    const char* fileName = "SaveData:/Lumi_Variables.bin";
    const char* backupFileName = "SaveData:/Lumi_Variables_BK.bin";

    System::Int32 works[workSize];
    System::Boolean flags[flagSize];
    System::Boolean sysflags[sysFlagSize];

    long GetByteCount() {
        long count = 0;
        count += sizeof(System::Int32) * workSize;
        count += sizeof(System::Boolean) * flagSize;
        count += sizeof(System::Boolean) * sysFlagSize;
        return count;
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
        Logger::log("size:%d index:%d\n", buffer_size, index);
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

void loadVariables(bool isBackup);
void linkVariables(PlayerWork::Object* playerWork);
void unlinkVariables(PlayerWork::Object* playerWork);
void saveVariables(bool isMain, bool isBackup);
void relinkVariables(PlayerWork::Object* playerWork);