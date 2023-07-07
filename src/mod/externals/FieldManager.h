#pragma once

#include "externals/il2cpp-api.h"

struct FieldManager : ILClass<FieldManager> {
    struct Fields {
        // TODO
    };

    inline uint16_t GetFormNo(int32_t mons, int32_t karana, int32_t anno) {
        return external<uint16_t>(0x0179f560, this, mons, karana, anno);
    }
};
