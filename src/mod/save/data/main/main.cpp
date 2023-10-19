#include "helpers/fsHelper.h"
#include "save/save.h"

void loadMain(bool isBackup)
{
    if (!isBackup && FsHelper::isFileExist(getCustomSaveData()->main.fileName))
    {
        long actualSize = FsHelper::getFileSize(getCustomSaveData()->main.fileName);
        long expectedSize = getCustomSaveData()->main.GetByteCount();
        long size = std::max(actualSize, expectedSize);
        FsHelper::LoadData data {
            .path = getCustomSaveData()->main.fileName,
            .alignment = 0x1000,
            .bufSize = size,
        };
        FsHelper::loadFileFromPath(data);
        getCustomSaveData()->main.FromBytes((char*)data.buffer, actualSize, 0);
        Logger::log("Loaded Lumi_Main!\n");
    }
    else if (FsHelper::isFileExist(getCustomSaveData()->main.backupFileName))
    {
        long actualSize = FsHelper::getFileSize(getCustomSaveData()->main.backupFileName);
        long expectedSize = getCustomSaveData()->main.GetByteCount();
        long size = std::max(actualSize, expectedSize);
        FsHelper::LoadData data {
            .path = getCustomSaveData()->main.backupFileName,
            .alignment = 0x1000,
            .bufSize = size,
        };
        FsHelper::loadFileFromPath(data);
        getCustomSaveData()->main.FromBytes((char*)data.buffer, actualSize, 0);
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
