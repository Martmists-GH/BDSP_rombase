#pragma once

#include "LOCATION_WORK.h"

namespace DPData {
    struct WorpPoint : ILStruct<WorpPoint> {
        struct Fields {
            DPData::LOCATION_WORK::Object teleport;
            DPData::LOCATION_WORK::Object zenmetu;
            DPData::LOCATION_WORK::Object ananuke;
        };
    };
}
