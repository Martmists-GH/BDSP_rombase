#include "externals/PlayerWork.h"

#include "save/save.h"

#include "logger/logger.h"

void migrateFromVanilla(PlayerWork::Object* playerWork) {
    Logger::log("Migrating from Vanilla...\n");
    CustomSaveData* save = getCustomSaveData();

    auto& savedata = playerWork->fields._saveData.fields;
    auto& zukan = playerWork->fields._saveData.fields.zukanData.fields;
    auto& kinomigrow = playerWork->fields._saveData.fields.kinomiGrowSaveData.fields;
    auto& myStatus = playerWork->fields._saveData.fields.playerData.fields.mystatus.fields;

    // Copy over data from PlayerWork into the custom save
    zukan.get_status->copyInto(save->dex.get_status);
    zukan.male_color_flag->copyInto(save->dex.male_color_flag);
    zukan.female_color_flag->copyInto(save->dex.female_color_flag);
    zukan.male_flag->copyInto(save->dex.male_flag);
    zukan.female_flag->copyInto(save->dex.female_flag);

    savedata.intValues->copyInto(save->variables.works);
    savedata.boolValues->copyInto(save->variables.flags);
    savedata.systemFlags->copyInto(save->variables.sysflags);

    savedata.tr_battleData->copyInto(save->trainers.items);

    savedata.saveItem->copyInto(save->items.items);

    kinomigrow.kinomiGrows->copyInto(save->berries.items);

    // Set first player color to the one in the vanilla save
    save->colorVariations.playerColorID[0] = myStatus.body_type;

    // Set amount of boxes unlocked to 40 for now
    playerWork->fields._saveData.fields.boxData.fields.trayMax = 40;

    Logger::log("Migration from Vanilla done!\n");
}

void migrate(PlayerWork::Object* playerWork) {
    ModVersion newVersion;

    switch (getCustomSaveData()->version) {
        case ModVersion::Vanilla: {
            migrateFromVanilla(playerWork);

            newVersion = ModVersion::Release_3_0;
            break;
        }

        case ModVersion::Release_3_0: {
            // New save migration code goes here

            newVersion = ModVersion::Dev;
            break;
        }

        case ModVersion::Dev: {
            // should never happen; return
            return;
        }
    }

    getCustomSaveData()->version = newVersion;
}
