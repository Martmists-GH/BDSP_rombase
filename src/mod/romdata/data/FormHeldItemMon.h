#pragma once

#include "externals/il2cpp-api.h"
#include "memory/json.h"
#include "memory/vector.h"

namespace RomData
{
    struct FormHeldItem
    {
        int32_t itemNo;
        int32_t formNo;
    };

    struct FormHeldItemMon
    {
        int32_t defaultForm;
        nn::vector<FormHeldItem> itemForms;
    };

    JSON_TEMPLATE
    void to_json(GENERIC_JSON& j, const FormHeldItem& i) {
        j = nn::json {
            {"itemNo", i.itemNo},
            {"formNo", i.formNo},
        };
    }

    JSON_TEMPLATE
    void from_json(const GENERIC_JSON& j, FormHeldItem& i) {
        j.at("itemNo").get_to(i.itemNo);
        j.at("formNo").get_to(i.formNo);
    }

    JSON_TEMPLATE
    void to_json(GENERIC_JSON& j, const FormHeldItemMon& m) {
        j = nn::json {
            {"defaultForm", m.defaultForm},
            {"itemForms", m.itemForms},
        };
    }

    JSON_TEMPLATE
    void from_json(const GENERIC_JSON& j, FormHeldItemMon& m) {
        j.at("defaultForm").get_to(m.defaultForm);
        j.at("itemForms").get_to(m.itemForms);
    }
}
