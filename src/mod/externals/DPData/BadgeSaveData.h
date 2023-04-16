#pragma once

namespace DPData {
    struct BadgeSaveData : ILStruct<BadgeSaveData> {
        struct Fields {
            void* CleanValues;
        };
    };
}
