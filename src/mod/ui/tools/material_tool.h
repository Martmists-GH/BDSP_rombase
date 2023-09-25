#pragma once

#include "data/species.h"
#include "externals/ZukanWork.h"
#include "ui/base/collapsing_header.h"
#include "ui/base/element.h"
#include "ui/ui.h"

namespace ui {
    ELEMENT(MaterialTool) {
        MaterialTool() {
            auto header = CollapsingHeader::create([this](CollapsingHeader &_) {
                _.label = "Material Tool";

                _.Button([](Button &_) {
                    _.label = "Billionaire!";
                    _.onClick = []() {
                        PlayerWork::SetMoney(999999);
                    };
                });
            });

            addChild(header);
        }
    };
}
