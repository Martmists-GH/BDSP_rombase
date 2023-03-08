#pragma once

namespace DPData {
    struct UnionSaveData : IlStruct<UnionSaveData> {
        struct Fields {
            bool initNpcTalk;
            int32_t penartyCounter;
            float penartyTime;
        };
    };
}
