#include "exlaunch.hpp"

#include "externals/Dpr/EvScript/EvDataManager.h"
#include "externals/PlayerWork.h"
#include "externals/FlagWork.h"
#include "helpers.h"
#include "memory/json.h"
#include "memory/string.h"
#include "romdata/data/LevelCap.h"

#include "logger/logger.h"

static RomData::LevelCapData levelCapData;
static bool isLevelCapDataLoaded = false;

const char* levelCapFolderPath = "rom:/Data/ExtraData/LevelCap/";

void LoadLevelCapData()
{
    nn::string levelCapFilePath(levelCapFolderPath);
    levelCapFilePath.append("level_caps.json");
    nn::json j = FsHelper::loadJsonFileFromPath(levelCapFilePath.c_str());
    if (j != nullptr && !j.is_discarded())
    {
        RomData::LevelCaps levelCaps = {};
        levelCaps = j.get<RomData::LevelCaps>();
        levelCapData.caps = levelCaps;
    }
    else
    {
        Logger::log("Error when parsing level_caps.json!\n");
        return;
    }

    nn::string worksFilePath(levelCapFolderPath);
    worksFilePath.append("works.json");
    j = FsHelper::loadJsonFileFromPath(worksFilePath.c_str());
    if (j != nullptr && !j.is_discarded())
    {
        RomData::LevelCapWorks works = {};
        works = j.get<RomData::LevelCapWorks>();
        levelCapData.works = works;
    }
    else
    {
        Logger::log("Error when parsing works.json!\n");
        return;
    }

    nn::string flagsFilePath(levelCapFolderPath);
    flagsFilePath.append("flags.json");
    j = FsHelper::loadJsonFileFromPath(flagsFilePath.c_str());
    if (j != nullptr && !j.is_discarded())
    {
        RomData::LevelCapFlags flags = {};
        flags = j.get<RomData::LevelCapFlags>();
        levelCapData.flags = flags;
    }
    else
    {
        Logger::log("Error when parsing flags.json!\n");
        return;
    }

    nn::string sysFlagsFilePath(levelCapFolderPath);
    sysFlagsFilePath.append("sys_flags.json");
    j = FsHelper::loadJsonFileFromPath(sysFlagsFilePath.c_str());
    if (j != nullptr && !j.is_discarded())
    {
        RomData::LevelCapSysFlags sysFlags = {};
        sysFlags = j.get<RomData::LevelCapSysFlags>();
        levelCapData.sysFlags = sysFlags;
    }
    else
    {
        Logger::log("Error when parsing sys_flags.json!\n");
        return;
    }

    isLevelCapDataLoaded = true;
}

RomData::LevelCapData GetLevelCapData()
{
    if (!isLevelCapDataLoaded)
        LoadLevelCapData();

    return levelCapData;
}

uint32_t GetLevelCapLevel(uint32_t index)
{
    RomData::LevelCapData data = GetLevelCapData();

    if (index < data.caps.caps.size())
    {
        return data.caps.caps[index];
    }

    return data.caps.defaultLevel;
}

uint32_t GetLevelCapIndex()
{
    RomData::LevelCapData data = GetLevelCapData();

    Dpr::EvScript::EvDataManager::Object* evDataManager = Dpr::EvScript::EvDataManager::get_Instanse();
    int32_t numEvents = evDataManager->GetBadgeCount();

    for (RomData::LevelCapWork w : data.works.works)
    {
        int32_t actualValue = PlayerWork::GetInt(w.work);

        if (w.comparison == "EQ" && actualValue == w.value)         numEvents += 1;
        else if (w.comparison == "NE" && actualValue != w.value)    numEvents += 1;
        else if (w.comparison == "GT" && actualValue > w.value)     numEvents += 1;
        else if (w.comparison == "GE" && actualValue >= w.value)    numEvents += 1;
        else if (w.comparison == "LT" && actualValue < w.value)     numEvents += 1;
        else if (w.comparison == "LE" && actualValue <= w.value)    numEvents += 1;
    }

    for (int32_t f : data.flags.flags)
    {
        if (PlayerWork::GetBool(f)) numEvents += 1;
    }

    for (int32_t s : data.sysFlags.sysFlags)
    {
        if (PlayerWork::GetSystemFlag(s)) numEvents += 1;
    }

    return numEvents;
}

uint32_t GetMaxLevel()
{
    uint32_t index = GetLevelCapIndex();
    return GetLevelCapLevel(index);
}

uint32_t GetLevelCapIndexOfLevel(uint32_t level)
{
    RomData::LevelCapData data = GetLevelCapData();

    uint32_t i = 0;
    uint32_t levelOfCap = 0;
    do
    {
        levelOfCap = GetLevelCapLevel(i);
        if (level <= levelOfCap)
        {
            return i;
        }
        i++;
    }
    while (levelOfCap < data.caps.defaultLevel);

    return 0;
}
