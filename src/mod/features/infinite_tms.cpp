#include "exlaunch.hpp"
#include "externals/Dpr/UI/UIBag.h"

HOOK_DEFINE_REPLACE(SkipTMBreak) {
    static void Callback(Dpr::UI::UIBag::__c__DisplayClass134_0* __this) {
        // Return to UseWazaMachine proc
        __this->_UseWazaMachine_b__3(0);
    }
};

HOOK_DEFINE_REPLACE(DoNothing) {
    static void Callback() { }
};

void exl_tms_main() {
    SkipTMBreak::InstallAtOffset(0x01be0d40);

    DoNothing::InstallAtOffset(0x01be1220);  // Dpr.UI.UIBag.<>c__DisplayClass134_0$$<UseWazaMachine>b__5
    DoNothing::InstallAtOffset(0x01be1460);  // Dpr.UI.UIBag.<>c__DisplayClass134_0$$<UseWazaMachine>b__6

    // Skip closing of text popup for reusing
    exl::patch::CodePatcher p(0x01be0fec);
    p.WriteInst(exl::armv8::inst::Nop());
}
