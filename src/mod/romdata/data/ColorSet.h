#pragma once

#include "externals/il2cpp-api.h"

#include "externals/UnityEngine/Color.h"

namespace RomData
{
    struct ColorSet
    {
        // Field
        UnityEngine::Color::Object fSkinFace;
        UnityEngine::Color::Object fSkinMouth;
        UnityEngine::Color::Object fEyes;
        UnityEngine::Color::Object fEyebrows;
        UnityEngine::Color::Object fSkinBody;
        UnityEngine::Color::Object fHair;

        // Battle
        UnityEngine::Color::Object bSkinFace;
        UnityEngine::Color::Object bHairExtra;
        UnityEngine::Color::Object bEyeLeft;
        UnityEngine::Color::Object bEyeRight;
        UnityEngine::Color::Object bSkinBody;
        UnityEngine::Color::Object bHair;
    };

    enum class ColorSetID : int32_t {
        F_SKIN_FACE = 0,
        F_SKIN_MOUTH = 1,
        F_EYES = 2,
        F_EYEBROWS = 3,
        F_SKIN_BODY = 4,
        F_HAIR = 5,

        B_SKIN_FACE = 0,
        B_HAIR_EXTRA = 1,
        B_EYE_LEFT = 2,
        B_EYE_RIGHT = 3,
        B_SKIN_BODY = 4,
        B_HAIR = 5,
    };
}
