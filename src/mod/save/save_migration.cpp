#include "save/save.h"
#include "externals/PlayerWork.h"
#include "logger/logger.h"

void migrate(CustomSaveData* save, PlayerWork::Object* playerWork) {
    ModVersion newVersion;

    switch (save->version) {
        case Vanilla: {
            // Copy over dex data
            auto zukan = playerWork->fields._saveData.fields.zukanData.fields;

            Logger::log("Zukan get_status max_length: %d\n", zukan.get_status->max_length);

            zukan.get_status->copyInto(save->dex.get_status);
            zukan.male_color_flag->copyInto(save->dex.male_color_flag);
            zukan.female_color_flag->copyInto(save->dex.female_color_flag);
            zukan.male_flag->copyInto(save->dex.male_flag);
            zukan.female_flag->copyInto(save->dex.female_flag);

            // Copy over trainer data
            auto trainer = playerWork->fields._saveData.fields.tr_battleData;

            Logger::log("tr_battleData max_length: %d\n", trainer->max_length);

            trainer->copyInto((DPData::TR_BATTLE_DATA*)save->trainers);

            newVersion = ModVersion::Release_001;
            break;
        }

        case Release_001: {
            // Save migration code goes here

            newVersion = Dev;
            break;
        }

        case Dev: {  // should never happen; return
            return;
        }
    }

    save->version = newVersion;
}
