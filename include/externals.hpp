#pragma once

#include "exlaunch.hpp"

#define DEFINE_EXTERNAL_NAME(name) \
    extern "C" { \
        static void* name; \
    }

#define EXTERNAL_ADDRESS(name, address) name = reinterpret_cast<typeof(name)>(exl::util::modules::GetTargetOffset(address));
