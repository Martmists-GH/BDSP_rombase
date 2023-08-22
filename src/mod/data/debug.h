#pragma once

static constexpr const char *DEBUG_SEXES[] = {
    "-",
    "Male",
    "Female",
    "Genderless",
};

static constexpr const char *DEBUG_SHINIES[] = {
    "-",
    "Non-shiny",
    "Shiny",
    "Square Shiny",
};

constexpr int DEBUG_SEX_COUNT = sizeof(DEBUG_SEXES) / sizeof(DEBUG_SEXES[0]);

constexpr int DEBUG_SHINY_COUNT = sizeof(DEBUG_SHINIES) / sizeof(DEBUG_SHINIES[0]);