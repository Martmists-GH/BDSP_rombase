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
    .boxes = {},
    .badges_polish = {},
};

CustomSaveData* getCustomSaveData() {
    return &gCustomSaveData;
}

void save_custom_data(void* buffer) {
    Logger::log("Saving custom save data.\n");
    memcpy(buffer, &gCustomSaveData, sizeof(CustomSaveData));
}

void load_custom_data(void* buffer, PlayerWork::Object* playerWork) {
    auto *save = (CustomSaveData *) buffer;
    Logger::log("Save data size: %d\n", sizeof(CustomSaveData));

    ModVersion version;
    bool changed = false;
    while ((version = save->version) < CURRENT_VERSION) {
        Logger::log("Custom save data version mismatch! Expected %d, got %d; performing migration.\n", CURRENT_VERSION,
                    version);
        migrate(save, playerWork);
        changed = true;
    }

    if (changed) {
        nn::err::ApplicationErrorArg err(0, "A mod update has been detected. Press Details to view the changelog.", CHANGELOG, nn::settings::LanguageCode::Make(nn::settings::Language::Language_English));
        nn::err::ShowApplicationError(err);
    }

    memcpy(&gCustomSaveData, buffer, sizeof(CustomSaveData));
    Logger::log("Custom save data loaded.\n");
}

void load_default_custom_data(PlayerWork::Object* playerWork) {
    Logger::log("Generating save data for first launch.\n");

    gCustomSaveData.version = ModVersion::Vanilla;

    ModVersion version;
    while ((version = gCustomSaveData.version) < CURRENT_VERSION) {
        Logger::log("Custom save data version mismatch! Expected %d, got %d; performing migration.\n", CURRENT_VERSION, version);
        migrate(&gCustomSaveData, playerWork);
    }

    gCustomSaveData.initialized = true;
}

#define zukan_cache(field) static typeof(DPData::ZUKAN_WORK::Fields::field) cache_##field
zukan_cache(get_status);
zukan_cache(male_color_flag);
zukan_cache(female_color_flag);
zukan_cache(male_flag);
zukan_cache(female_flag);
#undef zukan_cache

static System::Int32_array* cache_works;
static System::Boolean_array* cache_flags;
static System::Boolean_array* cache_sysflags;

static DPData::TR_BATTLE_DATA::Array* cache_trainers;

static Dpr::Item::SaveItem::Array* cache_items;

static DPData::KinomiGrow::Array* cache_berries;

static Dpr::Box::SaveBoxData::_STR17::Array* cache_boxNames;
static System::Byte_array* cache_wallpapers;
static Dpr::Box::SaveBoxTrayData::Array* cache_boxPokemonParams;

static System::Byte_array* cache_badgePolish;

