#include "exlaunch.hpp"
#include "save/save.h"
#include "externals/PlayerWork.h"
#include "externals/System/Primitives.h"
#include "helpers/fsHelper.h"
#include "logger/logger.h"
#include "nn/err.h"
#include "changelog.h"

static CustomSaveData gCustomSaveData {
    .initialized = false,
    .version = ModVersion::Vanilla,
    .dex = {},
    .variables = {},
    .trainers = {},
    .items = {},
    .berries = {},
    .strings = {},
};

const char* saveFileName = "SaveData:/Luminescent.bin";
const char* saveFileBackupName = "SaveData:/Luminescent_Backup.bin";

// Vanilla data cache
static DPData::GET_STATUS_array* cache_get_status;
static System::Boolean_array* cache_male_color_flag;
static System::Boolean_array* cache_female_color_flag;
static System::Boolean_array* cache_male_flag;
static System::Boolean_array* cache_female_flag;

static System::Int32_array* cache_works;
static System::Boolean_array* cache_flags;
static System::Boolean_array* cache_sysflags;

static DPData::TR_BATTLE_DATA::Array* cache_trainers;

static Dpr::Item::SaveItem::Array* cache_items;

static DPData::KinomiGrow::Array* cache_berries;

// Temp custom data storage
static DPData::GET_STATUS_array* tmp_get_status;
static System::Boolean_array* tmp_male_color_flag;
static System::Boolean_array* tmp_female_color_flag;
static System::Boolean_array* tmp_male_flag;
static System::Boolean_array* tmp_female_flag;

static System::Int32_array* tmp_works;
static System::Boolean_array* tmp_flags;
static System::Boolean_array* tmp_sysflags;

static DPData::TR_BATTLE_DATA::Array* tmp_trainers;

static Dpr::Item::SaveItem::Array* tmp_items;

static DPData::KinomiGrow::Array* tmp_berries;

CustomSaveData* getCustomSaveData() {
    return &gCustomSaveData;
}

void save_custom_data(void* buffer) {
    Logger::log("Saving custom save data.\n");
    gCustomSaveData.ToBytes((char*)buffer, 0);
}

void load_custom_data(FsHelper::LoadData buffer, PlayerWork::Object* playerWork) {
    gCustomSaveData.FromBytes((char*)buffer.buffer, buffer.bufSize, 0);

    ModVersion version;
    bool changed = false;
    while ((version = gCustomSaveData.version) < CURRENT_VERSION) {
        Logger::log("Custom save data version mismatch! Expected %d, got %d; performing migration.\n", CURRENT_VERSION, version);
        migrate(playerWork);
        changed = true;
    }

    if (changed) {
        nn::err::ApplicationErrorArg err(0, "A mod update has been detected. Press Details to view the changelog.", CHANGELOG, nn::settings::LanguageCode::Make(nn::settings::Language::Language_English));
        nn::err::ShowApplicationError(err);
    }

    Logger::log("Custom save data loaded.\n");
}

void load_default_custom_data(PlayerWork::Object* playerWork) {
    Logger::log("Generating save data for first launch.\n");

    gCustomSaveData.version = ModVersion::Vanilla;

    ModVersion version;
    while ((version = gCustomSaveData.version) < CURRENT_VERSION) {
        Logger::log("Custom save data version mismatch! Expected %d, got %d; performing migration.\n", CURRENT_VERSION, version);
        migrate(playerWork);
    }

    gCustomSaveData.initialized = true;
}

// LOAD CUSTOM DATA ONTO PLAYERWORK
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
    memcpy(newStatus->m_Items, gCustomSaveData.dex.get_status, sizeof(gCustomSaveData.dex.get_status));
    memcpy(newMaleColorFlag->m_Items, gCustomSaveData.dex.male_color_flag, sizeof(gCustomSaveData.dex.male_color_flag));
    memcpy(newFemaleColorFlag->m_Items, gCustomSaveData.dex.female_color_flag, sizeof(gCustomSaveData.dex.female_color_flag));
    memcpy(newMaleFlag->m_Items, gCustomSaveData.dex.male_flag, sizeof(gCustomSaveData.dex.male_flag));
    memcpy(newFemaleFlag->m_Items, gCustomSaveData.dex.female_flag, sizeof(gCustomSaveData.dex.female_flag));

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

