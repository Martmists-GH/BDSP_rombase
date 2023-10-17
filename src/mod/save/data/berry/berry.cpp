#include "save/save.h"

static DPData::KinomiGrow::Array* cache_berries;

static DPData::KinomiGrow::Array* tmp_berries;

void loadBerries(PlayerWork::Object* playerWork)
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

void saveBerries(PlayerWork::Object* playerWork)
{
    auto& kinomigrow = playerWork->fields._saveData.fields.kinomiGrowSaveData.fields;

    // Copy PlayerWork data to our Custom save data
    memcpy(getCustomSaveData()->berries.items, kinomigrow.kinomiGrows->m_Items, sizeof(getCustomSaveData()->berries.items));

    // Create a temp copy of the PlayerWork data
    tmp_berries = kinomigrow.kinomiGrows;

    // Set PlayerWork to our cached data
    kinomigrow.kinomiGrows = cache_berries;
}

void restoreBerries(PlayerWork::Object* playerWork)
{
    auto& kinomigrow = playerWork->fields._saveData.fields.kinomiGrowSaveData.fields;

    // Restore PlayerWork to our temp copy
    kinomigrow.kinomiGrows = tmp_berries;
}