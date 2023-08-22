#pragma once

#include "data/persons.h"
#include "data/utils.h"
#include "externals/FlagWork.h"
#include "ui/base/collapsing_header.h"
#include "ui/base/element.h"

namespace ui {
    ELEMENT(ModelTool) {
        ModelTool() {
            auto header = CollapsingHeader::create([this](CollapsingHeader &_) {
                _.label = "Model Tool";

                _.Checkbox([](Checkbox &_) {
                    _.label = "Force Model in Boutique UI";
                    _.enabled = false;
                    _.onChange = [](bool value) {
                        FlagWork::SetSysFlag(FlagWork_SysFlag::SYSFLAG_998, value);
                    };
                });

                auto* fieldModel = _.ComboSimple([](ComboSimple &_) {
                    _.label = "Field Model";
                    _.items = FIELD_PERSON_NAMES;
                    _.items_count = FIELD_PERSON_NAME_COUNT;
                    _.selected = array_index(FIELD_PERSON_NAMES, "Lucas (Everyday)");
                });

                _.Button([fieldModel](Button &_) {
                    _.label = "Set Field Model";
                    _.onClick = [fieldModel]() {
                        FlagWork::SetWork(FlagWork_Work::WORK_4000, fieldModel->selected);
                    };
                });

                auto* battleModel = _.ComboSimple([](ComboSimple &_) {
                    _.label = "Battle Model";
                    _.items = BATTLE_PERSON_NAMES;
                    _.items_count = BATTLE_PERSON_NAME_COUNT;
                    _.selected = array_index(BATTLE_PERSON_NAMES, "Lucas (Everyday)");
                });

                _.Button([battleModel](Button &_) {
                    _.label = "Set Battle Model";
                    _.onClick = [battleModel]() {
                        FlagWork::SetWork(FlagWork_Work::WORK_4001, battleModel->selected);
                    };
                });
            });

            addChild(header);
        }
    };
}
