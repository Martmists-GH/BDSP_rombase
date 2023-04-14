#pragma once

#include "externals/il2cpp-api.h"
#include "externals/System/Primitives.h"

namespace Dpr::Field::FieldEncount {
    struct ENC_FLD_SPA : ILStruct<ENC_FLD_SPA> {
        struct Fields {
            int32_t TrainerID;
            bool SprayCheck;
            bool EncCancelSpInvalid;
            int32_t SpMyLv;
            bool Egg;
            int32_t Spa;
            System_Int32_array* FormProb;
            int32_t AnnoonTblType;
        };
    };
}
