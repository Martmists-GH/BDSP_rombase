#pragma once

#include "ui/base/element.h"
#include "ui/base/button.h"
#include "ui/base/checkbox.h"
#include "ui/base/child.h"
#include "ui/base/combo.h"
#include "ui/base/combo_simple.h"
#include "ui/base/menu_bar.h"
#include "ui/base/slider.h"
#include "ui/base/spacing.h"
#include "ui/base/text.h"
#include "ui/base/text_unformatted.h"
#include "ui/components/file_selector.h"
#include "input_int.h"
#include "ui/components/string_view.h"
#include "ui/components/element_inspector.h"


namespace ui {
    ELEMENT(CollapsingHeader) {
        std::string label;
        ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_None;

        bool isValid() override {
            return !label.empty();
        }

        bool beginDraw() override {
            return ImGui::CollapsingHeader(label.c_str());
        };

        COMMON_ELEMENTS();
    };
}
