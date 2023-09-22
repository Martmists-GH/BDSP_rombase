#pragma once

#include "memory/string.h"
#include "element.h"

namespace ui {
    ELEMENT(InputFloat) {
        nn::string label;
        float value;
        float min = 0.0f;
        float max = 100.0f;
        float step = 0.1f;
        float stepFast = 1.0f;
        std::function<void(float)> onValueChanged;

        bool isValid() override {
            return !label.empty();
        }

        void draw() override {
            if (ImGui::InputFloat(label.c_str(), &value, step, stepFast, "%.1f", ImGuiInputTextFlags_None)) {
                if (value < min) {
                    value = min;
                } else if (value > max) {
                    value = max;
                }

                if (onValueChanged) {
                    onValueChanged(value);
                }
            }
        }
    };
}
