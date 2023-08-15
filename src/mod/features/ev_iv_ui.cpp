#include "exlaunch.hpp"
#include "externals/il2cpp-api.h"

#include "externals/Pml/PokePara/CoreParam.h"
#include "externals/Pml/PokePara/PowerID.h"
#include "externals/Dpr/UI/BoxStatusPanel.h"
#include "externals/Dpr/UI/StatusPanelLocals.h"
#include "externals/Dpr/UI/BoxStatusPanelUI.h"
#include "externals/Dpr/UI/StatusPanelUI.h"
#include "externals/Dpr/UI/UIText.h"
#include "externals/Dpr/Message/MessageWordSetHelper.h"
#include "externals/Dpr/Message/MessageManager.h"
#include "externals/UnityEngine/Events/UnityAction.h"
#include "externals/UnityEngine/Coroutine.h"
#include "externals/UnityEngine/Transform.h"
#include "externals/System/String.h"
#include "logger/logger.h"

struct colorFields {
    float r;
    float g;
    float b;
    float a;
};

colorFields mapColorToPower(int32_t power) {

    colorFields customColorFields;

    //Colors in Hex sRGB
    if (power >= 310) {
        //3F7F27FF
        customColorFields.r = 0.24705882352941178f;
        customColorFields.g = 0.4980392156862745f;
        customColorFields.b = 0.15294117647058825;
    }
    else if (power <= 309 && power >= 300) {
        //448128FF
        customColorFields.r = 0.26666666666666666f;
        customColorFields.g = 0.5058823529411764f;
        customColorFields.b = 0.1568627450980392f;
    }
    else if (power <= 299 && power >= 290) {
        //4B8529FF
        customColorFields.r = 0.29411764705882354f;
        customColorFields.g = 0.5215686274509804f;
        customColorFields.b = 0.1607843137254902f;
    }
    else if (power <= 289 && power >= 280) {
        //538A2BFF
        customColorFields.r = 0.3254901960784314f;
        customColorFields.g = 0.5411764705882353f;
        customColorFields.b = 0.16862745098039217f;
    }
    else if (power <= 279 && power >= 270) {
        //5B8F2DFF
        customColorFields.r = 0.3568627450980392f;
        customColorFields.g = 0.5607843137254902f;
        customColorFields.b = 0.17647058823529413f;
    }
    else if (power <= 269 && power >= 260) {
        //63942FFF
        customColorFields.r = 0.38823529411764707f;
        customColorFields.g = 0.5803921568627451f;
        customColorFields.b = 0.1843137254901961f;
    }
    else if (power <= 259 && power >= 250) {
        //6C9A31FF
        customColorFields.r = 0.4235294117647059f;
        customColorFields.g = 0.6039215686274509f;
        customColorFields.b = 0.19215686274509805f;
    }
    else if (power <= 249 && power >= 240) {
        //77A033FF
        customColorFields.r = 0.4666666666666667f;
        customColorFields.g = 0.6274509803921569f;
        customColorFields.b = 0.2f;
    }
    else if (power <= 239 && power >= 230) {
        //7FA435FF
        customColorFields.r = 0.4980392156862745f;
        customColorFields.g = 0.6431372549019608f;
        customColorFields.b = 0.20784313725490197f;
    }
    else if (power <= 229 && power >= 220) {
        //89A936FF
        customColorFields.r = 0.5372549019607843f;
        customColorFields.g = 0.6627450980392157f;
        customColorFields.b = 0.21176470588235294f;
    }
    else if (power <= 219 && power >= 210) {
        //91AE38FF
        customColorFields.r = 0.5686274509803921f;
        customColorFields.g = 0.6823529411764706f;
        customColorFields.b = 0.2196078431372549f;
    }
    else if (power <= 209 && power >= 200) {
        //9AB13AFF
        customColorFields.r = 0.6039215686274509f;
        customColorFields.g = 0.6941176470588235f;
        customColorFields.b = 0.22745098039215686f;
    }
    else if (power <= 199 && power >= 190) {
        //A1B43BFF
        customColorFields.r = 0.6313725490196078f;
        customColorFields.g = 0.7058823529411765f;
        customColorFields.b = 0.23137254901960785f;
    }
    else if (power <= 189 && power >= 180) {
        //A8B53BFF
        customColorFields.r = 0.6588235294117647f;
        customColorFields.g = 0.7098039215686275f;
        customColorFields.b = 0.23137254901960785f;
    }
    else if (power <= 179 && power >= 170) {
        //ADB53CFF
        customColorFields.r = 0.6784313725490196f;
        customColorFields.g = 0.7098039215686275f;
        customColorFields.b = 0.23529411764705882f;
    }
    else if (power <= 169 && power >= 160) {
        //B2B33CFF
        customColorFields.r = 0.6980392156862745f;
        customColorFields.g = 0.7019607843137254f;
        customColorFields.b = 0.23529411764705882f;
    }
    else if (power <= 159 && power >= 150) {
        //B4B03BFF
        customColorFields.r = 0.7058823529411765f;
        customColorFields.g = 0.6901960784313725f;
        customColorFields.b = 0.23137254901960785f;
    }
    else if (power <= 149 && power >= 140) {
        //B8AA3AFF
        customColorFields.r = 0.7215686274509804f;
        customColorFields.g = 0.6666666666666666f;
        customColorFields.b = 0.22745098039215686f;
    }
    else if (power <= 139 && power >= 130) {
        //B7A238FF
        customColorFields.r = 0.7176470588235294f;
        customColorFields.g = 0.6352941176470588f;
        customColorFields.b = 0.2196078431372549f;
    }
    else if (power <= 129 && power >= 120) {
        //B79835FF
        customColorFields.r = 0.7176470588235294f;
        customColorFields.g = 0.596078431372549f;
        customColorFields.b = 0.20784313725490197f;
    }
    else if (power <= 119 && power >= 110) {
        //B78E32FF
        customColorFields.r = 0.7176470588235294f;
        customColorFields.g = 0.5568627450980392f;
        customColorFields.b = 0.19607843137254902f;
    }
    else if (power <= 109 && power >= 100) {
        //B3822FFF
        customColorFields.r = 0.7019607843137254f;
        customColorFields.g = 0.5098039215686274f;
        customColorFields.b = 0.1843137254901961f;
    }
    else if (power <= 99 && power >= 90) {
        //B1762CFF
        customColorFields.r = 0.6941176470588235f;
        customColorFields.g = 0.4627450980392157f;
        customColorFields.b = 0.17254901960784313f;
    }
    else if (power <= 89 && power >= 80) {
        //AE6A29FF
        customColorFields.r = 0.6823529411764706f;
        customColorFields.g = 0.41568627450980394f;
        customColorFields.b = 0.1607843137254902f;
    }
    else if (power <= 79 && power >= 70) {
        //AA5E26FF
        customColorFields.r = 0.6666666666666666f;
        customColorFields.g = 0.3686274509803922f;
        customColorFields.b = 0.14901960784313725f;
    }
    else if (power <= 69 && power >= 60) {
        //A65123FF
        customColorFields.r = 0.6509803921568628f;
        customColorFields.g = 0.3176470588235294f;
        customColorFields.b = 0.13725490196078433f;
    }
    else if (power <= 59 && power >= 50) {
        //A34621FF
        customColorFields.r = 0.6392156862745098f;
        customColorFields.g = 0.27450980392156865f;
        customColorFields.b = 0.12941176470588237f;
    }
    else if (power <= 49 && power >= 40) {
        //A03B1EFF
        customColorFields.r = 0.6274509803921569f;
        customColorFields.g = 0.23137254901960785f;
        customColorFields.b = 0.11764705882352941f;
    }
    else if (power <= 39 && power >= 30) {
        //9C321DFF
        customColorFields.r = 0.611764705882353f;
        customColorFields.g = 0.19607843137254902f;
        customColorFields.b = 0.11372549019607843f;
    }
    else if (power <= 29 && power >= 20) {
        //9A2A1BFF
        customColorFields.r = 0.6039215686274509f;
        customColorFields.g = 0.16470588235294117f;
        customColorFields.b = 0.10588235294117647f;
    }
    else if (power <= 19 && power >= 10) {
        //99251AFF
        customColorFields.r = 0.6f;
        customColorFields.g = 0.1450980392156863f;
        customColorFields.b = 0.10196078431372549f;
    }
    else
    {
        //99241AFF
        customColorFields.r = 0.6f;
        customColorFields.g = 0.1411764705882353f;
        customColorFields.b = 0.10196078431372549f;
    }
    customColorFields.a = 1.0f;
    return customColorFields;
}

