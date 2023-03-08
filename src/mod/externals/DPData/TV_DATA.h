#pragma once

#include "TV_RECORD.h"
#include "TV_TOPIC.h"
#include "INTERVIEWER_DATA.h"

namespace DPData {
    struct TV_DATA : IlStruct<TV_DATA> {
        struct Fields {
            DPData::TV_RECORD::Object UseRecord;
            DPData::TV_RECORD::Object MyRecord;
            DPData::TV_TOPIC::Object UseTopic;
            DPData::TV_TOPIC::Object MyTopic;
            DPData::INTERVIEWER_DATA::Object InterviewerData;
            int32_t TvWatchCount;
        };
    };
}
