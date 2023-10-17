#include "save/save.h"
#include "save/migration/save_migration.h"

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
