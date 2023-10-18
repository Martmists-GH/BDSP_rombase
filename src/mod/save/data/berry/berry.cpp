#include "helpers/fsHelper.h"
#include "save/save.h"

static DPData::KinomiGrow::Array* cache_berries;

static DPData::KinomiGrow::Array* tmp_berries;

void loadBerries(bool isBackup)
{
    if (!isBackup && FsHelper::isFileExist(getCustomSaveData()->berries.fileName))
    {
        long size = std::max(FsHelper::getFileSize(getCustomSaveData()->berries.fileName), getCustomSaveData()->berries.GetByteCount());
        FsHelper::LoadData data {
            .path = getCustomSaveData()->berries.fileName,
            .alignment = 0x1000,
            .bufSize = size,
        };
        FsHelper::loadFileFromPath(data);
        getCustomSaveData()->berries.FromBytes((char*)data.buffer, data.bufSize, 0);
        Logger::log("Loaded Lumi_Berries!\n");
    }
    else if (FsHelper::isFileExist(getCustomSaveData()->berries.backupFileName))
    {
        long size = std::max(FsHelper::getFileSize(getCustomSaveData()->berries.backupFileName), getCustomSaveData()->berries.GetByteCount());
        FsHelper::LoadData data {
                .path = getCustomSaveData()->berries.backupFileName,
                .alignment = 0x1000,
                .bufSize = size,
        };
        FsHelper::loadFileFromPath(data);
        getCustomSaveData()->berries.FromBytes((char*)data.buffer, data.bufSize, 0);
        Logger::log("Loaded Lumi_Berries_BK!\n");
    }
}

void linkBerries(PlayerWork::Object* playerWork)
{
    auto kinomiGrowCls = DPData::KinomiGrow_array_TypeInfo();

    // Create new array
    auto newBerries = (DPData::KinomiGrow::Array*) system_array_new(kinomiGrowCls, BerryCount);

    // Fill the new array with the custom save data
    memcpy(newBerries->m_Items, getCustomSaveData()->berries.items, sizeof(getCustomSaveData()->berries.items));

    // Cache the data that is in the vanilla save
    auto& kinomigrow = playerWork->fields._saveData.fields.kinomiGrowSaveData.fields;
    cache_berries = kinomigrow.kinomiGrows;

    // Set the data in PlayerWork to our custom save data
    kinomigrow.kinomiGrows = newBerries;
}

void unlinkBerries(PlayerWork::Object* playerWork)
{
    auto& kinomigrow = playerWork->fields._saveData.fields.kinomiGrowSaveData.fields;

    // Copy PlayerWork data to our Custom save data
    memcpy(getCustomSaveData()->berries.items, kinomigrow.kinomiGrows->m_Items, sizeof(getCustomSaveData()->berries.items));

    // Create a temp copy of the PlayerWork data
    tmp_berries = kinomigrow.kinomiGrows;

    // Set PlayerWork to our cached data
    kinomigrow.kinomiGrows = cache_berries;
}

void saveBerries(bool isMain, bool isBackup)
{
    char buffer[getCustomSaveData()->berries.GetByteCount()];
    getCustomSaveData()->berries.ToBytes((char*)buffer, 0);

    if (isMain)
        FsHelper::writeFileToPath(buffer, sizeof(buffer), getCustomSaveData()->berries.fileName);
    if (isBackup)
        FsHelper::writeFileToPath(buffer, sizeof(buffer), getCustomSaveData()->berries.backupFileName);
}

void relinkBerries(PlayerWork::Object* playerWork)
{
    auto& kinomigrow = playerWork->fields._saveData.fields.kinomiGrowSaveData.fields;

    // Restore PlayerWork to our temp copy
    kinomigrow.kinomiGrows = tmp_berries;
}