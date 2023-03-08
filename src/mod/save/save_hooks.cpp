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

            // FIXME: Set up Playerwork to use gCustomSaveData
        }

        return success;
    }
};

HOOK_DEFINE_REPLACE(PatchExistingSaveData__Save) {
    static void Callback(PlayerWork::Object* playerWork, System_Byte_array** save_ptr) {
        char buffer[sizeof(CustomSaveData)];
        save_custom_data(buffer);
        FsHelper::writeFileToPath(buffer, sizeof(buffer), "SaveData:/Custom.bin");

        // TODO: Restore Playerwork to use default sizes
    }
};

HOOK_DEFINE_REPLACE(PatchExistingSaveData__Verify) {
    static bool Callback(System_Byte_array* playerWork) {
        return true;
    }
};

void exl_save_main() {
    PatchExistingSaveData__Load::InstallAtOffset(0x02ceb850);
#ifndef DEBUG_DISABLE_SAVE  // Allow disabling the saving to test the save migration code
    PatchExistingSaveData__Save::InstallAtOffset(0x02cebff0);
#endif
    PatchExistingSaveData__Verify::InstallAtOffset(0x02ceba00);
}
