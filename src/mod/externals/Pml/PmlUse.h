#pragma once

#include "externals/il2cpp.h"


namespace Pml {
    struct PmlUse : ILClass<PmlUse> {

        static inline PmlUse::Object* get_Instance() {
            return external<PmlUse::Object*>(0x024a0110);
        }

        inline int32_t get_LangId() {
            return external<int32_t>(0x024a3c20, this);
        }
    };
}
