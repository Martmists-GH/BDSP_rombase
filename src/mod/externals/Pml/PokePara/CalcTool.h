#pragma once

#include "externals/il2cpp-api.h"

namespace Pml::PokePara {
    struct CalcTool : ILClass<CalcTool, 0x04c64410> {
        static inline uint8_t GetArceusType(uint32_t itemno) {
            return external<uint8_t>(0x024ae710, itemno);
        }
    };
}