HOOK_DEFINE_TRAMPOLINE(PatchExistingSaveData__Load) {
    static bool Callback(PlayerWork::Object* playerWork) {
        bool success = Orig(playerWork);

        if (success) {
            if (FsHelper::isFileExist("SaveData:/Custom.bin")) {
                long size = std::max(FsHelper::getFileSize("SaveData:/Custom.bin"),
                                     (long)sizeof(CustomSaveData));
                FsHelper::LoadData data {
                    .path = "SaveData:/Custom.bin",
                    .alignment = 0x1000,
                    .bufSize = size,
                };
                FsHelper::loadFileFromPath(data);

                load_custom_data(data.buffer, playerWork);
            } else {
                load_default_custom_data(playerWork);
            }

            auto boolCls = System::Boolean_array_TypeInfo();
            auto int32Cls = System::Int32_array_TypeInfo();
            auto byteCls = System::Byte_array_TypeInfo();
            auto trainerCls = DPData::TR_BATTLE_DATA_array_TypeInfo();
            auto saveItemCls = Dpr::Item::SaveItem_array_TypeInfo();
            auto kinomiGrowCls = DPData::KinomiGrow_array_TypeInfo();
            auto saveBoxSTR17Cls = Dpr::Box::SaveBoxData::_STR17_array_TypeInfo();
            auto saveBoxTrayCls = Dpr::Box::SaveBoxTrayData_array_TypeInfo();

            // Create new arrays
            auto newStatus = (DPData::GET_STATUS_array*)system_array_new(DPData::GET_STATUS_array_TypeInfo(), DexSize);
            auto newMaleColorFlag = (System::Boolean_array*)system_array_new(boolCls, DexSize);
            auto newFemaleColorFlag = (System::Boolean_array*)system_array_new(boolCls, DexSize);
            auto newMaleFlag = (System::Boolean_array*)system_array_new(boolCls, DexSize);
            auto newFemaleFlag = (System::Boolean_array*)system_array_new(boolCls, DexSize);

            auto newWorks = (System::Int32_array*) system_array_new(int32Cls, WorkCount);
            auto newFlags = (System::Boolean_array*) system_array_new(boolCls, FlagCount);
            auto newSysflags = (System::Boolean_array*) system_array_new(boolCls, SysFlagCount);

            auto newTrainers = (DPData::TR_BATTLE_DATA::Array*) system_array_new(trainerCls, TrainerCount);

            auto newItems = (Dpr::Item::SaveItem::Array*) system_array_new(saveItemCls, SaveItemCount);

            auto newBerries = (DPData::KinomiGrow::Array*) system_array_new(kinomiGrowCls, BerryCount);

            auto newBoxNames = (Dpr::Box::SaveBoxData::_STR17::Array*) system_array_new(saveBoxSTR17Cls, BoxCount);
            auto newWallpapers = (System::Byte_array*) system_array_new(byteCls, BoxCount);
            auto newBoxPokemonParams = (Dpr::Box::SaveBoxTrayData::Array*) system_array_new(saveBoxTrayCls, BoxCount);

            auto newBadgePolish = (System::Byte_array*) system_array_new(byteCls, BadgeCount);

            // Fill the new arrays with the custom save data
            memcpy(newStatus->m_Items, gCustomSaveData.dex.get_status, sizeof(gCustomSaveData.dex.get_status));
            memcpy(newMaleColorFlag->m_Items, gCustomSaveData.dex.male_color_flag, sizeof(gCustomSaveData.dex.male_color_flag));
            memcpy(newFemaleColorFlag->m_Items, gCustomSaveData.dex.female_color_flag, sizeof(gCustomSaveData.dex.female_color_flag));
            memcpy(newMaleFlag->m_Items, gCustomSaveData.dex.male_flag, sizeof(gCustomSaveData.dex.male_flag));
            memcpy(newFemaleFlag->m_Items, gCustomSaveData.dex.female_flag, sizeof(gCustomSaveData.dex.female_flag));

            memcpy(newWorks->m_Items, gCustomSaveData.variables.works, sizeof(gCustomSaveData.variables.works));
            memcpy(newFlags->m_Items, gCustomSaveData.variables.flags, sizeof(gCustomSaveData.variables.flags));
            memcpy(newSysflags->m_Items, gCustomSaveData.variables.sysflags, sizeof(gCustomSaveData.variables.sysflags));

            memcpy(newTrainers->m_Items, gCustomSaveData.trainers.items, sizeof(gCustomSaveData.trainers.items));

            memcpy(newItems->m_Items, gCustomSaveData.items.items, sizeof(gCustomSaveData.items.items));

            memcpy(newBerries->m_Items, gCustomSaveData.berries.items, sizeof(gCustomSaveData.berries.items));

            memcpy(newBoxNames->m_Items, gCustomSaveData.boxes.boxNames, sizeof(gCustomSaveData.boxes.boxNames));
            memcpy(newWallpapers->m_Items, gCustomSaveData.boxes.wallpapers, sizeof(gCustomSaveData.boxes.wallpapers));
            memcpy(newBoxPokemonParams->m_Items, gCustomSaveData.boxes.pokemonParams, sizeof(gCustomSaveData.boxes.pokemonParams));

            memcpy(newBadgePolish->m_Items, gCustomSaveData.badges_polish.items, sizeof(gCustomSaveData.badges_polish.items));

            // Cache the data in the vanilla save
            auto& zukan = playerWork->fields._saveData.fields.zukanData.fields;
            cache_get_status = zukan.get_status;
            cache_male_color_flag = zukan.male_color_flag;
            cache_female_color_flag = zukan.female_color_flag;
            cache_male_flag = zukan.male_flag;
            cache_female_flag = zukan.female_flag;

            auto& savedata = playerWork->fields._saveData.fields;
            cache_works = savedata.intValues;
            cache_flags = savedata.boolValues;
            cache_sysflags = savedata.systemFlags;

            cache_trainers = savedata.tr_battleData;

            cache_items = savedata.saveItem;

            auto& kinomigrow = playerWork->fields._saveData.fields.kinomiGrowSaveData.fields;
            cache_berries = kinomigrow.kinomiGrows;

            auto& boxdata = playerWork->fields._saveData.fields.boxData.fields;
            cache_boxNames = boxdata.trayName;
            cache_wallpapers = boxdata.wallPaper;
            cache_boxPokemonParams = savedata.boxTray;

            auto& badgedata = playerWork->fields._saveData.fields.badgeSaveData.fields;
            cache_badgePolish = badgedata.CleanValues;

            // Set the data in PlayerWork to our custom save data
            zukan.get_status = newStatus;
            zukan.male_color_flag = newMaleColorFlag;
            zukan.female_color_flag = newFemaleColorFlag;
            zukan.male_flag = newMaleFlag;
            zukan.female_flag = newFemaleFlag;

            savedata.intValues = newWorks;
            savedata.boolValues = newFlags;
            savedata.systemFlags = newSysflags;

            savedata.tr_battleData = newTrainers;

            savedata.saveItem = newItems;

            kinomigrow.kinomiGrows = newBerries;

            boxdata.trayName = newBoxNames;
            boxdata.wallPaper = newWallpapers;
            savedata.tr_battleData = newTrainers;

            badgedata.CleanValues = newBadgePolish;
        }

        return success;
    }
};

