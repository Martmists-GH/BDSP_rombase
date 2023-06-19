#pragma once

#include "externals/PlayerWork.h"
#include "externals/FlagWork_Enums.h"
#include "utils/get_badges.cpp"
#include "romdata/romdata.h"

uint32_t GetLevelCapIndex()
{
    constexpr size_t NUM_FLAGS = 1;
    constexpr size_t NUM_SYS_FLAGS = 1;
    constexpr size_t NUM_WORK_VALUES = 2;
    uint32_t numEvents = GetBadgeCount();

    uint32_t flags[NUM_FLAGS] = {
        FLAG_CYRUS_SPEAR_PILLAR // Beating Cyrus at spear pillar
    };

    uint32_t sysflags[NUM_SYS_FLAGS] = {
        SYS_FLAG_GAME_CLEAR
    };

    uint32_t works[NUM_WORK_VALUES] = {
        WK_SCENE_R205A, // Beating Mars at Valley Windworks
        WK_SCENE_C02 // Beating Barry at Canalave
    };

    uint32_t workMins[NUM_WORK_VALUES] = {
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