#include "exlaunch.hpp"

#include "externals/il2cpp-api.h"
#include "externals/Dpr/UI/PoketchWindow.h"
#include "externals/UnityEngine/Component.h"
#include "ui/ui.h"

void goBackAction(Dpr::UI::PoketchWindow* __this) {
    __this->SelectApp(false);
}

HOOK_DEFINE_INLINE(PoketchInBoundsCheck) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        auto res = ctx->X[0];
        auto prevCheck = ctx->W[8];
        if (prevCheck == 0 || (res & 1) != 0) return;

        auto window = (Dpr::UI::PoketchWindow::Object*)ctx->X[19];

        auto windowTransform = window->cast<UnityEngine::Component>()->get_transform();
        auto buttonTransform = windowTransform->GetChild({ 1, 0, 1, 0, 2});
        auto button = buttonTransform->GetComponent<Dpr::UI::PoketchButton>(window->fields._changeButton->klass);

        // Get float values from registers (not yet supported through ctx, see: https://github.com/shadowninja108/exlaunch/issues/1)
        float x, y;
        __asm(
            R"(
                mov %0.16B, v8.16B
                mov %1.16B, v9.16B
            )"
            : "=w"(x), "=w"(y)
        );

        if (button != nullptr && window->IsInRange(button, x, y)) {
            button->OnPush();
        }
    }
};

HOOK_DEFINE_TRAMPOLINE(PoketchAppButtonExtend) {
    static void Callback(Dpr::UI::PoketchWindow::Object* window) {
        Orig(window);

        auto windowTransform = window->cast<UnityEngine::Component>()->get_transform();
        auto mask = windowTransform->GetChild({ 1, 0, 1, 0 });

        auto change = window->fields._changeButton;
        auto newButton = UnityEngine::_Object::Instantiate<UnityEngine::Transform>(change->cast<UnityEngine::Component>()->get_transform());

        newButton->SetParent(mask, false);
        auto btn = newButton->GetComponent<Dpr::UI::PoketchButton>(change->klass);

        // Reposition button
        UnityEngine::Vector3::Object trans {
                .fields = UnityEngine::Vector3::Fields {
                        .x = 0.0f,
                        .y = 0.0f,
                        .z = 0.0f,
                }
        };
        newButton->Translate(&trans);

        // Change button action
        ILMethod mi(change->fields._onButtonAction->fields.method);
        auto action = change->fields._onButtonAction->klass->newInstance(window, mi.copyWith((Il2CppMethodPointer) &goBackAction));
        btn->Initialize(action, -1);

        // Seems to largely get ignored?
        window->fields._preButton = btn;

        auto apps = window->fields._poketchAppList->fields._items;
        for (int i = 0; i < apps->max_length; i++) {
            auto app = apps->m_Items[i];
            auto size = app->fields.Buttons->max_length;
            auto newArray = (Dpr::UI::PoketchButton::Array*)system_array_new(app->fields.Buttons->obj.klass, size + 1);
            app->fields.Buttons->copyInto(&newArray->m_Items[0]);
            app->fields.Buttons = newArray;
            app->fields.Buttons->m_Items[size] = btn;
        }
    }
};

void exl_poketch_main() {
    PoketchInBoundsCheck::InstallAtOffset(0x01e67660);
    PoketchAppButtonExtend::InstallAtOffset(0x01e66870);
}
