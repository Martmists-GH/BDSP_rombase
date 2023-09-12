#include "exlaunch.hpp"

void exl_battle_camera_fix_main() {
    exl::patch::CodePatcher p(0x01c92008);
    p.WriteInst(exl::armv8::inst::Nop());
};