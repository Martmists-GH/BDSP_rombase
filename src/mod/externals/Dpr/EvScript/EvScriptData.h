#pragma once

#include "externals/il2cpp-api.h"

#include "externals/EvData/_EvData.h"

namespace Dpr::EvScript {
    struct EvScriptData : ILClass<EvScriptData> {
        struct Fields {
            _EvData::Object* EvData;
            int32_t LabelIndex;
            int32_t CommandIndex;
            int32_t RetIndex;
        };
    };
}
