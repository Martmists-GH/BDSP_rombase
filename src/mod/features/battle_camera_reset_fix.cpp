#include "exlaunch.hpp"
#include "logger/logger.h"

static void BattleCameraResetSkip() {
    Logger::log("Skipping camera.\n");
}

void exl_battle_camera_fix_main() {
    exl::patch::CodePatcher p(0x01c92008);
    p.BranchLinkInst((void*)&BattleCameraResetSkip);
};