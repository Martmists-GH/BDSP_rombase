#pragma once

#include "externals/il2cpp-api.h"

namespace Pml::PokePara {
    struct CalcTool : ILClass<CalcTool, 0x04c64410> {
        static inline uint8_t GetArceusType(uint32_t itemno) {
            return external<uint8_t>(0x024ae710, itemno);
        }

        static inline bool IsRareColor(uint32_t id, uint32_t rnd) {
            return external<bool>(0x024ad790, id, rnd);
        }

        static inline uint32_t CorrectColorRndForRareType(uint32_t id, uint32_t rnd, uint8_t type) {
            return external<uint32_t>(0x024adce0, id, rnd, type);
        }
    };
}
