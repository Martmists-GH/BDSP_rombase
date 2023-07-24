#pragma once

#include "externals/il2cpp-api.h"

namespace Pml {
    struct WazaData : ILClass<WazaData> {
        struct WazaDataSystem
        {
            inline static uint8_t GetType(int32_t id) {
                return external<uint8_t>(0x020533a0, id);
            };
        };
    };
}