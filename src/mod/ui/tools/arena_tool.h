#pragma once

#include "data/arenas.h"
#include "data/utils.h"
#include "ui/base/collapsing_header.h"
#include "ui/base/element.h"
#include "ui/ui.h"

namespace ui {
    ELEMENT(ArenaTool) {
        ArenaTool() {
            auto header = CollapsingHeader::create([this](CollapsingHeader &_) {
                _.label = "Arena Tool";

                static bool enabled = false;
                static int id = array_index(ARENAS, "Grass");
                _.Checkbox([](Checkbox &_) {
                    _.label = "Enabled";
                    _.enabled = enabled;
                    _.onChange = [](bool value) {
                        enabled = value;
                        setArenaSettings(enabled, id);
                    };
                });

                _.ComboSimple([](ComboSimple &_) {
                    _.label = "Arena";
                    _.items = ARENAS;
                    _.items_count = ARENA_COUNT;
                    _.selected = id;
                    _.onChange = [](int _id) {
                        id = _id;
                        setArenaSettings(enabled, id);
                    };
                });
            });

            addChild(header);
        }
    };
}
