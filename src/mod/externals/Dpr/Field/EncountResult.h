#pragma once

#include "externals/Pml/MonsNo.h"
#include "externals/il2cpp-api.h"

namespace Dpr::Field {
    struct EncountResult : ILClass<EncountResult> {
        struct Fields {
            int32_t Type;
            Pml_MonsNo_array* Enemy;
            void* Level;
            void* FixSex;
            void* FixSeikaku;
            bool IsRare;
            int32_t Partner;
            int32_t HatudouTokusei;
            int32_t BattleBG;
            int32_t MP_SaveIndex;
            bool IsKakure;
            int32_t karanaForm;
            int32_t annoForm;
        };
    };
}
