#pragma once

namespace DPData {
    struct BadgeSaveData : IlStruct<BadgeSaveData> {
        struct Fields {
            void* CleanValues;
        };
    };
}
