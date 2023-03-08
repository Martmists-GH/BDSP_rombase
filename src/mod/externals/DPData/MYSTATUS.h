#pragma once

#include "externals/System/String.h"
#include "externals/UnityEngine/Vector2Int.h"

namespace DPData {
    struct MYSTATUS : IlStruct<MYSTATUS> {
        struct Fields {
            System::String::Object* name;
            uint32_t id;
            int32_t gold;
            bool sex;
            uint8_t region_code;
            uint8_t badge;
            uint8_t trainer_view;
            uint8_t rom_code;
            bool dp_clear;
            uint8_t body_type;
            uint8_t fashion;
            int32_t defaultPokeType;
            bool dsPlayerFlag;
            int32_t turewalkMemberIndex;
            UnityEngine::Vector2Int::Object grid;
            float height;
            float rotation;
        };
    };
}
