#pragma once

#include "externals/il2cpp.h"

#include "externals/Pml/PokePara/PokemonParam.h"

struct FieldPoketch : ILClass<FieldPoketch, 0x04c5e648> {
    static inline void OnPushedAppearButton() {
        external<void>(0x01db9a50);
    }

    static inline void RestorePoketchWindow() {
        external<void>(0x01dba500);
    }

    static inline bool IsControlPoketch() {
        return external<bool>(0x01db0a70);
    }

    static inline bool IsRejectPoketch() {
        return external<bool>(0x01db9c60);
    }

    static inline bool IsCloseOncePoketch() {
        return external<bool>(0x01db9e40);
    }

    static inline void AddPokemonHistory(Pml::PokePara::PokemonParam::Object* pokeParam) {
        external<void>(0x01dba9c0, pokeParam);
    }
};
