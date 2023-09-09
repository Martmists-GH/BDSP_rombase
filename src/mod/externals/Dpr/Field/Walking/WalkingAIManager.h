#pragma once

#include "externals/il2cpp-api.h"
#include "externals/FieldObjectEntity.h"

namespace Dpr::Field::Walking {
    struct WalkingAIManager : ILClass<WalkingAIManager> {
        struct Fields {
            void* walkingCharacters; // System_Collections_Generic_List_WalkingCharacterController__o*
            bool isAllStop;
            FieldObjectEntity::Object* testEntity;
            int32_t Button01;
            int32_t Button02;
        };
    };
}