/*
HOOK_DEFINE_REPLACE(displayPower) {
    static void Callback(Dpr::UI::BoxStatusPanelUI::Object *boxStatusPanel) {

        Logger::log("Displaying box power:\n");
        int32_t power = boxStatusPanel->fields.pokemonParam->GetPower(Pml::PokePara::PowerID::ATK);
        Dpr::Message::MessageWordSetHelper::SetDigitWord(0, power);
    }
};

HOOK_DEFINE_REPLACE(displaySummaryPower) {
    static void Callback(Dpr::UI::StatusPanelUI::Object *statusPanel) {

        Dpr::UI::StatusPanelLocals::Object *locals = statusPanel->fields.locals;
        Pml::PokePara::CoreParam *pokemonParam = locals->fields.pokemonParam;
        Pml::PokePara::CoreParam::Object* coreParamObj = locals->fields.pokemonParam;

        System::Int32_array* _powerIdMap = locals->fields.__4__this->fields._powerIdMap;
        int32_t i = statusPanel->fields.i;
        int32_t effortPower = coreParamObj->GetEffortPower(coreParamObj, _powerIdMap->m_Items[i]);
        Logger::log("Displaying effort power: %d\n", effortPower);
        int32_t power = pokemonParam->GetPower(_powerIdMap->m_Items[i]);

        //Dpr::Message::MessageManager::Object* messageManagerObj = Dpr::Message::MessageManager::instance();
        //System::String::Object* stringObj = messageManagerObj->GetSimpleMessage(locals->fields.__4__this->fields._tokuseiDescription->fields._messageFile, locals->fields.__4__this->fields._tokuseiDescription->fields._messageId);

        for (int j = 0; j < statusPanel->fields.locals->fields.__4__this->fields._colorUpDowns->max_length; j++)
        {
            mapColorToPower(power);

            statusPanel->fields.locals->fields.__4__this->fields._colorUpDowns->m_Items[j].fields.r = mapColorToPower(power).r;
            statusPanel->fields.locals->fields.__4__this->fields._colorUpDowns->m_Items[j].fields.g = mapColorToPower(power).g;
            statusPanel->fields.locals->fields.__4__this->fields._colorUpDowns->m_Items[j].fields.b = mapColorToPower(power).b;
            statusPanel->fields.locals->fields.__4__this->fields._colorUpDowns->m_Items[j].fields.a = mapColorToPower(power).a;
        }

        Dpr::Message::MessageWordSetHelper::SetDigitWord(0, power);
    }
};
*/

