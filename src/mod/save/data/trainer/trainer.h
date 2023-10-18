#pragma once

#include "externals/DPData/TR_BATTLE_DATA.h"
#include "externals/PlayerWork.h"

template <int32_t size>
struct TrainerSaveData {
    const char* fileName = "SaveData:/Lumi_Trainers.bin";
    const char* backupFileName = "SaveData:/Lumi_Trainers_BK.bin";

    DPData::TR_BATTLE_DATA::Object items[size];

    long GetByteCount() {
        return sizeof(TrainerSaveData<size>);
    }

    long ToBytes(char* buffer, long index) {
        memcpy((void*)(buffer+index), &items, sizeof(DPData::TR_BATTLE_DATA::Object)*size);
        index += sizeof(DPData::TR_BATTLE_DATA::Object)*size;

        return index;
    }

    long FromBytes(char* buffer, long buffer_size, long index) {
        if (buffer_size >= GetByteCount() + index)
        {
            memcpy(&items, (void*)(buffer+index), sizeof(DPData::TR_BATTLE_DATA::Object)*size);
            index += sizeof(DPData::TR_BATTLE_DATA::Object)*size;

            return index;
        }

        return index + GetByteCount();
    }
};

void loadTrainers(bool isBackup);
void linkTrainers(PlayerWork::Object* playerWork);
void unlinkTrainers(PlayerWork::Object* playerWork);
void saveTrainers(bool isMain, bool isBackup);
void relinkTrainers(PlayerWork::Object* playerWork);