#pragma once

#include "data/species.h"
#include "externals/Dpr/EvScript/EvCmdID.h"
#include "externals/Dpr/EvScript/EvDataManager.h"
#include "externals/ZukanWork.h"
#include "ui/base/collapsing_header.h"
#include "ui/base/element.h"
#include "ui/ui.h"

namespace ui {
    ELEMENT(MiscTool) {
        MiscTool() {
            auto header = CollapsingHeader::create([this](CollapsingHeader &_) {
                _.label = "Misc Tool";

                _.Button([](Button &_) {
                    _.label = "Billionaire!";
                    _.onClick = []() {
                        PlayerWork::SetMoney(999999);
                    };
                });

                _.Button([](Button &_) {
                    _.label = "Play last area name";
                    _.onClick = []() {
                        showAreaName();
                    };
                });

                _.Checkbox([](Checkbox &_) {
                    _.label = "Fly anywhere";
                    _.enabled = false;
                    _.onChange = [](bool value) {
                        setFlyOverride(value);
                    };
                });

                _.Button([](Button &_) {
                    _.label = "Register all Pokémon to Dex";
                    _.onClick = []() {
                        for (int i = 1; i <= SPECIES_COUNT; i++){
                            ZukanWork::SetPoke(i, 3, 0, 0, true);
                            ZukanWork::SetPoke(i, 3, 1, 0, true);
                            ZukanWork::SetPoke(i, 3, 0, 0, false);
                            ZukanWork::SetPoke(i, 3, 1, 0, false);
                        }
                    };
                });

                _.Button([](Button &_) {
                    _.label = "Poffins";
                    _.onClick = []() {
                        Logger::log("Trying to add Poffin\n");
                        Dpr::EvScript::EvDataManager::Object * evDataManager = Dpr::EvScript::EvDataManager::get_Instanse();
                        evDataManager->RunEvCmd((int32_t)Dpr::EvScript::EvCmdID::NAME::_ADD_MAROYAKA_POFFIN);
                        Logger::log("Added Poffin\n");
                    };
                });
            });

            addChild(header);
        }
    };
}
