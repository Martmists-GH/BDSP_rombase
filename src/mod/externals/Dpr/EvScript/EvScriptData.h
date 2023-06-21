#pragma once

#include "externals/il2cpp-api.h"

#include "externals/EvData.h"

namespace Dpr::EvScript {
    struct EvScriptData : ILClass<EvScriptData> {
        struct Fields {
            EvData::Object* EvData;
            int32_t LabelIndex;
            int32_t CommandIndex;
            int32_t RetIndex;
        };
    };
}
