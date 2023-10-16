#include "exlaunch.hpp"

#include "externals/BattleCharacterEntity.h"
#include "externals/ColorVariation.h"
#include "externals/Dpr/Battle/Logic/TRAINER_DATA.h"
#include "externals/Dpr/Battle/View/TrainerSimpleParam.h"
#include "externals/FieldCharacterEntity.h"
#include "externals/UnityEngine/Component.h"
#include "externals/UnityEngine/GameObject.h"
#include "externals/UnityEngine/MaterialPropertyBlock.h"
#include "save/save.h"
#include "romdata/data/ColorSet.h"
#include "romdata/romdata.h"

#include "logger/logger.h"

RomData::ColorSet GetCustomColorSet()
{
    RomData::ColorSet set = {
        .fieldSkinFace = {
            getCustomSaveData()->colorVariations.fSkinFace[0].fields.r,
            getCustomSaveData()->colorVariations.fSkinFace[0].fields.g,
            getCustomSaveData()->colorVariations.fSkinFace[0].fields.b,
            getCustomSaveData()->colorVariations.fSkinFace[0].fields.a,
        },
        .fieldSkinMouth = {
            getCustomSaveData()->colorVariations.fSkinMouth[0].fields.r,
            getCustomSaveData()->colorVariations.fSkinMouth[0].fields.g,
            getCustomSaveData()->colorVariations.fSkinMouth[0].fields.b,
            getCustomSaveData()->colorVariations.fSkinMouth[0].fields.a,
        },
        .fieldEyes = {
            getCustomSaveData()->colorVariations.fEyes[0].fields.r,
            getCustomSaveData()->colorVariations.fEyes[0].fields.g,
            getCustomSaveData()->colorVariations.fEyes[0].fields.b,
            getCustomSaveData()->colorVariations.fEyes[0].fields.a,
        },
        .fieldEyebrows = {
            getCustomSaveData()->colorVariations.fEyebrows[0].fields.r,
            getCustomSaveData()->colorVariations.fEyebrows[0].fields.g,
            getCustomSaveData()->colorVariations.fEyebrows[0].fields.b,
            getCustomSaveData()->colorVariations.fEyebrows[0].fields.a,
        },
        .fieldSkinBody = {
            getCustomSaveData()->colorVariations.fSkinBody[0].fields.r,
            getCustomSaveData()->colorVariations.fSkinBody[0].fields.g,
            getCustomSaveData()->colorVariations.fSkinBody[0].fields.b,
            getCustomSaveData()->colorVariations.fSkinBody[0].fields.a,
        },
        .fieldHair = {
            getCustomSaveData()->colorVariations.fHair[0].fields.r,
            getCustomSaveData()->colorVariations.fHair[0].fields.g,
            getCustomSaveData()->colorVariations.fHair[0].fields.b,
            getCustomSaveData()->colorVariations.fHair[0].fields.a,
        },

        .battleSkinFace = {
            getCustomSaveData()->colorVariations.bSkinFace[0].fields.r,
            getCustomSaveData()->colorVariations.bSkinFace[0].fields.g,
            getCustomSaveData()->colorVariations.bSkinFace[0].fields.b,
            getCustomSaveData()->colorVariations.bSkinFace[0].fields.a,
        },
        .battleHairExtra = {
            getCustomSaveData()->colorVariations.bHairExtra[0].fields.r,
            getCustomSaveData()->colorVariations.bHairExtra[0].fields.g,
            getCustomSaveData()->colorVariations.bHairExtra[0].fields.b,
            getCustomSaveData()->colorVariations.bHairExtra[0].fields.a,
        },
        .battleEyeLeft = {
            getCustomSaveData()->colorVariations.bEyeLeft[0].fields.r,
            getCustomSaveData()->colorVariations.bEyeLeft[0].fields.g,
            getCustomSaveData()->colorVariations.bEyeLeft[0].fields.b,
            getCustomSaveData()->colorVariations.bEyeLeft[0].fields.a,
        },
        .battleEyeRight = {
            getCustomSaveData()->colorVariations.bEyeRight[0].fields.r,
            getCustomSaveData()->colorVariations.bEyeRight[0].fields.g,
            getCustomSaveData()->colorVariations.bEyeRight[0].fields.b,
            getCustomSaveData()->colorVariations.bEyeRight[0].fields.a,
        },
        .battleSkinBody = {
            getCustomSaveData()->colorVariations.bSkinBody[0].fields.r,
            getCustomSaveData()->colorVariations.bSkinBody[0].fields.g,
            getCustomSaveData()->colorVariations.bSkinBody[0].fields.b,
            getCustomSaveData()->colorVariations.bSkinBody[0].fields.a,
        },
        .battleHair = {
            getCustomSaveData()->colorVariations.bHair[0].fields.r,
            getCustomSaveData()->colorVariations.bHair[0].fields.g,
            getCustomSaveData()->colorVariations.bHair[0].fields.b,
            getCustomSaveData()->colorVariations.bHair[0].fields.a,
        },
    };

    return set;
}

