#pragma once

#include "externals/il2cpp-api.h"

struct AttributeID : ILClass<AttributeID> {
    static inline bool MATR_IsWater(int32_t matr_code) {
        return external<bool>(0x021267d0, matr_code);
    }
};
