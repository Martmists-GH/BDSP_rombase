#pragma once

#include "externals/FlagWork.h"
#include "save/save.h"
#include "ui/base/collapsing_header.h"
#include "ui/base/element.h"

namespace ui {
    ELEMENT(VariablesTool) {
        VariablesTool() {
            auto header = CollapsingHeader::create([this](CollapsingHeader &_) {
                _.label = "Variables Tool";

                auto *flagSelector = _.InputInt([](InputInt &_) {
                    _.label = "Flag";
                    _.min = 0;
                    _.max = FlagCount;
                    _.value = 0;
                });

                auto *flagValue = _.Checkbox([](Checkbox &_) {
                    _.label = "Flag State";
                    _.enabled = false;
                });

                _.Button([flagSelector, flagValue](Button &_) {
                    _.label = "Set Flag State";
                    _.onClick = [flagSelector, flagValue]() {
                        FlagWork::SetSysFlag(flagSelector->value, flagValue->enabled);
                    };
                });

                _.Spacing();

                auto *sysFlagSelector = _.InputInt([](InputInt &_) {
                    _.label = "System Flag";
                    _.min = 0;
                    _.max = SysFlagCount;
                    _.value = 0;
                });

                auto *sysFlagValue = _.Checkbox([](Checkbox &_) {
                    _.label = "System Flag State";
                    _.enabled = false;
                });

                _.Button([sysFlagSelector, sysFlagValue](Button &_) {
                    _.label = "Set System Flag State";
                    _.onClick = [sysFlagSelector, sysFlagValue]() {
                        FlagWork::SetSysFlag(sysFlagSelector->value, sysFlagValue->enabled);
                    };
                });

                _.Spacing();

                auto *workSelector = _.InputInt([](InputInt &_) {
                    _.label = "Work";
                    _.min = 0;
                    _.max = WorkCount;
                    _.value = 0;
                });

                auto *workValue = _.InputInt([](InputInt &_) {
                    _.label = "Work Value";
                    _.min = 0;
                    _.max = INT32_MAX;
                    _.value = 0;
                });

                _.Button([workSelector, workValue](Button &_) {
                    _.label = "Set Work Value";
                    _.onClick = [workSelector, workValue]() {
                        FlagWork::SetWork(workSelector->value, workValue->value);
                    };
                });
            });

            addChild(header);
        }
    };
}
