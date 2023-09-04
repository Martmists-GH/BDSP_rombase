#pragma once

#include "externals/il2cpp-api.h"

namespace Dpr::Battle::View::Objects {
    struct MotionTimingData : ILStruct<MotionTimingData> {
        struct Fields {
            int32_t Buturi01;
            int32_t Buturi02;
            int32_t Buturi03;
            int32_t Tokusyu01;
            int32_t Tokusyu02;
            int32_t Tokusyu03;
            int32_t BodyBlow;
            int32_t Punch;
            int32_t Kick;
            int32_t Tail;
            int32_t Bite;
            int32_t Peck;
            int32_t Radial;
            int32_t Cry;
            int32_t Dust;
            int32_t Shot;
            int32_t Guard;
            int32_t LandingFall;
            int32_t LandingFallEase;
        };
    };
}