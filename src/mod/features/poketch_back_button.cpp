#include "exlaunch.hpp"

#include "externals/il2cpp-api.h"
#include "externals/Dpr/UI/PoketchWindow.h"
#include "externals/UnityEngine/Component.h"
#include "ui/ui.h"

void goBackAction(Dpr::UI::PoketchWindow* __this) {
    __this->SelectApp(false);
}

HOOK_DEFINE_INLINE(IsInRange_Small) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        auto window = (Dpr::UI::PoketchWindow::Object*)ctx->X[19];
        auto forwardsButton = (Dpr::UI::PoketchButton::Object*)ctx->X[1];

        auto windowTransform = window->cast<UnityEngine::Component>()->get_transform();
        auto backwardsTransform = windowTransform->Find(System::String::Create("Window"))
                ->Find(System::String::Create("Poketch"))
                ->Find(System::String::Create("Body_02"))
                ->Find(System::String::Create("Mask"))
                ->Find(System::String::Create("Image_button2"));
        auto backwardsButton = backwardsTransform->GetComponent<Dpr::UI::PoketchButton>(window->fields._changeButton->klass);

        // Get float values from registers (not yet supported through ctx, see: https://github.com/shadowninja108/exlaunch/issues/1)
        float x, y;
        __asm(
            R"(
                mov %0.16B, v8.16B
                mov %1.16B, v9.16B
            )"
            : "=w"(x), "=w"(y)
        );

        if (backwardsButton != nullptr && window->IsInRange(backwardsButton, x, y))
        {
            backwardsButton->OnPush();
            ctx->X[0] = (uint64_t)false;
            return;
        }

        if (forwardsButton != nullptr)
        {
            ctx->X[0] = (uint64_t)window->IsInRange(forwardsButton, x, y);
            return;
        }
    }
};

HOOK_DEFINE_INLINE(IsInRange_Big) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        Logger::log("Enter IsInRange_Big\n");
        auto window = (Dpr::UI::PoketchWindow::Object*)ctx->X[19];
        auto buttonToCheck = (Dpr::UI::PoketchButton::Object*)ctx->X[1];

        auto windowTransform = window->cast<UnityEngine::Component>()->get_transform();
        auto backwardsTransform = windowTransform->Find(System::String::Create("Window"))
                ->Find(System::String::Create("Poketch"))
                ->Find(System::String::Create("Body_02"))
                ->Find(System::String::Create("Mask"))
                ->Find(System::String::Create("Image_button2"));
        auto backwardsButton = backwardsTransform->GetComponent<Dpr::UI::PoketchButton>(window->fields._changeButton->klass);

        Logger::log("Pre button! %08X\n", window->fields._preButton);

        // Get float values from registers (not yet supported through ctx, see: https://github.com/shadowninja108/exlaunch/issues/1)
        float x, y;
        __asm(
                R"(
                mov %0.16B, v8.16B
                mov %1.16B, v9.16B
            )"
                : "=w"(x), "=w"(y)
                );

        /*if (UnityEngine::_Object::op_Equality((UnityEngine::_Object::Object*)buttonToCheck, (UnityEngine::_Object::Object*)window->fields._changeButton))
        {
            if (backwardsButton != nullptr && window->IsInRange(backwardsButton, x, y))
            {
                Logger::log("Actually, this was the backwards button!\n");
                ctx->X[20] = (uint64_t)backwardsButton;
                ctx->X[0] = (uint64_t)true;
                Logger::log("Exit IsInRange_Big\n");
                return;
            }

            if (window->fields._changeButton != nullptr)
            {
                Logger::log("Forwards button!\n");
                ctx->X[0] = (uint64_t)window->IsInRange(window->fields._changeButton, x, y);
                Logger::log("Exit IsInRange_Big\n");
                return;
            }
        }*/

        ctx->X[0] = (uint64_t)window->IsInRange(buttonToCheck, x, y);

        Logger::log("Exit IsInRange_Big\n");
    }
};

HOOK_DEFINE_INLINE(ButtonInit) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        auto forwardsButton = (Dpr::UI::PoketchButton::Object*)ctx->X[0];
        auto forwardsAction = (UnityEngine::Events::UnityAction::Object*)ctx->X[1];
        auto forwardsSeEventId = (int32_t)ctx->W[2];

        forwardsButton->Initialize(forwardsAction, forwardsSeEventId);

        auto poketchWindow = (Dpr::UI::PoketchWindow::Object*)ctx->X[19];
        auto windowTransform = poketchWindow->cast<UnityEngine::Component>()->get_transform();
        auto mask = windowTransform->Find(System::String::Create("Window"))
                ->Find(System::String::Create("Poketch"))
                ->Find(System::String::Create("Body_02"))
                ->Find(System::String::Create("Mask"));

        auto backwardsButton = mask->Find(System::String::Create("Image_button2"))->GetComponent<Dpr::UI::PoketchButton>(poketchWindow->fields._changeButton->klass);
        ILMethod mi(forwardsAction->fields.method);
        auto backwardsAction = UnityEngine::Events::UnityAction::getClass(UnityEngine::Events::UnityAction::void_TypeInfo)->newInstance(poketchWindow, mi.copyWith((Il2CppMethodPointer) &goBackAction));

        backwardsButton->Initialize(backwardsAction, forwardsSeEventId);
    }
};

void exl_poketch_main() {
    IsInRange_Small::InstallAtOffset(0x01e67a3c);
    IsInRange_Big::InstallAtOffset(0x01e67d54);
    ButtonInit::InstallAtOffset(0x01e66b5c);

    // Make our CheckOnPush hook get called one extra time, for the backwards button
    /*using namespace exl::armv8::inst;
    using namespace exl::armv8::reg;
    exl::patch::CodePatcher p(0x01e67c64);
    p.WriteInst(Nop());
    p.WriteInst(AddImmediate(X8, X8, 0x2));
    p.WriteInst(0xeb08037f);*/ // cmp x27, x8
}
