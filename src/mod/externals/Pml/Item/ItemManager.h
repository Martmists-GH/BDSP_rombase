#pragma once

#include "externals/il2cpp-api.h"

#include "externals/XLSXContent/ItemTable.h"

namespace Pml::Item {
    struct ItemManager : ILClass<ItemManager, 0x04c5a680> {
        struct Fields {
            XLSXContent::ItemTable::Object* m_alldata;
        };

        struct StaticFields {
            Pml::Item::ItemManager::Object* s_Instance;
        };

        static inline uint32_t GetWazaMachineNo(uint16_t item) {
            return external<uint32_t>(0x0249d4e0, item);
        }
    };
}
