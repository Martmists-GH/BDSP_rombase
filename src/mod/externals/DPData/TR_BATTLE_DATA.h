#pragma once

#include "externals/il2cpp.h"

namespace DPData {
    struct TR_BATTLE_DATA : ILStruct<TR_BATTLE_DATA> {
        struct Fields {
            bool IsWin;
            bool IsBattleSearcher;
        };
    };

    static Il2CppClass* TR_BATTLE_DATA_array_TypeInfo() {
        return *reinterpret_cast<Il2CppClass**>(exl::util::modules::GetTargetOffset(0x04c64da8));
    }
}
