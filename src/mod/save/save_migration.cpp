#include "externals/PlayerWork.h"
#include "romdata/romdata.h"
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

    // Set custom player color to the one in vanilla save
    auto set = GetColorSet(0);
    save->colorVariations.fSkinFace[0] =  { .fields = { set.fSkinFace.fields.r, set.fSkinFace.fields.g, set.fSkinFace.fields.b, set.fSkinFace.fields.a } };
    save->colorVariations.fSkinMouth[0] = { .fields = { set.fSkinMouth.fields.r, set.fSkinMouth.fields.g, set.fSkinMouth.fields.b, set.fSkinMouth.fields.a } };
    save->colorVariations.fEyes[0] =      { .fields = { set.fEyes.fields.r, set.fEyes.fields.g, set.fEyes.fields.b, set.fEyes.fields.a } };
    save->colorVariations.fEyebrows[0] =  { .fields = { set.fEyebrows.fields.r, set.fEyebrows.fields.g, set.fEyebrows.fields.b, set.fEyebrows.fields.a } };
    save->colorVariations.fSkinBody[0] =  { .fields = { set.fSkinBody.fields.r, set.fSkinBody.fields.g, set.fSkinBody.fields.b, set.fSkinBody.fields.a } };
    save->colorVariations.fHair[0] =      { .fields = { set.fHair.fields.r, set.fHair.fields.g, set.fHair.fields.b, set.fHair.fields.a } };

    save->colorVariations.bSkinFace[0] =  { .fields = { set.bSkinFace.fields.r, set.bSkinFace.fields.g, set.bSkinFace.fields.b, set.bSkinFace.fields.a } };
    save->colorVariations.bHairExtra[0] = { .fields = { set.bHairExtra.fields.r, set.bHairExtra.fields.g, set.bHairExtra.fields.b, set.bHairExtra.fields.a } };
    save->colorVariations.bEyeLeft[0] =   { .fields = { set.bEyeLeft.fields.r, set.bEyeLeft.fields.g, set.bEyeLeft.fields.b, set.bEyeLeft.fields.a } };
    save->colorVariations.bEyeRight[0] =  { .fields = { set.bEyeRight.fields.r, set.bEyeRight.fields.g, set.bEyeRight.fields.b, set.bEyeRight.fields.a } };
    save->colorVariations.bSkinBody[0] =  { .fields = { set.bSkinBody.fields.r, set.bSkinBody.fields.g, set.bSkinBody.fields.b, set.bSkinBody.fields.a } };
    save->colorVariations.bHair[0] =      { .fields = { set.bHair.fields.r, set.bHair.fields.g, set.bHair.fields.b, set.bHair.fields.a } };

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
