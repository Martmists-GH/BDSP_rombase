#pragma once

#include "externals/il2cpp-api.h"

struct ZukanWork : ILClass<ZukanWork> {
    static inline bool GetZenkokuFlag() {
        return external<bool>(0x017db490);
    }
};
