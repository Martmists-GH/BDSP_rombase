#include "save/save.h"
#include "externals/PlayerWork.h"
#include "logger/logger.h"

void migrate(CustomSaveData* save, PlayerWork::Object* playerWork) {
    ModVersion newVersion;

    switch (save->version) {
        case ModVersion::Vanilla: {
            // Copy over data
            auto& savedata = playerWork->fields._saveData.fields;
            auto& zukan = playerWork->fields._saveData.fields.zukanData.fields;
            auto& kinomigrow = playerWork->fields._saveData.fields.kinomiGrowSaveData.fields;
            auto& boxdata = playerWork->fields._saveData.fields.boxData.fields;
            auto& badgedata = playerWork->fields._saveData.fields.badgeSaveData.fields;

            Logger::log("Zukan get_status max_length: %d\n", zukan.get_status->max_length);
            zukan.get_status->copyInto(save->dex.get_status);
            zukan.male_color_flag->copyInto(save->dex.male_color_flag);
            zukan.female_color_flag->copyInto(save->dex.female_color_flag);
            zukan.male_flag->copyInto(save->dex.male_flag);
            zukan.female_flag->copyInto(save->dex.female_flag);

            Logger::log("Works max_length: %d\n", savedata.intValues->max_length);
            Logger::log("Flags max_length: %d\n", savedata.boolValues->max_length);
            Logger::log("SysFlags max_length: %d\n", savedata.systemFlags->max_length);
            savedata.intValues->copyInto(save->variables.works);
            savedata.boolValues->copyInto(save->variables.flags);
            savedata.systemFlags->copyInto(save->variables.sysflags);

            Logger::log("Trainers max_length: %d\n", savedata.tr_battleData->max_length);
            savedata.tr_battleData->copyInto(save->trainers.items);

            Logger::log("SaveItem max_length: %d\n", savedata.saveItem->max_length);
            savedata.saveItem->copyInto(save->items.items);

            Logger::log("kinomiGrows max_length: %d\n", kinomigrow.kinomiGrows->max_length);
            kinomigrow.kinomiGrows->copyInto(save->berries.items);

            Logger::log("box (trayName) max_length: %d\n", savedata.boxData.fields.trayName->max_length);
            boxdata.trayName->copyInto(save->boxes.boxNames);
            boxdata.wallPaper->copyInto(save->boxes.wallpapers);
            savedata.boxTray->copyInto(save->boxes.pokemonParams);

            Logger::log("badgeSaveData max_length: %d\n", savedata.badgeSaveData.fields.CleanValues->max_length);
            badgedata.CleanValues->copyInto(save->badges_polish.items);

            // Set amount of boxes unlocked to 40 for now
            playerWork->fields._saveData.fields.boxData.fields.trayMax = 40;

            newVersion = ModVersion::Release_001;
            break;
        }

        case ModVersion::Release_001: {
            // Save migration code goes here

            newVersion = ModVersion::Dev;
            break;
        }

        case ModVersion::Dev: {  // should never happen; return
            return;
        }
    }

    save->version = newVersion;
}
