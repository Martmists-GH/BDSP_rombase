#pragma once

#include "externals/il2cpp-api.h"
#include "externals/UnityEngine/UI/MaskableGraphic.h"
#include "externals/System/String.h"
#include "externals/System/Collections/Generic/List.h"
#include "externals/TMPro/TextMeshProUGUI.h"

namespace Dpr::UI {
    struct UIText : ILClass<UIText> {
        struct Fields : TMPro::TextMeshProUGUI::Fields {
            int32_t _sizeId;
            bool _useMessage;
            System::String::Object* _messageFile;
            System::String::Object* _messageId;
            bool _useTag;
            bool _isManual;
            int32_t _fontMaterialDataIndex;
            bool _uiTextEnable;
            void* _msgFile;
            int32_t _messageIndex;
        };

        void SetupMessage(System::String* messageFile, System::String* messageId) {
            external<void>(0x01dd18d0, this, messageFile, messageId);
        }

        /*
        inline void UpdateMessage(UIText::Object *__this, bool isForce, int32_t langId) {
            external<void>(0x01dd1480, this, isForce, langId);
        }
        */
    };
}

namespace System::Collections::Generic {
    struct List$$UIText : List<List$$UIText, Dpr::UI::UIText> {

    };
}
