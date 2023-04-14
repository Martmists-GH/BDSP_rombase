#pragma once

#include "externals/il2cpp-api.h"
#include "externals/UnityEngine/UI/Graphic.h"
#include "externals/UnityEngine/Vector3.h"

namespace UnityEngine::UI {
    struct MaskableGraphic : ILClass<MaskableGraphic> {
        struct Fields : UnityEngine::UI::Graphic::Fields {
            bool m_ShouldRecalculateStencil;
            void* m_MaskMaterial;
            void* m_ParentMask;
            bool m_Maskable;
            bool m_IsMaskingGraphic;
            bool m_IncludeForMasking;
            void* m_OnCullStateChanged;
            bool m_ShouldRecalculate;
            int32_t m_StencilValue;
            UnityEngine::Vector3::Array* m_Corners;
        };
    };
}
