#include "exlaunch.hpp"

#include "data/types.h"
#include "data/utils.h"
#include "externals/Dpr/Battle/Logic/BattleProc.h"
#include "externals/Pml/Personal/EvolveCond.h"
#include "externals/Pml/Personal/EvolveTableExtensions.h"
#include "externals/Pml/PmlUse.h"
#include "externals/Pml/PokePara/CalcTool.h"
#include "externals/Pml/PokePara/CoreParam.h"
#include "externals/Pml/PokePara/EggCheckType.h"
#include "externals/Pml/PokePara/EvolveManager.h"
#include "externals/Pml/PokePara/EvolveSituation.h"
#include "externals/Pml/PokeParty.h"
#include "externals/Pml/Sex.h"
#include "externals/Pml/WazaData/WazaDataSystem.h"
#include "externals/XLSXContent/EvolveTable.h"
#include "logger/logger.h"

struct ExtraEvoData {
    uint32_t personalRnd;
    uint16_t totalTurnCount;
    uint16_t criticalCount;
    uint16_t totalDamageReceived;
    uint16_t deadCount;
};

static ExtraEvoData extraEvoData[6] = { {},{},{},{},{},{} };

uint32_t GetFriendship(Pml::PokePara::Accessor::Object* accessor, Pml::PokePara::OwnerInfo::Object* ownerInfo)
{
    if (ownerInfo->fields.sex == accessor->GetOyasex() &&
        ownerInfo->fields.trainerId == accessor->GetID() &&
        accessor->CompareOyaName(ownerInfo->fields.name))
    {
        return accessor->GetFriendship();
    }
    else
    {
        return (uint32_t)accessor->GetOthersFriendship();
    }
}

bool IsHighFriendship(Pml::PokePara::Accessor::Object* accessor, Pml::PokePara::OwnerInfo::Object* ownerInfo)
{
    return GetFriendship(accessor, ownerInfo) >= 160;
}

bool HasMove(Pml::PokePara::CoreParam::Object* poke, int32_t wazaNo)
{
    for (uint8_t i=0; i<4; i++)
    {
        if (poke->GetWazaNo(i) == wazaNo)
            return true;
    }
    return false;
}

bool HasMoveType(Pml::PokePara::CoreParam::Object* poke, uint8_t type)
{
    for (uint8_t i=0; i<4; i++)
    {
        if (Pml::WazaData::WazaDataSystem::GetType(poke->GetWazaNo(i)) == type)
            return true;
    }
    return false;
}

bool IsNotEgg(Pml::PokePara::CoreParam::Object* poke)
{
    return !poke->IsEgg(Pml::PokePara::EggCheckType::BOTH_EGG);
}

bool HasPokemonTypeInParty(Pml::PokeParty::Object* party, uint8_t type)
{
    for (uint32_t i=0; i<party->fields.m_memberCount; i++)
    {
        auto member = (Pml::PokePara::CoreParam::Object*)party->GetMemberPointer(i);
        if (IsNotEgg(member))
        {
            if (member->GetType1() == type || member->GetType2() == type)
                return true;
        }
    }
    return false;
}

bool IsGameVersion(uint16_t version)
{
    Pml::PmlUse::getClass()->initIfNeeded();
    auto pmlUse = Pml::PmlUse::get_Instance();
    return (uint16_t)pmlUse->get_CassetVersion() == version;
}

int32_t FindExtraDataByPoke(Pml::PokePara::CoreParam::Object* poke)
{
    for (int32_t i=0; i<6; i++)
    {
        Logger::log("%d: %08X and %08X\n", i, extraEvoData[i].personalRnd, poke->GetPersonalRnd());
        if (extraEvoData[i].personalRnd == poke->GetPersonalRnd())
            return i;
    }

    return -1;
}

void ClearExtraEvoData()
{
    for (auto &i : extraEvoData)
    {
        i.personalRnd = 0;
        i.totalTurnCount = 0;
        i.criticalCount = 0;
        i.totalDamageReceived = 0;
        i.deadCount = 0;
    }
}

