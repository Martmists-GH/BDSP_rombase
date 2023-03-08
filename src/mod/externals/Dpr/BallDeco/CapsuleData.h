#pragma once

#include <cstdint>

namespace Dpr::BallDeco {
    struct CapsuleData : IlStruct<CapsuleData> {
        struct Fields {
            uint32_t AttachPokemonId;
            uint32_t AttachPersonalRnd;
            bool Is3DEditMode;
            bool IsAppliedTemplate;
            uint8_t AffixSealCount;
            void* AffixSealDatas;
        };
    };
}