void loadVariables(PlayerWork::Object* playerWork)
{
    auto boolCls = System::Boolean_array_TypeInfo();
    auto int32Cls = System::Int32_array_TypeInfo();

    // Create new arrays
    auto newWorks = (System::Int32_array*) system_array_new(int32Cls, WorkCount);
    auto newFlags = (System::Boolean_array*) system_array_new(boolCls, FlagCount);
    auto newSysflags = (System::Boolean_array*) system_array_new(boolCls, SysFlagCount);

    // Fill the new arrays with the custom save data
    memcpy(newWorks->m_Items, gCustomSaveData.variables.works, sizeof(gCustomSaveData.variables.works));
    memcpy(newFlags->m_Items, gCustomSaveData.variables.flags, sizeof(gCustomSaveData.variables.flags));
    memcpy(newSysflags->m_Items, gCustomSaveData.variables.sysflags, sizeof(gCustomSaveData.variables.sysflags));

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

void loadTrainers(PlayerWork::Object* playerWork)
{
    auto trainerCls = DPData::TR_BATTLE_DATA_array_TypeInfo();

    // Create new array
    auto newTrainers = (DPData::TR_BATTLE_DATA::Array*) system_array_new(trainerCls, TrainerCount);

    // Fill the new array with the custom save data
    memcpy(newTrainers->m_Items, gCustomSaveData.trainers.items, sizeof(gCustomSaveData.trainers.items));

    // Cache the data that is in the vanilla save
    auto& savedata = playerWork->fields._saveData.fields;
    cache_trainers = savedata.tr_battleData;

    // Set the data in PlayerWork to our custom save data
    savedata.tr_battleData = newTrainers;
}

void loadItems(PlayerWork::Object* playerWork)
{
    auto saveItemCls = Dpr::Item::SaveItem_array_TypeInfo();

    // Create new array
    auto newItems = (Dpr::Item::SaveItem::Array*) system_array_new(saveItemCls, SaveItemCount);

    // Fill the new array with the custom save data
    memcpy(newItems->m_Items, gCustomSaveData.items.items, sizeof(gCustomSaveData.items.items));

    // Cache the data that is in the vanilla save
    auto& savedata = playerWork->fields._saveData.fields;
    cache_items = savedata.saveItem;

    // Set the data in PlayerWork to our custom save data
    savedata.saveItem = newItems;
}

void loadBerries(PlayerWork::Object* playerWork)
{
    auto kinomiGrowCls = DPData::KinomiGrow_array_TypeInfo();

    // Create new array
    auto newBerries = (DPData::KinomiGrow::Array*) system_array_new(kinomiGrowCls, BerryCount);

    // Fill the new array with the custom save data
    memcpy(newBerries->m_Items, gCustomSaveData.berries.items, sizeof(gCustomSaveData.berries.items));

    // Cache the data that is in the vanilla save
    auto& kinomigrow = playerWork->fields._saveData.fields.kinomiGrowSaveData.fields;
    cache_berries = kinomigrow.kinomiGrows;

    // Set the data in PlayerWork to our custom save data
    kinomigrow.kinomiGrows = newBerries;
}

// SAVE CUSTOM DATA ONTO OUR STRUCT AND SET PLAYERWORK TO CACHED VANILLA DATA
void saveZukan(PlayerWork::Object* playerWork)
{
    auto& zukan = playerWork->fields._saveData.fields.zukanData.fields;

    // Copy PlayerWork data to our Custom save data
    memcpy(gCustomSaveData.dex.get_status, zukan.get_status->m_Items, sizeof(gCustomSaveData.dex.get_status));
    memcpy(gCustomSaveData.dex.male_color_flag, zukan.male_color_flag->m_Items, sizeof(gCustomSaveData.dex.male_color_flag));
    memcpy(gCustomSaveData.dex.female_color_flag, zukan.female_color_flag->m_Items, sizeof(gCustomSaveData.dex.female_color_flag));
    memcpy(gCustomSaveData.dex.male_flag, zukan.male_flag->m_Items, sizeof(gCustomSaveData.dex.male_flag));
    memcpy(gCustomSaveData.dex.female_flag, zukan.female_flag->m_Items, sizeof(gCustomSaveData.dex.female_flag));

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

void saveVariables(PlayerWork::Object* playerWork)
{
    auto& savedata = playerWork->fields._saveData.fields;

    // Copy PlayerWork data to our Custom save data
    memcpy(gCustomSaveData.variables.works, savedata.intValues->m_Items, sizeof(gCustomSaveData.variables.works));
    memcpy(gCustomSaveData.variables.flags, savedata.boolValues->m_Items, sizeof(gCustomSaveData.variables.flags));
    memcpy(gCustomSaveData.variables.sysflags, savedata.systemFlags->m_Items, sizeof(gCustomSaveData.variables.sysflags));

    // Create a temp copy of the PlayerWork data
    tmp_works = savedata.intValues;
    tmp_flags = savedata.boolValues;
    tmp_sysflags = savedata.systemFlags;

    // Set PlayerWork to our cached data
    savedata.intValues = cache_works;
    savedata.boolValues = cache_flags;
    savedata.systemFlags = cache_sysflags;
}

void saveTrainers(PlayerWork::Object* playerWork)
{
    auto& savedata = playerWork->fields._saveData.fields;

    // Copy PlayerWork data to our Custom save data
    memcpy(gCustomSaveData.trainers.items, savedata.tr_battleData->m_Items, sizeof(gCustomSaveData.trainers.items));

    // Create a temp copy of the PlayerWork data
    tmp_trainers = savedata.tr_battleData;

    // Set PlayerWork to our cached data
    savedata.tr_battleData = cache_trainers;
}

void saveItems(PlayerWork::Object* playerWork)
{
    auto& savedata = playerWork->fields._saveData.fields;

    // Copy PlayerWork data to our Custom save data
    memcpy(gCustomSaveData.items.items, savedata.saveItem->m_Items, sizeof(gCustomSaveData.items.items));

    // Create a temp copy of the PlayerWork data
    tmp_items = savedata.saveItem;

    // Set PlayerWork to our cached data
    savedata.saveItem = cache_items;
}

void saveBerries(PlayerWork::Object* playerWork)
{
    auto& kinomigrow = playerWork->fields._saveData.fields.kinomiGrowSaveData.fields;

    // Copy PlayerWork data to our Custom save data
    memcpy(gCustomSaveData.berries.items, kinomigrow.kinomiGrows->m_Items, sizeof(gCustomSaveData.berries.items));

    // Create a temp copy of the PlayerWork data
    tmp_berries = kinomigrow.kinomiGrows;

    // Set PlayerWork to our cached data
    kinomigrow.kinomiGrows = cache_berries;
}

// RESTORING PLAYERWORK TO THE TEMP DATA
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

void restoreVariables(PlayerWork::Object* playerWork)
{
    auto& savedata = playerWork->fields._saveData.fields;

    // Restore PlayerWork to our temp copy
    savedata.intValues = tmp_works;
    savedata.boolValues = tmp_flags;
    savedata.systemFlags = tmp_sysflags;
}

void restoreTrainers(PlayerWork::Object* playerWork)
{
    auto& savedata = playerWork->fields._saveData.fields;

    // Restore PlayerWork to our temp copy
    savedata.tr_battleData = tmp_trainers;
}

void restoreItems(PlayerWork::Object* playerWork)
{
    auto& savedata = playerWork->fields._saveData.fields;

    // Restore PlayerWork to our temp copy
    savedata.saveItem = tmp_items;
}

void restoreBerries(PlayerWork::Object* playerWork)
{
    auto& kinomigrow = playerWork->fields._saveData.fields.kinomiGrowSaveData.fields;

    // Restore PlayerWork to our temp copy
    kinomigrow.kinomiGrows = tmp_berries;
}

HOOK_DEFINE_TRAMPOLINE(PatchExistingSaveData__Load) {
    static bool Callback(PlayerWork::Object* playerWork) {
        bool success = Orig(playerWork);

        bool isMain = playerWork->fields._isMainSave;
        bool isBackup = playerWork->fields._isBackupSave;
        Logger::log("LOAD: isMain %d, isBackup %d\n", isMain, isBackup);

        if (success)
        {
            if (isBackup && FsHelper::isFileExist(saveFileBackupName))
            {
                long size = std::max(FsHelper::getFileSize(saveFileBackupName), gCustomSaveData.GetByteCount());
                FsHelper::LoadData data {
                    .path = saveFileBackupName,
                    .alignment = 0x1000,
                    .bufSize = size,
                };
                FsHelper::loadFileFromPath(data);
                load_custom_data(data, playerWork);
                Logger::log("Loaded Custom Backup File!\n");
            }
            else if (isMain && FsHelper::isFileExist(saveFileName))
            {
                long size = std::max(FsHelper::getFileSize(saveFileName), gCustomSaveData.GetByteCount());
                FsHelper::LoadData data {
                        .path = saveFileName,
                        .alignment = 0x1000,
                        .bufSize = size,
                };
                FsHelper::loadFileFromPath(data);
                load_custom_data(data, playerWork);
                Logger::log("Loaded Custom Main File!\n");
            }
            else
            {
                load_default_custom_data(playerWork);
            }

            // Put our custom data into playerWork for the game to access
            loadZukan(playerWork);
            loadVariables(playerWork);
            loadTrainers(playerWork);
            loadItems(playerWork);
            loadBerries(playerWork);
        }

        playerWork->fields._isBackupSave = false;

        return success;
    }
};

HOOK_DEFINE_TRAMPOLINE(PatchExistingSaveData__Save) {
    static void Callback(PlayerWork::Object* playerWork, void* param_2, void* param_3, void* param_4) {
        bool isMain = playerWork->fields._isMainSave;
        bool isBackup = playerWork->fields._isBackupSave;
        Logger::log("SAVE: isMain %d, isBackup %d\n", isMain, isBackup);

        saveZukan(playerWork);
        saveVariables(playerWork);
        saveTrainers(playerWork);
        saveItems(playerWork);
        saveBerries(playerWork);

        char buffer[gCustomSaveData.GetByteCount()];
#ifndef DEBUG_DISABLE_SAVE  // Allow disabling the saving to test the save migration code
        save_custom_data(buffer);
#endif

        if (isMain)
            FsHelper::writeFileToPath(buffer, sizeof(buffer), saveFileName);
        if (isBackup)
            FsHelper::writeFileToPath(buffer, sizeof(buffer), saveFileBackupName);

        Orig(playerWork, param_2, param_3, param_4);

        restoreZukan(playerWork);
        restoreVariables(playerWork);
        restoreTrainers(playerWork);
        restoreItems(playerWork);
        restoreBerries(playerWork);
    }
};

HOOK_DEFINE_REPLACE(PatchExistingSaveData__Verify) {
    static bool Callback(System::Byte_array* playerWork) {
        return true;
    }
};

void exl_save_main() {
    PatchExistingSaveData__Load::InstallAtOffset(0x02ceb850);
    PatchExistingSaveData__Save::InstallAtOffset(0x01a8c2f0);
    PatchExistingSaveData__Verify::InstallAtOffset(0x02ceba00);

    // Backup save patches
    using namespace exl::armv8::inst;
    using namespace exl::armv8::reg;
    exl::patch::CodePatcher p(0);
    auto inst = std::vector {
        std::make_pair<uint32_t, Instruction>(0x02ceb9dc, Nop()),
    };
    p.WriteInst(inst);

}
