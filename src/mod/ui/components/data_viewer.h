#pragma once

#include "ui/base/element.h"
#include "ui/base/text.h"
#include "logger/logger.h"
#include "externals/EntityManager.h"
#include "externals/PlayerWork.h"

namespace ui {
    ELEMENT(DataViewer) {

        void draw() override {
            auto entity = (FieldObjectEntity::Object *)EntityManager::getClass()->static_fields->_activeFieldPlayer_k__BackingField;

            ImGui::Text("x = %f", entity->fields.worldPosition.fields.x);
            ImGui::Text("y = %f", entity->fields.worldPosition.fields.y);
            ImGui::Text("z = %f", entity->fields.worldPosition.fields.z);
        }
    };
}