HOOK_DEFINE_TRAMPOLINE(PatchExistingSaveData__Save) {
    static void Callback(PlayerWork::Object* playerWork, void* param_2, void* param_3, void* param_4) {
        auto& zukan = playerWork->fields._saveData.fields.zukanData.fields;
        auto& savedata = playerWork->fields._saveData.fields;
        auto& kinomigrow = playerWork->fields._saveData.fields.kinomiGrowSaveData.fields;
        auto& boxdata = playerWork->fields._saveData.fields.boxData.fields;
        auto& badgedata = playerWork->fields._saveData.fields.badgeSaveData.fields;

        // Copy PlayerWork data to our Custom save data
        memcpy(gCustomSaveData.dex.get_status, zukan.get_status->m_Items, sizeof(gCustomSaveData.dex.get_status));
        memcpy(gCustomSaveData.dex.male_color_flag, zukan.male_color_flag->m_Items, sizeof(gCustomSaveData.dex.male_color_flag));
        memcpy(gCustomSaveData.dex.female_color_flag, zukan.female_color_flag->m_Items, sizeof(gCustomSaveData.dex.female_color_flag));
        memcpy(gCustomSaveData.dex.male_flag, zukan.male_flag->m_Items, sizeof(gCustomSaveData.dex.male_flag));
        memcpy(gCustomSaveData.dex.female_flag, zukan.female_flag->m_Items, sizeof(gCustomSaveData.dex.female_flag));

        memcpy(gCustomSaveData.variables.works, savedata.intValues->m_Items, sizeof(gCustomSaveData.variables.works));
        memcpy(gCustomSaveData.variables.flags, savedata.boolValues->m_Items, sizeof(gCustomSaveData.variables.flags));
        memcpy(gCustomSaveData.variables.sysflags, savedata.systemFlags->m_Items, sizeof(gCustomSaveData.variables.sysflags));

        memcpy(gCustomSaveData.trainers.items, savedata.tr_battleData->m_Items, sizeof(gCustomSaveData.trainers.items));

        memcpy(gCustomSaveData.items.items, savedata.saveItem->m_Items, sizeof(gCustomSaveData.items.items));

        memcpy(gCustomSaveData.berries.items, kinomigrow.kinomiGrows->m_Items, sizeof(gCustomSaveData.berries.items));

        memcpy(gCustomSaveData.boxes.boxNames, boxdata.trayName->m_Items, sizeof(gCustomSaveData.boxes.boxNames));
        memcpy(gCustomSaveData.boxes.wallpapers, boxdata.wallPaper->m_Items, sizeof(gCustomSaveData.boxes.wallpapers));
        memcpy(gCustomSaveData.boxes.pokemonParams, savedata.boxTray->m_Items, sizeof(gCustomSaveData.boxes.pokemonParams));

        memcpy(gCustomSaveData.badges_polish.items, badgedata.CleanValues->m_Items, sizeof(gCustomSaveData.badges_polish.items));

        // Create a temp copy of the PlayerWork data
        auto tmp_get_status = zukan.get_status;
        auto tmp_male_color_flag = zukan.male_color_flag;
        auto tmp_female_color_flag = zukan.female_color_flag;
        auto tmp_male_flag = zukan.male_flag;
        auto tmp_female_flag = zukan.female_flag;

        auto tmp_works = savedata.intValues;
        auto tmp_flags = savedata.boolValues;
        auto tmp_sysflags = savedata.systemFlags;

        auto tmp_trainers = savedata.tr_battleData;

        auto tmp_items = savedata.saveItem;

        auto tmp_berries = kinomigrow.kinomiGrows;

        auto tmp_boxNames = boxdata.trayName;
        auto tmp_wallpapers = boxdata.wallPaper;
        auto tmp_boxPokemonParams = savedata.boxTray;

        auto tmp_badgePolish = badgedata.CleanValues;

        // Set PlayerWork to our cached data
        zukan.get_status = cache_get_status;
        zukan.male_color_flag = cache_male_color_flag;
        zukan.female_color_flag = cache_female_color_flag;
        zukan.male_flag = cache_male_flag;
        zukan.female_flag = cache_female_flag;

        savedata.intValues = cache_works;
        savedata.boolValues = cache_flags;
        savedata.systemFlags = cache_sysflags;

        savedata.tr_battleData = cache_trainers;

        savedata.saveItem = cache_items;

        kinomigrow.kinomiGrows = cache_berries;

        boxdata.trayName = cache_boxNames;
        boxdata.wallPaper = cache_wallpapers;
        savedata.boxTray = cache_boxPokemonParams;

        badgedata.CleanValues = cache_badgePolish;

        char buffer[sizeof(CustomSaveData)];
#ifndef DEBUG_DISABLE_SAVE  // Allow disabling the saving to test the save migration code
        save_custom_data(buffer);
#endif
        FsHelper::writeFileToPath(buffer, sizeof(buffer), "SaveData:/Custom.bin");

        Orig(playerWork, param_2, param_3, param_4);

        // Restore PlayerWork to our temp copy
        zukan.get_status = tmp_get_status;
        zukan.male_color_flag = tmp_male_color_flag;
        zukan.female_color_flag = tmp_female_color_flag;
        zukan.male_flag = tmp_male_flag;
        zukan.female_flag = tmp_female_flag;

        savedata.intValues = tmp_works;
        savedata.boolValues = tmp_flags;
        savedata.systemFlags = tmp_sysflags;

        savedata.tr_battleData = tmp_trainers;

        savedata.saveItem = tmp_items;

        kinomigrow.kinomiGrows = tmp_berries;

        boxdata.trayName = tmp_boxNames;
        boxdata.wallPaper = tmp_wallpapers;
        savedata.boxTray = tmp_boxPokemonParams;

        badgedata.CleanValues = tmp_badgePolish;
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
}
