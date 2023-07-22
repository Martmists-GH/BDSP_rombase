#pragma once

#include "externals/il2cpp-api.h"

#include "externals/UnityEngine/ScriptableObject.h"

namespace XLSXContent {
    struct CalenderEncTable : ILClass<CalenderEncTable> {
        struct Sheetdata : ILClass<Sheetdata> {
            struct Fields {
                int32_t month;
                int32_t day;
                int32_t add_rate;
                int32_t add_hatching;
            };
        };

        struct Sheetweather : ILClass<Sheetweather> {
            struct Fields {
                int32_t r212b;
                int32_t r213;
                int32_t r216;
                int32_t l3;
                int32_t c9;
            };
        };

        struct Fields : UnityEngine::ScriptableObject::Fields {
            XLSXContent::CalenderEncTable::Sheetdata::Array* data;
	        XLSXContent::CalenderEncTable::Sheetweather::Array* weather;
        };
    };
}
