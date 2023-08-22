#pragma once

#include "data/items.h"
#include "data/utils.h"
#include "externals/ItemWork.h"
#include "ui/base/collapsing_header.h"
#include "ui/base/element.h"

namespace ui {
    ELEMENT(ItemTool) {
        ItemTool() {
            auto header = CollapsingHeader::create([this](CollapsingHeader &_) {
                _.label = "Item Tool";

                auto* item = _.ComboSimple([](ComboSimple &_) {
                    _.label = "Item";
                    _.items = ITEMS;
                    _.items_count = ITEM_COUNT;
                    _.selected = array_index(ITEMS, "Master Ball");
                });

                auto *amount = _.InputInt([](InputInt &_) {
                    _.label = "Amount";
                    _.min = 1;
                    _.max = 100;
                    _.value = 1;
                });

                _.Button([item, amount](Button &_) {
                    _.label = "Give Item";
                    _.onClick = [item, amount]() {
                        ItemWork::AddItem(item->selected, amount->value);
                    };
                });
            });

            addChild(header);
        }
    };
}
