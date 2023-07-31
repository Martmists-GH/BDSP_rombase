#pragma once

#include "externals/il2cpp-api.h"

#include "externals/Pml/PokePara/CoreParam.h"

namespace Dpr::Message {
    struct MessageWordSetHelper : ILClass<MessageWordSetHelper, 0x04c5ac68> {
        struct Fields {
        };

        static inline void SetPokemonNickNameWord(int32_t tagIndex, Pml::PokePara::CoreParam::Object* pp, bool isShowNickName) {
            external<void>(0x01f99b90, tagIndex, pp, isShowNickName);
        }

        static inline void SetDigitWord(int32_t tagIndex,int32_t number) {
            external<void>(0x01f9a580, tagIndex, number);
        }
    };
}