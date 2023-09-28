#pragma once

#include <vector>
#include "memory/string.h"
#include <functional>
#include "ui/base/element.h"

namespace ui {
    ELEMENT(Text) {
        nn::string content;

        bool isValid() override {
            return !content.empty();
        }

        void draw() override {
            ImGui::Text("%s", content.c_str());
        }
    };
}
