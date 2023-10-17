#include "save/save.h"

static DPData::TR_BATTLE_DATA::Array* cache_trainers;

static DPData::TR_BATTLE_DATA::Array* tmp_trainers;

void loadTrainers(PlayerWork::Object* playerWork)
{
    auto trainerCls = DPData::TR_BATTLE_DATA_array_TypeInfo();

    // Create new array
    auto newTrainers = (DPData::TR_BATTLE_DATA::Array*) system_array_new(trainerCls, TrainerCount);

    // Fill the new array with the custom save data
    memcpy(newTrainers->m_Items, getCustomSaveData()->trainers.items, sizeof(getCustomSaveData()->trainers.items));

    // Cache the data that is in the vanilla save
    auto& savedata = playerWork->fields._saveData.fields;
    cache_trainers = savedata.tr_battleData;

    // Set the data in PlayerWork to our custom save data
    savedata.tr_battleData = newTrainers;
}

void saveTrainers(PlayerWork::Object* playerWork)
{
    auto& savedata = playerWork->fields._saveData.fields;

    // Copy PlayerWork data to our Custom save data
    memcpy(getCustomSaveData()->trainers.items, savedata.tr_battleData->m_Items, sizeof(getCustomSaveData()->trainers.items));

    // Create a temp copy of the PlayerWork data
    tmp_trainers = savedata.tr_battleData;

    // Set PlayerWork to our cached data
    savedata.tr_battleData = cache_trainers;
}

void restoreTrainers(PlayerWork::Object* playerWork)
{
    auto& savedata = playerWork->fields._saveData.fields;

    // Restore PlayerWork to our temp copy
    savedata.tr_battleData = tmp_trainers;
}