#pragma once

#include "externals/il2cpp-api.h"

namespace Dpr::Item {
    struct SaveItem : ILStruct<SaveItem> {
        struct Fields {
            int32_t Count;
            bool VanishNew;
            bool FavoriteFlag;
            bool ShowWazaNameFlag;
            uint8_t Dummy1;
            uint8_t Dummy2;
            uint16_t SortNumber;
        };
    };

    static Il2CppClass* SaveItem_array_TypeInfo() {
        return *reinterpret_cast<Il2CppClass**>(exl::util::modules::GetTargetOffset(0x04c64d90));
    }
}
