#pragma once

#include "il2cpp-api.h"

struct ItemWork : ILClass<ItemWork> {
    static inline int32_t AddItem(int32_t itemno, int32_t num) {
        return external<int32_t>(0x01aea3a0, itemno, num);
    }

    static inline int32_t SubItem(int32_t itemno,int32_t num) {
        return external<int32_t>(0x01aea450, itemno, num);
    }


};
