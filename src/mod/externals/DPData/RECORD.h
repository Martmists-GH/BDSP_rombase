#pragma once

namespace DPData {
    struct RECORD : ILStruct<RECORD> {
        struct Fields {
            System_UInt32_array* VanishNew;
        };
    };

    struct RECORD_ARRAY : ILStruct<RECORD_ARRAY> {
        struct Fields {
            RECORD::Array* VanishNew;
        };
    };
}
