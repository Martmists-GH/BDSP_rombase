#pragma once

#include "externals/il2cpp-api.h"
#include "externals/UnityEngine/MonoBehaviour.h"
#include "externals/UnityEngine/UI/ScrollRect.h"
#include "externals/UnityEngine/UI/LayoutGroup.h"

namespace Dpr::UI {
    struct UIScrollView : IlClass<UIScrollView> {
        struct Fields : UnityEngine::MonoBehaviour::Fields {
            UnityEngine::UI::ScrollRect::Object* scrollRect;
            void* itemPrefab;
            int32_t direction;
            int32_t duplicateItemCount;
            int32_t beginScrollCount;
            void* indexSelector;
            void* onRequiedItemData;
            void* onSelectItem;
            void* onUnSelectItem;
            UnityEngine::UI::LayoutGroup::Object* layoutGroup;
            bool isHorizontal;
            bool isActive;
            void* scrollRectItems;
            float viewportSize;
            int32_t itemSize;
            int32_t itemSizeWithSpacing;
            int32_t viewItemCount;
            int32_t itemCount;
            int32_t topPadding;
            int32_t bottomPadding;
            int32_t spacing;
            float contentSize;
            int32_t viewmaxIndex;
            int32_t renderedStartIndex;
            int32_t topPaddingItemCount;
            int32_t paddingItemCount;
            int32_t gridItemCount;
            float maxScrollValue;
            void* selectedItemNode;
        };
    };
}