void LogExtraData()
{
    for (auto &i : extraEvoData)
    {
        Logger::log("ExtraData: rnd %d, turn %d, crit %d, dmg %d, dead %d\n", i.personalRnd, i.totalTurnCount, i.criticalCount, i.totalDamageReceived, i.deadCount);
    }
}

HOOK_DEFINE_REPLACE(IsSatisfyEvolveConditionLevelUp) {
    static bool Callback(Pml::PokePara::EvolveManager::Object* __this, Pml::PokePara::CoreParam::Object* poke, Pml::PokeParty::Object* party,
        Pml::PokePara::EvolveSituation::Object* situation, XLSXContent::EvolveTable::SheetEvolve::Object* evolveData, int32_t evolveRouteIndex) {
        system_load_typeinfo(0x4724);

        Logger::log("IsSatisfyEvolveConditionLevelUp\n");
        LogExtraData();

        Pml::Personal::EvolveCond evolutionCondition = Pml::Personal::EvolveTableExtensions::GetEvolutionCondition(evolveData, evolveRouteIndex);
        uint16_t evolutionParam = Pml::Personal::EvolveTableExtensions::GetEvolutionParam(evolveData, evolveRouteIndex);
        int32_t evolutionMonsNo = Pml::Personal::EvolveTableExtensions::GetEvolvedMonsNo(evolveData, evolveRouteIndex);
        uint8_t evolveEnableLevel = Pml::Personal::EvolveTableExtensions::GetEvolveEnableLevel(evolveData, evolveRouteIndex);

        Logger::log("Checking Level\n");

        // Check level
        if (poke->fields.m_accessor->HaveCalcData())
        {
            uint32_t level = poke->fields.m_accessor->GetLevel();
            if (level < evolveEnableLevel)
            {
                return false;
            }
        }
        else
        {
            uint8_t level = poke->CalcLevel();
            if (level < evolveEnableLevel)
            {
                return false;
            }
        }

        Logger::log("Finding extra data\n");

        int32_t extraDataIndex = FindExtraDataByPoke(poke);
        Logger::log("Found %d\n", extraDataIndex);

        Logger::log("Checking Conditions\n");

        switch (evolutionCondition)
        {
            case Pml::Personal::EvolveCond::FAMILIARITY_HIGH: // High Friendship
            case Pml::Personal::EvolveCond::FRIENDLY: // ???
                Logger::log("FAMILIARITY_HIGH\n");
                return IsHighFriendship(poke->fields.m_accessor, situation->fields.owner_info);

            case Pml::Personal::EvolveCond::FAMILIARITY_HIGH_NOON: // High Friendship + Morning/Day
                Logger::log("FAMILIARITY_HIGH_NOON\n");
                return IsHighFriendship(poke->fields.m_accessor, situation->fields.owner_info) && situation->fields.isMorningOrNoon;

            case Pml::Personal::EvolveCond::FAMILIARITY_HIGH_NIGHT: // High Friendship + Night
                Logger::log("FAMILIARITY_HIGH_NIGHT\n");
                return IsHighFriendship(poke->fields.m_accessor, situation->fields.owner_info) && situation->fields.isNight;

            case Pml::Personal::EvolveCond::LEVELUP: // Pure level up
            case Pml::Personal::EvolveCond::SPECIAL_LEVELUP: // Nincada level up
                Logger::log("LEVELUP\n");
                return true;

            case Pml::Personal::EvolveCond::SPECIAL_POW: // Atk > Def
                Logger::log("SPECIAL_POW\n");
                return poke->GetAtk() > poke->GetDef();

            case Pml::Personal::EvolveCond::SPECIAL_EVEN: // Atk == Def
                Logger::log("SPECIAL_EVEN\n");
                return poke->GetAtk() == poke->GetDef();

            case Pml::Personal::EvolveCond::SPECIAL_DEF: // Atk < Def
                Logger::log("SPECIAL_DEF\n");
                return poke->GetAtk() < poke->GetDef();

            case Pml::Personal::EvolveCond::SPECIAL_RND_EVEN: // Even encryption constant
                Logger::log("SPECIAL_RND_EVEN\n");
                return 4 >= (poke->GetPersonalRnd() >> 0x10) % 10;

            case Pml::Personal::EvolveCond::SPECIAL_RND_ODD: // Odd encryption constant
                Logger::log("SPECIAL_RND_ODD\n");
                return 4 < (poke->GetPersonalRnd() >> 0x10) % 10;

            case Pml::Personal::EvolveCond::SPECIAL_NUKENIN: // Shedinja (Does nothing)
                Logger::log("SPECIAL_NUKENIN\n");
                return false;

            case Pml::Personal::EvolveCond::SPECIAL_BEAUTIFUL: // High Beauty
                Logger::log("SPECIAL_BEAUTIFUL\n");
                return poke->fields.m_accessor->GetBeautiful() >= evolutionParam;

            case Pml::Personal::EvolveCond::SOUBI_NOON: // Held Item + Day
                Logger::log("SOUBI_NOON\n");
                return poke->fields.m_accessor->GetItemNo() == evolutionParam && situation->fields.isMorningOrNoon;

            case Pml::Personal::EvolveCond::SOUBI_NIGHT: // Held Item + Night
                Logger::log("SOUBI_NIGHT\n");
                return poke->fields.m_accessor->GetItemNo() == evolutionParam && situation->fields.isNight;

            case Pml::Personal::EvolveCond::WAZA: // Move
                Logger::log("WAZA\n");
                return HasMove(poke, evolutionParam);

            case Pml::Personal::EvolveCond::POKEMON: // Pokémon in party
                Logger::log("POKEMON\n");
                return party->CheckPokeExist(evolutionParam);

            case Pml::Personal::EvolveCond::MALE: // Male
                Logger::log("MALE\n");
                return poke->GetSex() == (uint8_t)Pml::Sex::MALE;

            case Pml::Personal::EvolveCond::FEMALE: // Female
            case Pml::Personal::EvolveCond::FEMALE_FORMCHANGE: // Female (Meowstic, Basculegion, Oinkologne)
                Logger::log("FEMALE\n");
                return poke->GetSex() == (uint8_t)Pml::Sex::FEMALE;

            case Pml::Personal::EvolveCond::PLACE_MAGNETIC: // Special magnetic field
                Logger::log("PLACE_MAGNETIC\n");
                return situation->fields.isMagneticField;

            case Pml::Personal::EvolveCond::PLACE_KOKE: // Moss rock
                Logger::log("PLACE_KOKE\n");
                return situation->fields.isMossField;

            case Pml::Personal::EvolveCond::PLACE_ICE: // Ice rock
                Logger::log("PLACE_ICE\n");
                return situation->fields.isIceField;

            case Pml::Personal::EvolveCond::DEVICE_TURNOVER: // Upside-down device
                Logger::log("DEVICE_TURNOVER\n");
                return situation->fields.isDeviceTurnedOver;

            case Pml::Personal::EvolveCond::FRIENDLY_WAZATYPE: // High Friendship + Move type
                Logger::log("FRIENDLY_WAZATYPE\n");
                return IsHighFriendship(poke->fields.m_accessor, situation->fields.owner_info) && HasMoveType(poke, evolutionParam);

            case Pml::Personal::EvolveCond::WITH_POKETYPE_AKU: // Dark-type Pokémon in party
                Logger::log("WITH_POKETYPE_AKU\n");
                return HasPokemonTypeInParty(party, array_index(TYPES, "Dark"));

            case Pml::Personal::EvolveCond::WEATHER_RAIN: // Raining
                Logger::log("WEATHER_RAIN\n");
                return situation->fields.isRain;

            case Pml::Personal::EvolveCond::NOON: // Day
                Logger::log("NOON\n");
                return situation->fields.isMorningOrNoon;

            case Pml::Personal::EvolveCond::NIGHT: // Night
                Logger::log("NIGHT\n");
                return situation->fields.isNight;

            case Pml::Personal::EvolveCond::CASSETTE_VERSION: // Game version
                Logger::log("CASSETTE_VERSION\n");
                return IsGameVersion(evolutionParam);

            case Pml::Personal::EvolveCond::CASSETTE_VERSION_NOON: // Game version + Day
                Logger::log("CASSETTE_VERSION_NOON\n");
                return IsGameVersion(evolutionParam) && situation->fields.isMorningOrNoon;

            case Pml::Personal::EvolveCond::CASSETTE_VERSION_NIGHT: // Game version + Night
                Logger::log("CASSETTE_VERSION_NIGHT\n");
                return IsGameVersion(evolutionParam) && situation->fields.isNight;

            case Pml::Personal::EvolveCond::PLACE_SNOW_MOUNTAIN: // Mount Lanakila (Crabrawler)
                Logger::log("PLACE_SNOW_MOUNTAIN\n");
                return situation->fields.isSnowMountain;

            case Pml::Personal::EvolveCond::EVENING: // Evening
                Logger::log("EVENING\n");
                return situation->fields.isEvening;

            case Pml::Personal::EvolveCond::PLACE_ULTRA_SPACE: // Ultra Space
                Logger::log("PLACE_ULTRA_SPACE\n");
                return situation->fields.isUltraSpace;

            case Pml::Personal::EvolveCond::CRITICAL_HIT: // Critical hits
                Logger::log("CRITICAL_HIT\n");
                if (extraDataIndex != -1) {
                    Logger::log("  crits %d\n", extraEvoData[extraDataIndex].criticalCount);
                    return extraEvoData[extraDataIndex].criticalCount >= evolutionParam;
                }

            case Pml::Personal::EvolveCond::TOTAL_DAMAGE_RECIEVED: // Total damage recieved in last battle
                Logger::log("TOTAL_DAMAGE_RECIEVED\n");
                if (extraDataIndex != -1) {
                    Logger::log("  damage: %d\n", extraEvoData[extraDataIndex].totalDamageReceived);
                    return extraEvoData[extraDataIndex].totalDamageReceived >= evolutionParam;
                }
                return false;

            case Pml::Personal::EvolveCond::SEIKAKU_HIGH: // Amped nature
                Logger::log("SEIKAKU_HIGH\n");
                return Pml::PokePara::CalcTool::IsSeikakuHigh(poke->GetSeikaku());

            case Pml::Personal::EvolveCond::SEIKAKU_LOW: // Low key nature
                Logger::log("SEIKAKU_LOW\n");
                return Pml::PokePara::CalcTool::IsSeikakuLow(poke->GetSeikaku());

            default:
                return false;
        }
    }
};

