#pragma once

#include "externals/il2cpp-api.h"

struct WeatherWork : ILClass<WeatherWork> {
    struct Fields {

    };

    static inline void set_WeatherID(int32_t value) {
        external<void>(0x017d18a0, value);
    }
};
