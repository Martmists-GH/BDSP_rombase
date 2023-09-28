#pragma once

#include <vector>
#include "memory/string.h"
#include <functional>
#include "ui/base/element.h"

namespace ui {
    ELEMENT(Button) {
        nn::string label;
        std::function<void()> onClick;

        bool isValid()
        override{
                return !label.empty() && onClick;
        }

        void draw()
        override{
                if (ImGui::Button(label.c_str())) {
                    onClick();
                }
        }
    };
}
