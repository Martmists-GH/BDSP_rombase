#pragma once

#include "externals/il2cpp-api.h"

namespace Dpr::UI {
    struct IndexSelector : ILClass<IndexSelector> {
        struct Fields {
            bool IsStopInEnd;
            bool IsStopRepeatMovingWhenOutOfRanges;
            bool IsLoop;
            int32_t moveState;
            int32_t _CurrentIndex_k__BackingField;
            int32_t _MinCount_k__BackingField;
            int32_t _MaxCount_k__BackingField;
            bool _IsLooping_k__BackingField;
        };
    };
}