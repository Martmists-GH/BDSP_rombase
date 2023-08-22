#pragma once

#include "helpers/fsHelper.h"
#include "nn/result.h"
#include "ui/base/collapsing_header.h"
#include "ui/base/element.h"

namespace ui {
    ELEMENT(SaveTool) {
        SaveTool() {
            auto header = CollapsingHeader::create([this](CollapsingHeader &_) {
                _.label = "Save Tool";

                _.Button([](Button &_) {
                    _.label = "Delete custom save";
                    _.onClick = []() {
                        nn::Result result = nn::fs::DeleteFile("SaveData:/Custom.bin");
                        if (result.isSuccess()) {
                            Logger::log("Deleted custom save\n");
                        } else {
                            Logger::log("Failed to delete custom save\n");
                        }
                    };
                });

                _.Button([](Button &_) {
                    _.label = "Dump save to SD";
                    _.onClick = []() {
                        FsHelper::writeFileToPath(getCustomSaveData(), sizeof(CustomSaveData), "sd:/SigPlat_Custom_Savedata.bin");
                    };
                });
            });

            addChild(header);
        }
    };
}
