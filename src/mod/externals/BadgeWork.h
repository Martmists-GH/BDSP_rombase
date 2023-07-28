#pragma once

#include "externals/il2cpp-api.h"

struct BadgeWork : ILClass<BadgeWork> {
    static inline bool IsGet(int32_t id) {
        return external<bool>(0x01d603e0, id);
    }
};