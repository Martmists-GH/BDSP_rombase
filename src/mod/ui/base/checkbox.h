#pragma once

#include <vector>
#include "memory/string.h"
#include <functional>
#include "ui/base/element.h"

namespace ui {
    ELEMENT(Checkbox) {
        nn::string label;
        bool enabled = false;
        std::function<void(bool)> onChange;

        bool isValid() override {
            return !label.empty();
        }

        void draw() override{
            if (ImGui::Checkbox(label.c_str(), &enabled)) {
                if (onChange) {
                    onChange(enabled);
                }
            }
        }
    };
}
