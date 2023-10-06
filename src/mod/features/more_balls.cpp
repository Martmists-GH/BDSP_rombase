#include "exlaunch.hpp"

#include "data/balls.h"
#include "data/utils.h"

#include "externals/Dpr/Battle/View/Systems/BattleViewSystem.h"
#include "externals/Dpr/SealPreview/SealPreviewViewSystem.h"
#include "externals/System/String.h"

#include "logger/logger.h"

System::String::Object * GenerateBallModelPath(uint8_t ballId)
{
    if (ballId < BALL_COUNT)
    {
        nn::string objectId = nn::to_string(((int32_t)ballId) + 200);
        return System::String::Create("objects/ob0" + objectId + "_00");
    }
    else
    {
        return System::String::Create("objects/ob0200_00");
    }
}

HOOK_DEFINE_REPLACE(IsStrangeBall) {
    static bool Callback(uint8_t ballid) {
        return ballid >= BALL_COUNT || ballid == 0;
    }
};

HOOK_DEFINE_INLINE(InlineGetBallModelPath) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        uint8_t ballid = ctx->W[24];
        ctx->X[0] = (uint64_t)GenerateBallModelPath(ballid);
    }
};

HOOK_DEFINE_REPLACE(BattleViewSystemGetBallModelPath) {
    static System::String::Object * Callback(Dpr::Battle::View::Systems::BattleViewSystem::Object *__this, int32_t idx) {
        if ((uint64_t)idx < __this->fields.m_effectBallInfo->max_length)
        {
            uint8_t ballid = __this->fields.m_effectBallInfo->m_Items[idx].fields.ballId;
            return GenerateBallModelPath(ballid);
        }
        else
        {
            return GenerateBallModelPath(0);
        }
    }
};

HOOK_DEFINE_REPLACE(SealPreviewViewSystemGetBallModelPath) {
    static System::String::Object * Callback(Dpr::SealPreview::SealPreviewViewSystem::Object *__this, int32_t idx) {
        if ((uint64_t)idx < __this->fields.m_effectBallInfo->max_length)
        {
            uint8_t ballid = __this->fields.m_effectBallInfo->m_Items[idx].fields.ballId;
            return GenerateBallModelPath(ballid);
        }
        else
        {
            return GenerateBallModelPath(0);
        }
    }
};

HOOK_DEFINE_REPLACE(UtilsGetBallModelPath) {
    static System::String::Object * Callback(uint8_t ballId) {
        return GenerateBallModelPath(ballId);
    }
};

void exl_balls_main() {
    IsStrangeBall::InstallAtOffset(0x0249f130);
    InlineGetBallModelPath::InstallAtOffset(0x01db6cb4);
    BattleViewSystemGetBallModelPath::InstallAtOffset(0x01c92790);
    SealPreviewViewSystemGetBallModelPath::InstallAtOffset(0x01bd9aa0);
    UtilsGetBallModelPath::InstallAtOffset(0x0186b4a0);
    UtilsGetBallModelPath::InstallAtOffset(0x01e4df50);

    // Assembly Patches
    using namespace exl::armv8::inst;
    using namespace exl::armv8::reg;
    exl::patch::CodePatcher p(0);
    auto inst = nn::vector<exl::patch::Instruction> {
        { 0x01db6a40, Movz(W20, BALL_COUNT + 2) },
        { 0x01db7488, Movz(W10, array_index(BALLS, "--BALL ZERO--")) },
        { 0x01db6e78, Movz(W8, array_index(BALLS, "--BALL ZERO--")) },
        { 0x01db7244, Movz(W10, array_index(BALLS, "--BALL ZERO--")) },
        { 0x01db6f18, Movz(W28, array_index(BALLS, "--BALL ZERO--")) },
        { 0x01db6c08, Movz(W8, array_index(BALLS, "--BALL ZERO--")) },
        { 0x01db6c38, CmpImmediate(W9, array_index(BALLS, "--BALL ZERO--")) },
        { 0x01abc8dc, Movz(W8, array_index(BALLS, "--BALL ZERO--")) },
        { 0x02cc01b4, CmpImmediate(W1, array_index(BALLS, "--BALL ZERO--")) },
        { 0x02cc01c4, CmpImmediate(W1, array_index(BALLS, "--BALL ZERO--")) },
    };
    p.WriteInst(inst);
}
