#pragma once

#include "externals/il2cpp-api.h"
#include "externals/UnityEngine/UI/LayoutGroup.h"

namespace UnityEngine::UI {
    struct HorizontalOrVerticalLayoutGroup : ILClass<HorizontalOrVerticalLayoutGroup> {
        struct Fields : UnityEngine::UI::LayoutGroup::Fields {
            float m_Spacing;
            bool m_ChildForceExpandWidth;
            bool m_ChildForceExpandHeight;
            bool m_ChildControlWidth;
            bool m_ChildControlHeight;
            bool m_ChildScaleWidth;
            bool m_ChildScaleHeight;
        };
    };
}
