#pragma once

#include "externals/BattleCharacterEntity.h"
#include "externals/Dpr/UI/UIManager.h"
#include "externals/FieldPokemonEntity.h"
#include "externals/UnityEngine/_Object.h"
#include "externals/UnityEngine/SkinnedMeshRenderer.h"
#include "ui/base/collapsing_header.h"
#include "ui/base/element.h"
#include "ui/ui.h"

void Debug_LogUIEntityRenderers() {
    system_load_typeinfo(0x7deb);
    system_load_typeinfo(0x1e84);
    system_load_typeinfo(0x1e8d);

    auto uiManager = Dpr::UI::UIManager::instance();
    auto go = uiManager->fields._modelView->fields._modelParam->fields.gameObject;
    auto unityObj = (UnityEngine::_Object::Object*)go;
    Logger::log("GameObject %s\n", unityObj->GetName()->asCString().c_str());
    ui_inspect(go->get_transform());

    auto renderers = go->GetComponentsInChildren(false, UnityEngine::GameObject::Method$$SkinnedMeshRenderer$$GetComponentsInChildren);
    if (renderers != nullptr)
    {
        for (uint64_t i=0; i<renderers->max_length; i++)
        {
            auto renderer = (UnityEngine::Renderer::Object*)renderers->m_Items[i];
            Logger::log("  Renderer %d = %s\n", i, ((UnityEngine::_Object::Object*)renderer)->GetName()->asCString().c_str());
            auto materials = renderer->get_materials();
            for (uint64_t j=0; j<materials->max_length; j++)
            {
                auto material = materials->m_Items[j];
                Logger::log("    Material %d = %s\n", j, ((UnityEngine::_Object::Object*)material)->GetName()->asCString().c_str());
            }
        }
    }
}

namespace ui {
    ELEMENT(MaterialTool) {
        MaterialTool() {
            auto header = CollapsingHeader::create([this](CollapsingHeader &_) {
                _.label = "Material Tool";

                auto colorPicker = _.ColorEdit3([](ColorEdit3 &_) {
                    _.label = "Color Value";
                });

                _.Button([](Button &_) {
                    _.label = "Log Renderers and Materials";
                    _.onClick = []() {
                        Debug_LogUIEntityRenderers();
                    };
                });

                _.Button([](Button &_) {
                    _.label = "Log Properties of Selected Material";
                    _.onClick = []() {
                        Debug_LogUIEntityRenderers();
                    };
                });
            });

            addChild(header);
        }
    };
}
