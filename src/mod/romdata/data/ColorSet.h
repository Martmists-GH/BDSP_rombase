#pragma once

#include "externals/il2cpp-api.h"

#include "externals/UnityEngine/Color.h"

namespace RomData
{
    struct ColorSet
    {
        // Field
        UnityEngine::Color::Object skinFace;
        UnityEngine::Color::Object skinMouth;
        UnityEngine::Color::Object eyes;
        UnityEngine::Color::Object eyebrows;
        UnityEngine::Color::Object skinBody;
        UnityEngine::Color::Object hair;

        // Battle
        // TODO
    };

    enum class ColorSetID : int32_t {
        SKIN_FACE,
        SKIN_MOUTH,
        EYES,
        EYEBROWS,
        SKIN_BODY,
        HAIR
    };
}
