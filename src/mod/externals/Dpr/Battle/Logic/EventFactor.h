#pragma once

#include "externals/il2cpp-api.h"

#include "externals/Dpr/Battle/Logic/MainModule.h"

namespace Dpr::Battle::Logic {
    struct EventFactor : ILClass<EventFactor> {
        struct EventHandlerArgs : ILClass<EventHandlerArgs> {
            struct Fields {
                Dpr::Battle::Logic::MainModule::Object* pMainModule;
                void* pBattleEnv; // Dpr::Battle::Logic::BattleEnv::Object*
                void* pPokeActionContainer; // Dpr::Battle::Logic::PokeActionContainer::Object*
                void* pPokeChangeRequest; // Dpr::Battle::Logic::PokeChangeRequest::Object*
                void* pSectionContainer; // Dpr::Battle::Logic::SectionContainer::Object*
                void* pSectionSharedData; // Dpr::Battle::Logic::SectionSharedData::Object*
                void* pEventSystem; // Dpr::Battle::Logic::EventSystem::Object*
                void* pEventVar; // Dpr::Battle::Logic::EventVarSet::Object*
                Dpr::Battle::Logic::EventFactor::Object* pMyFactor;
            };
        };
    };
}
