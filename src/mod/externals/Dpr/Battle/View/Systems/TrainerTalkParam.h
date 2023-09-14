#pragma once

#include "externals/il2cpp-api.h"

namespace Dpr::Battle::View::Systems {
    struct TrainerTalkParam : ILStruct<TrainerTalkParam> {
        struct Fields {
            uint8_t clientId;
            uint32_t param;
            bool isKeyWait;
        };
    };
}