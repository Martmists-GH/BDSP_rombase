#include "exlaunch.hpp"

#include "helpers.h"
#include "memory/json.h"
#include "memory/string.h"

#include "romdata/data/ShinyRates.h"

#include "logger/logger.h"

static RomData::ShinyRates shinyRatesData;
static bool isShinyRatesDataLoaded = false;

const char* shinyRatesFolderPath = "rom:/Data/ExtraData/ShinyRates/";

void LoadShinyRates()
{
    nn::string filePath(shinyRatesFolderPath);
    filePath.append("shiny_rates.json");
    Logger::log("Checking Shiny Rates for %s!\n", filePath.c_str());

    nn::json j = FsHelper::loadJsonFileFromPath(filePath.c_str());
    if (j != nullptr && !j.is_discarded())
    {
        Logger::log("Parsed Shiny Rates for %s!\n", filePath.c_str());
        shinyRatesData = j.get<RomData::ShinyRates>();
        isShinyRatesDataLoaded = true;
    }
    else
    {
        Logger::log("Error when parsing Shiny Rates data!\n");
        // Default - Lumi odds
        shinyRatesData = {
            .baseRolls = 8,
            .charmRolls = 2,
            .masudaRolls = 6,
        };
        isShinyRatesDataLoaded = true;
    }
}

RomData::ShinyRates GetShinyRates()
{
    if (!isShinyRatesDataLoaded)
        LoadShinyRates();

    return shinyRatesData;
}