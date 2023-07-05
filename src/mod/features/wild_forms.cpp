#include "exlaunch.hpp"
#include "externals/FieldManager.h"
#include "externals/Dpr/Field/EncountResult.h"
#include "externals/Pml/PokeParty.h"
#include "externals/Dpr/Field/FieldEncount.h"
#include "data/species.h"
#include "data/utils.h"
#include "imgui.h"
#include "logger/logger.h"

#define _SPECIES(monsno) (monsno & 0xFFFF)
#define _FORM(monsno) ((monsno >> 16) & 0xFFFF)

static uint32_t forms = 0;
HOOK_DEFINE_REPLACE(PatchDataInit) {
    static void Callback(Dpr::Field::EncountResult::Object **result, Dpr::Field::FieldEncount::ENC_FLD_SPA::Object *spa) {
        auto encount = *result;
        if (encount->fields.HatudouTokusei == 0 && spa->fields.Egg == 0 && (spa->fields.Spa == 14 || spa->fields.Spa == 105)) {
            encount->fields.HatudouTokusei = spa->fields.Spa;
        }

        auto encSpecies = encount->fields.Enemy;

        if (encSpecies->max_length == 0) {
            return;
        }

        for (uint64_t i = 0; i < encSpecies->max_length; i++) {
            int species = _SPECIES(encSpecies->m_Items[i]);
            int form = _FORM(encSpecies->m_Items[i]);

            if (species == array_index(SPECIES, "Shellos") || species == array_index(SPECIES, "Gastrodon")) {
                form = spa->fields.FormProb->m_Items[0] != 0;
            }

            if (i == 0) {
                // single battle
                encount->fields.karanaForm = form;
                encSpecies->m_Items[i] = species;
            } else if (i == 1) {
                // double battle
                encount->fields.karanaForm |= form << 16;
                encSpecies->m_Items[i] = species;
            }

            if (species == array_index(SPECIES, "Unown")) {
                encount->fields.annoForm = spa->fields.AnnoonTblType;
            }
        }
    }
};

HOOK_DEFINE_TRAMPOLINE(PatchGetForm) {
    static uint16_t Callback(FieldManager* __this, int32_t mons, int32_t karana, int32_t anno) {
        if (mons == array_index(SPECIES, "Shellos") || mons == array_index(SPECIES, "Gastrodon")) {
            return karana != 0;
        }

        if (mons == array_index(SPECIES, "Unown")) {
            return Orig(__this, mons, karana, anno);
        }

        uint16_t res = forms & 0xFFFF;
        forms >>= 16;
        return res;
    }
};

void exl_wild_forms_main() {
    PatchDataInit::InstallAtOffset(0x019b4990);
    PatchGetForm::InstallAtOffset(0x0179f560);
}