ColorVariation::Property::Array* GetEditedProperty00(ColorVariation::Object* variation, int32_t index)
{
    system_load_typeinfo(0x2c09);
    system_load_typeinfo(0x9c60);

    auto component = variation->cast<UnityEngine::Component>();
    auto gameObject = component->get_gameObject()->instance();

    ColorVariation::Property::Array* properties = variation->fields.Property00;

    for (uint64_t i=0; i<properties->max_length; i++)
    {
        ColorVariation::Property::MaskColor::Array* colors = properties->m_Items[i].fields.colors;

        RomData::ColorSet set = {};
        if (index == -1)
            set = GetCustomColorSet();
        else
            set = GetColorSet(index);

        if (gameObject->GetComponent(UnityEngine::Component::Method$$BattleCharacterEntity$$GetComponent) != nullptr)
        {
            if (colors->max_length > (int32_t)RomData::ColorSetID::B_SKIN_FACE)
                colors->m_Items[(int32_t)RomData::ColorSetID::B_SKIN_FACE].fields.color.fields = { set.battleSkinFace.r, set.battleSkinFace.g, set.battleSkinFace.b, set.battleSkinFace.a };
            if (colors->max_length > (int32_t)RomData::ColorSetID::B_HAIR_EXTRA)
                colors->m_Items[(int32_t)RomData::ColorSetID::B_HAIR_EXTRA].fields.color.fields = { set.battleHairExtra.r, set.battleHairExtra.g, set.battleHairExtra.b, set.battleHairExtra.a };
            if (colors->max_length > (int32_t)RomData::ColorSetID::B_EYE_LEFT)
                colors->m_Items[(int32_t)RomData::ColorSetID::B_EYE_LEFT].fields.color.fields = { set.battleEyeLeft.r, set.battleEyeLeft.g, set.battleEyeLeft.b, set.battleEyeLeft.a };
            if (colors->max_length > (int32_t)RomData::ColorSetID::B_EYE_RIGHT)
                colors->m_Items[(int32_t)RomData::ColorSetID::B_EYE_RIGHT].fields.color.fields = { set.battleEyeRight.r, set.battleEyeRight.g, set.battleEyeRight.b, set.battleEyeRight.a };
            if (colors->max_length > (int32_t)RomData::ColorSetID::B_SKIN_BODY)
                colors->m_Items[(int32_t)RomData::ColorSetID::B_SKIN_BODY].fields.color.fields = { set.battleSkinBody.r, set.battleSkinBody.g, set.battleSkinBody.b, set.battleSkinBody.a };
            if (colors->max_length > (int32_t)RomData::ColorSetID::B_HAIR)
                colors->m_Items[(int32_t)RomData::ColorSetID::B_HAIR].fields.color.fields = { set.battleHair.r, set.battleHair.g, set.battleHair.b, set.battleHair.a };
        }

        if (gameObject->GetComponent(UnityEngine::Component::Method$$FieldCharacterEntity$$GetComponent) != nullptr)
        {
            if (colors->max_length > (int32_t)RomData::ColorSetID::F_SKIN_FACE)
                colors->m_Items[(int32_t)RomData::ColorSetID::F_SKIN_FACE].fields.color.fields = { set.fieldSkinFace.r, set.fieldSkinFace.g, set.fieldSkinFace.b, set.fieldSkinFace.a };
            if (colors->max_length > (int32_t)RomData::ColorSetID::F_SKIN_MOUTH)
                colors->m_Items[(int32_t)RomData::ColorSetID::F_SKIN_MOUTH].fields.color.fields = { set.fieldSkinMouth.r, set.fieldSkinMouth.g, set.fieldSkinMouth.b, set.fieldSkinMouth.a };
            if (colors->max_length > (int32_t)RomData::ColorSetID::F_EYES)
                colors->m_Items[(int32_t)RomData::ColorSetID::F_EYES].fields.color.fields = { set.fieldEyes.r, set.fieldEyes.g, set.fieldEyes.b, set.fieldEyes.a };
            if (colors->max_length > (int32_t)RomData::ColorSetID::F_EYEBROWS)
                colors->m_Items[(int32_t)RomData::ColorSetID::F_EYEBROWS].fields.color.fields = { set.fieldEyebrows.r, set.fieldEyebrows.g, set.fieldEyebrows.b, set.fieldEyebrows.a };
            if (colors->max_length > (int32_t)RomData::ColorSetID::F_SKIN_BODY)
                colors->m_Items[(int32_t)RomData::ColorSetID::F_SKIN_BODY].fields.color.fields = { set.fieldSkinBody.r, set.fieldSkinBody.g, set.fieldSkinBody.b, set.fieldSkinBody.a };
            if (colors->max_length > (int32_t)RomData::ColorSetID::F_HAIR)
                colors->m_Items[(int32_t)RomData::ColorSetID::F_HAIR].fields.color.fields = { set.fieldHair.r, set.fieldHair.g, set.fieldHair.b, set.fieldHair.a };
        }
    }

    return properties;
}

