#pragma once

#include "externals/il2cpp-api.h"
#include "externals/TMPro/TMP_Text.h"
#include "externals/UnityEngine/Coroutine.h"
#include "externals/UnityEngine/Rect.h"

namespace TMPro {
    struct TextMeshProUGUI : ILClass<TextMeshProUGUI, 0x04c59018> {
        struct Fields : TMPro::TMP_Text::Fields {
            bool m_hasFontAssetChanged;
            void* m_subTextObjects; //TMPro_TMP_SubMeshUI_array*
            float m_previousLossyScaleY;
            void* m_RectTransformCorners; //UnityEngine_Vector3_array*
            void* m_canvasRenderer; //UnityEngine_CanvasRenderer_o*
            void* m_canvas; //UnityEngine_Canvas_o*
            bool m_isFirstAllocation;
            int32_t m_max_characters;
            void* m_baseMaterial; //UnityEngine_Material_o*
            bool m_isScrollRegionSet;
            void* m_maskOffset; //UnityEngine_Vector4_o
            void* m_EnvMapMatrix; //UnityEngine_Matrix4x4_o
            bool m_isRegisteredForEvents;
            bool m_isRebuildingLayout;
            UnityEngine::Coroutine::Object* m_DelayedGraphicRebuild;
            UnityEngine::Coroutine::Object* m_DelayedMaterialRebuild;
            UnityEngine::Rect::Object m_ClipRect;
            bool m_ValidRect;
            void* OnPreRenderText; //System_Action_TMP_TextInfo__o*
        };
    };
}
