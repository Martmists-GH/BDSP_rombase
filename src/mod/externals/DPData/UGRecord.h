#pragma once

#include "UgSecretBase.h"

namespace DPData {
    struct UGRecord : ILStruct<UGRecord> {
        struct Fields {
            uint32_t talkPlayerDataID;
            uint32_t talkPlayerCount;
            DPData::UgSecretBase::Object myBase;
        };
    };
}
