#include "save/save.h"

static DPData::GET_STATUS_array* cache_get_status;
static System::Boolean_array* cache_male_color_flag;
static System::Boolean_array* cache_female_color_flag;
static System::Boolean_array* cache_male_flag;
static System::Boolean_array* cache_female_flag;

static DPData::GET_STATUS_array* tmp_get_status;
static System::Boolean_array* tmp_male_color_flag;
static System::Boolean_array* tmp_female_color_flag;
static System::Boolean_array* tmp_male_flag;
static System::Boolean_array* tmp_female_flag;

void loadZukan(PlayerWork::Object* playerWork)
{
    auto boolCls = System::Boolean_array_TypeInfo();

    // Create new arrays
    auto newStatus = (DPData::GET_STATUS_array*)system_array_new(DPData::GET_STATUS_array_TypeInfo(), DexSize);
    auto newMaleColorFlag = (System::Boolean_array*)system_array_new(boolCls, DexSize);
    auto newFemaleColorFlag = (System::Boolean_array*)system_array_new(boolCls, DexSize);
    auto newMaleFlag = (System::Boolean_array*)system_array_new(boolCls, DexSize);
    auto newFemaleFlag = (System::Boolean_array*)system_array_new(boolCls, DexSize);

    // Fill the new arrays with the custom save data
    memcpy(newStatus->m_Items, getCustomSaveData()->dex.get_status, sizeof(getCustomSaveData()->dex.get_status));
    memcpy(newMaleColorFlag->m_Items, getCustomSaveData()->dex.male_color_flag, sizeof(getCustomSaveData()->dex.male_color_flag));
    memcpy(newFemaleColorFlag->m_Items, getCustomSaveData()->dex.female_color_flag, sizeof(getCustomSaveData()->dex.female_color_flag));
    memcpy(newMaleFlag->m_Items, getCustomSaveData()->dex.male_flag, sizeof(getCustomSaveData()->dex.male_flag));
    memcpy(newFemaleFlag->m_Items, getCustomSaveData()->dex.female_flag, sizeof(getCustomSaveData()->dex.female_flag));

    // Cache the data that is in the vanilla save
    auto& zukan = playerWork->fields._saveData.fields.zukanData.fields;
    cache_get_status = zukan.get_status;
    cache_male_color_flag = zukan.male_color_flag;
    cache_female_color_flag = zukan.female_color_flag;
    cache_male_flag = zukan.male_flag;
    cache_female_flag = zukan.female_flag;

    // Set the data in PlayerWork to our custom save data
    zukan.get_status = newStatus;
    zukan.male_color_flag = newMaleColorFlag;
    zukan.female_color_flag = newFemaleColorFlag;
    zukan.male_flag = newMaleFlag;
    zukan.female_flag = newFemaleFlag;
}

void saveZukan(PlayerWork::Object* playerWork)
{
    auto& zukan = playerWork->fields._saveData.fields.zukanData.fields;

    // Copy PlayerWork data to our Custom save data
    memcpy(getCustomSaveData()->dex.get_status, zukan.get_status->m_Items, sizeof(getCustomSaveData()->dex.get_status));
    memcpy(getCustomSaveData()->dex.male_color_flag, zukan.male_color_flag->m_Items, sizeof(getCustomSaveData()->dex.male_color_flag));
    memcpy(getCustomSaveData()->dex.female_color_flag, zukan.female_color_flag->m_Items, sizeof(getCustomSaveData()->dex.female_color_flag));
    memcpy(getCustomSaveData()->dex.male_flag, zukan.male_flag->m_Items, sizeof(getCustomSaveData()->dex.male_flag));
    memcpy(getCustomSaveData()->dex.female_flag, zukan.female_flag->m_Items, sizeof(getCustomSaveData()->dex.female_flag));

    // Create a temp copy of the PlayerWork data
    tmp_get_status = zukan.get_status;
    tmp_male_color_flag = zukan.male_color_flag;
    tmp_female_color_flag = zukan.female_color_flag;
    tmp_male_flag = zukan.male_flag;
    tmp_female_flag = zukan.female_flag;

    // Set PlayerWork to our cached data
    zukan.get_status = cache_get_status;
    zukan.male_color_flag = cache_male_color_flag;
    zukan.female_color_flag = cache_female_color_flag;
    zukan.male_flag = cache_male_flag;
    zukan.female_flag = cache_female_flag;
}

void restoreZukan(PlayerWork::Object* playerWork)
{
    auto& zukan = playerWork->fields._saveData.fields.zukanData.fields;

    // Restore PlayerWork to our temp copy
    zukan.get_status = tmp_get_status;
    zukan.male_color_flag = tmp_male_color_flag;
    zukan.female_color_flag = tmp_female_color_flag;
    zukan.male_flag = tmp_male_flag;
    zukan.female_flag = tmp_female_flag;
}