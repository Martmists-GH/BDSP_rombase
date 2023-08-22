#pragma once

#include "externals/il2cpp-api.h"

namespace DPData {
    struct PoffinData : ILStruct<PoffinData> {
        struct Fields {
            uint8_t MstID;
            uint8_t Level;
            uint8_t Taste;
            bool IsNew;
            void* Flavor; //System_Byte_array*
        };

    };
}