HOOK_DEFINE_REPLACE(ColorVariation_LateUpdate) {
    static void Callback(ColorVariation::Object* __this) {
        system_load_typeinfo(0x2c09);
        ColorVariation::Property::Array* properties = GetEditedProperty00(__this, __this->fields.ColorIndex);

        if (__this->fields.propertyBlock != nullptr)
        {
            for (uint64_t i=0; i<properties->max_length; i++)
            {
                properties->m_Items[i].Update(__this->fields.propertyBlock);
            }
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

HOOK_DEFINE_INLINE(CardModelViewController_LoadModels) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        auto trainerParam = (Dpr::Battle::View::TrainerSimpleParam::Object*)ctx->X[1];
        auto isContest = (bool)ctx->W[2];
        auto battleCharacterEntity = (BattleCharacterEntity*)ctx->X[20];

        int32_t colorID = getCustomSaveData()->colorVariations.playerColorID[0];
        trainerParam->fields.colorID = colorID;

        battleCharacterEntity->Initialize(trainerParam, isContest);
    }
};

void exl_color_variations_main() {
    ColorVariation_LateUpdate::InstallAtOffset(0x018ecd90);

    GetColorID::InstallAtOffset(0x0203d3f0);
    GetColorID::InstallAtOffset(0x02cef820);

    SetColorID::InstallAtOffset(0x02cef870);
    SetColorID_Inline::InstallAtOffset(0x02cf3c7c);

    SetColorID_TrainerParam_StoreCore::InstallAtOffset(0x020387c4);

    CardModelViewController_LoadModels::InstallAtOffset(0x01a315a4);

    using namespace exl::armv8::inst;
    using namespace exl::armv8::reg;
    exl::patch::CodePatcher p(0x020388ac);
    p.WriteInst(Nop());
}
