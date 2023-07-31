#include "exlaunch.hpp"
#include "externals/il2cpp-api.h"

#include "externals/Pml/PokePara/CoreParam.h"
#include "externals/Dpr/Message/MessageWordSetHelper.h"
#include "externals/System/Array.h"
#include "externals/Dpr/UI/BoxStatusPanelUI.h"
#include "externals/Dpr/UI/StatusPanelUI.h"
#include "externals/Dpr/UI/StatusPanelLocals.h"
#include "externals/System/String.h"



int32_t POWER_ID_HP = 0;
int32_t POWER_ID_ATK = 1;
int32_t POWER_ID_DEF = 2;
int32_t POWER_ID_SPATK = 3;
int32_t POWER_ID_SPDEF = 4;
int32_t POWER_ID_AGI = 5;

extern void * int_TypeInfo;

struct colorFields {
    float r;
    float g;
    float b;
    float a = 1.0f;
};

colorFields customColorFields;

void mapColorToPower(int32_t power) {

    //Colors in Hex sRGB
    if (power >= 310) {
        //3F7F27FF
        customColorFields.r = 0.049707f;
        customColorFields.g = 0.212231f;
        customColorFields.b = 0.020289f;
    }
    else if (power <= 309 && power >= 300) {
        //448128FF
        customColorFields.r = 0.057805f;
        customColorFields.g = 0.219526f;
        customColorFields.b = 0.021219f;
    }
    else if (power <= 299 && power >= 290) {
        //4B8529FF
        customColorFields.r = 0.07036f;
        customColorFields.g = 0.234551f;
        customColorFields.b = 0.022174f;
    }
    else if (power <= 289 && power >= 280) {
        //538A2BFF
        customColorFields.r = 0.0865f;
        customColorFields.g = 0.254152f;
        customColorFields.b = 0.024158f;
    }
    else if (power <= 279 && power >= 270) {
        //5B8F2DFF
        customColorFields.r = 0.104616f;
        customColorFields.g = 0.274677f;
        customColorFields.b = 0.026241f;
    }
    else if (power <= 269 && power >= 260) {
        //63942FFF
        customColorFields.r = 0.124772f;
        customColorFields.g = 0.296138f;
        customColorFields.b = 0.028426f;
    }
    else if (power <= 259 && power >= 250) {
        //6C9A31FF
        customColorFields.r = 0.14996f;
        customColorFields.g = 0.323143f;
        customColorFields.b = 0.030713f;
    }
    else if (power <= 249 && power >= 240) {
        //77A033FF
        customColorFields.r = 0.184475f;
        customColorFields.g = 0.351533f;
        customColorFields.b = 0.033105f;
    }
    else if (power <= 239 && power >= 230) {
        //7FA435FF
        customColorFields.r = 0.212231f;
        customColorFields.g = 0.371238f;
        customColorFields.b = 0.035601f;
    }
    else if (power <= 229 && power >= 220) {
        //89A936FF
        customColorFields.r = 0.250158f;
        customColorFields.g = 0.396755f;
        customColorFields.b = 0.036889f;
    }
    else if (power <= 219 && power >= 210) {
        //91AE38FF
        customColorFields.r = 0.283149f;
        customColorFields.g = 0.423268f;
        customColorFields.b = 0.039546f;
    }
    else if (power <= 209 && power >= 200) {
        //9AB13AFF
        customColorFields.r = 0.323143f;
        customColorFields.g = 0.439657f;
        customColorFields.b = 0.042311f;
    }
    else if (power <= 199 && power >= 190) {
        //A1B43BFF
        customColorFields.r = 0.3564f;
        customColorFields.g = 0.456411f;
        customColorFields.b = 0.043735f;
    }
    else if (power <= 189 && power >= 180) {
        //A8B53BFF
        customColorFields.r = 0.391573f;
        customColorFields.g = 0.462077f;
        customColorFields.b = 0.043735f;
    }
    else if (power <= 179 && power >= 170) {
        //ADB53CFF
        customColorFields.r = 0.417885f;
        customColorFields.g = 0.462077f;
        customColorFields.b = 0.045186f;
    }
    else if (power <= 169 && power >= 160) {
        //B2B33CFF
        customColorFields.r = 0.445201f;
        customColorFields.g = 0.450786f;
        customColorFields.b = 0.045186f;
    }
    else if (power <= 159 && power >= 150) {
        //B4B03BFF
        customColorFields.r = 0.456411f;
        customColorFields.g = 0.434154f;
        customColorFields.b = 0.043735f;
    }
    else if (power <= 149 && power >= 140) {
        //B8AA3AFF
        customColorFields.r = 0.47932f;
        customColorFields.g = 0.401978f;
        customColorFields.b = 0.042311f;
    }
    else if (power <= 139 && power >= 130) {
        //B7A238FF
        customColorFields.r = 0.473532f;
        customColorFields.g = 0.361307f;
        customColorFields.b = 0.039546f;
    }
    else if (power <= 129 && power >= 120) {
        //B79835FF
        customColorFields.r = 0.473532f;
        customColorFields.g = 0.313989f;
        customColorFields.b = 0.035601f;
    }
    else if (power <= 119 && power >= 110) {
        //B78E32FF
        customColorFields.r = 0.473532f;
        customColorFields.g = 0.270498f;
        customColorFields.b = 0.031896f;
    }
    else if (power <= 109 && power >= 100) {
        //B3822FFF
        customColorFields.r = 0.450786f;
        customColorFields.g = 0.223228f;
        customColorFields.b = 0.028426f;
    }
    else if (power <= 99 && power >= 90) {
        //B1762CFF
        customColorFields.r = 0.439657f;
        customColorFields.g = 0.181164f;
        customColorFields.b = 0.025187f;
    }
    else if (power <= 89 && power >= 80) {
        //AE6A29FF
        customColorFields.r = 0.423268f;
        customColorFields.g = 0.144128f;
        customColorFields.b = 0.022174f;
    }
    else if (power <= 79 && power >= 70) {
        //AA5E26FF
        customColorFields.r = 0.401978f;
        customColorFields.g = 0.111932f;
        customColorFields.b = 0.019382f;
    }
    else if (power <= 69 && power >= 60) {
        //A65123FF
        customColorFields.r = 0.381326f;
        customColorFields.g = 0.082283f;
        customColorFields.b = 0.016807f;
    }
    else if (power <= 59 && power >= 50) {
        //A34621FF
        customColorFields.r = 0.366253f;
        customColorFields.g = 0.061246f;
        customColorFields.b = 0.015209f;
    }
    else if (power <= 49 && power >= 40) {
        //A03B1EFF
        customColorFields.r = 0.351533f;
        customColorFields.g = 0.043735f;
        customColorFields.b = 0.012983f;
    }
    else if (power <= 39 && power >= 30) {
        //9C321DFF
        customColorFields.r = 0.332452f;
        customColorFields.g = 0.031896f;
        customColorFields.b = 0.012286f;
    }
    else if (power <= 29 && power >= 20) {
        //9A2A1BFF
        customColorFields.r = 0.323143f;
        customColorFields.g = 0.023153f;
        customColorFields.b = 0.01096f;
    }
    else if (power <= 19 && power >= 10) {
        //99251AFF
        customColorFields.r = 0.318547f;
        customColorFields.g = 0.0185f;
        customColorFields.b = 0.01033f;
    }
    else
    {
        //99241AFF
        customColorFields.r = 0.318547f;
        customColorFields.g = 0.017642f;
        customColorFields.b = 0.01033f;
    }
}

