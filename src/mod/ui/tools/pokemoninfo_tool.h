#pragma once

#include "data/persons.h"
#include "data/utils.h"
#include "externals/GameData/DataManager.h"
#include "ui/base/collapsing_header.h"
#include "ui/base/element.h"

namespace ui {
    ELEMENT(PokemonInfoTool) {
        PokemonInfoTool() {
            auto header = CollapsingHeader::create([this](CollapsingHeader &_) {
                _.label = "PokemonInfo Tool";

                auto* species = _.ComboSimple([](ComboSimple &_) {
                    _.label = "Species";
                    _.items = SPECIES;
                    _.items_count = SPECIES_COUNT;
                    _.selected =  array_index(SPECIES, "Bulbasaur");
                });

                auto* form = _.InputInt([](InputInt &_) {
                    _.label = "Form";
                    _.min = 0;
                    _.max = 100;
                    _.value = 0;
                });

                auto* sex = _.ComboSimple([](ComboSimple &_) {
                    _.label = "Sex";
                    _.items = DEBUG_SEXES_NO_NONE;
                    _.items_count = DEBUG_SEX_NO_NONE_COUNT;
                    _.selected = array_index(DEBUG_SEXES_NO_NONE, "Male");
                });

                auto* shiny = _.Checkbox([](Checkbox &_) {
                    _.label = "Shiny";
                    _.enabled = false;
                });

                _.Spacing();

                auto* battleScale = _.SliderFloat([](SliderFloat &_) {
                    _.label = "Battle Scale";
                    _.value = 1.0;
                    _.max = 10.0;
                });

                auto* contestScale = _.SliderFloat([](SliderFloat &_) {
                    _.label = "Contest Scale";
                    _.value = 1.0;
                    _.max = 10.0;
                });

                auto* contestSize = _.InputInt([](InputInt &_) {
                    _.label = "Contest Size";
                    _.value = 1;
                });

                auto* fieldScale = _.SliderFloat([](SliderFloat &_) {
                    _.label = "Field Scale";
                    _.value = 1.0;
                    _.max = 10.0;
                });

                auto* fieldChikaScale = _.SliderFloat([](SliderFloat &_) {
                    _.label = "Field Chika Scale";
                    _.value = 1.0;
                    _.max = 10.0;
                });

                auto* statueScale = _.SliderFloat([](SliderFloat &_) {
                    _.label = "Statue Scale";
                    _.value = 1.0;
                    _.max = 10.0;
                });

                auto* fieldWalkingScale = _.SliderFloat([](SliderFloat &_) {
                    _.label = "Field Walking Scale";
                    _.value = 1.0;
                    _.max = 10.0;
                });

                auto* fieldFureaiScale = _.SliderFloat([](SliderFloat &_) {
                    _.label = "Field Fureai Scale";
                    _.value = 1.0;
                    _.max = 10.0;
                });

                _.Spacing();

                auto* menuScale = _.SliderFloat([](SliderFloat &_) {
                    _.label = "Menu Scale";
                    _.value = 1.0;
                    _.max = 10.0;
                });

                auto* modelOffset = _.SliderFloat3([](SliderFloat3 &_) {
                    _.label = "Model Offset";
                    _.value = { 1.0f, 1.0f, 1.0f };
                    _.min = -10.0f;
                    _.max = 10.0f;
                });

                auto* modelRotationAngle = _.SliderFloat3([](SliderFloat3 &_) {
                    _.label = "Model Rotation Angle";
                    _.value = { 1.0f, 1.0f, 1.0f };
                    _.min = -360.0f;
                    _.max = 360.0f;
                });

                _.Spacing();

                auto* distributionScale = _.SliderFloat([](SliderFloat &_) {
                    _.label = "Distribution Scale";
                    _.value = 1.0;
                    _.max = 10.0;
                });

                auto* distributionModelOffset = _.SliderFloat3([](SliderFloat3 &_) {
                    _.label = "Distribution Model Offset";
                    _.value = { 0.0f, 0.0f, 0.0f };
                    _.min = -10.0f;
                    _.max = 10.0f;
                });

                auto* distributionModelRotationAngle = _.SliderFloat3([](SliderFloat3 &_) {
                    _.label = "Distribution Model Rotation Angle";
                    _.value = { 0.0f, 0.0f, 0.0f };
                    _.min = -360.0f;
                    _.max = 360.0f;
                });

                _.Spacing();

                auto* voiceScale = _.SliderFloat([](SliderFloat &_) {
                    _.label = "Voice Scale";
                    _.value = 1.0;
                    _.max = 10.0;
                });

                auto* voiceModelOffset = _.SliderFloat3([](SliderFloat3 &_) {
                    _.label = "Voice Model Offset";
                    _.value = { 0.0f, 0.0f, 0.0f };
                    _.min = -10.0f;
                    _.max = 10.0f;
                });

                auto* voiceModelRotationAngle = _.SliderFloat3([](SliderFloat3 &_) {
                    _.label = "Voice Model Rotation Angle";
                    _.value = { 0.0f, 0.0f, 0.0f };
                    _.min = -360.0f;
                    _.max = 360.0f;
                });

                _.Spacing();

                auto* centerPointOffset = _.SliderFloat3([](SliderFloat3 &_) {
                    _.label = "Center Point Offset";
                    _.value = { 0.0f, 0.0f, 0.0f };
                    _.min = -10.0f;
                    _.max = 10.0f;
                });

                auto* rotationLimitAngle = _.SliderFloat2([](SliderFloat2 &_) {
                    _.label = "Rotation Limit Angle";
                    _.value = { 0.0f, 0.0f };
                    _.min = -360.0f;
                    _.max = 360.0f;
                });

                _.Spacing();

                auto* statusScale = _.SliderFloat([](SliderFloat &_) {
                    _.label = "Status Scale";
                    _.value = 1.0;
                    _.max = 10.0;
                });

                auto* statusModelOffset = _.SliderFloat3([](SliderFloat3 &_) {
                    _.label = "Status Model Offset";
                    _.value = { 0.0f, 0.0f, 0.0f };
                    _.min = -10.0f;
                    _.max = 10.0f;
                });

                auto* statusModelRotationAngle = _.SliderFloat3([](SliderFloat3 &_) {
                    _.label = "Status Model Rotation Angle";
                    _.value = { 0.0f, 0.0f, 0.0f };
                    _.min = -360.0f;
                    _.max = 360.0f;
                });

                _.Spacing();

                auto* boxScale = _.SliderFloat([](SliderFloat &_) {
                    _.label = "Box Scale";
                    _.value = 1.0;
                    _.max = 10.0;
                });

                auto* boxModelOffset = _.SliderFloat3([](SliderFloat3 &_) {
                    _.label = "Box Model Offset";
                    _.value = { 0.0f, 0.0f, 0.0f };
                    _.min = -10.0f;
                    _.max = 10.0f;
                });

                auto* boxModelRotationAngle = _.SliderFloat3([](SliderFloat3 &_) {
                    _.label = "Box Model Rotation Angle";
                    _.value = { 0.0f, 0.0f, 0.0f };
                    _.min = -360.0f;
                    _.max = 360.0f;
                });

                _.Spacing();

                auto* compareScale = _.SliderFloat([](SliderFloat &_) {
                    _.label = "Compare Scale";
                    _.value = 1.0;
                    _.max = 10.0;
                });

                auto* compareModelOffset = _.SliderFloat3([](SliderFloat3 &_) {
                    _.label = "Compare Model Offset";
                    _.value = { 0.0f, 0.0f, 0.0f };
                    _.min = -10.0f;
                    _.max = 10.0f;
                });

                auto* compareModelRotationAngle = _.SliderFloat3([](SliderFloat3 &_) {
                    _.label = "Compare Model Rotation Angle";
                    _.value = { 0.0f, 0.0f, 0.0f };
                    _.min = -360.0f;
                    _.max = 360.0f;
                });

                _.Spacing();

                auto* brakeStart = _.SliderFloat([](SliderFloat &_) {
                    _.label = "Brake Start";
                    _.value = 1.0;
                });

                auto* brakeEnd = _.SliderFloat([](SliderFloat &_) {
                    _.label = "Brake End";
                    _.value = 1.0;
                });

                auto* walkSpeed = _.SliderFloat([](SliderFloat &_) {
                    _.label = "Walk Speed";
                    _.value = 1.0;
                });

                auto* runSpeed = _.SliderFloat([](SliderFloat &_) {
                    _.label = "Run Speed";
                    _.value = 1.0;
                });

                auto* walkStart = _.SliderFloat([](SliderFloat &_) {
                    _.label = "Walk Start";
                    _.value = 1.0;
                });

                auto* runStart = _.SliderFloat([](SliderFloat &_) {
                    _.label = "Run Start";
                    _.value = 1.0;
                });

                auto* bodySize = _.SliderFloat([](SliderFloat &_) {
                    _.label = "Body Size";
                    _.value = 1.0;
                });

                auto* appearLimit = _.SliderFloat([](SliderFloat &_) {
                    _.label = "Appear Limit";
                    _.value = 1.0;
                });

                auto* moveType = _.InputInt([](InputInt &_) {
                    _.label = "Move Type";
                    _.value = 1;
                });

                auto* groundEffect = _.InputInt([](InputInt &_) {
                    _.label = "Ground Effect";
                    _.value = 1;
                });

                auto* waitMoving = _.InputInt([](InputInt &_) {
                    _.label = "Wait Moving";
                    _.value = 1;
                });

                auto* battleAjustHeight = _.InputInt([](InputInt &_) {
                    _.label = "Battle Ajust Height";
                    _.value = 1;
                    _.max = 500;
                });

                _.Spacing();

                _.Button([species, form, sex, shiny,
                          battleScale, contestScale, contestSize, fieldScale,
                          fieldChikaScale, statueScale, fieldWalkingScale, fieldFureaiScale,
                          menuScale, modelOffset, modelRotationAngle,
                          distributionScale, distributionModelOffset, distributionModelRotationAngle,
                          voiceScale, voiceModelOffset, voiceModelRotationAngle,
                          centerPointOffset, rotationLimitAngle,
                          statusScale, statusModelOffset, statusModelRotationAngle,
                          boxScale, boxModelOffset, boxModelRotationAngle,
                          compareScale, compareModelOffset, compareModelRotationAngle,
                          brakeStart, brakeEnd, walkSpeed, runSpeed,
                          walkStart, runStart, bodySize, appearLimit,
                          moveType, groundEffect, waitMoving, battleAjustHeight](Button &_) {
                    _.label = "Load current values";
                    _.onClick = [species, form, sex, shiny,
                            battleScale, contestScale, contestSize, fieldScale,
                            fieldChikaScale, statueScale, fieldWalkingScale, fieldFureaiScale,
                            menuScale, modelOffset, modelRotationAngle,
                            distributionScale, distributionModelOffset, distributionModelRotationAngle,
                            voiceScale, voiceModelOffset, voiceModelRotationAngle,
                            centerPointOffset, rotationLimitAngle,
                            statusScale, statusModelOffset, statusModelRotationAngle,
                            boxScale, boxModelOffset, boxModelRotationAngle,
                            compareScale, compareModelOffset, compareModelRotationAngle,
                            brakeStart, brakeEnd, walkSpeed, runSpeed,
                            walkStart, runStart, bodySize, appearLimit,
                            moveType, groundEffect, waitMoving, battleAjustHeight]() {
                        Pml::Sex sexResult = Pml::Sex::MALE;
                        if (sex->selected == array_index(DEBUG_SEXES_NO_NONE, "Male"))
                            sexResult = Pml::Sex::MALE;
                        else if (sex->selected == array_index(DEBUG_SEXES_NO_NONE, "Female"))
                            sexResult = Pml::Sex::FEMALE;
                        else if (sex->selected == array_index(DEBUG_SEXES_NO_NONE, "Genderless"))
                            sexResult = Pml::Sex::UNKNOWN;

                        auto catalog = GameData::DataManager::GetPokemonCatalog(species->selected, form->value, sexResult, shiny->enabled, false);

                        battleScale->value = catalog->fields.BattleScale;
                        contestScale->value = catalog->fields.ContestScale;
                        contestSize->value = catalog->fields.ContestSize;
                        fieldScale->value = catalog->fields.FieldScale;

                        fieldChikaScale->value = catalog->fields.FieldChikaScale;
                        statueScale->value = catalog->fields.StatueScale;
                        fieldWalkingScale->value = catalog->fields.FieldWalkingScale;
                        fieldFureaiScale->value = catalog->fields.FieldFureaiScale;

                        menuScale->value = catalog->fields.MenuScale;
                        modelOffset->value = catalog->fields.ModelOffset.fields;
                        modelRotationAngle->value = catalog->fields.ModelRotationAngle.fields;

                        distributionScale->value = catalog->fields.DistributionScale;
                        distributionModelOffset->value = catalog->fields.DistributionModelOffset.fields;
                        distributionModelRotationAngle->value = catalog->fields.DistributionModelRotationAngle.fields;

                        voiceScale->value = catalog->fields.VoiceScale;
                        voiceModelOffset->value = catalog->fields.VoiceModelOffset.fields;
                        voiceModelRotationAngle->value = catalog->fields.VoiceModelRotationAngle.fields;

                        centerPointOffset->value = catalog->fields.CenterPointOffset.fields;
                        rotationLimitAngle->value = catalog->fields.RotationLimitAngle.fields;

                        statusScale->value = catalog->fields.StatusScale;
                        statusModelOffset->value = catalog->fields.StatusModelOffset.fields;
                        statusModelRotationAngle->value = catalog->fields.StatusModelRotationAngle.fields;

                        boxScale->value = catalog->fields.BoxScale;
                        boxModelOffset->value = catalog->fields.BoxModelOffset.fields;
                        boxModelRotationAngle->value = catalog->fields.BoxModelRotationAngle.fields;

                        compareScale->value = catalog->fields.CompareScale;
                        compareModelOffset->value = catalog->fields.CompareModelOffset.fields;
                        compareModelRotationAngle->value = catalog->fields.CompareModelRotationAngle.fields;

                        brakeStart->value = catalog->fields.BrakeStart;
                        brakeEnd->value = catalog->fields.BrakeEnd;
                        walkSpeed->value = catalog->fields.WalkSpeed;
                        runSpeed->value = catalog->fields.RunSpeed;

                        walkStart->value = catalog->fields.WalkStart;
                        runStart->value = catalog->fields.RunStart;
                        bodySize->value = catalog->fields.BodySize;
                        appearLimit->value = catalog->fields.AppearLimit;

                        moveType->value = catalog->fields.MoveType;
                        groundEffect->value = catalog->fields.GroundEffect;
                        waitMoving->value = catalog->fields.Waitmoving;
                        battleAjustHeight->value = catalog->fields.BattleAjustHeight;
                    };
                });

                _.Button([species, form, sex, shiny,
                         battleScale, contestScale, contestSize, fieldScale,
                         fieldChikaScale, statueScale, fieldWalkingScale, fieldFureaiScale,
                         menuScale, modelOffset, modelRotationAngle,
                         distributionScale, distributionModelOffset, distributionModelRotationAngle,
                         voiceScale, voiceModelOffset, voiceModelRotationAngle,
                         centerPointOffset, rotationLimitAngle,
                         statusScale, statusModelOffset, statusModelRotationAngle,
                         boxScale, boxModelOffset, boxModelRotationAngle,
                         compareScale, compareModelOffset, compareModelRotationAngle,
                         brakeStart, brakeEnd, walkSpeed, runSpeed,
                         walkStart, runStart, bodySize, appearLimit,
                         moveType, groundEffect, waitMoving, battleAjustHeight](Button &_) {
                    _.label = "Apply values";
                    _.onClick = [species, form, sex, shiny,
                            battleScale, contestScale, contestSize, fieldScale,
                            fieldChikaScale, statueScale, fieldWalkingScale, fieldFureaiScale,
                            menuScale, modelOffset, modelRotationAngle,
                            distributionScale, distributionModelOffset, distributionModelRotationAngle,
                            voiceScale, voiceModelOffset, voiceModelRotationAngle,
                            centerPointOffset, rotationLimitAngle,
                            statusScale, statusModelOffset, statusModelRotationAngle,
                            boxScale, boxModelOffset, boxModelRotationAngle,
                            compareScale, compareModelOffset, compareModelRotationAngle,
                            brakeStart, brakeEnd, walkSpeed, runSpeed,
                            walkStart, runStart, bodySize, appearLimit,
                            moveType, groundEffect, waitMoving, battleAjustHeight]() {
                        Pml::Sex sexResult = Pml::Sex::MALE;
                        if (sex->selected == array_index(DEBUG_SEXES_NO_NONE, "Male"))
                            sexResult = Pml::Sex::MALE;
                        else if (sex->selected == array_index(DEBUG_SEXES_NO_NONE, "Female"))
                            sexResult = Pml::Sex::FEMALE;
                        else if (sex->selected == array_index(DEBUG_SEXES_NO_NONE, "Genderless"))
                            sexResult = Pml::Sex::UNKNOWN;

                        auto catalog = GameData::DataManager::GetPokemonCatalog(species->selected, form->value, sexResult, shiny->enabled, false);

                        catalog->fields.BattleScale = battleScale->value;
                        catalog->fields.ContestScale = contestScale->value;
                        catalog->fields.ContestSize = contestSize->value;
                        catalog->fields.FieldScale = fieldScale->value;

                        catalog->fields.FieldChikaScale = fieldChikaScale->value;
                        catalog->fields.StatueScale = statueScale->value;
                        catalog->fields.FieldWalkingScale = fieldWalkingScale->value;
                        catalog->fields.FieldFureaiScale = fieldFureaiScale->value;

                        catalog->fields.MenuScale = menuScale->value;
                        catalog->fields.ModelOffset.fields = modelOffset->value;
                        catalog->fields.ModelRotationAngle.fields = modelRotationAngle->value;

                        catalog->fields.DistributionScale = distributionScale->value;
                        catalog->fields.DistributionModelOffset.fields = distributionModelOffset->value;
                        catalog->fields.DistributionModelRotationAngle.fields = distributionModelRotationAngle->value;

                        catalog->fields.VoiceScale = voiceScale->value;
                        catalog->fields.VoiceModelOffset.fields = voiceModelOffset->value;
                        catalog->fields.VoiceModelRotationAngle.fields = voiceModelRotationAngle->value;

                        catalog->fields.CenterPointOffset.fields = centerPointOffset->value;
                        catalog->fields.RotationLimitAngle.fields = rotationLimitAngle->value;

                        catalog->fields.StatusScale = statusScale->value;
                        catalog->fields.StatusModelOffset.fields = statusModelOffset->value;
                        catalog->fields.StatusModelRotationAngle.fields = statusModelRotationAngle->value;

                        catalog->fields.BoxScale = boxScale->value;
                        catalog->fields.BoxModelOffset.fields = boxModelOffset->value;
                        catalog->fields.BoxModelRotationAngle.fields = boxModelRotationAngle->value;

                        catalog->fields.CompareScale = compareScale->value;
                        catalog->fields.CompareModelOffset.fields = compareModelOffset->value;
                        catalog->fields.CompareModelRotationAngle.fields = compareModelRotationAngle->value;

                        catalog->fields.BrakeStart = brakeStart->value;
                        catalog->fields.BrakeEnd = brakeEnd->value;
                        catalog->fields.WalkSpeed = walkSpeed->value;
                        catalog->fields.RunSpeed = runSpeed->value;

                        catalog->fields.WalkStart = walkStart->value;
                        catalog->fields.RunStart = runStart->value;
                        catalog->fields.BodySize = bodySize->value;
                        catalog->fields.AppearLimit = appearLimit->value;

                        catalog->fields.MoveType = moveType->value;
                        catalog->fields.GroundEffect = groundEffect->value;
                        catalog->fields.Waitmoving = waitMoving->value;
                        catalog->fields.BattleAjustHeight = battleAjustHeight->value;
                    };
                });
            });

            addChild(header);
        }
    };
}
