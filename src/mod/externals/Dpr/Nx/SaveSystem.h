#pragma once

#include <cstdint>
#include "externals/il2cpp-api.h"

namespace Dpr::Nx {
    struct SaveSystem : IlClass<SaveSystem, 0x04c600b8> {
        inline bool Load(bool fromBackup) {
            return external<bool>(0x01ddf910, this, fromBackup);
        }
    };
}
