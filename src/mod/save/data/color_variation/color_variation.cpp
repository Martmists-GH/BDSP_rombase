#include "helpers/fsHelper.h"
#include "save/save.h"

void loadColorVariations(bool isBackup)
{
    if (!isBackup && FsHelper::isFileExist(getCustomSaveData()->colorVariations.fileName))
    {
        long size = std::max(FsHelper::getFileSize(getCustomSaveData()->colorVariations.fileName), getCustomSaveData()->colorVariations.GetByteCount());
        FsHelper::LoadData data {
            .path = getCustomSaveData()->colorVariations.fileName,
            .alignment = 0x1000,
            .bufSize = size,
        };
        FsHelper::loadFileFromPath(data);
        getCustomSaveData()->colorVariations.FromBytes((char*)data.buffer, data.bufSize, 0);
        Logger::log("Loaded Lumi_ColorVariations!\n");
    }
    else if (FsHelper::isFileExist(getCustomSaveData()->colorVariations.backupFileName))
    {
        long size = std::max(FsHelper::getFileSize(getCustomSaveData()->colorVariations.backupFileName), getCustomSaveData()->colorVariations.GetByteCount());
        FsHelper::LoadData data {
            .path = getCustomSaveData()->colorVariations.backupFileName,
            .alignment = 0x1000,
            .bufSize = size,
        };
        FsHelper::loadFileFromPath(data);
        getCustomSaveData()->colorVariations.FromBytes((char*)data.buffer, data.bufSize, 0);
        Logger::log("Loaded Lumi_ColorVariations_BK!\n");
    }
}

void linkColorVariations(PlayerWork::Object* playerWork)
{
    // Nothing to do
}

void unlinkColorVariations(PlayerWork::Object* playerWork)
{
    // Nothing to do
}

void saveColorVariations(bool isMain, bool isBackup)
{
    char buffer[getCustomSaveData()->colorVariations.GetByteCount()];
    getCustomSaveData()->colorVariations.ToBytes((char*)buffer, 0);

    if (isMain)
        FsHelper::writeFileToPath(buffer, sizeof(buffer), getCustomSaveData()->colorVariations.fileName);
    if (isBackup)
        FsHelper::writeFileToPath(buffer, sizeof(buffer), getCustomSaveData()->colorVariations.backupFileName);
}

void relinkColorVariations(PlayerWork::Object* playerWork)
{
    // Nothing to do
}