HOOK_DEFINE_REPLACE(Dpr_UI_BoxStatusPanel_GetJudgeTextCode) {
    static System::String::Object * Callback(Dpr::UI::BoxStatusPanel::Object *boxPanel, Pml::PokePara::CoreParam *pokemonParam, int32_t powerId) {

        bool trainingDone = pokemonParam->IsTrainingDone(powerId);
        int32_t messageID;
        System::String::Object* msgLabel;

        if (trainingDone) {
            msgLabel = System::String::Create("SS_box_590");

        } else {
            //Logger::log("power ID: %d\n", powerId);
            messageID = 0x24e + pokemonParam->GetTalentPower(powerId);
            std::string stringMessageID = std::to_string(messageID);
            System::String::Object* convertedMessageID = System::String::Create(stringMessageID);
            //Logger::log("message ID: %s\n", convertedMessageID->asCString().c_str());
            msgLabel = System::String::Create("SS_box_");
            msgLabel = System::String::Concat(msgLabel, convertedMessageID);
            //Logger::log("message label: %s\n", msgLabel->asCString().c_str());
        }

        return msgLabel;
    }
};

HOOK_DEFINE_REPLACE(Dpr_UI_PokemonStatusPanelAbility__SelectRaderChartIndex) {
    static void Callback (Dpr::UI::PokemonStatusPanelAbility::Object *panelRef,int32_t selectIndex,bool isInitialized) {

    int32_t panelIndex;
    UnityEngine::Transform::Object *panelObjRef;
    UnityEngine::GameObject::Object *gameObjRef;
    //undefined8 longUndef;
    Dpr::UI::PokemonStatusPanelAbility::ChartItem::Array* panelArray;
    ulong longLength;
    int childCursor;
    ulong panelLenCursor;

    if (((panelRef->fields)._selectRaderChartIndex == selectIndex) && (!isInitialized)) {
        return;
    }

    panelRef->fields._selectRaderChartIndex = selectIndex;
    Logger::log("Index selected: %d\n", panelRef->fields._selectRaderChartIndex);
    panelIndex = ((UnityEngine::Transform::Object *)panelRef->fields._raderChartRoot)->get_childCount();
    Logger::log("Cast to transform obj success\n");

    if (0 < panelIndex) {
        Logger::log("0 less than child count\n");
        childCursor = 0;
        do {
            UnityEngine::Transform::Object * transformObj00 = (UnityEngine::Transform::Object *)panelRef->fields._raderChartRoot;
            panelObjRef = transformObj00->GetChild(childCursor);
            UnityEngine::Component::Object * componentObj = (UnityEngine::Component::Object *)panelObjRef;
            UnityEngine::GameObject::Object * gameObj = (UnityEngine::GameObject::Object *)componentObj;

            gameObjRef = gameObj->get_gameObject();

            gameObj->SetActive(childCursor);

            childCursor = childCursor + 1;
            panelIndex = transformObj00->get_childCount();
        }
        while (childCursor < panelIndex);
    }

    panelArray = (panelRef->fields)._chartItems;

    Logger::log("Checking chart length\n");

    Logger::log("Zero less than chart length\n");
    childCursor = (panelRef->fields)._selectRaderChartIndex;
    panelLenCursor = 0;
        longLength = panelArray->max_length & 0xffffffff;
        do {

            /*
            if (uVar5 <= panelLenCursor) {
                longUndef = thunk_FUN_710025c83c();
                FUN_71002afbc0(longUndef,0);
            }
            */

            UnityEngine::Component::Object * componentObj = (UnityEngine::Component::Object *)panelArray->m_Items[panelLenCursor]->fields.text;
            UnityEngine::GameObject::Object * gameObj = (UnityEngine::GameObject::Object *)componentObj;
            gameObj = gameObj->get_gameObject();
            gameObj->SetActive(childCursor);
            panelArray = (panelRef->fields)._chartItems;
            panelLenCursor = panelLenCursor + 1;
            longLength = (ulong)*(uint *)&panelArray->max_length;
        }
            while ((long)panelLenCursor < (long)(int)*(uint *)&panelArray->max_length);
        panelRef->PlayEffortEffects( (panelRef->fields)._pokemonParam);
    return;
    }
};

