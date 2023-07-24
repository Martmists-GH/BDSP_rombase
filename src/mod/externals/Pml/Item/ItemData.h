#pragma once

#include "externals/il2cpp-api.h"

namespace Pml::Item {
    struct ItemData : ILClass<ItemData> {
        static inline uint32_t GetWazaMachineNo(uint16_t item) {
            return external<uint32_t>(0x0249d4e0, item);
        }
    };
}
