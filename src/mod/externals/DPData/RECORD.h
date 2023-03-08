#pragma once

namespace DPData {
    struct RECORD : IlStruct<RECORD> {
        struct Fields {
            System_UInt32_array* VanishNew;
        };
    };

    struct RECORD_ARRAY : IlStruct<RECORD_ARRAY> {
        struct Fields {
            RECORD::Array* VanishNew;
        };
    };
}
