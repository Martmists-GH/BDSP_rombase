#pragma once

#include "externals/Dpr/Item/SaveItem.h"
#include "externals/PlayerWork.h"

#include "logger/logger.h"

template <int32_t size>
struct ItemSaveData {
    const char* fileName = "SaveData:/Lumi_Items.bin";
    const char* backupFileName = "SaveData:/Lumi_Items_BK.bin";

    Dpr::Item::SaveItem::Object items[size];

    long GetByteCount() {
        return sizeof(Dpr::Item::SaveItem::Object) * size;
    }

    long ToBytes(char* buffer, long index) {
        memcpy((void*)(buffer+index), &items, sizeof(Dpr::Item::SaveItem::Object)*size);
        index += sizeof(Dpr::Item::SaveItem::Object)*size;

        return index;
    }

    long FromBytes(char* buffer, long buffer_size, long index) {
        Logger::log("size:%d index:%d\n", buffer_size, index);
        if (buffer_size >= GetByteCount() + index)
        {
            memcpy(&items, (void*)(buffer+index), sizeof(Dpr::Item::SaveItem::Object)*size);
            index += sizeof(Dpr::Item::SaveItem::Object)*size;

            return index;
        }

        return index + GetByteCount();
    }
};

void loadItems(bool isBackup);
void linkItems(PlayerWork::Object* playerWork);
void unlinkItems(PlayerWork::Object* playerWork);
void saveItems(bool isMain, bool isBackup);
void relinkItems(PlayerWork::Object* playerWork);