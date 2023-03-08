#pragma once

#include "CONFIG.h"
#include "MYSTATUS.h"
#include "PLAYTIME.h"
#include "CONTEST_DATA.h"

namespace DPData {
    struct PLAYER_DATA : IlStruct<PLAYER_DATA> {
        struct Fields {
            DPData::CONFIG::Object config;
            DPData::MYSTATUS::Object mystatus;
            DPData::PLAYTIME::Object playtime;
            DPData::CONTEST_DATA::Object contestdata;
        };
    };
}
