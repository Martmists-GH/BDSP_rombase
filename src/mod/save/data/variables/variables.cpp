#include "save/save.h"

static System::Int32_array* cache_works;
static System::Boolean_array* cache_flags;
static System::Boolean_array* cache_sysflags;

static System::Int32_array* tmp_works;
static System::Boolean_array* tmp_flags;
static System::Boolean_array* tmp_sysflags;

void loadVariables(PlayerWork::Object* playerWork)
{
    auto boolCls = System::Boolean_array_TypeInfo();
    auto int32Cls = System::Int32_array_TypeInfo();

    // Create new arrays
    auto newWorks = (System::Int32_array*) system_array_new(int32Cls, WorkCount);
    auto newFlags = (System::Boolean_array*) system_array_new(boolCls, FlagCount);
    auto newSysflags = (System::Boolean_array*) system_array_new(boolCls, SysFlagCount);

    // Fill the new arrays with the custom save data
    memcpy(newWorks->m_Items, getCustomSaveData()->variables.works, sizeof(getCustomSaveData()->variables.works));
    memcpy(newFlags->m_Items, getCustomSaveData()->variables.flags, sizeof(getCustomSaveData()->variables.flags));
    memcpy(newSysflags->m_Items, getCustomSaveData()->variables.sysflags, sizeof(getCustomSaveData()->variables.sysflags));

    // Cache the data that is in the vanilla save
    auto& savedata = playerWork->fields._saveData.fields;
    cache_works = savedata.intValues;
    cache_flags = savedata.boolValues;
    cache_sysflags = savedata.systemFlags;

    // Set the data in PlayerWork to our custom save data
    savedata.intValues = newWorks;
    savedata.boolValues = newFlags;
    savedata.systemFlags = newSysflags;
}

void saveVariables(PlayerWork::Object* playerWork)
{
    auto& savedata = playerWork->fields._saveData.fields;

    // Copy PlayerWork data to our Custom save data
    memcpy(getCustomSaveData()->variables.works, savedata.intValues->m_Items, sizeof(getCustomSaveData()->variables.works));
    memcpy(getCustomSaveData()->variables.flags, savedata.boolValues->m_Items, sizeof(getCustomSaveData()->variables.flags));
    memcpy(getCustomSaveData()->variables.sysflags, savedata.systemFlags->m_Items, sizeof(getCustomSaveData()->variables.sysflags));

    // Create a temp copy of the PlayerWork data
    tmp_works = savedata.intValues;
    tmp_flags = savedata.boolValues;
    tmp_sysflags = savedata.systemFlags;

    // Set PlayerWork to our cached data
    savedata.intValues = cache_works;
    savedata.boolValues = cache_flags;
    savedata.systemFlags = cache_sysflags;
}

void restoreVariables(PlayerWork::Object* playerWork)
{
    auto& savedata = playerWork->fields._saveData.fields;

    // Restore PlayerWork to our temp copy
    savedata.intValues = tmp_works;
    savedata.boolValues = tmp_flags;
    savedata.systemFlags = tmp_sysflags;
}