#pragma once

#include "externals/il2cpp-api.h"

#include "externals/UnityEngine/Texture.h"

namespace UnityEngine {
    struct Texture2D : ILStruct<Texture2D> {
        struct Fields : UnityEngine::Texture::Fields {
        };
    };
}
