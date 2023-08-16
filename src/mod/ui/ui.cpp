#include "externals/il2cpp.h"

#include "data/arenas.h"
#include "data/balls.h"
#include "data/clip_names.h"
#include "data/debug.h"
#include "data/items.h"
#include "data/moves.h"
#include "data/species.h"
#include "data/utils.h"
#include "data/zones.h"
#include "externals/Dpr/EvScript/EvDataManager.h"
#include "externals/Dpr/EvScript/EvCmdID.h"
#include "externals/FlagWork.h"
#include "externals/ItemWork.h"
#include "externals/PlayerWork.h"
#include "externals/Pml/PokePara/InitialSpec.h"
#include "externals/Pml/PokePara/PokemonParam.h"
#include "externals/poketool/poke_memo/poketool_poke_memo.h"
#include "externals/ZukanWork.h"

#include "logger/logger.h"
#include "save/save.h"
#include "ui/ui.h"

using namespace ui;

static Window debugLogWindow = Window::single([](Window &_) {
    _.title = "Debug Log";
    auto *view = _.StringView();

    // WARNING: Turning this on is a ticking time bomb.
    // Eventually there are too many logs and the game hangs.
    /*Logger::addListener([view](const char *message) {
        view->append(message);
    });*/
});

static ElementInspector inspector = ElementInspector::single([](ElementInspector &_) {

});

void ui_inspect(UnityEngine::Transform* transform) {
    inspector.root = transform;
}

static Window inspectorWindow = Window::single([](Window &_) {
    _.title = "Inspector";
    _.flags |= ImGuiWindowFlags_MenuBar;
    _.initialPos = ImVec2(50, 50);
    _.initialSize = ImVec2(600, 650);
    _.allow_static = true;

    _.MenuBar([](MenuBar &_) {
        _.Menu([](Menu &_) {
            _.label = "Options";
            _.MenuItem([](MenuItem &_) {
                _.label = "Show Children";
                _.checked = &inspector.showChildren;
            });
            _.MenuItem([](MenuItem &_) {
                _.label = "Show Components";
                _.checked = &inspector.showComponents;
            });
        });
    });
    _.addChild(&inspector);
});

