#include "exlaunch.hpp"

#include "changelog.h"
#include "externals/PlayerWork.h"
#include "externals/System/Primitives.h"
#include "helpers/fsHelper.h"
#include "logger/logger.h"
#include "nn/err.h"
#include "save/save.h"
#include "save/migration/save_migration.h"

static CustomSaveData gCustomSaveData {
    .initialized = false,
    .version = ModVersion::Vanilla,
    .dex = {},
    .variables = {},
    .trainers = {},
    .items = {},
    .berries = {},
    .colorVariations = {},
};

const char* saveFileName = "SaveData:/Luminescent.bin";
const char* saveFileBackupName = "SaveData:/Luminescent_Backup.bin";

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
        migrate(playerWork);
    }

    gCustomSaveData.initialized = true;
}

HOOK_DEFINE_TRAMPOLINE(PatchExistingSaveData__Load) {
    static bool Callback(PlayerWork::Object* playerWork) {
        bool success = Orig(playerWork);

        bool isMain = playerWork->fields._isMainSave;
        bool isBackup = playerWork->fields._isBackupSave;

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
    auto inst = nn::vector<exl::patch::Instruction> {
        { 0x02ceb9dc, Nop() },
    };
    p.WriteInst(inst);
}
