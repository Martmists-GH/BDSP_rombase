#include "romdata/romdata.h"
#include "save/migration/save_migration.h"
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

    // Set custom player color to the default Lucas/Dawn one
    auto set = GetColorSet(0);
    save->colorVariations.fSkinFace[0] =  { .fields = { set.fieldSkinFace.r, set.fieldSkinFace.g, set.fieldSkinFace.b, set.fieldSkinFace.a } };
    save->colorVariations.fSkinMouth[0] = { .fields = { set.fieldSkinMouth.r, set.fieldSkinMouth.g, set.fieldSkinMouth.b, set.fieldSkinMouth.a } };
    save->colorVariations.fEyes[0] =      { .fields = { set.fieldEyes.r, set.fieldEyes.g, set.fieldEyes.b, set.fieldEyes.a } };
    save->colorVariations.fEyebrows[0] =  { .fields = { set.fieldEyebrows.r, set.fieldEyebrows.g, set.fieldEyebrows.b, set.fieldEyebrows.a } };
    save->colorVariations.fSkinBody[0] =  { .fields = { set.fieldSkinBody.r, set.fieldSkinBody.g, set.fieldSkinBody.b, set.fieldSkinBody.a } };
    save->colorVariations.fHair[0] =      { .fields = { set.fieldHair.r, set.fieldHair.g, set.fieldHair.b, set.fieldHair.a } };

    save->colorVariations.bSkinFace[0] =  { .fields = { set.battleSkinFace.r, set.battleSkinFace.g, set.battleSkinFace.b, set.battleSkinFace.a } };
    save->colorVariations.bHairExtra[0] = { .fields = { set.battleHairExtra.r, set.battleHairExtra.g, set.battleHairExtra.b, set.battleHairExtra.a } };
    save->colorVariations.bEyeLeft[0] =   { .fields = { set.battleEyeLeft.r, set.battleEyeLeft.g, set.battleEyeLeft.b, set.battleEyeLeft.a } };
    save->colorVariations.bEyeRight[0] =  { .fields = { set.battleEyeRight.r, set.battleEyeRight.g, set.battleEyeRight.b, set.battleEyeRight.a } };
    save->colorVariations.bSkinBody[0] =  { .fields = { set.battleSkinBody.r, set.battleSkinBody.g, set.battleSkinBody.b, set.battleSkinBody.a } };
    save->colorVariations.bHair[0] =      { .fields = { set.battleHair.r, set.battleHair.g, set.battleHair.b, set.battleHair.a } };

    // Set amount of boxes unlocked to 40 for now
    playerWork->fields._saveData.fields.boxData.fields.trayMax = 40;

    Logger::log("Migration from Vanilla done!\n");
}