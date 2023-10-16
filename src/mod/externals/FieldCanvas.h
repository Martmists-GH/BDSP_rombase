#pragma once

#include "externals/Dpr/Demo/DemoBase.h"
#include "externals/System/String.h"

struct FieldCanvas : ILClass<FieldCanvas, 0x04c5ed38> {
    static inline void OpenAreaNameWindow(System::String* labelName) {
        external<void>(0x01786970, labelName);
    }

    static inline void ResetAreaNameWindow() {
        external<void>(0x01786b00);
    }

    static inline void PlayDemoOrStock(Dpr::Demo::DemoBase::Object* demo) {
        external<void>(0x0177f2c0, demo);
    }
};