static Window mainWindow = Window::single([](Window &_) {
    _.title = "BDSP Toolbox";
    _.toggleable = false;
    _.flags |= ImGuiWindowFlags_MenuBar;
    _.initialPos = ImVec2(50, 50);
    _.initialSize = ImVec2(250, 300);

    _.Text([](Text &_) {
        _.content = "Press ZL+ZR to toggle all menus.\nHold L to walk through walls.";
    });

    _.Spacing();

    _.MenuBar([](MenuBar &_) {
        _.Menu([](Menu &_) {
            _.label = "Tools";
            _.MenuItem([](MenuItem &_) {
                _.label = "Debug Log";
                _.checked = &debugLogWindow.open;
            });
            _.MenuItem([](MenuItem &_) {
                _.label = "Inspector";
                _.checked = &inspectorWindow.open;
            });
        });
    });

    _.CollapsingHeader([](CollapsingHeader &_) {
        _.label = "Item Tool";

        auto* item = _.ComboSimple([](ComboSimple &_) {
            _.label = " Item";
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

    _.CollapsingHeader([](CollapsingHeader &_) {
        _.label = "Pokemon Tool";

        auto* species = _.ComboSimple([](ComboSimple &_) {
            _.label = " Species";
            _.items = SPECIES;
            _.items_count = SPECIES_COUNT;
            _.selected =  array_index(SPECIES, "Bulbasaur");
        });
        auto *form = _.InputInt([](InputInt &_) {
            _.label = "Form";
            _.min = 0;
            _.max = 100;
            _.value = 0;
        });
        auto *level = _.InputInt([](InputInt &_) {
            _.label = "Level";
            _.min = 1;
            _.max = 100;
            _.value = 5;
        });
        auto *ball = _.ComboSimple([](ComboSimple &_) {
            _.label = "Caught Ball";
            _.items = BALLS;
            _.items_count = BALL_COUNT;
            _.selected = array_index(BALLS, "--BALL ZERO--");
        });
        auto *sex = _.ComboSimple([](ComboSimple &_) {
            _.label = "Sex";
            _.items = DEBUG_SEXES;
            _.items_count = DEBUG_SEX_COUNT;
            _.selected = array_index(DEBUG_SEXES, "-");
        });
        auto *shiny = _.ComboSimple([](ComboSimple &_) {
            _.label = "Shininess";
            _.items = DEBUG_SHINIES;
            _.items_count = DEBUG_SHINY_COUNT;
            _.selected = array_index(DEBUG_SHINIES, "-");
        });
        auto* customMoves = _.Checkbox([](Checkbox &_) {
            _.label = "Custom moves";
            _.enabled = false;
        });
        auto *move1 = _.ComboSimple([](ComboSimple &_) {
            _.label = " Move 1";
            _.items = MOVES;
            _.items_count = MOVE_COUNT;
            _.selected = array_index(MOVES, "Pound");
        });
        auto *move2 = _.ComboSimple([](ComboSimple &_) {
            _.label = " Move 2";
            _.items = MOVES;
            _.items_count = MOVE_COUNT;
            _.selected = array_index(MOVES, "Karate Chop");
        });
        auto *move3 = _.ComboSimple([](ComboSimple &_) {
            _.label = " Move 3";
            _.items = MOVES;
            _.items_count = MOVE_COUNT;
            _.selected = array_index(MOVES, "Double Slap");
        });
        auto *move4 = _.ComboSimple([](ComboSimple &_) {
            _.label = " Move 4";
            _.items = MOVES;
            _.items_count = MOVE_COUNT;
            _.selected = array_index(MOVES, "Comet Punch");
        });

        _.Button([species, form, level, ball, sex, shiny, customMoves, move1, move2, move3, move4](Button &_) {
            _.label = "Give Pokemon";
            _.onClick = [species, form, level, ball, sex, shiny, customMoves, move1, move2, move3, move4]() {
                system_load_typeinfo(0x43be);
                auto party = PlayerWork::get_playerParty();

                auto initialSpec = Pml::PokePara::InitialSpec::newInstance();
                initialSpec->fields.monsno = species->selected;
                initialSpec->fields.formno = form->value;
                initialSpec->fields.level = level->value;
                if (sex->selected == array_index(DEBUG_SEXES, "Male"))
                    initialSpec->fields.sex = 0;
                else if (sex->selected == array_index(DEBUG_SEXES, "Female"))
                    initialSpec->fields.sex = 1;
                else if (sex->selected == array_index(DEBUG_SEXES, "Genderless"))
                    initialSpec->fields.sex = 2;

                auto param = Pml::PokePara::PokemonParam::newInstance(initialSpec);
                auto core = param->cast<Pml::PokePara::CoreParam>();

                if (customMoves->enabled)
                {
                    core->SetWaza(0, move1->selected);
                    core->SetWaza(1, move2->selected);
                    core->SetWaza(2, move3->selected);
                    core->SetWaza(3, move4->selected);
                }
                core->SetGetBall(ball->selected);
                if (shiny->selected == array_index(DEBUG_SHINIES, "Non-shiny"))
                    core->SetRareType(0);
                else if (shiny->selected == array_index(DEBUG_SHINIES, "Shiny"))
                    core->SetRareType(1);
                else if (shiny->selected == array_index(DEBUG_SHINIES, "Square Shiny"))
                    core->SetRareType(2);

                auto myStatus = PlayerWork::get_playerStatus();
                auto zoneID = PlayerWork::get_zoneID();
                poketool::poke_memo::poketool_poke_memo::SetFromCapture((Pml::PokePara::CoreParam::Object*)param, myStatus, zoneID);
                if (!party->AddMember(param))
                    Logger::log("Could not give Pokémon!\n");
            };
        });
    });

    _.CollapsingHeader([](CollapsingHeader &_) {
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
            _.label = " Arena";
            _.items = ARENAS;
            _.items_count = ARENA_COUNT;
            _.selected = id;
            _.onChange = [](int _id) {
                id = _id;
                setArenaSettings(enabled, id);
            };
        });
    });

    _.CollapsingHeader([](CollapsingHeader &_) {
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

    _.CollapsingHeader([](CollapsingHeader &_) {
        _.label = "Misc Tools";

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
    });

    _.CollapsingHeader([](CollapsingHeader& _){
        _.label = "Save Tools";

        _.Button([](Button &_) {
            _.label = "Delete custom save";
            _.onClick = []() {
                if (nn::fs::DeleteFile("SaveData:/Custom.bin").isSuccess()) {
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

    _.CollapsingHeader([](CollapsingHeader& _){
        _.label = "Natdex Tools";

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

        auto* loopAnim = _.Checkbox([](Checkbox &_) {
            _.label = "Loop Animation";
            _.enabled = true;
        });

        _.Checkbox([](Checkbox &_) {
            _.label = "Force Battle Bundles in UI";
            _.enabled = false;
            _.onChange = [](bool value) {
                FlagWork::SetSysFlag(FlagWork_SysFlag::SYSFLAG_999, value);
            };
        });

        auto *fieldAnimationId = _.ComboSimple([](ComboSimple &_) {
            _.label = "Field Animation ID";
            _.items = FIELD_MON_CLIPS;
            _.items_count = FIELD_MON_CLIP_COUNT;
            _.selected = array_index(FIELD_MON_CLIPS, "Idle");
        });

        auto *battleAnimationId = _.ComboSimple([](ComboSimple &_) {
            _.label = "Battle Animation ID";
            _.items = BATTLE_MON_CLIPS;
            _.items_count = BATTLE_MON_CLIP_COUNT;
            _.selected = array_index(BATTLE_MON_CLIPS, "WaitA01");
        });

        _.Button([fieldAnimationId, loopAnim](Button &_) {
            _.label = "Play Field Animation";
            _.onClick = [fieldAnimationId, loopAnim]() {
                auto uiManager = Dpr::UI::UIManager::instance();
                Logger::log("Playing Field Animation %s (%d)\n", FIELD_MON_CLIPS[fieldAnimationId->selected], fieldAnimationId->selected);
                uiManager->fields._modelView->PlayAnimation(fieldAnimationId->selected, loopAnim->enabled);
            };
        });

        _.Button([battleAnimationId, loopAnim](Button &_) {
            _.label = "Play Battle Animation";
            _.onClick = [battleAnimationId, loopAnim]() {
                auto uiManager = Dpr::UI::UIManager::instance();
                Logger::log("Playing Battle Animation %s (%d)\n", BATTLE_MON_CLIPS[battleAnimationId->selected], battleAnimationId->selected);
                uiManager->fields._modelView->PlayAnimation(battleAnimationId->selected, loopAnim->enabled);
            };
        });
    });
});

void setup_ui() {
    ROOT->addChild(&mainWindow);
    ROOT->addChild(&debugLogWindow);
    ROOT->addChild(&inspectorWindow);
}
