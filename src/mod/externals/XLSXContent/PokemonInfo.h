#pragma once

#include "externals/il2cpp-api.h"

#include "externals/System/Primitives.h"
#include "externals/System/String.h"
#include "externals/UnityEngine/ScriptableObject.h"
#include "externals/UnityEngine/Vector2.h"
#include "externals/UnityEngine/Vector3.h"

namespace XLSXContent {
    struct PokemonInfo : ILClass<PokemonInfo> {
        struct SheetCatalog : ILClass<SheetCatalog> {
            struct Fields {
                int32_t UniqueID;
                int32_t No;
                int32_t SinnohNo;
                int32_t MonsNo;
                int32_t FormNo;
                uint8_t Sex;
                bool Rare;
                System::String::Object* AssetBundleName;
                float BattleScale;
                float ContestScale;
                int32_t ContestSize;
                float FieldScale;
                float FieldChikaScale;
                float StatueScale;
                float FieldWalkingScale;
                float FieldFureaiScale;
                float MenuScale;
                System::String::Object* ModelMotion;
                UnityEngine::Vector3::Object ModelOffset;
                UnityEngine::Vector3::Object ModelRotationAngle;
                float DistributionScale;
                System::String::Object* DistributionModelMotion;
                UnityEngine::Vector3::Object DistributionModelOffset;
                UnityEngine::Vector3::Object DistributionModelRotationAngle;
                float VoiceScale;
                System::String::Object* VoiceModelMotion;
                UnityEngine::Vector3::Object VoiceModelOffset;
                UnityEngine::Vector3::Object VoiceModelRotationAngle;
                UnityEngine::Vector3::Object CenterPointOffset;
                UnityEngine::Vector2::Object RotationLimitAngle;
                float StatusScale;
                System::String::Object* StatusModelMotion;
                UnityEngine::Vector3::Object StatusModelOffset;
                UnityEngine::Vector3::Object StatusModelRotationAngle;
                float BoxScale;
                System::String::Object* BoxModelMotion;
                UnityEngine::Vector3::Object BoxModelOffset;
                UnityEngine::Vector3::Object BoxModelRotationAngle;
                float CompareScale;
                System::String::Object* CompareModelMotion;
                UnityEngine::Vector3::Object CompareModelOffset;
                UnityEngine::Vector3::Object CompareModelRotationAngle;
                float BrakeStart;
                float BrakeEnd;
                float WalkSpeed;
                float RunSpeed;
                float WalkStart;
                float RunStart;
                float BodySize;
                float AppearLimit;
                int32_t MoveType;
                bool GroundEffect;
                bool Waitmoving;
                int32_t BattleAjustHeight;
            };
        };

        struct SheetTrearuki : ILClass<SheetTrearuki> {
            struct Fields {
                bool Enable;
                System::Int32_array* AnimeIndex;
                void* AnimeDuration; // System::Single_array*
            };
        };

        struct Fields : UnityEngine::ScriptableObject::Fields {
            XLSXContent::PokemonInfo::SheetCatalog::Array* Catalog;
            XLSXContent::PokemonInfo::SheetTrearuki::Array* Trearuki;
        };

        static_assert(offsetof(SheetCatalog::Fields, MenuScale) == 0x40);
    };
}
