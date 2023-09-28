#pragma once

#include <vector>
#include "memory/string.h"
#include <functional>
#include "externals/UnityEngine/Vector2.h"
#include "externals/UnityEngine/Vector3.h"
#include "ui/base/element.h"

namespace ui {
    ELEMENT(SliderFloat) {
        nn::string label;
        float value = 1.0f;
        float min = 0.0f;
        float max = 100.0f;

        bool isValid() override {
            return !label.empty() &&
            (min <= value) && (value <= max);
        }

        void draw() override {
            ImGui::SliderFloat(label.c_str(), &value, min, max, "%.2f");
        }
    };

    ELEMENT(SliderFloat2) {
        nn::string label;
        UnityEngine::Vector2::Fields value;
        float min = 0.0f;
        float max = 100.0f;

        bool isValid() override {
            return !label.empty() &&
            (min <= value.x) && (value.x <= max) &&
            (min <= value.y) && (value.y <= max);
        }

        void draw() override {
            ImGui::SliderFloat2(label.c_str(), (float*)&value, min, max, "%.2f");
        }
    };

    ELEMENT(SliderFloat3) {
        nn::string label;
        UnityEngine::Vector3::Fields value;
        float min = 0.0f;
        float max = 100.0f;

        bool isValid() override {
            return !label.empty() &&
            (min <= value.x) && (value.x <= max) &&
            (min <= value.y) && (value.y <= max) &&
            (min <= value.z) && (value.z <= max);
        }

        void draw() override {
            ImGui::SliderFloat3(label.c_str(), (float*)&value, min, max, "%.2f");
        }
    };

    ELEMENT(SliderInt) {
        nn::string label;
        int min, max, value;
        std::function<void(int)> onChange;

        bool isValid() override {
            return !label.empty() && (min <= value) && (value <= max) && onChange != nullptr;
        }

        void render() override {
            if (ImGui::SliderInt(label.c_str(), &value, min, max)) {
                onChange(value);
            }
        }
    };
}
