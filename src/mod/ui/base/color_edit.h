#pragma once

#include <vector>
#include <string>
#include <functional>
#include "ui/base/element.h"

namespace ui {
    ELEMENT(ColorEdit3) {
        std::string label;
        ImVec4 value;

        bool isValid() override {
            return !label.empty();
        }

        void draw() override {
            ImGui::ColorEdit3(label.c_str(), (float*)&value, ImGuiColorEditFlags_None);
        }
    };
}
