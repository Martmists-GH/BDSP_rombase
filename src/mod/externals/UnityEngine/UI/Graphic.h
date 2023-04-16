#pragma once

#include "externals/il2cpp-api.h"
#include "externals/UnityEngine/EventSystems/UIBehaviour.h"
#include "externals/UnityEngine/Color.h"
#include "externals/UnityEngine/RectTransform.h"
#include "externals/UnityEngine/Vector2.h"

namespace UnityEngine::UI {
    struct Graphic : ILClass<Graphic> {
        struct Fields : UnityEngine::EventSystems::UIBehaviour::Fields {
            void* m_Material;
            UnityEngine::Color::Object m_Color;
            bool m_SkipLayoutUpdate;
            bool m_SkipMaterialUpdate;
            bool m_RaycastTarget;
            UnityEngine::RectTransform::Object m_RectTransform;
            void* m_CanvasRenderer;
            void* m_Canvas;
            bool m_VertsDirty;
            bool m_MaterialDirty;
            void* m_OnDirtyLayoutCallback;
            void* m_OnDirtyVertsCallback;
            void* m_OnDirtyMaterialCallback;
            void* m_CachedMesh;
            UnityEngine::Vector2::Array* m_CachedUvs;
            void* m_ColorTweenRunner;
            bool _useLegacyMeshGeneration_k__BackingField;
        };
    };
}
