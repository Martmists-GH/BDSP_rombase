#include "helpers/fsHelper.h"
#include "save/save.h"

void loadMain(bool isBackup)
{
    if (!isBackup && FsHelper::isFileExist(getCustomSaveData()->main.fileName))
    {
        long size = std::max(FsHelper::getFileSize(getCustomSaveData()->main.fileName), getCustomSaveData()->main.GetByteCount());
        FsHelper::LoadData data {
            .path = getCustomSaveData()->main.fileName,
            .alignment = 0x1000,
            .bufSize = size,
        };
        FsHelper::loadFileFromPath(data);
        getCustomSaveData()->main.FromBytes((char*)data.buffer, data.bufSize, 0);
        Logger::log("Loaded Lumi_Main!\n");
    }
    else if (FsHelper::isFileExist(getCustomSaveData()->main.backupFileName))
    {
        long size = std::max(FsHelper::getFileSize(getCustomSaveData()->main.backupFileName), getCustomSaveData()->main.GetByteCount());
        FsHelper::LoadData data {
            .path = getCustomSaveData()->main.backupFileName,
            .alignment = 0x1000,
            .bufSize = size,
        };
        FsHelper::loadFileFromPath(data);
        getCustomSaveData()->main.FromBytes((char*)data.buffer, data.bufSize, 0);
        Logger::log("Loaded Lumi_Main_BK!\n");
    }
}

void saveMain(bool isMain, bool isBackup)
{
    char buffer[getCustomSaveData()->main.GetByteCount()];
    getCustomSaveData()->main.ToBytes((char*)buffer, 0);

    if (isMain)
        FsHelper::writeFileToPath(buffer, sizeof(buffer), getCustomSaveData()->main.fileName);
    if (isBackup)
        FsHelper::writeFileToPath(buffer, sizeof(buffer), getCustomSaveData()->main.backupFileName);
}
