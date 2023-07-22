#pragma once

#include "externals/il2cpp-api.h"

#include "externals/Dpr/EvScript/EvDataManager.h"
#include "externals/UnityEngine/MonoBehaviour.h"
#include "externals/UnityEngine/Transform.h"
#include "externals/UnityEngine/Vector2Int.h"
#include "externals/UnityEngine/Vector3.h"

struct BaseEntity : ILClass<BaseEntity> {
    struct Fields : UnityEngine::MonoBehaviour::Fields {
        System::String::Object* _enityName;
        bool _alreadyRegistered;
        float yawAngle;
        UnityEngine::Vector3::Object worldPosition;
        float savedYawAngle;
        UnityEngine::Vector3::Object savedPosition;
        UnityEngine::Vector3::Object _beforePosition_k__BackingField;
        UnityEngine::Transform::Object* _cacheTransform;
        int32_t _currentSequence_k__BackingField;
        int32_t _nextSequence_k__BackingField;
        float _sequenceTime_k__BackingField;
        BaseEntity::Object* _target_k__BackingField;
    };
};
