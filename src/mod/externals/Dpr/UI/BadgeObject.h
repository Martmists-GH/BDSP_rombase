#pragma once

#include "externals/il2cpp-api.h"

#include "externals/UnityEngine/GameObject.h"
#include "externals/UnityEngine/Transform.h"
#include "externals/Effect/EffectInstance.h"

namespace Dpr::UI {
    struct BadgeObject : ILClass<BadgeObject> {
        struct Fields {
            int32_t id;
            UnityEngine::GameObject::Object* gameObject;
            UnityEngine::Transform::Object* nodeTransform;
            int32_t currentBadgeCondition;
            Effect::EffectInstance::Object* conditionEffect;
            int32_t polishedCount;
            int32_t needCleanupCount;
            uint8_t cleanupValue;
            bool _IsVisible_k__BackingField;
            bool _IsAutoRotate_k__BackingField;
        };
    };
}