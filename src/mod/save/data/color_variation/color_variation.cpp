#include "helpers/fsHelper.h"
#include "save/save.h"

void loadColorVariations(bool isBackup)
{
    if (!isBackup && FsHelper::isFileExist(getCustomSaveData()->playerColorVariation.fileName))
    {
        long actualSize = FsHelper::getFileSize(getCustomSaveData()->playerColorVariation.fileName);
        long expectedSize = getCustomSaveData()->playerColorVariation.GetByteCount();
        long size = std::max(actualSize, expectedSize);
        FsHelper::LoadData data {
            .path = getCustomSaveData()->playerColorVariation.fileName,
            .alignment = 0x1000,
            .bufSize = size,
        };
        FsHelper::loadFileFromPath(data);
        getCustomSaveData()->playerColorVariation.FromBytes((char*)data.buffer, actualSize, 0);
        Logger::log("Loaded Lumi_PlayerColorVariation!\n");
    }
    else if (FsHelper::isFileExist(getCustomSaveData()->playerColorVariation.backupFileName))
    {
        long actualSize = FsHelper::getFileSize(getCustomSaveData()->playerColorVariation.backupFileName);
        long expectedSize = getCustomSaveData()->playerColorVariation.GetByteCount();
        long size = std::max(actualSize, expectedSize);
        FsHelper::LoadData data {
            .path = getCustomSaveData()->playerColorVariation.backupFileName,
            .alignment = 0x1000,
            .bufSize = size,
        };
        FsHelper::loadFileFromPath(data);
        getCustomSaveData()->playerColorVariation.FromBytes((char*)data.buffer, actualSize, 0);
        Logger::log("Loaded Lumi_PlayerColorVariation_BK!\n");
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
    char buffer[getCustomSaveData()->playerColorVariation.GetByteCount()];
    getCustomSaveData()->playerColorVariation.ToBytes((char*)buffer, 0);

    if (isMain)
        FsHelper::writeFileToPath(buffer, sizeof(buffer), getCustomSaveData()->playerColorVariation.fileName);
    if (isBackup)
        FsHelper::writeFileToPath(buffer, sizeof(buffer), getCustomSaveData()->playerColorVariation.backupFileName);
}

void relinkColorVariations(PlayerWork::Object* playerWork)
{
    // Nothing to do
}