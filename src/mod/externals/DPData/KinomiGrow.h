#pragma once

#include "externals/il2cpp-api.h"

namespace DPData {
    struct KinomiGrow : ILStruct<KinomiGrow> {
        struct Fields {
            int32_t tagNo;
            int32_t harvestCount;
            int32_t minutes;
            uint8_t _wet;
            uint8_t _selfPlant;
            uint8_t _padding0;
            uint8_t _padding1;
        };
    };

    static Il2CppClass* KinomiGrow_array_TypeInfo() {
        return *reinterpret_cast<Il2CppClass**>(exl::util::modules::GetTargetOffset(0x04c5a4b0));
    }
}
