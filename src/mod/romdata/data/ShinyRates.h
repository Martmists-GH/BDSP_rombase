#pragma once

#include "externals/il2cpp-api.h"
#include "memory/json.h"
#include "memory/vector.h"

namespace RomData
{
    struct ShinyRates
    {
        uint32_t baseRolls;
        uint32_t charmRolls;
        uint32_t masudaRolls;
    };

    JSON_TEMPLATE
    void to_json(GENERIC_JSON& j, const ShinyRates& s) {
        j = nn::json {
            {"baseRolls", s.baseRolls},
            {"charmRolls", s.charmRolls},
            {"masudaRolls", s.masudaRolls},
        };
    }

    JSON_TEMPLATE
    void from_json(const GENERIC_JSON& j, ShinyRates& s) {
        j.at("baseRolls").get_to(s.baseRolls);
        j.at("charmRolls").get_to(s.charmRolls);
        j.at("masudaRolls").get_to(s.masudaRolls);
    }
}
