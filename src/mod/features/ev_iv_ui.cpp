#include "exlaunch.hpp"
#include "externals/il2cpp-api.h"

#include "externals/Pml/PokePara/CoreParam.h"
#include "externals/Dpr/UI/BoxStatusPanel.h"
#include "externals/Dpr/UI/PokemonStatusPanelAbility.h"
#include "externals/Dpr/Message/MessageWordSetHelper.h"
#include "externals/UnityEngine/Transform.h"
#include "externals/System/String.h"
#include "logger/logger.h"

void displaySummaryPower(Dpr::UI::PokemonStatusPanelAbility::Object *statusPanel, Pml::PokePara::PokemonParam::Object* pokeParam, int cursor, int index) {

    System::String::Object* msgLabel;
    System::String::Object* msgFile;
    Pml::PokePara::CoreParam *pokemonParam = (Pml::PokePara::CoreParam *)pokeParam;
    Pml::PokePara::CoreParam::Object* coreParamObj = (Pml::PokePara::CoreParam::Object*)pokeParam;

    System::Int32_array* _powerIdMap = statusPanel->fields._powerIdMap;
    int32_t effortPower = coreParamObj->GetEffortPower(_powerIdMap->m_Items[cursor]);
    int32_t power = pokemonParam->GetPower(_powerIdMap->m_Items[cursor]);
    int32_t talentPower = pokemonParam->GetTalentPower(cursor);

    if (index == 0) {
        Dpr::Message::MessageWordSetHelper::SetDigitWord(0, power);
        System::String::Object* convertedMessageID = System::String::Create("018");
        msgLabel = System::String::Create("SS_box_");
        msgFile = System::String::Create("ss_box");
        msgLabel = System::String::Concat(msgLabel, convertedMessageID);
        statusPanel->fields._chartItems->m_Items[cursor]->fields.text->SetupMessage(msgFile, msgLabel);
    }
    else if (index == 1) {
        Dpr::Message::MessageWordSetHelper::SetDigitWord(0, effortPower);
        System::String::Object* convertedMessageID = System::String::Create("026");
        msgLabel = System::String::Create("SS_box_");
        msgFile = System::String::Create("ss_box");
        msgLabel = System::String::Concat(msgLabel, convertedMessageID);
        statusPanel->fields._chartItems->m_Items[cursor]->fields.text->SetupMessage(msgFile, msgLabel);
    }
    else if (index == 2) {
        Dpr::Message::MessageWordSetHelper::SetDigitWord(0, talentPower);
        System::String::Object* convertedMessageID = System::String::Create("026");
        msgLabel = System::String::Create("SS_box_");
        msgFile = System::String::Create("ss_box");
        msgLabel = System::String::Concat(msgLabel, convertedMessageID);
        statusPanel->fields._chartItems->m_Items[cursor]->fields.text->SetupMessage(msgFile, msgLabel);
    }

}

HOOK_DEFINE_REPLACE(Dpr_UI_BoxStatusPanel_GetJudgeTextCode) {
    static System::String::Object * Callback(Dpr::UI::BoxStatusPanel::Object *boxPanel, Pml::PokePara::CoreParam *pokemonParam, int32_t powerId) {

        bool trainingDone = pokemonParam->IsTrainingDone(powerId);
        int32_t messageID;
        System::String::Object* msgLabel;

        if (trainingDone) {
            msgLabel = System::String::Create("SS_box_590");

        } else {
            messageID = 0x24e + pokemonParam->GetTalentPower(powerId);
            std::string stringMessageID = std::to_string(messageID);
            System::String::Object* convertedMessageID = System::String::Create(stringMessageID);
            msgLabel = System::String::Create("SS_box_");
            msgLabel = System::String::Concat(msgLabel, convertedMessageID);
        }

        return msgLabel;
    }
};

HOOK_DEFINE_REPLACE(Dpr_UI_PokemonStatusPanelAbility__SelectRaderChartIndex) {
    static void Callback (Dpr::UI::PokemonStatusPanelAbility::Object *panelRef, int32_t selectIndex, bool isInitialized) {
        if (((panelRef->fields)._selectRaderChartIndex == selectIndex) && (!isInitialized))
        {
            return;
        }

        (panelRef->fields)._selectRaderChartIndex = selectIndex;

        UnityEngine::Transform::Object* radarRootTransform = ((UnityEngine::Transform::Object *)panelRef->fields._raderChartRoot);
        for (int i = 0; i < radarRootTransform->get_childCount(); i++)
        {
            auto panelObjTransform = radarRootTransform->GetChild(i);
            auto gameObj = (UnityEngine::GameObject::Object*)((UnityEngine::Component::Object *)panelObjTransform)->get_gameObject();
            gameObj->SetActive(selectIndex == i);
        }

        for (int i = 0; i < panelRef->fields._chartItems->max_length; i++)
        {
            auto panelText = (UnityEngine::Component::Object*)panelRef->fields._chartItems->m_Items[i]->fields.text;
            auto gameObj = (UnityEngine::GameObject::Object*)(panelText)->get_gameObject();
            gameObj->SetActive(true);

            displaySummaryPower(panelRef, panelRef->fields._pokemonParam, i, selectIndex);
            //Logger::log("Displaying summary\n");
        }
        panelRef->PlayEffortEffects((panelRef->fields)._pokemonParam);
    }
};

void exl_ev_iv_ui_main(){

    Dpr_UI_PokemonStatusPanelAbility__SelectRaderChartIndex::InstallAtOffset(0x01d99260);

    Dpr_UI_BoxStatusPanel_GetJudgeTextCode::InstallAtOffset(0x01cb1e40);

    using namespace exl::armv8::inst;
    using namespace exl::armv8::reg;

    exl::patch::CodePatcher p(0x01cba4f4);
    p.WriteInst(Movz(X0, 1));
};