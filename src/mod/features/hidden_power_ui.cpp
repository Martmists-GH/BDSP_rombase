#include "exlaunch.hpp"
#include "externals/Dpr/Battle/Logic/BTL_POKEPARAM.h"
#include "externals/Pml/PokePara/CoreParam.h"
#include "externals/Pml/WazaData.h"
#include "data/moves.h"
#include "logger/logger.h"


int32_t findHiddenPowerIndex()
{
    for(int i=0; i<MOVE_COUNT; i++)
    {
        if(MOVES[i] == "Hidden Power")
        {
            Logger::log("Hidden Power ID: %D\n", i);
            return i;
        }
    }
}

const int32_t HIDDEN_POWER_ID = findHiddenPowerIndex();

static Pml::PokePara::CoreParam::Object * gPokemonParam;

uint8_t WazaDataSystem_GetType(int32_t id, Pml::PokePara::CoreParam::Object * pokemonParam)
{
    Logger::log("WazaDataSystem_GetType. ID: %D\n", id);
    if (pokemonParam == nullptr || id != HIDDEN_POWER_ID)
    {
        Logger::log("Invalid hidden power. Expecting ID: %D\n", HIDDEN_POWER_ID);
        return Pml::WazaData::WazaDataSystem::GetType(id);
    }

    uint8_t TypeID = pokemonParam->GetMezapaType();
    Logger::log("GetMezapaType: %D\n", TypeID);
    return pokemonParam->GetMezapaType();
}

uint8_t WAZADATA_GetType(int32_t id, Dpr::Battle::Logic::BTL_POKEPARAM::Object * bpp)
{
    Logger::log("WAZADATA_GetType\n");
    Pml::PokePara::CoreParam::Object * pokemonParam = (Pml::PokePara::CoreParam::Object *)bpp->GetSrcDataConst();

    return WazaDataSystem_GetType(id, pokemonParam);
}

uint8_t WazaManageSubWazaPanel_GetType(int32_t id)
{
    Logger::log("WazaManageSubWazaPanel_GetType\n");
    uint8_t type = WazaDataSystem_GetType(id, gPokemonParam);
    return type;
}

int32_t WazaManagePokemonStausPanel_GetWazaNo(Pml::PokePara::CoreParam::Object * coreParam, uint8_t index)
{
    Logger::log("pokemonParam: %08X\n", coreParam);
    gPokemonParam = coreParam;
    // __this->fields.m_accessor->GetWazaNo(index);
    return coreParam->fields.m_accessor->GetWazaNo(index);
}

void exl_hidden_power_ui_main(){
    using namespace exl::armv8::inst;
    using namespace exl::armv8::reg;

    exl::patch::CodePatcher p(0x01da02bc);
    p.WriteInst(MovRegister(X1, X21));

    p.Seek(0x01da02c4);
    p.BranchLinkInst((void*)&WazaDataSystem_GetType);

    p.Seek(0x01d2badc);
    p.WriteInst(MovRegister(X1, X19));

    p.Seek(0x01d2bae4);
    p.BranchLinkInst((void*)&WAZADATA_GetType);

    p.Seek(0x01888c78);
    p.WriteInst(MovRegister(X1, X2));
    p.BranchInst((void*)&WazaDataSystem_GetType);

    p.Seek(0x1a41bd8);
    p.BranchLinkInst((void*)&WazaManagePokemonStausPanel_GetWazaNo);

    p.Seek(0x01a41d54);
    p.BranchLinkInst((void*)&WazaManageSubWazaPanel_GetType);
};