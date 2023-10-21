#include "exlaunch.hpp"

#include "helpers.h"
#include "memory/json.h"
#include "memory/string.h"

#include "romdata/data/TMLearnset.h"

#include "logger/logger.h"

const char* tmLearnsetFolderPath = "rom:/Data/ExtraData/MonData/TMLearnset/";

RomData::TMLearnset GetTMLearnset(int32_t monsno, int32_t formno)
{
    nn::string filePath(tmLearnsetFolderPath);
    filePath.append("monsno_" + nn::to_string(monsno) + "_formno_" + nn::to_string(formno) + ".json");

    nn::json j = FsHelper::loadJsonFileFromPath(filePath.c_str());
    if (j != nullptr && !j.is_discarded())
    {
        RomData::TMLearnset tmLearnset = {};
        tmLearnset = j.get<RomData::TMLearnset>();

        return tmLearnset;
    }
    else
    {
        Logger::log("Error when parsing TM Learnset data!\n");
    }

    // Default - No TMs learned
    return {
        .set01 = 0,
        .set02 = 0,
        .set03 = 0,
        .set04 = 0,
        .set05 = 0,
        .set06 = 0,
        .set07 = 0,
        .set08 = 0,
    };
}

bool CanLearnTM(int32_t monsno, int32_t formno, int32_t tm)
{
    // Re-index to TM01 -> 0, etc.
    tm = tm - 1;

    if (tm > -1 && tm < 256)
    {
        RomData::TMLearnset learnset = GetTMLearnset(monsno, formno);
        int32_t bit = tm % 32;
        int32_t set = tm / 32;
        switch (set)
        {
            case 0:
                return ((learnset.set01 >> bit) & 1) == 1;
            case 1:
                return ((learnset.set02 >> bit) & 1) == 1;
            case 2:
                return ((learnset.set03 >> bit) & 1) == 1;
            case 3:
                return ((learnset.set04 >> bit) & 1) == 1;
            case 4:
                return ((learnset.set05 >> bit) & 1) == 1;
            case 5:
                return ((learnset.set06 >> bit) & 1) == 1;
            case 6:
                return ((learnset.set07 >> bit) & 1) == 1;
            case 7:
                return ((learnset.set08 >> bit) & 1) == 1;
            default:
                return false;
        }
    }

    // Default - Not learned
    return false;
}