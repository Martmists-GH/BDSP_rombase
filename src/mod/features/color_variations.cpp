#include "exlaunch.hpp"

#include "externals/ColorVariation.h"
#include "romdata/data/ColorSet.h"
#include "romdata/romdata.h"

#include "logger/logger.h"

RomData::ColorSet GetCustomColorSet()
{
    RomData::ColorSet set = { // TODO: Get from save
        .skinFace =     { .fields = { 0.9490196, 0.76862746, 0.6627451, 1 } },    // White skin
        .skinMouth =    { .fields = { 0.9490196, 0.76862746, 0.6627451, 1 } },    // White skin
        .eyes =         { .fields = { 0.72156864, 0.79607844, 0.9019608, 1 } },   // Baby blue
        .eyebrows =     { .fields = { 0.83921569, 0.87450982, 0.86862746, 1 } },  // ???
        .skinBody =     { .fields = { 0.9490196, 0.76862746, 0.6627451, 1 } },    // White skin
        .hair =         { .fields = { 0.83921569, 0.87450982, 0.86862746, 1 } },  // ???
    };

    return set;
}

ColorVariation::Property::Array* GetEditedProperty00(ColorVariation::Object* variation, int32_t index)
{
    system_load_typeinfo(0x2c09);

    ColorVariation::Property::Array* properties = variation->fields.Property00;

    if (properties->max_length > 0)
    {
        ColorVariation::Property::MaskColor::Array* colors = properties->m_Items[0].fields.colors;

        RomData::ColorSet set = {};
        if (index == 255)
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

void exl_color_variations_main() {
    ColorVariation_LateUpdate::InstallAtOffset(0x018ecd90);
}
