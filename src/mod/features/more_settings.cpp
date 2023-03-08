#include <utility>

#include "exlaunch.hpp"
#include "externals/Dpr/UI/SettingWindow.h"
#include "logger/logger.h"
#include "externals/FlagWork.h"
#include "externals/PlayerWork.h"
#include "externals/UnityEngine/UI/HorizontalLayoutGroup.h"
#include "ui/ui.h"

HOOK_DEFINE_TRAMPOLINE(GetSetting) {
    static int32_t Callback(DPData::CONFIG::Object* __this, int32_t id) {
        switch (id) {
            case 14:
                return FlagWork::GetFlag(FLAG_AFFECTION_ENABLED);
            default:
                return Orig(__this, id);
                break;
        }
    }
};

HOOK_DEFINE_TRAMPOLINE(SetSetting) {
    static void Callback(DPData::CONFIG::Object* __this, int32_t id, int32_t value) {
        switch (id) {
            case 14:
                FlagWork::SetFlag(FLAG_AFFECTION_ENABLED, value);
                break;
            default:
                Orig(__this, id, value);
                break;
        }
    }
};

HOOK_DEFINE_TRAMPOLINE(SettingIsEqual) {
    static bool Callback(DPData::CONFIG::Object* __this, int32_t id, DPData::CONFIG::Object* other) {
        switch (id) {
            case 14:
                // TODO: Rewrite to support comparisons, otherwise reverting settings does not work
                return true;
            default:
                return Orig(__this, id, other);
                break;
        }
    }
};


HOOK_DEFINE_TRAMPOLINE(AddSettingsEntries) {
    static bool Callback(Dpr::UI::SettingWindow::_OpOpen_d__11::Object* __this) {
        auto res = Orig(__this);

        auto window = __this->fields.__4__this;
        ui_inspect(window->cast<UnityEngine::Component>()->get_transform());
        if (window->fields._activeItems->fields._size > 13) {
            return res;
        }

        // Warning: This will crash if ss_option does not contain SS_option_109 through SS_option_113

        system_load_typeinfo(0x870a);

        auto contentRoot = window->fields._scrollRect->fields.m_Content;
        auto child = contentRoot->cast<UnityEngine::Transform>()->GetChild(4);

        // TODO: Clean up this logic to be easier to use, maybe an external setting structure?
        auto origItem = child->cast<UnityEngine::Component>()->GetComponent(UnityEngine::Component::Method$$SettingMenuItem$$GetComponent);

        auto newTransform = UnityEngine::_Object::Instantiate<UnityEngine::Transform>(child);
        newTransform->SetParent(contentRoot->cast<UnityEngine::Transform>(), false);

        Dpr::UI::SettingMenuItem::Object* newItem = newTransform->cast<UnityEngine::Component>()->GetComponent(UnityEngine::Component::Method$$SettingMenuItem$$GetComponent);
        newItem->Setup(14, FlagWork::GetFlag(FLAG_AFFECTION_ENABLED), System::String::Create("SS_option_113"), origItem->fields._onValueChanged);
        auto textRoot = newTransform->GetChild(1);
        auto title = textRoot->GetChild(0);
        system_load_typeinfo(0x870a);
        auto titleComponent = title->cast<UnityEngine::Component>()->GetComponent(UnityEngine::Component::Method$$UIText$$GetComponent);
        titleComponent->SetupMessage(
            System::String::Create("ss_option"),
            System::String::Create("SS_option_109")
        );
        auto options = textRoot->GetChild(1)->GetChild(0);
        for (int i = 0; i < 2; i++) {
            auto option = options->GetChild(i)->GetChild(0)->cast<UnityEngine::Component>()->GetComponent(UnityEngine::Component::Method$$UIText$$GetComponent);
            option->SetupMessage(
                System::String::Create("ss_option"),
                System::String::Create("SS_option_" + std::to_string(110 + i))
            );
        }

        // Insert at x
        auto x = 1;
        newTransform->SetSiblingIndex(x+1);
        window->fields._activeItems->insert(newItem, x);

        return res;
    }
};


void exl_settings_main() {
    AddSettingsEntries::InstallAtOffset(0x01d42830);
    GetSetting::InstallAtOffset(0x02299720);
    SetSetting::InstallAtOffset(0x022997d0);
    SettingIsEqual::InstallAtOffset(0x022998a0);
}
