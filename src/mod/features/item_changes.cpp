#include "exlaunch.hpp"
#include "externals/il2cpp.h"
#include "externals/Dpr/UI/UIBag.h"
#include "externals/Pml/PokePara/CoreParam.h"
#include "externals/Pml/PokePara/PokemonParam.h"
#include "externals/Pml/Personal/PersonalSystem.h"
#include "utils/utils.h"
#include "logger/logger.h"

// Checks if Ability Patch can be used.
HOOK_DEFINE_REPLACE(AbilityPatchUsability) {
       static bool Callback(Dpr::UI::UIBag::__c__DisplayClass135_0::Object *bagObject, Pml::PokePara::PokemonParam::Object *pp)
        {
            system_load_typeinfo(0x9592);

            //Pml::PokePara::CoreParam *coreParam = (Pml::PokePara::CoreParam *) bagObject->fields.pokeParam;
            auto coreParam = reinterpret_cast<Pml::PokePara::CoreParam::Object *>(pp);
            Logger::log("Ability patch used.\n");

            int32_t monsno = coreParam->GetMonsNo();
            int32_t formno = coreParam->GetFormNo();

            Pml::Personal::PersonalSystem::LoadPersonalData(monsno, formno);
            int32_t pattern = Pml::Personal::PersonalSystem::GetTokuseiPattern(monsno, formno);

            Logger::log("Pattern: %d.\n", pattern);
            switch (pattern) {
                case 0: // A1 == A2 == HA
                    return false;
                case 1: // A1 == A2 != HA
                case 2: // A1 != A2 != HA
                    Pml::PokePara::CoreParam *corePp = (Pml::PokePara::CoreParam *) pp;
                    uint8_t abilitySlot = corePp->GetTokuseiIndex();

                    if (abilitySlot != 2) // Change to Hidden Ability
                    {
                        corePp->SetTokuseiIndex(coreParam, 2);
                        Logger::log("Changed to second ability.\n");
                    } else // Change to first Ability
                    {
                        corePp->SetTokuseiIndex(coreParam, 0);
                        Logger::log("Changed to second ability.\n");
                    }
                    return true;
            }

            return false;
        }
};

void exl_item_changes_main(){
    AbilityPatchUsability::InstallAtOffset(0x01be1580);
};