HOOK_DEFINE_INLINE(BattleProc_FinalizeCoroutine_AdjustEvolveSituation) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        auto party = (Pml::PokeParty::Object*)ctx->X[0];
        uint32_t index = ctx->W[1];
        auto poke = (Pml::PokePara::CoreParam::Object*)party->GetMemberPointer(index);
        auto evolveSituation = (Pml::PokePara::EvolveSituation::Object*)ctx->X[20];
        auto pokeResult = Dpr::Battle::Logic::BattleProc::getClass()->static_fields->setupParam->fields.pokeResult;

        evolveSituation->fields.criticalHitCount = (uint8_t)pokeResult->m_Items[index]->fields.criticalCount;

        extraEvoData[index].personalRnd = poke->GetPersonalRnd();
        extraEvoData[index].totalDamageReceived = pokeResult->m_Items[index]->fields.totalDamageRecieved;

        ctx->X[0] = (uint64_t)poke;
    }
};

void exl_evolution_methods_main() {
    IsSatisfyEvolveConditionLevelUp::InstallAtOffset(0x020525d0);
    BattleProc_FinalizeCoroutine_AdjustEvolveSituation::InstallAtOffset(0x0187e5b8);

    // Always check for evolutions, even if none are ready, and clear the extra data before checking
    using namespace exl::armv8::inst;
    using namespace exl::armv8::reg;
    exl::patch::CodePatcher p(0x0187e484);
    p.BranchLinkInst((void*)&ClearExtraEvoData);
}
