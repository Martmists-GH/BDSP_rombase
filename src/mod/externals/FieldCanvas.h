#pragma once

#include "externals/System/String.h"

struct FieldCanvas : IlClass<FieldCanvas> {
    static inline void OpenAreaNameWindow(System::String* labelName) {
        external<void>(0x01786970, labelName);
    }

    static inline void ResetAreaNameWindow() {
        external<void>(0x01786b00);
    }
};
