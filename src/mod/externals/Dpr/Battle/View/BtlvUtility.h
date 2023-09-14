#pragma once

#include "externals/il2cpp-api.h"

namespace Dpr::Battle::View {
    struct BtlvUtility : ILClass<BtlvUtility> {
        struct Fields {
        };

        inline int32_t GetUniqueWazaDataTurnType(int32_t wazaNo,int32_t monsNo,uint8_t formNo,int32_t turnType) {
            return external<int32_t>(0x01e4ec40, this, wazaNo, monsNo, formNo, turnType);
        }
    };
}