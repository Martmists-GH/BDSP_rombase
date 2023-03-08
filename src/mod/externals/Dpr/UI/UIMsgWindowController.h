#pragma once

#include "externals/il2cpp.h"
#include "externals/UnityEngine/Vector2.h"
#include "externals/System/Nullable.h"

namespace Dpr::UI {
    struct UIMsgWindowController : IlClass<UIMsgWindowController, 0x04c5e6a8> {
        struct Fields {
            void* msgWindow;
            void* onCloseMsgWindow;
            void* onFinishedContinueMessage;
            bool isWaitMsgWindow;
            System::Nullable<UnityEngine::Vector2>::Object windowAnchorPosition;
            void* msgWindowParam;
            void* continueMessageLabels;
            void* continueMessageOnSets;
        };

        void ctor() {
            external<void>(0x01a140a0, this);
        }
    };
}