HOOK_DEFINE_REPLACE(displayPower1) {
    static void Callback(Dpr::UI::BoxStatusPanelUI::Object *boxStatusPanel) {
        int32_t power = boxStatusPanel->fields.pokemonParam->GetPower(POWER_ID_ATK);
        Dpr::Message::MessageWordSetHelper::SetDigitWord(0, power);
    }
};

void displayPower2(Dpr::UI::BoxStatusPanelUI::Object *boxStatusPanel)
{
    int32_t power = boxStatusPanel->fields.pokemonParam->GetPower(POWER_ID_DEF);
    Dpr::Message::MessageWordSetHelper::SetDigitWord(0, power);
}

HOOK_DEFINE_REPLACE(displaySummaryPower) {
    static void Callback(Dpr::UI::StatusPanelUI::Object *statusPanel) {
        Dpr::UI::StatusPanelLocals::Object *locals = statusPanel->fields.locals;
        Pml::PokePara::CoreParam *pokemonParam = locals->fields.pokemonParam;
        System::Array<int32_t> *_powerIdMap = locals->fields.__4__this->fields._powerIdMap;
        int32_t i = statusPanel->fields.i;
        int32_t power = pokemonParam->GetPower(_powerIdMap->m_Items[i]);

        for (int j = 0; j < statusPanel->fields.locals->fields.__4__this->fields._colorUpDowns->max_length; j++)
        {
            mapColorToPower(power);

            statusPanel->fields.locals->fields.__4__this->fields._colorUpDowns->m_Items[j].fields.r = customColorFields.r;
            statusPanel->fields.locals->fields.__4__this->fields._colorUpDowns->m_Items[j].fields.g = customColorFields.g;
            statusPanel->fields.locals->fields.__4__this->fields._colorUpDowns->m_Items[j].fields.b = customColorFields.b;
            statusPanel->fields.locals->fields.__4__this->fields._colorUpDowns->m_Items[j].fields.a = customColorFields.a;
        }

        Dpr::Message::MessageWordSetHelper::SetDigitWord(0, power);
    }
};

Il2CppObject * thunk_FUN_7100252fd8(void * typeInfo, void * data);

HOOK_DEFINE_REPLACE(Dpr_UI_BoxStatusPanel_GetJudgeTextCode) {
    static System::String *
    Callback(Dpr::UI::BoxStatusPanelUI::Object *__this, Pml::PokePara::CoreParam *pokemonParam, int32_t powerId) {
        
        bool trainingDone = pokemonParam->IsTrainingDone(powerId);
        int32_t messageID;
        if (trainingDone) {
            messageID = 0x241;
        } else {
            messageID = 0x24e + pokemonParam->GetTalentPower(powerId);
        }

        //system_load_typeinfo(0x2609);

        Il2CppObject *intObject = thunk_FUN_7100252fd8(int_TypeInfo, (void *) &messageID);
        return System::String::Concat(intObject);
    }
};

void exl_ev_iv_ui_main(){
    displayPower1::InstallAtOffset(0x01cb2380);
    displaySummaryPower::InstallAtOffset(0x01d99c20);

    using namespace exl::armv8::inst;
    using namespace exl::armv8::reg;

    exl::patch::CodePatcher p(0x01cba4f4);
    p.WriteInst(MovRegister(X0, X1));

    Dpr_UI_BoxStatusPanel_GetJudgeTextCode::InstallAtOffset(0x01cb1e40);
};