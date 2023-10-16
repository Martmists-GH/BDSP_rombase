#pragma once

#include "externals/il2cpp-api.h"
#include "memory/json.h"
#include "memory/vector.h"

namespace RomData
{
    struct HoneyTreeSlot
    {
        int32_t maxlv;
        int32_t minlv;
        int32_t monsNo;
        int32_t formNo;
    };

    struct HoneyTreeZone
    {
        nn::vector<HoneyTreeSlot> slots;
    };

    JSON_TEMPLATE
    void to_json(GENERIC_JSON& j, const HoneyTreeSlot& s) {
        j = nn::json {
            {"maxlv", s.maxlv},
            {"minlv", s.minlv},
            {"monsNo", s.monsNo},
            {"formNo", s.formNo},
        };
    }

    JSON_TEMPLATE
    void from_json(const GENERIC_JSON& j, HoneyTreeSlot& s) {
        j.at("maxlv").get_to(s.maxlv);
        j.at("minlv").get_to(s.minlv);
        j.at("monsNo").get_to(s.monsNo);
        j.at("formNo").get_to(s.formNo);
    }

    JSON_TEMPLATE
    void to_json(GENERIC_JSON& j, const HoneyTreeZone& z) {
        j = nn::json {
            {"slots", z.slots},
        };
    }

    JSON_TEMPLATE
    void from_json(const GENERIC_JSON& j, HoneyTreeZone& z) {
        j.at("slots").get_to(z.slots);
    }
}
