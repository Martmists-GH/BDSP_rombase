#pragma once

#include "data/zones.h"
#include "data/utils.h"
#include "externals/PlayerWork.h"
#include "ui/base/collapsing_header.h"
#include "ui/base/element.h"

namespace ui {
    ELEMENT(WarpTool) {
        WarpTool() {
            auto header = CollapsingHeader::create([this](CollapsingHeader &_) {
                _.label = "Warp Tool";

                auto *zoneSelector = _.ComboSimple([](ComboSimple &_) {
                    _.label = " Map";
                    _.items = ZONES;
                    _.items_count = ZONE_COUNT;
                    _.selected = array_index(ZONES, "Jubilife City");
                });

                auto *warpSelector = _.InputInt([](InputInt &_) {
                    _.label = "Warp ID";
                    _.min = 0;
                    _.max = 100;
                    _.value = 0;
                });

                _.Button([zoneSelector, warpSelector](Button &_) {
                    _.label = "Warp";
                    _.onClick = [zoneSelector, warpSelector]() {
                        PlayerWork::SetWarpSorawotobu(zoneSelector->selected, warpSelector->value);
                    };
                });
            });

            addChild(header);
        }
    };
}
