#include <vector>

#include "exlaunch.hpp"

#include "data/items.h"
#include "data/species.h"
#include "data/utils.h"
#include "externals/DPData/Form_Enums.h"
#include "romdata/data/FormHeldItemMon.h"
#include "romdata/data/UnbreakablePokeItem.h"

std::vector<RomData::FormHeldItemMon> GetFormHeldItemMons()
{
    return {
        { .monsno = array_index(SPECIES, "Mewtwo"), .itemno = array_index(ITEMS, "Mewtwo Armor"), .formno = (uint16_t)MewtwoForm::ARMORED_MK2 },
        { .monsno = array_index(SPECIES, "Mewtwo"), .itemno = array_index(ITEMS, "Old Mewtwo Armor"), .formno = (uint16_t)MewtwoForm::ARMORED_MK1 },

        { .monsno = array_index(SPECIES, "Giratina"), .itemno = array_index(ITEMS, "Griseous Orb"), .formno = (uint16_t)GiratinaForm::ORIGIN },

        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Fist Plate"), .formno = (uint16_t)ArceusForm::FIGHTING },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Sky Plate"), .formno = (uint16_t)ArceusForm::FLYING },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Toxic Plate"), .formno = (uint16_t)ArceusForm::POISON },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Earth Plate"), .formno = (uint16_t)ArceusForm::GROUND },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Stone Plate"), .formno = (uint16_t)ArceusForm::ROCK },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Insect Plate"), .formno = (uint16_t)ArceusForm::BUG },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Spooky Plate"), .formno = (uint16_t)ArceusForm::GHOST },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Iron Plate"), .formno = (uint16_t)ArceusForm::STEEL },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Flame Plate"), .formno = (uint16_t)ArceusForm::FIRE },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Splash Plate"), .formno = (uint16_t)ArceusForm::WATER },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Meadow Plate"), .formno = (uint16_t)ArceusForm::GRASS },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Zap Plate"), .formno = (uint16_t)ArceusForm::ELECTRIC },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Mind Plate"), .formno = (uint16_t)ArceusForm::PSYCHIC },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Icicle Plate"), .formno = (uint16_t)ArceusForm::ICE },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Draco Plate"), .formno = (uint16_t)ArceusForm::DRAGON },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Dread Plate"), .formno = (uint16_t)ArceusForm::DARK },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Pixie Plate"), .formno = (uint16_t)ArceusForm::FAIRY },

        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Fightinium Z (Held)"), .formno = (uint16_t)ArceusForm::FIGHTING },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Flyinium Z (Held)"), .formno = (uint16_t)ArceusForm::FLYING },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Poisonium Z (Held)"), .formno = (uint16_t)ArceusForm::POISON },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Groundium Z (Held)"), .formno = (uint16_t)ArceusForm::GROUND },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Rockium Z (Held)"), .formno = (uint16_t)ArceusForm::ROCK },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Buginium Z (Held)"), .formno = (uint16_t)ArceusForm::BUG },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Ghostium Z (Held)"), .formno = (uint16_t)ArceusForm::GHOST },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Steelium Z (Held)"), .formno = (uint16_t)ArceusForm::STEEL },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Firium Z (Held)"), .formno = (uint16_t)ArceusForm::FIRE },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Waterium Z (Held)"), .formno = (uint16_t)ArceusForm::WATER },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Grassium Z (Held)"), .formno = (uint16_t)ArceusForm::GRASS },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Electrium Z (Held)"), .formno = (uint16_t)ArceusForm::ELECTRIC },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Psychium Z (Held)"), .formno = (uint16_t)ArceusForm::PSYCHIC },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Icium Z (Held)"), .formno = (uint16_t)ArceusForm::ICE },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Dragonium Z (Held)"), .formno = (uint16_t)ArceusForm::DRAGON },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Darkinium Z (Held)"), .formno = (uint16_t)ArceusForm::DARK },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Fairium Z (Held)"), .formno = (uint16_t)ArceusForm::FAIRY },

        { .monsno = array_index(SPECIES, "Genesect"), .itemno = array_index(ITEMS, "Douse Drive"), .formno = (uint16_t)GenesectForm::DOUSE_DRIVE },
        { .monsno = array_index(SPECIES, "Genesect"), .itemno = array_index(ITEMS, "Shock Drive"), .formno = (uint16_t)GenesectForm::SHOCK_DRIVE },
        { .monsno = array_index(SPECIES, "Genesect"), .itemno = array_index(ITEMS, "Burn Drive"), .formno = (uint16_t)GenesectForm::BURN_DRIVE },
        { .monsno = array_index(SPECIES, "Genesect"), .itemno = array_index(ITEMS, "Chill Drive"), .formno = (uint16_t)GenesectForm::CHILL_DRIVE },

        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Fighting Memory"), .formno = (uint16_t)SilvallyForm::FIGHTING },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Flying Memory"), .formno = (uint16_t)SilvallyForm::FLYING },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Poison Memory"), .formno = (uint16_t)SilvallyForm::POISON },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Ground Memory"), .formno = (uint16_t)SilvallyForm::GROUND },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Rock Memory"), .formno = (uint16_t)SilvallyForm::ROCK },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Bug Memory"), .formno = (uint16_t)SilvallyForm::BUG },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Ghost Memory"), .formno = (uint16_t)SilvallyForm::GHOST },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Steel Memory"), .formno = (uint16_t)SilvallyForm::STEEL },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Fire Memory"), .formno = (uint16_t)SilvallyForm::FIRE },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Water Memory"), .formno = (uint16_t)SilvallyForm::WATER },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Grass Memory"), .formno = (uint16_t)SilvallyForm::GRASS },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Electric Memory"), .formno = (uint16_t)SilvallyForm::ELECTRIC },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Psychic Memory"), .formno = (uint16_t)SilvallyForm::PSYCHIC },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Ice Memory"), .formno = (uint16_t)SilvallyForm::ICE },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Dragon Memory"), .formno = (uint16_t)SilvallyForm::DRAGON },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Dark Memory"), .formno = (uint16_t)SilvallyForm::DARK },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Fairy Memory"), .formno = (uint16_t)SilvallyForm::FAIRY },

        { .monsno = array_index(SPECIES, "Zacian"), .itemno = array_index(ITEMS, "Rusted Sword"), .formno = (uint16_t)ZacianForm::CROWNED_SWORD },

        { .monsno = array_index(SPECIES, "Zamazenta"), .itemno = array_index(ITEMS, "Rusted Shield"), .formno = (uint16_t)ZamazentaForm::CROWNED_SHIELD },
    };
}

