#pragma once

#include "externals/il2cpp-api.h"

#include "externals/Pml/MonsNo.h"
#include "externals/System/Primitives.h"

namespace Dpr::Field {
    struct EncountResult : ILClass<EncountResult, 0x04c5f200> {
        enum class BtlType : int32_t {
            Single = 0,
            Double = 1,
            Safari = 2,
            MovePoke = 3,
        };

        struct Fields {
            BtlType Type;
            Pml_MonsNo_array* Enemy;
            System::Int32_array* Level;
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

        static_assert(offsetof(Fields, annoForm) == 0x44);

        inline Dpr::Field::EncountResult::Object* ctor() {
            return external<Dpr::Field::EncountResult::Object*>(0x019b2c70, this);
        }
    };
}
