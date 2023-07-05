#pragma once

#include "externals/il2cpp-api.h"

#include "externals/System/Primitives.h"
#include "externals/UnityEngine/Color.h"
#include "externals/UnityEngine/ScriptableObject.h"

struct PokemonWalkingDatas : ILClass<PokemonWalkingDatas> {
    struct Preset : ILClass<Preset> {
        struct Fields {
            float scale;
            float radius;
            float falloffNear;
            float falloffFar;
            float walkSpeed;
            float runSpeed;
            float walkThreshold;
            float runThreshold;
            float eraseThreshold;
        };
    };

    struct Parameters : ILClass<Parameters> {
        struct Fields {
            int32_t index;
            int32_t size;
            float scale;
            float radius;
            float falloffNear;
            float falloffFar;
            float walkSpeed;
            float runSpeed;
            float walkThreshold;
            float runThreshold;
            float eraseThreshold;
            bool footEffectEnable;
        };
    };

    struct Fields : UnityEngine::ScriptableObject::Fields {
        PokemonWalkingDatas::Preset::Object* presetS;
        PokemonWalkingDatas::Preset::Object* presetM;
        PokemonWalkingDatas::Preset::Object* presetL;
        PokemonWalkingDatas::Preset::Object* presetLL;
        PokemonWalkingDatas::Parameters::Array* list;
        int32_t currentIndex;
        bool debugBoundsEnable;
    };
};
