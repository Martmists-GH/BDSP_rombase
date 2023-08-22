#pragma once

#include "externals/il2cpp-api.h"

#include "externals/DPData/MYSTATUS.h"
#include "externals/Pml/PokePara/CoreParam.h"

namespace poketool::poke_memo {
    struct poketool_poke_memo : ILClass<poketool_poke_memo> {
        struct Fields {
            // TODO
        };

        static inline void SetFromCapture(Pml::PokePara::CoreParam::Object* pParam, DPData::MYSTATUS::Object* pMystatus, uint32_t placeNo) {
            external<void>(0x02bacb10, pParam, pMystatus, placeNo);
        }
    };
}
