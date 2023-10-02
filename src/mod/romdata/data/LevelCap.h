#pragma once

#include "externals/il2cpp-api.h"
#include "memory/json.h"
#include "memory/vector.h"

namespace RomData
{
    struct LevelCaps
    {
        uint32_t defaultLevel;
        nn::vector<uint32_t> caps;
    };

    struct LevelCapWork
    {
        int32_t work;
        nn::string comparison;
        int32_t value;
    };

    struct LevelCapWorks
    {
        nn::vector<LevelCapWork> works;
    };

    struct LevelCapFlags
    {
        nn::vector<int32_t> flags;
    };

    struct LevelCapSysFlags
    {
        nn::vector<int32_t> sysFlags;
    };

    struct LevelCapData
    {
        LevelCaps caps;
        LevelCapWorks works;
        LevelCapFlags flags;
        LevelCapSysFlags sysFlags;
    };

    JSON_TEMPLATE
    void to_json(GENERIC_JSON& j, const LevelCaps& i) {
        j = nn::json {
            {"defaultLevel", i.defaultLevel},
            {"caps", i.caps},
        };
    }

    JSON_TEMPLATE
    void from_json(const GENERIC_JSON& j, LevelCaps& i) {
        j.at("defaultLevel").get_to(i.defaultLevel);
        j.at("caps").get_to(i.caps);
    }

    JSON_TEMPLATE
    void to_json(GENERIC_JSON& j, const LevelCapWork& m) {
        j = nn::json {
            {"work", m.work},
            {"comparison", m.comparison},
            {"value", m.value},
        };
    }

    JSON_TEMPLATE
    void from_json(const GENERIC_JSON& j, LevelCapWork& m) {
        j.at("work").get_to(m.work);
        j.at("comparison").get_to(m.comparison);
        j.at("value").get_to(m.value);
    }

    JSON_TEMPLATE
    void to_json(GENERIC_JSON& j, const LevelCapWorks& m) {
        j = nn::json {
            {"works", m.works},
        };
    }

    JSON_TEMPLATE
    void from_json(const GENERIC_JSON& j, LevelCapWorks& m) {
        j.at("works").get_to(m.works);
    }

    JSON_TEMPLATE
    void to_json(GENERIC_JSON& j, const LevelCapFlags& m) {
        j = nn::json {
            {"flags", m.flags},
        };
    }

    JSON_TEMPLATE
    void from_json(const GENERIC_JSON& j, LevelCapFlags& m) {
        j.at("flags").get_to(m.flags);
    }

    JSON_TEMPLATE
    void to_json(GENERIC_JSON& j, const LevelCapSysFlags& m) {
        j = nn::json {
            {"sysFlags", m.sysFlags},
        };
    }

    JSON_TEMPLATE
    void from_json(const GENERIC_JSON& j, LevelCapSysFlags& m) {
        j.at("sysFlags").get_to(m.sysFlags);
    }
}
