#pragma once

static constexpr const char *DEBUG_SEXES[] = {
    "-",
    "Male",
    "Female",
    "Genderless",
};

static constexpr const char *DEBUG_SEXES_NO_NONE[] = {
    "Male",
    "Female",
    "Genderless",
};

static constexpr const char *DEBUG_SHINIES[] = {
    "-",
    "Non-shiny",
    "Shiny",
    "Square Shiny",
};

static constexpr const char *DEBUG_POKEMON_MATERIAL_FLOATS[] = {
    "_BaseColorAddEnable",
    "_BlendMode",
    "_BumpScale",
    "_ColorBaseU",
    "_ColorBaseV",
    "_ColorMapUvIndex",
    "_ConstantAlpha",
    "_ConstantColor0Val",
    "_ConstantColorSd0Val",
    "_ConstantColorValue",
    "_CullMode",
    "_Cutoff",
    "_DetailNormalMapScale",
    "_DiscardValue",
    "_DstBlend",
    "_EmissionMaskUse",
    "_EmissionMaskVal",
    "_EmissionScale",
    "_GlossMapScale",
    "_Glossiness",
    "_GlossyReflections",
    "_L1AddColor0Val",
    "_L1ConstantColor0Val",
    "_L1ConstantColorSd0Val",
    "_Layer1BaseU",
    "_Layer1BaseV",
    "_Layer1Enable",
    "_Layer1OverLerpValue",
    "_Layer1UvIndex",
    "_LayerCalcMulti",
    "_LightColorValue",
    "_MaskShadowPower",
    "_Metallic",
    "_Mode",
    "_OcclusionStrength",
    "_Parallax",
    "_PokemonStencil",
    "_RimColorValue",
    "_RimMaskEnable",
    "_RimPower",
    "_RimStrength",
    "_SmoothnessTextureChannel",
    "_SpecularHighlights",
    "_SpecularMaskEnable",
    "_SpecularPower",
    "_SpecularScale",
    "_SphereMapColorVal",
    "_SphereMaskEnable",
    "_SrcBlend",
    "_StencilComp",
    "_StencilOp",
    "_SwitchEmissionMaskTexUV",
    "_SwitchPriority",
    "_UVSec",
    "_ZTest",
    "_ZWrite",
};

static constexpr const char *DEBUG_POKEMON_MATERIAL_COLORS[] = {
    "_Color",
    "_ConstantColor",
    "_ConstantColor0",
    "_ConstantColorSd0",
    "_EmissionColor",
    "_FixMultiplierColor",
    "_L1AddColor0",
    "_L1ConstantColor0",
    "_L1ConstantColorSd0",
    "_RimColor",
    "_RimColorShadow",
    "_SpecularColor",
    "_SphereMapColor",
};

constexpr int DEBUG_SEX_COUNT = sizeof(DEBUG_SEXES) / sizeof(DEBUG_SEXES[0]);
constexpr int DEBUG_SEX_NO_NONE_COUNT = sizeof(DEBUG_SEXES_NO_NONE) / sizeof(DEBUG_SEXES_NO_NONE[0]);
constexpr int DEBUG_SHINY_COUNT = sizeof(DEBUG_SHINIES) / sizeof(DEBUG_SHINIES[0]);
constexpr int DEBUG_POKEMON_MATERIAL_FLOAT_COUNT = sizeof(DEBUG_POKEMON_MATERIAL_FLOATS) / sizeof(DEBUG_POKEMON_MATERIAL_FLOATS[0]);
constexpr int DEBUG_POKEMON_MATERIAL_COLOR_COUNT = sizeof(DEBUG_POKEMON_MATERIAL_COLORS) / sizeof(DEBUG_POKEMON_MATERIAL_COLORS[0]);