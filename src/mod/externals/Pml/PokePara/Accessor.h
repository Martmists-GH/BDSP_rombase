#pragma once

#include "externals/il2cpp-api.h"

namespace Pml::PokePara {
    struct Accessor : ILClass<Accessor> {
        inline void SetLangID(uint8_t langId) {
            external<void>(0x024a8bb0, this, langId);
        }

        inline void SetOwnedOthersFlag(bool flag) {
            external<void>(0x024ab2b0, this, flag);
        }
    };
}
