#include "exlaunch.hpp"

#include "data/balls.h"
#include "data/species.h"
#include "data/utils.h"

#include "externals/Dpr/Field/EncountResult.h"
#include "externals/Dpr/Field/FieldEncount/ENC_FLD_SPA.h"
#include "externals/System/String.h"

#include "logger/logger.h"

System::String::Object * GenerateBallModelPath(uint8_t ballId)
{
    if (ballId < BALL_COUNT)
    {
        std::string objectId = std::to_string(((int32_t)ballId) + 200);
        return System::String::Create("objects/ob0" + objectId + "_00");
    }
    else
    {
        return System::String::Create("objects/ob0200_00");
    }
}

HOOK_DEFINE_REPLACE(IsStrangeBall) {
    static bool Callback(uint8_t ballid) {
        return ballid >= BALL_COUNT;
    }
};

HOOK_DEFINE_INLINE(InlineGetBallModelPath) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        uint8_t ballid = ctx->W[24];
        ctx->X[0] = (uint64_t)GenerateBallModelPath(ballid);
    }
};

HOOK_DEFINE_REPLACE(ReplaceGetBallModelPath) {
    static System::String::Object * Callback(void *__this, int32_t idx) {
        uint8_t ballid = 0;
        return GenerateBallModelPath(ballid);
    }
};

void exl_balls_main() {
    IsStrangeBall::InstallAtOffset(0x0249f130);
    InlineGetBallModelPath::InstallAtOffset(0x01db6cb4);

}
