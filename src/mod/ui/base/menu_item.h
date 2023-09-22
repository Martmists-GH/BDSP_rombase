#pragma once

#include "memory/string.h"
#include "ui/base/element.h"

namespace ui {
    ELEMENT(MenuItem) {
        nn::string label;
        const char *shortcut = nullptr;
        bool enabled = true;
        bool *checked;

        bool isValid() override {
            return !label.empty();
        }

        void draw() override {
            ImGui::MenuItem(label.c_str(), shortcut, checked, enabled);
        }
    };
}
