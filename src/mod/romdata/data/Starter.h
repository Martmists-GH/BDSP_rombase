#pragma once

#include "externals/il2cpp-api.h"
#include "memory/json.h"
#include "memory/vector.h"

namespace RomData
{
    struct Starter
    {
        int32_t monsNo;
        int32_t formNo;
        uint32_t level;
        int32_t itemNo;
    };

    JSON_TEMPLATE
    void to_json(GENERIC_JSON& j, const Starter& s) {
        j = nn::json {
            {"monsNo", s.monsNo},
            {"formNo", s.formNo},
            {"level", s.level},
            {"itemNo", s.itemNo},
        };
    }

    JSON_TEMPLATE
    void from_json(const GENERIC_JSON& j, Starter& s) {
        j.at("monsNo").get_to(s.monsNo);
        j.at("formNo").get_to(s.formNo);
        j.at("level").get_to(s.level);
        j.at("itemNo").get_to(s.itemNo);
    }
}
