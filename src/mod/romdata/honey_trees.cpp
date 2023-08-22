#include "exlaunch.hpp"

#include "data/species.h"
#include "data/utils.h"
#include "data/zones.h"

#include "logger/logger.h"

int32_t GetHoneyTreeMonsNo(int32_t zoneID, int32_t slot)
{
    // Modulo the slot just to be sure
    slot = slot % 10;

    if (zoneID == array_index(ZONES, "Valley Windworks (Outside)"))
    {
        return (int32_t[]){
                array_index(SPECIES, "Aipom"),
                array_index(SPECIES, "Aipom"),
                array_index(SPECIES, "Aipom"),
                array_index(SPECIES, "Slakoth"),
                array_index(SPECIES, "Slakoth"),
                array_index(SPECIES, "Caterpie"),
                array_index(SPECIES, "Caterpie"),
                array_index(SPECIES, "Weedle"),
                array_index(SPECIES, "Weedle"),
                array_index(SPECIES, "Munchlax"),
        }[slot];
    }
    else if (zoneID == array_index(ZONES, "Eterna Forest (Outside)"))
    {
        return (int32_t[]){
                array_index(SPECIES, "Beedrill"),
                array_index(SPECIES, "Beedrill"),
                array_index(SPECIES, "Beedrill"),
                array_index(SPECIES, "Beedrill"),
                array_index(SPECIES, "Beedrill"),
                array_index(SPECIES, "Beedrill"),
                array_index(SPECIES, "Beedrill"),
                array_index(SPECIES, "Beedrill"),
                array_index(SPECIES, "Beedrill"),
                array_index(SPECIES, "Beedrill"),
        }[slot];
    }
    else if (zoneID == array_index(ZONES, "Fuego Ironworks (Outside)"))
    {
        return (int32_t[]){
                array_index(SPECIES, "Combee"),
                array_index(SPECIES, "Combee"),
                array_index(SPECIES, "Combee"),
                array_index(SPECIES, "Forretress"),
                array_index(SPECIES, "Wormadam"),
                array_index(SPECIES, "Mothim"),
                array_index(SPECIES, "Beautifly"),
                array_index(SPECIES, "Dustox"),
                array_index(SPECIES, "Heracross"),
                array_index(SPECIES, "Vespiquen"),
        }[slot];
    }
    else if (zoneID == array_index(ZONES, "Floaroma Meadow"))
    {
        return (int32_t[]){
                array_index(SPECIES, "Cherubi"),
                array_index(SPECIES, "Cherubi"),
                array_index(SPECIES, "Cherubi"),
                array_index(SPECIES, "Shroomish"),
                array_index(SPECIES, "Shroomish"),
                array_index(SPECIES, "Exeggcute"),
                array_index(SPECIES, "Exeggcute"),
                array_index(SPECIES, "Seedot"),
                array_index(SPECIES, "Seedot"),
                array_index(SPECIES, "Tangela"),
        }[slot];
    }
    else if (zoneID == array_index(ZONES, "Route 205 (South)"))
    {
        return (int32_t[]){
                array_index(SPECIES, "Combee"),
                array_index(SPECIES, "Combee"),
                array_index(SPECIES, "Combee"),
                array_index(SPECIES, "Burmy"),
                array_index(SPECIES, "Burmy"),
                array_index(SPECIES, "Pineco"),
                array_index(SPECIES, "Pineco"),
                array_index(SPECIES, "Wurmple"),
                array_index(SPECIES, "Wurmple"),
                array_index(SPECIES, "Heracross"),
        }[slot];
    }
    else if (zoneID == array_index(ZONES, "Route 205 (North)"))
    {
        return (int32_t[]){
                array_index(SPECIES, "Starly"),
                array_index(SPECIES, "Starly"),
                array_index(SPECIES, "Starly"),
                array_index(SPECIES, "Pidgey"),
                array_index(SPECIES, "Pidgey"),
                array_index(SPECIES, "Hoothoot"),
                array_index(SPECIES, "Hoothoot"),
                array_index(SPECIES, "Taillow"),
                array_index(SPECIES, "Taillow"),
                array_index(SPECIES, "Farfetch'd"),
        }[slot];
    }
    else if (zoneID == array_index(ZONES, "Route 206"))
    {
        return (int32_t[]){
                array_index(SPECIES, "Combee"),
                array_index(SPECIES, "Combee"),
                array_index(SPECIES, "Combee"),
                array_index(SPECIES, "Burmy"),
                array_index(SPECIES, "Burmy"),
                array_index(SPECIES, "Pineco"),
                array_index(SPECIES, "Pineco"),
                array_index(SPECIES, "Silcoon"),
                array_index(SPECIES, "Cascoon"),
                array_index(SPECIES, "Heracross"),
        }[slot];
    }
    else if (zoneID == array_index(ZONES, "Route 207"))
    {
        return (int32_t[]){
                array_index(SPECIES, "Aipom"),
                array_index(SPECIES, "Aipom"),
                array_index(SPECIES, "Aipom"),
                array_index(SPECIES, "Slakoth"),
                array_index(SPECIES, "Slakoth"),
                array_index(SPECIES, "Metapod"),
                array_index(SPECIES, "Metapod"),
                array_index(SPECIES, "Kakuna"),
                array_index(SPECIES, "Kakuna"),
                array_index(SPECIES, "Munchlax"),
        }[slot];
    }
    else if (zoneID == array_index(ZONES, "Route 208"))
    {
        return (int32_t[]){
                array_index(SPECIES, "Cherubi"),
                array_index(SPECIES, "Cherubi"),
                array_index(SPECIES, "Cherubi"),
                array_index(SPECIES, "Shroomish"),
                array_index(SPECIES, "Shroomish"),
                array_index(SPECIES, "Exeggcute"),
                array_index(SPECIES, "Exeggcute"),
                array_index(SPECIES, "Seedot"),
                array_index(SPECIES, "Seedot"),
                array_index(SPECIES, "Tangela"),
        }[slot];
    }
    else if (zoneID == array_index(ZONES, "Route 209"))
    {
        return (int32_t[]){
                array_index(SPECIES, "Staravia"),
                array_index(SPECIES, "Staravia"),
                array_index(SPECIES, "Staravia"),
                array_index(SPECIES, "Pidgeotto"),
                array_index(SPECIES, "Pidgeotto"),
                array_index(SPECIES, "Noctowl"),
                array_index(SPECIES, "Noctowl"),
                array_index(SPECIES, "Swellow"),
                array_index(SPECIES, "Swellow"),
                array_index(SPECIES, "Farfetch'd"),
        }[slot];
    }
    else if (zoneID == array_index(ZONES, "Route 210 (South)"))
    {
        return (int32_t[]){
                array_index(SPECIES, "Combee"),
                array_index(SPECIES, "Combee"),
                array_index(SPECIES, "Combee"),
                array_index(SPECIES, "Pineco"),
                array_index(SPECIES, "Pineco"),
                array_index(SPECIES, "Silcoon"),
                array_index(SPECIES, "Cascoon"),
                array_index(SPECIES, "Wormadam"),
                array_index(SPECIES, "Mothim"),
                array_index(SPECIES, "Heracross"),
        }[slot];
    }
    else if (zoneID == array_index(ZONES, "Route 210 (North)"))
    {
        return (int32_t[]){
                array_index(SPECIES, "Staravia"),
                array_index(SPECIES, "Staravia"),
                array_index(SPECIES, "Staravia"),
                array_index(SPECIES, "Pidgeotto"),
                array_index(SPECIES, "Pidgeotto"),
                array_index(SPECIES, "Noctowl"),
                array_index(SPECIES, "Noctowl"),
                array_index(SPECIES, "Swellow"),
                array_index(SPECIES, "Swellow"),
                array_index(SPECIES, "Farfetch'd"),
        }[slot];
    }
    else if (zoneID == array_index(ZONES, "Route 211 (East)"))
    {
        return (int32_t[]){
                array_index(SPECIES, "Aipom"),
                array_index(SPECIES, "Aipom"),
                array_index(SPECIES, "Aipom"),
                array_index(SPECIES, "Slakoth"),
                array_index(SPECIES, "Slakoth"),
                array_index(SPECIES, "Metapod"),
                array_index(SPECIES, "Metapod"),
                array_index(SPECIES, "Kakuna"),
                array_index(SPECIES, "Kakuna"),
                array_index(SPECIES, "Munchlax"),
        }[slot];
    }
    else if (zoneID == array_index(ZONES, "Route 212 (North)"))
    {
        return (int32_t[]){
                array_index(SPECIES, "Cherubi"),
                array_index(SPECIES, "Cherubi"),
                array_index(SPECIES, "Cherubi"),
                array_index(SPECIES, "Shroomish"),
                array_index(SPECIES, "Shroomish"),
                array_index(SPECIES, "Exeggcute"),
                array_index(SPECIES, "Exeggcute"),
                array_index(SPECIES, "Nuzleaf"),
                array_index(SPECIES, "Nuzleaf"),
                array_index(SPECIES, "Tangela"),
        }[slot];
    }
    else if (zoneID == array_index(ZONES, "Route 212 (South)"))
    {
        return (int32_t[]){
                array_index(SPECIES, "Cherrim"),
                array_index(SPECIES, "Cherrim"),
                array_index(SPECIES, "Cherrim"),
                array_index(SPECIES, "Shroomish"),
                array_index(SPECIES, "Shroomish"),
                array_index(SPECIES, "Exeggcute"),
                array_index(SPECIES, "Exeggcute"),
                array_index(SPECIES, "Nuzleaf"),
                array_index(SPECIES, "Nuzleaf"),
                array_index(SPECIES, "Tangela"),
        }[slot];
    }
    else if (zoneID == array_index(ZONES, "Route 213"))
    {
        return (int32_t[]){
                array_index(SPECIES, "Staravia"),
                array_index(SPECIES, "Staravia"),
                array_index(SPECIES, "Staravia"),
                array_index(SPECIES, "Pidgeotto"),
                array_index(SPECIES, "Pidgeotto"),
                array_index(SPECIES, "Noctowl"),
                array_index(SPECIES, "Noctowl"),
                array_index(SPECIES, "Swellow"),
                array_index(SPECIES, "Swellow"),
                array_index(SPECIES, "Farfetch'd"),
        }[slot];
    }
    else if (zoneID == array_index(ZONES, "Route 214"))
    {
        return (int32_t[]){
                array_index(SPECIES, "Aipom"),
                array_index(SPECIES, "Aipom"),
                array_index(SPECIES, "Aipom"),
                array_index(SPECIES, "Vigoroth"),
                array_index(SPECIES, "Vigoroth"),
                array_index(SPECIES, "Butterfree"),
                array_index(SPECIES, "Butterfree"),
                array_index(SPECIES, "Beedrill"),
                array_index(SPECIES, "Beedrill"),
                array_index(SPECIES, "Munchlax"),
        }[slot];
    }
    else if (zoneID == array_index(ZONES, "Route 215"))
    {
        return (int32_t[]){
                array_index(SPECIES, "Aipom"),
                array_index(SPECIES, "Aipom"),
                array_index(SPECIES, "Aipom"),
                array_index(SPECIES, "Vigoroth"),
                array_index(SPECIES, "Vigoroth"),
                array_index(SPECIES, "Metapod"),
                array_index(SPECIES, "Metapod"),
                array_index(SPECIES, "Kakuna"),
                array_index(SPECIES, "Kakuna"),
                array_index(SPECIES, "Munchlax"),
        }[slot];
    }
    else if (zoneID == array_index(ZONES, "Route 218"))
    {
        return (int32_t[]){
                array_index(SPECIES, "Combee"),
                array_index(SPECIES, "Combee"),
                array_index(SPECIES, "Combee"),
                array_index(SPECIES, "Forretress"),
                array_index(SPECIES, "Wormadam"),
                array_index(SPECIES, "Mothim"),
                array_index(SPECIES, "Beautifly"),
                array_index(SPECIES, "Dustox"),
                array_index(SPECIES, "Heracross"),
                array_index(SPECIES, "Vespiquen"),
        }[slot];
    }
    else if (zoneID == array_index(ZONES, "Route 221"))
    {
        return (int32_t[]){
                array_index(SPECIES, "Cherrim"),
                array_index(SPECIES, "Cherrim"),
                array_index(SPECIES, "Cherrim"),
                array_index(SPECIES, "Shroomish"),
                array_index(SPECIES, "Shroomish"),
                array_index(SPECIES, "Exeggcute"),
                array_index(SPECIES, "Exeggcute"),
                array_index(SPECIES, "Nuzleaf"),
                array_index(SPECIES, "Nuzleaf"),
                array_index(SPECIES, "Tangela"),
        }[slot];
    }
    else if (zoneID == array_index(ZONES, "Route 222"))
    {
        return (int32_t[]){
                array_index(SPECIES, "Tangela"),
                array_index(SPECIES, "Tangela"),
                array_index(SPECIES, "Tangela"),
                array_index(SPECIES, "Heracross"),
                array_index(SPECIES, "Heracross"),
                array_index(SPECIES, "Heracross"),
                array_index(SPECIES, "Farfetch'd"),
                array_index(SPECIES, "Farfetch'd"),
                array_index(SPECIES, "Farfetch'd"),
                array_index(SPECIES, "Snorlax"),
        }[slot];
    }

    // Default
    return array_index(SPECIES, "Ampharos");
}

