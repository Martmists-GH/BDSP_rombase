#pragma once

#include "externals/il2cpp-api.h"
#include "externals/UnityEngine/MonoBehaviour.h"
#include "externals/Dpr/Item/ItemInfo.h"

namespace Dpr::UI {
    struct BagItemButton : ILClass<BagItemButton> {
        struct Fields : UnityEngine::MonoBehaviour::Fields {
            // Fields
            /*
            [SerializeField] // RVA: 0x93600 Offset: 0x93701 VA: 0x93600
        private Image iconImage; // 0x18
            [SerializeField] // RVA: 0x93610 Offset: 0x93711 VA: 0x93610
        private UIText nameText; // 0x20
            [SerializeField] // RVA: 0x93620 Offset: 0x93721 VA: 0x93620
        private Image newIconImage; // 0x28
            [SerializeField] // RVA: 0x93630 Offset: 0x93731 VA: 0x93630
        private Image favoriteIconImage; // 0x30
            [SerializeField] // RVA: 0x93640 Offset: 0x93741 VA: 0x93640
        private UIText stockCountLabelText; // 0x38
            [SerializeField] // RVA: 0x93650 Offset: 0x93751 VA: 0x93650
        private UIText stockCountValueText; // 0x40
            [SerializeField] // RVA: 0x93660 Offset: 0x93761 VA: 0x93660
        private Image registerButtonImage; // 0x48
            [SerializeField] // RVA: 0x93670 Offset: 0x93771 VA: 0x93670
        private Sprite[] shortcutButonSprites; // 0x50
        private int index; // 0x58
        private RectTransform rectTransform; // 0x60
             */
        Dpr::Item::ItemInfo::Object* item; // 0x68
        };
    };
}