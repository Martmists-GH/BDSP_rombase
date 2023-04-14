#pragma once

#include <cstdint>
#include "externals/il2cpp-api.h"

namespace Dpr::Box {
    struct SaveBoxData : ILStruct<SaveBoxData> {
        struct Fields {
            void* trayName;
            void* teamName;
            void* teamPos;
            uint8_t teamLock;
            uint8_t trayMax;
            uint8_t currentTray;
            bool isOpened;
            void* wallPaper;
            uint16_t statusPut;
        };
    };
}
