#pragma once

#include "externals/Dpr/Box/SaveBoxData.h"
#include "externals/Dpr/Box/SaveBoxTrayData.h"
#include "externals/System/Primitives.h"

template <int32_t size>
struct BoxSaveData {
    Dpr::Box::SaveBoxData::_STR17::Object boxNames[size];
    System::Byte wallpapers[size];
    Dpr::Box::SaveBoxTrayData::Object pokemonParams[size];
};
