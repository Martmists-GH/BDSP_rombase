#pragma once

#include "externals/DPData/KinomiGrow.h"
#include "externals/PlayerWork.h"

#include "logger/logger.h"

template <int32_t size>
struct BerrySaveData {
    const char* fileName = "SaveData:/Lumi_Berries.bin";
    const char* backupFileName = "SaveData:/Lumi_Berries_BK.bin";

    DPData::KinomiGrow::Object items[size];

    long GetByteCount() {
        return sizeof(DPData::KinomiGrow::Object) * size;
    }

    long ToBytes(char* buffer, long index) {
        memcpy((void*)(buffer+index), &items, sizeof(DPData::KinomiGrow::Object)*size);
        index += sizeof(DPData::KinomiGrow::Object)*size;

        return index;
    }

    long FromBytes(char* buffer, long buffer_size, long index) {
        for (int32_t i=0; i<size; i++)
        {
            if (buffer_size < index + (long)sizeof(DPData::KinomiGrow::Object))
                break;

            memcpy(&items[i], (void*)(buffer+index), sizeof(DPData::KinomiGrow::Object));
            index += sizeof(DPData::KinomiGrow::Object);
        }

        return index + GetByteCount();
    }
};

void loadBerries(bool isBackup);
void linkBerries(PlayerWork::Object* playerWork);
void unlinkBerries(PlayerWork::Object* playerWork);
void saveBerries(bool isMain, bool isBackup);
void relinkBerries(PlayerWork::Object* playerWork);