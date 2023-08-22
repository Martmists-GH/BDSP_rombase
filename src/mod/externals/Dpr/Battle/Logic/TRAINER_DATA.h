#pragma once

#include "externals/il2cpp-api.h"

#include "externals/Dpr/Battle/Logic/MyStatus.h"
#include "externals/System/Primitives.h"
#include "externals/System/String.h"

namespace Dpr::Battle::Logic {
    struct TRAINER_DATA : ILClass<TRAINER_DATA> {
        struct Fields {
            Dpr::Battle::Logic::MyStatus::Object* playerStatus;
            void* trainerData; // XLSXContent_TrainerTable_SheetTrainerData_o*
            void* instTrainerData; // XLSXContent_TowerTrainerTable_SheetTrainerData_o*
            System::String::Object* name;
            System::String::Object* name_label;
            System::String::Object* trtype_name_label;
            int32_t trainerID;
            int32_t trainerType;
            uint8_t trainerGroup;
            uint8_t trainerSex;
            uint8_t trainerGold;
            uint32_t ai_bit;
            System::UInt16_array* useItem;
            System::String::Object* modelID;
            int32_t colorID;
        };
    };
}
