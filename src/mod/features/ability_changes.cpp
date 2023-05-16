#include "exlaunch.hpp"
#include "externals/Dpr/Battle/Logic/BTL_CLIENT.h"
#include "externals/Dpr/Battle/Logic/BTL_POKEPARAM.h"
#include "externals/Pml/Pml_Enums.h"

using namespace Dpr::Battle::Logic;

HOOK_DEFINE_TRAMPOLINE(CheckForbidChangeEscapeCommon) {
    static int32_t Callback(BTL_CLIENT *__this, BTL_POKEPARAM *procPoke, uint8_t *pokeID, uint16_t *tokuseiID) {
        // Nigeashi (Run Away) allows switch outs
        if (procPoke->GetValue(0x12) == NIGEASI) {
            return CANTESC_NULL; 
        } else {
            return Orig(__this, procPoke, pokeID, tokuseiID);
        }
    }
};

void exl_ability_changes_main() {
    CheckForbidChangeEscapeCommon::InstallAtOffset(0x01f574e0);

    // Treat HP as always full so gale wings is like Gen 6
    exl::patch::CodePatcher p(0x0195ec70);
    p.WriteInst(exl::armv8::inst::Movz(exl::armv8::reg::X0, 1));
}
