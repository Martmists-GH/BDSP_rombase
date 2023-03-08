#pragma once

#include "externals/il2cpp-api.h"
#include "externals/UnityEngine/UI/MaskableGraphic.h"
#include "externals/System/String.h"
#include "externals/System/Collections/Generic/List.h"

namespace Dpr::UI {
    struct UIText : IlClass<UIText> {
        struct Fields {
            char super[0x798];
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
    };
}

namespace System::Collections::Generic {
    struct List$$UIText : System::Collections::Generic::List<List$$UIText, Dpr::UI::UIText> {

    };
}
