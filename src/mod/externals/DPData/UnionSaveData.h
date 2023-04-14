#pragma once

namespace DPData {
    struct UnionSaveData : ILStruct<UnionSaveData> {
        struct Fields {
            bool initNpcTalk;
            int32_t penartyCounter;
            float penartyTime;
        };
    };
}
