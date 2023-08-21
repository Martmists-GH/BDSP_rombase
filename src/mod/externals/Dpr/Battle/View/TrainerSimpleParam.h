#pragma once

#include "externals/il2cpp-api.h"

#include "externals/System/String.h"

namespace Dpr::Battle::View {
    struct TrainerSimpleParam : ILStruct<TrainerSimpleParam> {
        struct Fields {
            int32_t trainerType;
            System::String::Object* modelID;
            int32_t colorID;
            int32_t hatVariation;
            int32_t shoesVariation;
            uint8_t dominanceHand;
            uint8_t holdBallHand;
            float loseLoopTime;
            uint8_t trainerAge;
            int32_t blinkIntervalMin;
            int32_t blinkIntervalMax;
            int32_t blinkTwiceRate;
        };
    };
}
