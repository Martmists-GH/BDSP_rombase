#pragma once

#include "externals/il2cpp-api.h"

namespace XLSXContent {
    struct ShopTable : ILClass<ShopTable> {
        struct SheetBoutiqueShop : ILClass<SheetBoutiqueShop> {
            struct Fields {
                int32_t DressNo;
                int32_t OpenDress;
                int32_t DressGet;
                int32_t Price;
            };
        };
    };
}