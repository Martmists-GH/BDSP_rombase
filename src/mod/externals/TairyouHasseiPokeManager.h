#pragma once

#include "externals/il2cpp-api.h"

#include "externals/UnityEngine/GameObject.h"

struct TairyouHasseiPokeManager : ILClass<TairyouHasseiPokeManager> {
    struct Fields {
        void* _objects; // TairyouHasseiPoke_array*
        void* _operation; // SmartPoint_AssetAssistant_AssetRequestOperation_o*
        float _defaultScale;
        uint8_t _loadingState;
        UnityEngine::GameObject::Object* _parent;
        int32_t _targetZone;
    };
};
