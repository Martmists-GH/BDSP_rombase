#pragma once

#include "externals/il2cpp-api.h"

#include "externals/PokemonWalkingDatas.h"
#include "externals/ScriptableObjectFormat/PokemonData.h"
#include "externals/System/String.h"
#include "externals/UnityEngine/ScriptableObject.h"
#include "externals/UnityEngine/Vector3.h"

namespace ScriptableObjectFormat {
    struct PokemonData : ILClass<PokemonData> {
        struct PersonalData : ILClass<PersonalData> {
            struct Fields {
                System::String::Object* ID;
                int32_t Index;
                System::String::Object* Name;
                int32_t Variation;
                System::String::Object* Form;
                System::String::Object* Attribute1;
                System::String::Object* Attribute2;
                System::String::Object* Class;
            };
        };

        struct ModelData : ILClass<ModelData> {
            struct Fields {
                System::String::Object* ID;
                int32_t Index;
                System::String::Object* Name;
                int32_t FormIndex;
                System::String::Object* Form;
                System::String::Object* Symbol;
                System::String::Object* AssetBundleName;
                System::String::Object* Variation;
                double Scale1;
                double Scale2;
                UnityEngine::Vector3::Object Offset;
                int32_t ModelHeight;
            };
        };

        struct Fields : UnityEngine::ScriptableObject::Fields {
            ScriptableObjectFormat::PokemonData::PersonalData::Array* Personal;
            ScriptableObjectFormat::PokemonData::ModelData::Array* Model;
            PokemonWalkingDatas::Object* WalkingData;
        };
    };
}
