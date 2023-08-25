#pragma once

#include "externals/il2cpp-api.h"

#include "externals/System/String.h"

namespace Pml::PokePara {
    struct OwnerInfo : ILClass<OwnerInfo> {
        struct Fields {
            uint32_t trainerId;
            uint8_t sex;
            uint8_t langID;
            System::String::Object* name;
        };
    };
}