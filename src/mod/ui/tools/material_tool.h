#pragma once

#include "externals/BattleCharacterEntity.h"
#include "externals/Dpr/UI/UIManager.h"
#include "externals/FieldPokemonEntity.h"
#include "ui/base/collapsing_header.h"
#include "ui/base/element.h"
#include "ui/ui.h"

namespace ui {
    ELEMENT(MaterialTool) {
        MaterialTool() {
            auto header = CollapsingHeader::create([this](CollapsingHeader &_) {
                _.label = "Material Tool";

                _.Checkbox([](Checkbox &_) {
                    _.label = "Overwrite material colors";
                    _.enabled = false;
                    _.onChange = [](bool value) {
                        FlagWork::SetSysFlag(FlagWork_SysFlag::SYSFLAG_997, value);
                    };
                });

                auto constantPicker = _.ColorEdit3([](ColorEdit3 &_) {
                    _.label = "Field - Skin (Face)";
                });

                auto constantSdPicker = _.ColorEdit3([](ColorEdit3 &_) {
                    _.label = "Field - Skin (Face)";
                });

                _.Button([](Button &_) {
                    _.label = "Testing";
                    _.onClick = []() {
                        auto uiManager = Dpr::UI::UIManager::instance();
                        Logger::log("Getting entity type...\n");
                        auto baseEntity = uiManager->fields._modelView->fields._modelParam->fields.baseEntity;
                        Logger::log("BaseEntity %08X\n", baseEntity);

                        if (baseEntity != nullptr)
                        {
                            auto baseEntityKlass = (Il2CppClass*)baseEntity->klass;

                            if (baseEntityKlass->isOfClass((Il2CppClass*)FieldPokemonEntity::getClass()))
                            {
                                Logger::log("FieldPokemonEntity!!!!\n");
                            }

                            if (baseEntityKlass->isOfClass((Il2CppClass*)BattleCharacterEntity::getClass()))
                            {
                                Logger::log("BattleCharacterEntity!!!!\n");
                            }
                        }

                        /*auto methodPtr = *baseEntity->klass->vtable->_4_get_entityType.methodPtr;
                        auto methodInfo = baseEntity->klass->vtable->_4_get_entityType.method;
                        Logger::log("methodPtr %08X\n", methodPtr);
                        Logger::log("methodInfo %08X\n", methodInfo);
                        System::String::Object* type = methodPtr(baseEntity, methodInfo);
                        Logger::log("Entity type is: %s\n", type->asCString().c_str());*/
                    };
                });
            });

            addChild(header);
        }
    };
}
