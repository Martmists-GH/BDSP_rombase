#include "exlaunch.hpp"

#include "externals/GameData/DataManager.h"
#include "externals/Pml/Personal/PersonalSystem.h"
#include "externals/Pml/Personal/SexVector.h"
#include "externals/Pml/Sex.h"
#include "externals/XLSXContent/PersonalTable.h"
#include "externals/XLSXContent/PokemonInfo.h"

XLSXContent::PokemonInfo::SheetCatalog::Object* GetDefaultCatalog(int32_t monsno, int32_t formno) {
    XLSXContent::PersonalTable::SheetPersonal::Object* personal = Pml::Personal::PersonalSystem::GetPersonalData(monsno, formno);
    uint8_t sexRate = personal->fields.sex;
    Pml::Sex sex;
    switch (sexRate)
    {
        case (uint8_t)Pml::Personal::SexVector::ONLY_FEMALE:
            sex = Pml::Sex::FEMALE;
            break;

        case (uint8_t)Pml::Personal::SexVector::UNKNOWN:
            sex = Pml::Sex::UNKNOWN;
            break;

        default:
            sex = Pml::Sex::MALE;
            break;
    }

    bool isRare = false;
    bool isEgg = false;

    return GameData::DataManager::GetPokemonCatalog(monsno, formno, sex, isRare, isEgg);
}