#pragma once

#include "externals/il2cpp-api.h"

#include "externals/DPData/MV_POKE_DATA.h"

struct EncountDataWork : ILClass<EncountDataWork> {
    static inline int32_t GetUrayamaIndex(int32_t index) {
        return external<int32_t>(0x01f09de0, index);
    }
    
    static inline bool EncDataSave_CanUseSpray() {
        return external<bool>(0x01f08ac0);
    }
    
    static inline bool GetMovePokeData(int32_t index, DPData::MV_POKE_DATA::Object *outData) {
        return external<bool>(0x01f08e10, index, outData);
    }
    
    static inline bool IsTairyouHassei() {
        return external<bool>(0x01f09d60);
    }
};
