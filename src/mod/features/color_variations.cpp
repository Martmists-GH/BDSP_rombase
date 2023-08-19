#include "exlaunch.hpp"

#include "externals/ColorVariation.h"
#include "externals/Dpr/Battle/Logic/TRAINER_DATA.h"
#include "save/save.h"
#include "romdata/data/ColorSet.h"
#include "romdata/romdata.h"

#include "logger/logger.h"

RomData::ColorSet GetCustomColorSet()
{
    RomData::ColorSet set = {
        .skinFace =     getCustomSaveData()->colorVariations.skinFace[0],
        .skinMouth =    getCustomSaveData()->colorVariations.skinMouth[0],
        .eyes =         getCustomSaveData()->colorVariations.eyes[0],
        .eyebrows =     getCustomSaveData()->colorVariations.eyebrows[0],
        .skinBody =     getCustomSaveData()->colorVariations.skinBody[0],
        .hair =         getCustomSaveData()->colorVariations.hair[0],
    };

    return set;
}

ColorVariation::Property::Array* GetEditedProperty00(ColorVariation::Object* variation, int32_t index)
{
    system_load_typeinfo(0x2c09);

    ColorVariation::Property::Array* properties = variation->fields.Property00;

    for (uint64_t i=0; i<properties->max_length; i++)
    {
        if (i == 1) Logger::log("Changing bike colors maybe? i=%d to index %d\n", i, index);
        ColorVariation::Property::MaskColor::Array* colors = properties->m_Items[i].fields.colors;

        RomData::ColorSet set = {};
        if (index == 13)
            set = GetCustomColorSet();
        else
            set = GetColorSet(index);

        if (colors->max_length > (int32_t)RomData::ColorSetID::SKIN_FACE)
            colors->m_Items[(int32_t)RomData::ColorSetID::SKIN_FACE].fields.color.fields = set.skinFace.fields;
        if (colors->max_length > (int32_t)RomData::ColorSetID::SKIN_MOUTH)
            colors->m_Items[(int32_t)RomData::ColorSetID::SKIN_MOUTH].fields.color.fields = set.skinMouth.fields;
        if (colors->max_length > (int32_t)RomData::ColorSetID::EYES)
            colors->m_Items[(int32_t)RomData::ColorSetID::EYES].fields.color.fields = set.eyes.fields;
        if (colors->max_length > (int32_t)RomData::ColorSetID::EYEBROWS)
            colors->m_Items[(int32_t)RomData::ColorSetID::EYEBROWS].fields.color.fields = set.eyebrows.fields;
        if (colors->max_length > (int32_t)RomData::ColorSetID::SKIN_BODY)
            colors->m_Items[(int32_t)RomData::ColorSetID::SKIN_BODY].fields.color.fields = set.skinBody.fields;
        if (colors->max_length > (int32_t)RomData::ColorSetID::HAIR)
            colors->m_Items[(int32_t)RomData::ColorSetID::HAIR].fields.color.fields = set.hair.fields;
    }

    return properties;
}

HOOK_DEFINE_REPLACE(ColorVariation_LateUpdate) {
    static void Callback(ColorVariation::Object* __this) {
        system_load_typeinfo(0x2c09);
        ColorVariation::Property::Array* properties = GetEditedProperty00(__this, __this->fields.ColorIndex);

        if (__this->fields.propertyBlock != nullptr && properties->max_length > 0)
        {
            properties->m_Items[0].Update(__this->fields.propertyBlock);
        }
    }
};

HOOK_DEFINE_REPLACE(GetColorID) {
    static int32_t Callback() {
        return getCustomSaveData()->colorVariations.playerColorID[0];
    }
};

HOOK_DEFINE_REPLACE(SetColorID) {
    static void Callback(int32_t value) {
        getCustomSaveData()->colorVariations.playerColorID[0] = value;
    }
};

HOOK_DEFINE_INLINE(SetColorID_Inline) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        auto colorId = (int32_t)ctx->W[20];
        getCustomSaveData()->colorVariations.playerColorID[0] = colorId;
    }
};

HOOK_DEFINE_INLINE(SetColorID_TrainerParam_StoreCore) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        auto trainerData = (Dpr::Battle::Logic::TRAINER_DATA::Object*)ctx->X[1];
        trainerData->fields.colorID = getCustomSaveData()->colorVariations.playerColorID[0];
        trainerData->fields.trainerID = 0;

        ctx->X[1] = (uint64_t)trainerData;
    }
};

void exl_color_variations_main() {
    ColorVariation_LateUpdate::InstallAtOffset(0x018ecd90);

    GetColorID::InstallAtOffset(0x0203d3f0);
    GetColorID::InstallAtOffset(0x02cef820);

    SetColorID::InstallAtOffset(0x02cef870);
    SetColorID_Inline::InstallAtOffset(0x02cf3c7c);

    SetColorID_TrainerParam_StoreCore::InstallAtOffset(0x020387c4);

    using namespace exl::armv8::inst;
    using namespace exl::armv8::reg;
    exl::patch::CodePatcher p(0x020388ac);
    p.WriteInst(Nop());
}
