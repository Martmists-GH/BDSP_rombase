#pragma once

#include "externals/il2cpp-api.h"
#include "memory/json.h"
#include "memory/vector.h"

namespace RomData
{
    struct TMLearnset
    {
        uint32_t set01;
        uint32_t set02;
        uint32_t set03;
        uint32_t set04;
        uint32_t set05;
        uint32_t set06;
        uint32_t set07;
        uint32_t set08;
    };

    JSON_TEMPLATE
    void to_json(GENERIC_JSON& j, const TMLearnset& l) {
        j = nn::json {
            {"set01", l.set01},
            {"set02", l.set02},
            {"set03", l.set03},
            {"set04", l.set04},
            {"set05", l.set05},
            {"set06", l.set06},
            {"set07", l.set07},
            {"set08", l.set08},
        };
    }

    JSON_TEMPLATE
    void from_json(const GENERIC_JSON& j, TMLearnset& l) {
        j.at("set01").get_to(l.set01);
        j.at("set02").get_to(l.set02);
        j.at("set03").get_to(l.set03);
        j.at("set04").get_to(l.set04);
        j.at("set05").get_to(l.set05);
        j.at("set06").get_to(l.set06);
        j.at("set07").get_to(l.set07);
        j.at("set08").get_to(l.set08);
    }
}
