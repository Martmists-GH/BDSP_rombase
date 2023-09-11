#pragma once

#include "externals/il2cpp-api.h"

#include "externals/Pml/PokePara/OwnerInfo.h"

namespace Pml::PokePara {
    struct EvolveSituation : ILClass<EvolveSituation> {
        struct Fields {
            bool isMagneticField;
            bool isIceField;
            bool isMossField;
            bool isSnowMountain;
            bool isUltraSpace;
            bool isMorningOrNoon;
            bool isNight;
            bool isEvening;
            bool isRain;
            bool isDeviceTurnedOver;
            bool isTurnRoundOnField;
            uint8_t criticalHitCount;
            Pml::PokePara::OwnerInfo::Object* owner_info;
        };
    };
}