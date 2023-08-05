#include "exlaunch.hpp"

#include "data/species.h"
#include "data/items.h"
#include "data/utils.h"

#include "externals/DPData/Form_Enums.h"
#include "externals/Pml/PokePara/CalcTool.h"

uint8_t GetSilvallyType(int32_t itemno) {
    if (itemno == array_index(ITEMS, "Fighting Memory"))
        return (uint8_t)SilvallyForm::FIGHTING;
    else if (itemno == array_index(ITEMS, "Flying Memory"))
        return (uint8_t)SilvallyForm::FLYING;
    else if (itemno == array_index(ITEMS, "Poison Memory"))
        return (uint8_t)SilvallyForm::POISON;
    else if (itemno == array_index(ITEMS, "Ground Memory"))
        return (uint8_t)SilvallyForm::GROUND;
    else if (itemno == array_index(ITEMS, "Rock Memory"))
        return (uint8_t)SilvallyForm::ROCK;
    else if (itemno == array_index(ITEMS, "Bug Memory"))
        return (uint8_t)SilvallyForm::BUG;
    else if (itemno == array_index(ITEMS, "Ghost Memory"))
        return (uint8_t)SilvallyForm::GHOST;
    else if (itemno == array_index(ITEMS, "Steel Memory"))
        return (uint8_t)SilvallyForm::STEEL;
    else if (itemno == array_index(ITEMS, "Fire Memory"))
        return (uint8_t)SilvallyForm::FIRE;
    else if (itemno == array_index(ITEMS, "Water Memory"))
        return (uint8_t)SilvallyForm::WATER;
    else if (itemno == array_index(ITEMS, "Grass Memory"))
        return (uint8_t)SilvallyForm::GRASS;
    else if (itemno == array_index(ITEMS, "Electric Memory"))
        return (uint8_t)SilvallyForm::ELECTRIC;
    else if (itemno == array_index(ITEMS, "Psychic Memory"))
        return (uint8_t)SilvallyForm::PSYCHIC;
    else if (itemno == array_index(ITEMS, "Ice Memory"))
        return (uint8_t)SilvallyForm::ICE;
    else if (itemno == array_index(ITEMS, "Dragon Memory"))
        return (uint8_t)SilvallyForm::DRAGON;
    else if (itemno == array_index(ITEMS, "Dark Memory"))
        return (uint8_t)SilvallyForm::DARK;
    else if (itemno == array_index(ITEMS, "Fairy Memory"))
        return (uint8_t)SilvallyForm::FAIRY;
    else
        return (uint8_t)SilvallyForm::NORMAL;
}

HOOK_DEFINE_REPLACE(DecideFormNoFromHoldItem) {
    static bool Callback(int32_t monsno, uint32_t holdItemno, uint16_t *formno) {
        system_load_typeinfo(0x29a9);
        int32_t intHeldItem = (int32_t)holdItemno;

        if (monsno == array_index(SPECIES, "Mewtwo"))
        {
            if (intHeldItem == array_index(ITEMS, "Mewtwo Armor"))
                *formno = (int32_t)MewtwoForm::ARMORED_MK2;
            else if (intHeldItem == array_index(ITEMS, "Old Mewtwo Armor"))
                *formno = (int32_t)MewtwoForm::ARMORED_MK1;
            else
                *formno = (int32_t)MewtwoForm::REGULAR;

            return true;
        }
        else if (monsno == array_index(SPECIES, "Giratina"))
        {
            if (intHeldItem == array_index(ITEMS, "Griseous Orb"))
                *formno = (int32_t)GiratinaForm::ORIGIN;
            else
                *formno = (int32_t)GiratinaForm::ALTERED;

            return true;
        }
        else if (monsno == array_index(SPECIES, "Arceus"))
        {
            *formno = Pml::PokePara::CalcTool::GetArceusType(intHeldItem);

            return true;
        }
        else if (monsno == array_index(SPECIES, "Genesect"))
        {
            if (intHeldItem == array_index(ITEMS, "Douse Drive"))
                *formno = (int32_t)GenesectForm::DOUSE_DRIVE;
            else if (intHeldItem == array_index(ITEMS, "Shock Drive"))
                *formno = (int32_t)GenesectForm::SHOCK_DRIVE;
            else if (intHeldItem == array_index(ITEMS, "Burn Drive"))
                *formno = (int32_t)GenesectForm::BURN_DRIVE;
            else if (intHeldItem == array_index(ITEMS, "Chill Drive"))
                *formno = (int32_t)GenesectForm::CHILL_DRIVE;
            else
                *formno = (int32_t)GenesectForm::REGULAR;

            return true;
        }
        else if (monsno == array_index(SPECIES, "Silvally"))
        {
            *formno = GetSilvallyType(intHeldItem);

            return true;
        }
        else if (monsno == array_index(SPECIES, "Zacian"))
        {
            if (intHeldItem == array_index(ITEMS, "Rusted Sword"))
                *formno = (int32_t)ZacianForm::CROWNED_SWORD;
            else
                *formno = (int32_t)ZacianForm::HERO_OF_MANY_BATTLES;

            return true;
        }
        else if (monsno == array_index(SPECIES, "Zamazenta"))
        {
            if (intHeldItem == array_index(ITEMS, "Rusted Shield"))
                *formno = (int32_t)ZamazentaForm::CROWNED_SHIELD;
            else
                *formno = (int32_t)ZamazentaForm::HERO_OF_MANY_BATTLES;

            return true;
        }
        else
        {
            // Doesn't match any pokémon that changes forms, don't change
            return false;
        }
    }
};

