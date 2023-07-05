#pragma once

#include "externals/il2cpp-api.h"

#include "externals/EnvironmentSettings.h"
#include "externals/System/String.h"
#include "externals/UnityEngine/ScriptableObject.h"

namespace XLSXContent {
    struct ArenaInfo : ILClass<ArenaInfo> {
        struct SheetArenaData : ILClass<SheetArenaData> {
            struct Fields {
                System::String::Object* Caption;
                int32_t ArenaID;
                System::String::Object* GroundAssetBundleName;
                System::String::Object* SkyAssetBundleName;
                EnvironmentSettings::Object* RenderSettings;
                bool EnableDarkBall;
                uint8_t MinomuttiFormNo;
                int32_t SizennotikaraWazaNo;
                int32_t FootEffectID;
                int32_t AttachJoint;
                int32_t ReflectionResolution;
                int32_t ShadowResolution;
                bool IsIndoor;
            };
        };

        struct Fields : UnityEngine::ScriptableObject::Fields {
            XLSXContent::ArenaInfo::SheetArenaData::Array* Data;
        };
    };
}
