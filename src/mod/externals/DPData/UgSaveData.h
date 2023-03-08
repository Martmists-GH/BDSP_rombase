#pragma once

#include <stddef.h>
#include "LOCATION_WORK.h"
#include "UGRecord.h"

namespace DPData {
    struct UgSaveData : IlStruct<UgSaveData> {
        struct Fields {
            int32_t ReturnZoneID;
            int32_t ReturnGridPosX;
            int32_t ReturnPosY;
            int32_t ReturnGridPosZ;
            DPData::LOCATION_WORK::Object ReturnZenmetsu_Ground;
            void* DigPoints;
            void* EncountPokes;
            void* EncountPokePositions;
            int32_t ReturnUgZoneID;
            DPData::UGRecord::Object ugRecord;
            void* FriendPlayerList;
            void* OtherPlayerList;
            void* TalkedNPCsID;
        };
    };
}
