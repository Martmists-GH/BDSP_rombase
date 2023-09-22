#pragma once

#include "memory/string.h"
#include "ui/base/element.h"
#include "ui/base/function_element.h"
#include "ui/base/slider.h"
#include "logger/logger.h"

namespace ui {
    ELEMENT(StringView) {
        nn::string buffer;
        int maxLines = 100;

        StringView() {
            addChild(SliderInt::create([this](SliderInt &s) {
                s.label = "Max lines";
                s.min = 10;
                s.max = 1000;
                s.value = maxLines;
                s.onChange = [this](int value) {
                    maxLines = value;
                };
            }));

            addChild(FunctionElement::create([this](FunctionElement &f) {
                f.callback = [this]() {
                    ImGui::TextUnformatted(buffer.c_str());
                };
            }));
        }

        void append(const char* str) {
            buffer += str;

            // trim to last N lines
            int lines = 0;
            for (long i = buffer.size() - 1; i >= 0; i--) {
                if (buffer[i] == '\n') {
                    lines++;
                    if (lines > maxLines) {
                        buffer = buffer.substr(i + 1);
                        break;
                    }
                }
            }
        }
    };
}
