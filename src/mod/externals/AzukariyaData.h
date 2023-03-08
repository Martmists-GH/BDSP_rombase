#pragma once

#include <cstdint>

struct AzukariyaData : IlStruct<AzukariyaData> {
    struct Fields {
        void* pokemonParam;
        bool eggExist;
        uint64_t eggSeed;
        int32_t eggStepCount;
    };
};
