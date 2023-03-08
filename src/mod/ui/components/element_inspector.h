#pragma once

#include "ui/base/element.h"
#include "ui/base/combo.h"
#include "ui/base/selectable.h"
#include "nn/fs/fs_directories.hpp"
#include "nn/result.h"
#include "logger/logger.h"
#include "externals/UnityEngine/Transform.h"
#include "externals/UnityEngine/_Object.h"
#include "externals/UnityEngine/UI/ListPool.h"

namespace ui {
    ELEMENT(ElementInspector) {
        UnityEngine::Transform* root;
        bool showChildren = true;
        bool showComponents = false;

        bool beginDraw() override {
            return root != nullptr;
        }

        void draw() override {
            drawElement(root);
        }

    private:
        void drawElement(UnityEngine::Transform* element, const std::string& prefix = "") {
            auto name = element->cast<UnityEngine::_Object>()->GetName();
            auto str = prefix + name->asCString();
            if (ImGui::TreeNode(str.c_str())) {
                auto childCount = element->get_childCount();
                auto list = UnityEngine::UI::ListPool::Get(UnityEngine::UI::ListPool::Method$$Component$$Get);
                System::RuntimeTypeHandle::Object handle{};
                handle.fields.value = &UnityEngine::Component::getClass()->_1.byval_arg;
                element->cast<UnityEngine::Component>()->GetComponents(System::Type::GetTypeFromHandle(handle), list);
                auto componentCount = list->fields._size;

                if (showChildren) {
                    for (int i = 0; i < childCount; i++) {
                        auto child = element->GetChild(i);
                        drawElement(child, std::to_string(i) + ": ");
                    }
                }

                if (showChildren && showComponents && childCount > 0 && componentCount > 0) {
                    ImGui::Separator();
                }

                if (showComponents) {
                    for (int i = 0; i < list->fields._size; i++) {
                        auto component = list->fields._items->m_Items[i];
                        ImGui::Text("%s", component->klass->_1.name);
                    }
                }

                ImGui::TreePop();
            }
        }
    };
}
