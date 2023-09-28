#pragma once

#include <vector>
#include "memory/string.h"
#include <functional>
#include "ui/base/element.h"

namespace ui {
    ELEMENT(ColorEdit3) {
        nn::string label;
        ImVec4 value;
        float min = 0;
        float max = 1;

        bool isValid() override {
            return !label.empty() &&
                (min <= value.x) && (value.x <= max) &&
                (min <= value.y) && (value.y <= max) &&
                (min <= value.z) && (value.z <= max) &&
                (min <= value.w) && (value.w <= max);
        }

        void draw() override {
            ImGui::ColorEdit3(label.c_str(), (float*)&value, ImGuiColorEditFlags_None);
        }
    };
}
