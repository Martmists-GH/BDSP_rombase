#include "externals/PlayerWork.h"

uint32_t GetLevelCapData(uint32_t index)
{
    switch (index)
    {
        case 0: // Roark
            return 16;
        case 1: // Valley Windworks
            return 19;
        case 2: // Gardenia
            return 26;
        case 3: // Fantina
            return 33;
        case 4: // Maylene
            return 39;
        case 5: // Crasher Wake
            return 44;
        case 6: // Canalave Barry
            return 49;
        case 7: // Byron
            return 53;
        case 8: // Candice
            return 56;
        case 9: // Spear Pillar
            return 60;
        case 10: // Volkner
            return 62;
        case 11: // Cynthia
            return 78;
        case 12: // Stark Mountain
            return 85;
        default: // Max
            return 100;
    }
}