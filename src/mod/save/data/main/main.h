#pragma once

#include "externals/PlayerWork.h"

enum class ModVersion : int32_t {
    // Base game
    Vanilla,

    // Mod releases (in order!)
    Release_3_0,

    // Development version, always after the latest release
    Dev,
};

struct MainSaveData {
    const char* fileName = "SaveData:/Lumi_Main.bin";
    const char* backupFileName = "SaveData:/Lumi_Main_BK.bin";

    ModVersion version;

    long GetByteCount() {
        return sizeof(ModVersion);
    }

    long ToBytes(char* buffer, long index) {
        *(ModVersion*)(buffer+index) = version;
        index += sizeof(ModVersion);

        return index;
    }

    long FromBytes(char* buffer, long buffer_size, long index) {
        if (buffer_size >= GetByteCount() + index)
        {
            memcpy(&version, (void*)(buffer+index), sizeof(ModVersion));
            index += sizeof(ModVersion);

            return index;
        }

        return index + GetByteCount();
    }
};

void loadMain(bool isBackup);
void saveMain(bool isMain, bool isBackup);