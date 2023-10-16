#pragma once

#include "externals/il2cpp-api.h"

namespace RomData
{
    struct UnbreakablePokeItem
    {
        nn::vector<int32_t> items;
    };

    JSON_TEMPLATE
    void to_json(GENERIC_JSON& j, const UnbreakablePokeItem& u) {
        j = nn::json {
            {"items", u.items},
        };
    }

    JSON_TEMPLATE
    void from_json(const GENERIC_JSON& j, UnbreakablePokeItem& u) {
        j.at("items").get_to(u.items);
    }
}
