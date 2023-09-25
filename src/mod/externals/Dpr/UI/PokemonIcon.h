#pragma once

#include "externals/il2cpp-api.h"

#include "externals/UnityEngine/MonoBehaviour.h"
#include "externals/UnityEngine/UI/Image.h"

namespace Dpr::UI {
    struct PokemonIcon : ILClass<PokemonIcon> {
        struct Fields : UnityEngine::MonoBehaviour::Fields {
            UnityEngine::UI::Image::Object* _imageMonsIcon;
            UnityEngine::UI::Image::Object* _imageItemIcon;
            UnityEngine::UI::Image::Object* _imageBallDecoIcon;
        };
    };
}
