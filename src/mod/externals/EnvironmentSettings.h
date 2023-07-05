#pragma once

#include "externals/il2cpp-api.h"

#include "externals/UnityEngine/Color.h"
#include "externals/UnityEngine/ScriptableObject.h"
#include "externals/UnityEngine/Texture2D.h"

struct EnvironmentSettings : ILClass<EnvironmentSettings> {
    struct Parameters : ILClass<Parameters> {
        struct Fields {
            float LightYaw;
            float LightPitch;
            UnityEngine::Color::Object LightColor;
            float LightIntensity;
            UnityEngine::Color::Object ReflectorColor;
            UnityEngine::Color::Object CharacterLightColor;
            float CharacterLightIntensity;
            UnityEngine::Color::Object CharacterReflectorColor;
            UnityEngine::Color::Object PokeLightColor;
            float PokeLightIntensity;
            UnityEngine::Color::Object PokeReflectorColor;
            bool ColorGradingEnable;
            UnityEngine::Texture2D::Object* ColorGradingLookup;
            float ColorGradingInfluence;
            UnityEngine::Texture2D::Object* NexColorGradingLookup;
            float ColorGradingBlendWeight;
            float VertexColorScale;
            float BloomThreshold;
            bool FogEnable;
            float FogStart;
            float FogEnd;
            float FogDensity;
            UnityEngine::Color::Object FogNearColor;
            UnityEngine::Color::Object FogFarColor;
            UnityEngine::Color::Object ShadowColor;
            float CloudShadowScale;
            float Blurry;
        };
    };

    struct Fields : UnityEngine::ScriptableObject::Fields {
        bool CloudShadowEnable;
        EnvironmentSettings::Parameters::Object* Morning;
        EnvironmentSettings::Parameters::Object* Daytime;
        EnvironmentSettings::Parameters::Object* Evening;
        EnvironmentSettings::Parameters::Object* Night;
        EnvironmentSettings::Parameters::Object* Midnight;
        bool FixedTime;
        int32_t FogMode;
        EnvironmentSettings::Parameters::Object* Temporary;
    };
};
