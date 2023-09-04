#pragma once

#include "externals/il2cpp-api.h"
#include "externals/UnityEngine/Vector3.h"
#include "externals/Dpr/Battle/View/BtlvBehaviour.h"

namespace Dpr::Battle::View::Objects {
    struct BattleObject : ILClass<BattleObject> {
        struct Fields : Dpr::Battle::View::BtlvBehaviour::Fields {
            UnityEngine::Vector3::Object m_translation;
            UnityEngine::Vector3::Object m_translationOffset;
            UnityEngine::Vector3::Object m_translationGOffset;
            UnityEngine::Vector3::Object m_scale;
            UnityEngine::Vector3::Object m_scaleOffset;
            UnityEngine::Vector3::Object m_beforeTranslation;
            UnityEngine::Vector3::Object m_nodeScaleTranslation;
            UnityEngine::Vector3::Object m_nodeRotateTranslation;
            UnityEngine::Vector3::Object m_rotVec;
            UnityEngine::Vector3::Object m_rotVecOffset;
            bool m_isVisible;
            bool m_isSubVisible;
            bool m_suspendUpdate;
            bool m_autoRotate;
            bool m_isVisibleCameraHit;
            bool m_isSubVisibleCameraHit;
            float _animSpeed;
            int32_t _Index_k__BackingField;
            bool _IsEnable_k__BackingField;
            int32_t _Priority_k__BackingField;
            UnityEngine::Vector3::Object _NodeScaleTranslation_k__BackingField;
            UnityEngine::Vector3::Object _NodeRotateTranslation_k__BackingField;
        };
    };
}