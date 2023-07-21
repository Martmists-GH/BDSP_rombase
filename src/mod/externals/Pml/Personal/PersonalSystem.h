#pragma once

#include "externals/Pml/PokePara/PokemonParam.h"
#include "externals/XLSXContent/PersonalTable.h"
#include "externals/il2cpp-api.h"

namespace Pml::Personal {
    struct PersonalSystem : ILClass<PersonalSystem,0x04c5ad18> {
        struct Fields {

        };
        static inline XLSXContent::PersonalTable::SheetPersonal::Object* GetPersonalData(int32_t monsno,uint16_t formno) {
            return external<XLSXContent::PersonalTable::SheetPersonal::Object*>(0x024a0ca0, monsno, formno);
        }

    };
}