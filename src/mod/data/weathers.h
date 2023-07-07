#pragma once

static constexpr const char* WEATHERS[] = {
        "Sunny",
        "Cloudy",
        "Rain",
        "Sideways Rain",
        "Thunderstorm",
        "Snow",
        "Snowstorm",
        "Heavy Snowstorm",
        "FOG (Stubbed)",
        "Ashy",
        "Sandstorm",
        "Diamond Dust",
        "SPIRIT (Stubbed)",
        "MYSTIC (Stubbed)",
        "MIST1 (Stubbed)",
        "MIST2 (Stubbed)",
        "FLASH (Stubbed)",
        "SPARK_EFF (Stubbed)",
        "FOGS (Stubbed)",
        "FOGM (Stubbed)",
};

constexpr int WEATHER_COUNT = sizeof(WEATHERS) / sizeof(WEATHERS[0]);
