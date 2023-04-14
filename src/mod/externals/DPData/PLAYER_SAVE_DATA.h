#pragma once

#include "WorpPoint.h"

namespace DPData {
    struct PLAYER_SAVE_DATA : ILStruct<PLAYER_SAVE_DATA> {
        struct Fields {
            bool gear_type;
            bool shoes_flag;
            uint32_t form;
            uint8_t bic_color;
            DPData::WorpPoint::Object worpPoint;
            float walkcount;
            int32_t natuki_walkcnt;
            DPData::LOCATION_WORK::Object TownMapLocation;
            bool isTokushuLocation;
            DPData::LOCATION_WORK::Object TokushuLocation;
        };
    };
}