HOOK_DEFINE_TRAMPOLINE(CheckUnbreakablePokeItem) {
    static bool Callback(uint16_t monsno, uint16_t itemID) {
        if (monsno == array_index(SPECIES, "Mewtwo"))
        {
            if (itemID == array_index(ITEMS, "Mewtwo Armor")
            || itemID == array_index(ITEMS, "Old Mewtwo Armor"))
                return true;
        }
        else if (monsno == array_index(SPECIES, "Genesect"))
        {
            if (itemID == array_index(ITEMS, "Douse Drive")
            || itemID == array_index(ITEMS, "Shock Drive")
            || itemID == array_index(ITEMS, "Burn Drive")
            || itemID == array_index(ITEMS, "Chill Drive"))
                return true;
        }
        else if (monsno == array_index(SPECIES, "Silvally"))
        {
            if (itemID == array_index(ITEMS, "Fighting Memory")
            || itemID == array_index(ITEMS, "Flying Memory")
            || itemID == array_index(ITEMS, "Poison Memory")
            || itemID == array_index(ITEMS, "Ground Memory")
            || itemID == array_index(ITEMS, "Rock Memory")
            || itemID == array_index(ITEMS, "Bug Memory")
            || itemID == array_index(ITEMS, "Ghost Memory")
            || itemID == array_index(ITEMS, "Steel Memory")
            || itemID == array_index(ITEMS, "Fire Memory")
            || itemID == array_index(ITEMS, "Water Memory")
            || itemID == array_index(ITEMS, "Grass Memory")
            || itemID == array_index(ITEMS, "Electric Memory")
            || itemID == array_index(ITEMS, "Psychic Memory")
            || itemID == array_index(ITEMS, "Ice Memory")
            || itemID == array_index(ITEMS, "Dragon Memory")
            || itemID == array_index(ITEMS, "Dark Memory")
            || itemID == array_index(ITEMS, "Fairy Memory"))
                return true;
        }
        else if (monsno == array_index(SPECIES, "Zacian"))
        {
            if (itemID == array_index(ITEMS, "Rusted Sword"))
                return true;
        }
        else if (monsno == array_index(SPECIES, "Zamazenta"))
        {
            if (itemID == array_index(ITEMS, "Rusted Shield"))
                return true;
        }
        else if (monsno == array_index(SPECIES, "Great Tusk")
        || monsno == array_index(SPECIES, "Scream Tail")
        || monsno == array_index(SPECIES, "Brute Bonnet")
        || monsno == array_index(SPECIES, "Flutter Mane")
        || monsno == array_index(SPECIES, "Slither Wing")
        || monsno == array_index(SPECIES, "Sandy Shocks")
        || monsno == array_index(SPECIES, "Roaring Moon")
        || monsno == array_index(SPECIES, "Iron Treads")
        || monsno == array_index(SPECIES, "Iron Bundle")
        || monsno == array_index(SPECIES, "Iron Hands")
        || monsno == array_index(SPECIES, "Iron Jugulis")
        || monsno == array_index(SPECIES, "Iron Moth")
        || monsno == array_index(SPECIES, "Iron Thorns")
        || monsno == array_index(SPECIES, "Iron Valiant")
        || monsno == array_index(SPECIES, "Walking Wake")
        || monsno == array_index(SPECIES, "Iron Leaves"))
        {
            if (itemID == array_index(ITEMS, "Booster Energy"))
                return true;
        }

        // Base method handles Kyogre/Groundon with Red/Blue Orb, Arceus with Plates, and Giratina with Griseous Orb
        return Orig(monsno, itemID);
    }
};

void exl_form_change_held_items_main(){
    DecideFormNoFromHoldItem::InstallAtOffset(0x024aeb90);
    CheckUnbreakablePokeItem::InstallAtOffset(0x01d0d780);
};