#pragma once

#include <cstdint>

namespace DPData {
    struct CON_PHOTO_LANG_DATA : ILStruct<CON_PHOTO_LANG_DATA> {
        struct Fields {
            uint8_t styleMonsLangID;
            uint8_t beautifulMonsLangID;
            uint8_t cuteMonsLangID;
            uint8_t cleverMonsLangID;
            uint8_t strongMonsLangID;
            int64_t reserved_long01;
            int64_t reserved_long02;
        };
    };
}
