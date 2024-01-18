#include "exlaunch.hpp"

#include "externals/Dpr/Battle/Logic/calc.h"
#include "externals/Dpr/Battle/Logic/Exp.h"
#include "externals/Dpr/Battle/Logic/ExpCalculator.h"
#include "externals/Dpr/Battle/Logic/MyStatus.h"
#include "externals/Dpr/Battle/Logic/MainModule.h"
#include "externals/Dpr/Battle/Logic/BTL_POKEPARAM.h"
#include "data/items.h"
#include "data/utils.h"

HOOK_DEFINE_REPLACE(CalcExp) {
    static void Callback(Dpr::Battle::Logic::ExpCalculator::CalcExpWork::Object* result,
                         Dpr::Battle::Logic::MyStatus::Object* myStatus,
                         Dpr::Battle::Logic::MainModule::Object** mainModule,
                         Dpr::Battle::Logic::BTL_POKEPARAM::Object** bpp,
                         Dpr::Battle::Logic::BTL_POKEPARAM::Object** deadPoke) {
        system_load_typeinfo(0x479c);

        if ((*bpp)->IsFightEnable()) {
            auto param = (*bpp)->GetSrcDataConst()->cast<Pml::PokePara::CoreParam>();
            auto calc = Dpr::Battle::Logic::Exp::CalcParam::newInstance();
            calc->fields.competitor = (*mainModule)->GetCompetitor(true);
            calc->fields.playerLanguageId = myStatus->fields.lang;
            calc->fields.levelCap = (*mainModule)->GetExpLevelCap();

            Dpr::Battle::Logic::ExpCalculator::getClass()->initIfNeeded();
            system_load_typeinfo(0x479f);

            calc->fields.deadPokeExp = Dpr::Battle::Logic::calc::PERSONAL_GetParam((*deadPoke)->GetMonsNo(), (*deadPoke)->fields.m_formNo, 9);
            calc->fields.deadPokeLevel = (*deadPoke)->GetValue(0x11);
            calc->fields.getPokeLevel = (*bpp)->GetValue(0x11);
            calc->fields.getPokeFriendship = (*mainModule)->GetPokeFriendship(*bpp);
            calc->fields.getPokeLanguageId = param->GetLangId();

            calc->fields.isMatch = (*deadPoke)->CONFRONT_REC_IsMatch((*bpp)->GetID()) || (*bpp)->GetItem() == array_index(ITEMS, "Exp. Share");
            calc->fields.isGakusyuSoutiOn = false;
            calc->fields.haveSiawasetamago = (*bpp)->GetItem() == array_index(ITEMS, "Lucky Egg");

            system_load_typeinfo(0x47a0);
            Dpr::Battle::Logic::calc::getClass()->initIfNeeded();

            calc->fields.isEvoCanceledPoke = Dpr::Battle::Logic::calc::PERSONAL_IsEvoCancelPokemon((*bpp)->GetMonsNo(), (*bpp)->fields.m_formNo, (*bpp)->GetValue(0x11));
            calc->fields.isMyPoke = myStatus->IsMyPokemon(param);

            auto cResult = Dpr::Battle::Logic::Exp::CalcResult::newInstance();

            Dpr::Battle::Logic::Exp::CalcExp(reinterpret_cast<Dpr::Battle::Logic::Exp::CalcParam **>(&calc), cResult);
            result->fields.exp = cResult->fields.exp;
            result->fields.bGakusyuSouti = cResult->fields.byGakusyuSouti;
            result->fields.fBonus = cResult->fields.isContainBonus;
        }
    }
};

void exl_items_exp_share_main() {
    CalcExp::InstallAtOffset(0x018f8c10);
}
