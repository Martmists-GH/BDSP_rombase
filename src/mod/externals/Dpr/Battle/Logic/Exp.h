#pragma once

#include "externals/il2cpp-api.h"

namespace Dpr::Battle::Logic {
    struct Exp : ILClass<Exp> {
        struct CalcParam : ILClass<CalcParam, 0x04c5b0a0> {
            struct Fields {
                int32_t competitor;
                uint32_t playerLanguageId;
                uint32_t levelCap;
                uint32_t deadPokeExp;
                uint32_t deadPokeLevel;
                uint32_t getPokeLevel;
                uint32_t getPokeFriendship;
                uint32_t getPokeLanguageId;
                bool isMatch;
                bool isGakusyuSoutiOn;
                bool haveSiawasetamago;
                bool isEvoCanceledPoke;
                bool isMyPoke;
            };

            inline void ctor() {
                external<void>(0x026d1230, this);
            }
        };

        struct CalcResult : ILClass<CalcResult, 0x04c5b0a8> {
            struct Fields {
                uint32_t exp;
                bool byGakusyuSouti;
                bool isContainBonus;
            };

            inline void ctor() {
                external<void>(0x026d1230, this);
            }
        };

        static inline void CalcExp(Dpr::Battle::Logic::Exp::CalcParam** param, Dpr::Battle::Logic::Exp::CalcResult* result) {
            external<void>(0x018f7d70, param, result);
        }
    };
}
