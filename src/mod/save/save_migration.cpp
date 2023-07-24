#include "save/save.h"
#include "externals/PlayerWork.h"
#include "logger/logger.h"

void migrate(CustomSaveData* save, PlayerWork::Object* playerWork) {
    ModVersion newVersion;

    switch (save->version) {
        case ModVersion::Vanilla: {
            // Copy over dex data
            auto& zukan = playerWork->fields._saveData.fields.zukanData.fields;
            auto& savedata = playerWork->fields._saveData.fields;

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
