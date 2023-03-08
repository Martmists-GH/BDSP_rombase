#pragma once

#include <cstdint>

namespace DPData {
    struct PLAYER_NETWORK_DATA : IlStruct<PLAYER_NETWORK_DATA> {
        struct Fields {
            void* publicKeyBASE64;
            void* bcatFlagArray;
            uint64_t nexUniqueId;
            uint64_t nexUniqueIdPassword;
            uint16_t publicKeyversion;
        };
    };
}
