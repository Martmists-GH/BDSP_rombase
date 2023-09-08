#pragma once

#include "externals/Pml/Personal/EvolveCond.h"
#include "externals/Pml/PokePara/PokemonParam.h"
#include "externals/XLSXContent/PersonalTable.h"
#include "externals/il2cpp-api.h"

namespace Pml::Personal {
    struct PersonalSystem : ILClass<PersonalSystem,0x04c5ad18> {
        struct Fields {

        };

        static inline XLSXContent::PersonalTable::SheetPersonal::Object* GetPersonalData(int32_t monsno, uint16_t formno) {
            return external<XLSXContent::PersonalTable::SheetPersonal::Object*>(0x024a0ca0, monsno, formno);
        }

        static inline void LoadPersonalData(int32_t monsno, uint16_t formno) {
            external<void>(0x024a0d50, monsno, formno);
        }

        static inline int32_t GetTokuseiPattern(int32_t monsno, uint16_t formno) {
            return external<int32_t>(0x024a15d0, monsno, formno);
        }

        static inline void LoadEvolutionTable(int32_t monsno, uint16_t formno) {
            external<void>(0x024a2240, monsno, formno);
        }

        static inline Pml::Personal::EvolveCond GetEvolutionCondition(uint8_t route_index) {
            return external<Pml::Personal::EvolveCond>(0x024a2500, route_index);
        }

        static inline int32_t GetEvolvedMonsNo(uint8_t route_index) {
            return external<int32_t>(0x024a26d0, route_index);
        }

        static inline bool IsEvolvedFormNoSpecified(uint8_t route_index) {
            return external<bool>(0x024a2830, route_index);
        }

        static inline uint16_t GetEvolvedFormNo(uint8_t route_index) {
            return external<uint16_t>(0x024a2780, route_index);
        }
    };
}