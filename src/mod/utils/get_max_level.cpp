#include "externals/PlayerWork.h"
#include "externals/FlagWork.h"
#include "romdata/romdata.h"
#include "utils/utils.h"

uint32_t GetLevelCapIndex()
{
    constexpr size_t NUM_FLAGS = 1;
    constexpr size_t NUM_SYS_FLAGS = 1;
    constexpr size_t NUM_WORK_VALUES = 2;
    uint32_t numEvents = GetBadgeCount();

    int32_t flags[NUM_FLAGS] = {
        (int32_t)FlagWork_Flag::FLAG_CYRUS_SPEAR_PILLAR // Beating Cyrus at spear pillar
    };

    int32_t sysflags[NUM_SYS_FLAGS] = {
        (int32_t)FlagWork_SysFlag::SYS_FLAG_GAME_CLEAR
    };

    int32_t works[NUM_WORK_VALUES] = {
        (int32_t)FlagWork_Work::WK_SCENE_R205A, // Beating Mars at Valley Windworks
        (int32_t)FlagWork_Work::WK_SCENE_C02 // Beating Barry at Canalave
    };

    int32_t workMins[NUM_WORK_VALUES] = {
        2, // WK_SCENE_R205A, Beating Mars at Valley Windworks
        1 // WK_SCENE_C02, Beating Barry at Canalave
    };

    for (size_t i = 0; i < NUM_FLAGS; i++)
    {
        if (PlayerWork::GetBool(flags[i]))
        {
            numEvents += 1;
        }
    }

    for (size_t i = 0; i < NUM_SYS_FLAGS; i++)
    {
        if (PlayerWork::GetSystemFlag(sysflags[i]))
        {
            numEvents += 1;
        }
    }

    for (size_t i = 0; i < NUM_WORK_VALUES; i++)
    {
        if (PlayerWork::GetInt(works[i]) >= workMins[i])
        {
            numEvents += 1;
        }
    }

    return numEvents;
}

uint32_t GetMaxLevel()
{
    uint32_t index = GetLevelCapIndex();
    return GetLevelCapData(index);
}

uint32_t GetLevelCapIndexOfLevel(uint32_t level)
{
    uint32_t i = 0;
    uint32_t levelOfCap = 0;
    do
    {
        levelOfCap = GetLevelCapData(i);
        if (level <= levelOfCap)
        {
            return i;
        }
        i++;
    }
    while (levelOfCap < 100);

    return 0;
}
