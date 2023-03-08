#pragma once


namespace DPData {
    struct POKETCH_POKETORE_COUNT : IlStruct<POKETCH_POKETORE_COUNT> {
        struct Fields {
            int16_t monsno;
            int16_t reserve;
            int32_t count;
            int32_t reserve1;
            int32_t reserve2;
        };
    };

    struct POKETCH_POKETORE_COUNT_ARRAY : IlStruct<POKETCH_POKETORE_COUNT_ARRAY> {
        struct Fields {
            POKETCH_POKETORE_COUNT::Array* data;
        };
    };
}
