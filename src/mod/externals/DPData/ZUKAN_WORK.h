#pragma once

#include "CONFIG.h"
#include "MYSTATUS.h"
#include "PLAYTIME.h"
#include "CONTEST_DATA.h"
#include "GET_STATUS.h"
#include "externals/System/Primitives.h"

namespace DPData {
    struct ZUKAN_WORK : ILStruct<ZUKAN_WORK> {
        struct Fields {
            DPData::GET_STATUS_array* get_status;
            System::Boolean_array* male_color_flag;
            System::Boolean_array* female_color_flag;
            System::Boolean_array* male_flag;
            System::Boolean_array* female_flag;
            void* UnknownTurn;
            void* UnknownColor;
            void* PowarunTurn;
            void* PowarunColor;
            void* DeokisisuTurn;
            void* DeokisisuColor;
            void* MinomuttiTurn;
            void* MinomuttiColor;
            void* MinomadamTurn;
            void* MinomadamColor;
            void* GaameiruTurn;
            void* GaameiruColor;
            void* TherimuTurn;
            void* TherimuColor;
            void* KaranakusiTurn;
            void* KaranakusiColor;
            void* ToritodonTurn;
            void* ToritodonColor;
            void* RotomTurn;
            void* RotomColor;
            void* GirathinaTurn;
            void* GirathinaColor;
            void* SheimiTurn;
            void* SheimiColor;
            void* AruseusuTurn;
            void* AruseusuColor;
            System::Int32_array* TextVersionUp;
            bool zukan_get;
            bool zenkoku_flag;
        };
    };
}
