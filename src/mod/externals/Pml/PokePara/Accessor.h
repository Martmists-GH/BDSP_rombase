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

        inline void SetFormNo(uint16_t formno) {
            external<void>(0x024a9c30, this, formno);
        }
        
        inline void SetGetBall(uint8_t ball) {
            external<void>(0x024aaba0, this, ball);
        }
    };
}
