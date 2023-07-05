#pragma once

#include "externals/il2cpp-api.h"

struct MonsLv : ILStruct<MonsLv> {
    struct Fields {
        int32_t maxlv;
        int32_t minlv;
        int32_t monsNo;
    };

    static Il2CppClass* Array_TypeInfo() {
        return *reinterpret_cast<Il2CppClass**>(exl::util::modules::GetTargetOffset(0x04c5f208));
    }
};
