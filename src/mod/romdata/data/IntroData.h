#pragma once

#include "externals/il2cpp-api.h"
#include "memory/json.h"
#include "memory/vector.h"

namespace RomData
{
    struct IntroData
    {
        nn::vector<int32_t> languages;
        nn::vector<int32_t> colorVariations;
    };

    JSON_TEMPLATE
    void to_json(GENERIC_JSON& j, const IntroData& i) {
        j = nn::json {
            {"languages", i.languages},
            {"colorVariations", i.colorVariations},
        };
    }

    JSON_TEMPLATE
    void from_json(const GENERIC_JSON& j, IntroData& i) {
        j.at("languages").get_to(i.languages);
        j.at("colorVariations").get_to(i.colorVariations);
    }
}
