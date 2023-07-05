#pragma once

#include "externals/il2cpp-api.h"

#include "externals/System/Primitives.h"
#include "externals/UnityEngine/Color.h"
#include "externals/UnityEngine/ScriptableObject.h"

namespace XLSXContent {
    struct WaterSettings : ILClass<WaterSettings> {
        struct SheetSettings : ILClass<SheetSettings> {
            struct Fields {
                System::Int32_array* ZoneIDs;
                float PlaneElevation;
                UnityEngine::Color::Object Color;
                float UpScale;
                float Attenuation;
                float MaxDensity;
                float Reflectivity;
                float FresnelPower;
                float SpecularIntensity;
                float SpecularCosinePower;
            };
        };

        struct Fields : UnityEngine::ScriptableObject::Fields {
            XLSXContent::WaterSettings::SheetSettings::Array* Settings;
        };
    };
}
