#pragma once

namespace DPData {
    struct ZUKAN_PERSONAL_RND_DATA : IlStruct<ZUKAN_PERSONAL_RND_DATA> {
        struct Fields {
            void* PattiiruSeePersonalRnds;
            void* PattiiruGetPersonalRnds;
            void* Reserved;
        };
    };
}
