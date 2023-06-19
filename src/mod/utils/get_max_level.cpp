#pragma once

#include "externals/PlayerWork.h"
#include "utils/get_badges.cpp"

uint32_t GetMaxLevel() {
    constexpr size_t NUM_FLAGS = 2;
    uint32_t maxLevel = 100;
    uint32_t numEvents = GetBadgeCount();

    uint32_t flags[NUM_FLAGS] = {
        2770, // Beating Cyrus at spear pillar
        2538, // Beating Stark Mountain
    };

    for (size_t i = 0; i < NUM_FLAGS; i++)
    {
        if (PlayerWork::GetBool(flags[i]))
        {
            numEvents += 1;
        }
    }


    switch (numEvents)
    {
        case 0: // Roark
            maxLevel = 16;
            break;
        case 1: // Gardenia
            maxLevel = 26;
            break;
        case 2: // Fantina
            maxLevel = 33;
            break;
        case 3: // Maylene
            maxLevel = 39;
            break;
        case 4: // Crasher Wake
            maxLevel = 44;
            break;
        case 5: // Byron
            maxLevel = 53;
            break;
        case 6: // Candice
            maxLevel = 56;
            break;
        case 7: // Spear Pillar
            maxLevel = 60;
        case 8: // Volkner
            maxLevel = 62;
            break;
        case 9: // Cynthia
            // Should add a check for if game beaten
            // to remove level 78 cap. For the moment, they can just disable
            // the cap if you want to overlevel in post game.
            maxLevel = 78;
        case 10:
            maxLevel = 85;
        default:
            break;
    }

    return maxLevel;
}