std::vector<RomData::FormHeldItemMon> GetFormHeldItemMonsDefault()
{
    return {
        { .monsno = array_index(SPECIES, "Mewtwo"), .itemno = 0, .formno = (uint16_t)MewtwoForm::REGULAR },
        { .monsno = array_index(SPECIES, "Giratina"), .itemno = 0, .formno = (uint16_t)GiratinaForm::ALTERED },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = 0, .formno = (uint16_t)ArceusForm::NORMAL },
        { .monsno = array_index(SPECIES, "Genesect"), .itemno = 0, .formno = (uint16_t)GenesectForm::REGULAR },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = 0, .formno = (uint16_t)SilvallyForm::NORMAL },
        { .monsno = array_index(SPECIES, "Zacian"), .itemno = 0, .formno = (uint16_t)ZacianForm::HERO_OF_MANY_BATTLES },
        { .monsno = array_index(SPECIES, "Zamazenta"), .itemno = 0, .formno = (uint16_t)ZamazentaForm::HERO_OF_MANY_BATTLES },
    };
}

std::vector<RomData::UnbreakablePokeItem> GetUnbreakablePokeItems()
{
    return {
        { .monsno = array_index(SPECIES, "Mewtwo"), .itemno = array_index(ITEMS, "Mewtwo Armor") },
        { .monsno = array_index(SPECIES, "Mewtwo"), .itemno = array_index(ITEMS, "Old Mewtwo Armor") },

        { .monsno = array_index(SPECIES, "Groudon"), .itemno = array_index(ITEMS, "Red Orb") },
        { .monsno = array_index(SPECIES, "Kyogre"), .itemno = array_index(ITEMS, "Blue Orb") },

        { .monsno = array_index(SPECIES, "Giratina"), .itemno = array_index(ITEMS, "Griseous Orb") },

        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Fist Plate") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Sky Plate") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Toxic Plate") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Earth Plate") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Stone Plate") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Insect Plate") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Spooky Plate") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Iron Plate") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Flame Plate") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Splash Plate") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Meadow Plate") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Zap Plate") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Mind Plate") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Icicle Plate") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Draco Plate") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Dread Plate") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Pixie Plate") },

        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Fightinium Z (Held)") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Flyinium Z (Held)") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Poisonium Z (Held)") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Groundium Z (Held)") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Rockium Z (Held)") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Buginium Z (Held)") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Ghostium Z (Held)") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Steelium Z (Held)") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Firium Z (Held)") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Waterium Z (Held)") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Grassium Z (Held)") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Electrium Z (Held)") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Psychium Z (Held)") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Icium Z (Held)") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Dragonium Z (Held)") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Darkinium Z (Held)") },
        { .monsno = array_index(SPECIES, "Arceus"), .itemno = array_index(ITEMS, "Fairium Z (Held)") },

        { .monsno = array_index(SPECIES, "Genesect"), .itemno = array_index(ITEMS, "Douse Drive") },
        { .monsno = array_index(SPECIES, "Genesect"), .itemno = array_index(ITEMS, "Shock Drive") },
        { .monsno = array_index(SPECIES, "Genesect"), .itemno = array_index(ITEMS, "Burn Drive") },
        { .monsno = array_index(SPECIES, "Genesect"), .itemno = array_index(ITEMS, "Chill Drive") },

        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Fighting Memory") },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Flying Memory") },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Poison Memory") },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Ground Memory") },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Rock Memory") },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Bug Memory") },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Ghost Memory") },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Steel Memory") },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Fire Memory") },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Water Memory") },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Grass Memory") },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Electric Memory") },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Psychic Memory") },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Ice Memory") },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Dragon Memory") },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Dark Memory") },
        { .monsno = array_index(SPECIES, "Silvally"), .itemno = array_index(ITEMS, "Fairy Memory") },

        { .monsno = array_index(SPECIES, "Zacian"), .itemno = array_index(ITEMS, "Rusted Sword") },

        { .monsno = array_index(SPECIES, "Zamazenta"), .itemno = array_index(ITEMS, "Rusted Shield") },

        { .monsno = array_index(SPECIES, "Great Tusk"), .itemno = array_index(ITEMS, "Booster Energy") },
        { .monsno = array_index(SPECIES, "Scream Tail"), .itemno = array_index(ITEMS, "Booster Energy") },
        { .monsno = array_index(SPECIES, "Brute Bonnet"), .itemno = array_index(ITEMS, "Booster Energy") },
        { .monsno = array_index(SPECIES, "Flutter Mane"), .itemno = array_index(ITEMS, "Booster Energy") },
        { .monsno = array_index(SPECIES, "Slither Wing"), .itemno = array_index(ITEMS, "Booster Energy") },
        { .monsno = array_index(SPECIES, "Sandy Shocks"), .itemno = array_index(ITEMS, "Booster Energy") },
        { .monsno = array_index(SPECIES, "Roaring Moon"), .itemno = array_index(ITEMS, "Booster Energy") },
        { .monsno = array_index(SPECIES, "Iron Treads"), .itemno = array_index(ITEMS, "Booster Energy") },
        { .monsno = array_index(SPECIES, "Iron Bundle"), .itemno = array_index(ITEMS, "Booster Energy") },
        { .monsno = array_index(SPECIES, "Iron Hands"), .itemno = array_index(ITEMS, "Booster Energy") },
        { .monsno = array_index(SPECIES, "Iron Jugulis"), .itemno = array_index(ITEMS, "Booster Energy") },
        { .monsno = array_index(SPECIES, "Iron Moth"), .itemno = array_index(ITEMS, "Booster Energy") },
        { .monsno = array_index(SPECIES, "Iron Thorns"), .itemno = array_index(ITEMS, "Booster Energy") },
        { .monsno = array_index(SPECIES, "Iron Valiant"), .itemno = array_index(ITEMS, "Booster Energy") },
        { .monsno = array_index(SPECIES, "Walking Wake"), .itemno = array_index(ITEMS, "Booster Energy") },
        { .monsno = array_index(SPECIES, "Iron Leaves"), .itemno = array_index(ITEMS, "Booster Energy") },
    };
}