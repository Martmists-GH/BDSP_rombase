#pragma once

#include "externals/il2cpp-api.h"
#include "externals/Dpr/UI/StatusPanelLocals.h"

namespace Dpr::UI {
    struct StatusPanelUI : ILClass<StatusPanelUI> {
        struct Fields {
            int32_t i;
            StatusPanelLocals::Object* locals;
        };
    };
}