/*
void Dpr_UI_UIText_SetFormattedText (Dpr::UI::UIText::Object *__this,UnityEngine::Events::UnityAction::Object *onSet, System::String::Object *messageFile,System::String::Object *messageId) {
    UnityEngine::Coroutine::Object **ppUVar1;
    ulong *puVar2;
    char cVar3;
    bool bVar4;


    if (messageFile != (System::String::Object *) 0x0) {
        ppUVar1 = &(__this->fields).super.m_DelayedMaterialRebuild;
        (__this->fields).super.m_DelayedMaterialRebuild = (UnityEngine::Coroutine::Object *) messageFile;
        return;
    }

    if (messageId != (System::String::Object *) 0x0) {
        *(System::String::Object **) &(__this->fields).super.m_ClipRect.fields = messageId;
    }

    onSet->Invoke(onSet);
    //*(undefined *) ((long) &(__this->fields).super.m_DelayedGraphicRebuild + 4) = 1;
    //*(undefined *) ((long) &(__this->fields).super.m_ClipRect.fields.m_Width + 1) = 1;
    __this->UpdateMessage(__this, true, 0xb);

    Logger::log("Set formatted text\n");
    return;
}
*/

void exl_ev_iv_ui_main(){
    //Dpr.UI.BoxStatusPanel.<>c__DisplayClass35_0$$<SetUp>b__5
    //displayPower::InstallAtOffset(0x01cb2380);

    //Dpr.UI.PokemonStatusPanelAbility.<>c__DisplayClass17_1$$<Setup>b__2
    //displaySummaryPower::InstallAtOffset(0x01d99c20);

    Dpr_UI_PokemonStatusPanelAbility__SelectRaderChartIndex::InstallAtOffset(0x01d99260);

    Dpr_UI_BoxStatusPanel_GetJudgeTextCode::InstallAtOffset(0x01cb1e40);

    using namespace exl::armv8::inst;
    using namespace exl::armv8::reg;

    exl::patch::CodePatcher p(0x01cba4f4);
    p.WriteInst(Movz(X0, 1));

    /*
    p.Seek(0x01d98eb8);
    p.BranchLinkInst((void*)&Dpr_UI_UIText_SetFormattedText);

    p.Seek(0x01d98f44);
    p.BranchLinkInst((void*)&Dpr_UI_UIText_SetFormattedText);
    */
};