int32_t GetHoneyTreeLevel(int32_t zoneID)
{
    if (zoneID == array_index(ZONES, "Valley Windworks (Outside)"))
    {
        return 12;
    }
    else if (zoneID == array_index(ZONES, "Eterna Forest (Outside)"))
    {
        return 15;
    }
    else if (zoneID == array_index(ZONES, "Fuego Ironworks (Outside)"))
    {
        return 40;
    }
    else if (zoneID == array_index(ZONES, "Floaroma Meadow"))
    {
        return 12;
    }
    else if (zoneID == array_index(ZONES, "Route 205 (South)"))
    {
        return 12;
    }
    else if (zoneID == array_index(ZONES, "Route 205 (North)"))
    {
        return 16;
    }
    else if (zoneID == array_index(ZONES, "Route 206"))
    {
        return 21;
    }
    else if (zoneID == array_index(ZONES, "Route 207"))
    {
        return 21;
    }
    else if (zoneID == array_index(ZONES, "Route 208"))
    {
        return 23;
    }
    else if (zoneID == array_index(ZONES, "Route 209"))
    {
        return 27;
    }
    else if (zoneID == array_index(ZONES, "Route 210 (South)"))
    {
        return 29;
    }
    else if (zoneID == array_index(ZONES, "Route 210 (North)"))
    {
        return 37;
    }
    else if (zoneID == array_index(ZONES, "Route 211 (East)"))
    {
        return 18;
    }
    else if (zoneID == array_index(ZONES, "Route 212 (North)"))
    {
        return 25;
    }
    else if (zoneID == array_index(ZONES, "Route 212 (South)"))
    {
        return 34;
    }
    else if (zoneID == array_index(ZONES, "Route 213"))
    {
        return 33;
    }
    else if (zoneID == array_index(ZONES, "Route 214"))
    {
        return 30;
    }
    else if (zoneID == array_index(ZONES, "Route 215"))
    {
        return 28;
    }
    else if (zoneID == array_index(ZONES, "Route 218"))
    {
        return 39;
    }
    else if (zoneID == array_index(ZONES, "Route 221"))
    {
        return 39;
    }
    else if (zoneID == array_index(ZONES, "Route 222"))
    {
        return 54;
    }

    // Default
    return 69;
}