#include <vector>

#include "exlaunch.hpp"

#include "data/items.h"
#include "data/species.h"
#include "data/utils.h"
#include "externals/DPData/Form_Enums.h"

std::vector<std::tuple<int32_t, uint32_t, uint16_t>> GetFormHeldItemMons()
{
    return {
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Mewtwo"), array_index(ITEMS, "Mewtwo Armor"), (uint16_t)MewtwoForm::ARMORED_MK2),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Mewtwo"), array_index(ITEMS, "Old Mewtwo Armor"), (uint16_t)MewtwoForm::ARMORED_MK1),

        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Giratina"), array_index(ITEMS, "Griseous Orb"), (uint16_t)GiratinaForm::ORIGIN),

        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Fist Plate"), (uint16_t)ArceusForm::FIGHTING),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Sky Plate"), (uint16_t)ArceusForm::FLYING),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Toxic Plate"), (uint16_t)ArceusForm::POISON),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Earth Plate"), (uint16_t)ArceusForm::GROUND),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Stone Plate"), (uint16_t)ArceusForm::ROCK),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Insect Plate"), (uint16_t)ArceusForm::BUG),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Spooky Plate"), (uint16_t)ArceusForm::GHOST),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Iron Plate"), (uint16_t)ArceusForm::STEEL),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Flame Plate"), (uint16_t)ArceusForm::FIRE),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Splash Plate"), (uint16_t)ArceusForm::WATER),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Meadow Plate"), (uint16_t)ArceusForm::GRASS),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Zap Plate"), (uint16_t)ArceusForm::ELECTRIC),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Mind Plate"), (uint16_t)ArceusForm::PSYCHIC),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Icicle Plate"), (uint16_t)ArceusForm::ICE),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Draco Plate"), (uint16_t)ArceusForm::DRAGON),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Dread Plate"), (uint16_t)ArceusForm::DARK),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Pixie Plate"), (uint16_t)ArceusForm::FAIRY),

        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Fightinium Z (Held)"), (uint16_t)ArceusForm::FIGHTING),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Flyinium Z (Held)"), (uint16_t)ArceusForm::FLYING),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Poisonium Z (Held)"), (uint16_t)ArceusForm::POISON),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Groundium Z (Held)"), (uint16_t)ArceusForm::GROUND),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Rockium Z (Held)"), (uint16_t)ArceusForm::ROCK),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Buginium Z (Held)"), (uint16_t)ArceusForm::BUG),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Ghostium Z (Held)"), (uint16_t)ArceusForm::GHOST),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Steelium Z (Held)"), (uint16_t)ArceusForm::STEEL),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Firium Z (Held)"), (uint16_t)ArceusForm::FIRE),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Waterium Z (Held)"), (uint16_t)ArceusForm::WATER),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Grassium Z (Held)"), (uint16_t)ArceusForm::GRASS),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Electrium Z (Held)"), (uint16_t)ArceusForm::ELECTRIC),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Psychium Z (Held)"), (uint16_t)ArceusForm::PSYCHIC),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Icium Z (Held)"), (uint16_t)ArceusForm::ICE),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Dragonium Z (Held)"), (uint16_t)ArceusForm::DRAGON),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Darkinium Z (Held)"), (uint16_t)ArceusForm::DARK),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Fairium Z (Held)"), (uint16_t)ArceusForm::FAIRY),

        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Genesect"), array_index(ITEMS, "Douse Drive"), (uint16_t)GenesectForm::DOUSE_DRIVE),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Genesect"), array_index(ITEMS, "Shock Drive"), (uint16_t)GenesectForm::SHOCK_DRIVE),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Genesect"), array_index(ITEMS, "Burn Drive"), (uint16_t)GenesectForm::BURN_DRIVE),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Genesect"), array_index(ITEMS, "Chill Drive"), (uint16_t)GenesectForm::CHILL_DRIVE),

        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Fighting Memory"), (uint16_t)SilvallyForm::FIGHTING),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Flying Memory"), (uint16_t)SilvallyForm::FLYING),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Poison Memory"), (uint16_t)SilvallyForm::POISON),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Ground Memory"), (uint16_t)SilvallyForm::GROUND),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Rock Memory"), (uint16_t)SilvallyForm::ROCK),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Bug Memory"), (uint16_t)SilvallyForm::BUG),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Ghost Memory"), (uint16_t)SilvallyForm::GHOST),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Steel Memory"), (uint16_t)SilvallyForm::STEEL),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Fire Memory"), (uint16_t)SilvallyForm::FIRE),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Water Memory"), (uint16_t)SilvallyForm::WATER),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Grass Memory"), (uint16_t)SilvallyForm::GRASS),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Electric Memory"), (uint16_t)SilvallyForm::ELECTRIC),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Psychic Memory"), (uint16_t)SilvallyForm::PSYCHIC),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Ice Memory"), (uint16_t)SilvallyForm::ICE),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Dragon Memory"), (uint16_t)SilvallyForm::DRAGON),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Dark Memory"), (uint16_t)SilvallyForm::DARK),
        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Fairy Memory"), (uint16_t)SilvallyForm::FAIRY),

        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Zacian"), array_index(ITEMS, "Rusted Sword"), (uint16_t)ZacianForm::CROWNED_SWORD),

        std::make_tuple<int32_t, uint32_t, uint16_t>(array_index(SPECIES, "Zamazenta"), array_index(ITEMS, "Rusted Shield"), (uint16_t)ZamazentaForm::CROWNED_SHIELD),
    };
}

std::vector<std::tuple<int32_t, uint16_t>> GetFormHeldItemMonsDefault()
{
    return {
        std::make_tuple<int32_t, uint16_t>(array_index(SPECIES, "Mewtwo"), (uint16_t)MewtwoForm::REGULAR),
        std::make_tuple<int32_t, uint16_t>(array_index(SPECIES, "Giratina"), (uint16_t)GiratinaForm::ALTERED),
        std::make_tuple<int32_t, uint16_t>(array_index(SPECIES, "Arceus"), (uint16_t)ArceusForm::NORMAL),
        std::make_tuple<int32_t, uint16_t>(array_index(SPECIES, "Genesect"), (uint16_t)GenesectForm::REGULAR),
        std::make_tuple<int32_t, uint16_t>(array_index(SPECIES, "Silvally"), (uint16_t)SilvallyForm::NORMAL),
        std::make_tuple<int32_t, uint16_t>(array_index(SPECIES, "Zacian"), (uint16_t)ZacianForm::HERO_OF_MANY_BATTLES),
        std::make_tuple<int32_t, uint16_t>(array_index(SPECIES, "Zamazenta"), (uint16_t)ZamazentaForm::HERO_OF_MANY_BATTLES),
    };
}

std::vector<std::tuple<uint16_t, uint16_t>> GetUnbreakablePokeItems()
{
    return {
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Mewtwo"), array_index(ITEMS, "Mewtwo Armor")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Mewtwo"), array_index(ITEMS, "Old Mewtwo Armor")),

        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Groudon"), array_index(ITEMS, "Red Orb")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Kyogre"), array_index(ITEMS, "Blue Orb")),

        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Giratina"), array_index(ITEMS, "Griseous Orb")),

        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Fist Plate")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Sky Plate")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Toxic Plate")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Earth Plate")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Stone Plate")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Insect Plate")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Spooky Plate")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Iron Plate")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Flame Plate")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Splash Plate")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Meadow Plate")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Zap Plate")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Mind Plate")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Icicle Plate")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Draco Plate")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Dread Plate")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Pixie Plate")),

        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Fightinium Z (Held)")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Flyinium Z (Held)")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Poisonium Z (Held)")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Groundium Z (Held)")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Rockium Z (Held)")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Buginium Z (Held)")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Ghostium Z (Held)")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Steelium Z (Held)")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Firium Z (Held)")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Waterium Z (Held)")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Grassium Z (Held)")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Electrium Z (Held)")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Psychium Z (Held)")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Icium Z (Held)")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Dragonium Z (Held)")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Darkinium Z (Held)")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Arceus"), array_index(ITEMS, "Fairium Z (Held)")),

        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Genesect"), array_index(ITEMS, "Douse Drive")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Genesect"), array_index(ITEMS, "Shock Drive")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Genesect"), array_index(ITEMS, "Burn Drive")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Genesect"), array_index(ITEMS, "Chill Drive")),

        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Fighting Memory")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Flying Memory")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Poison Memory")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Ground Memory")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Rock Memory")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Bug Memory")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Ghost Memory")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Steel Memory")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Fire Memory")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Water Memory")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Grass Memory")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Electric Memory")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Psychic Memory")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Ice Memory")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Dragon Memory")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Dark Memory")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Silvally"), array_index(ITEMS, "Fairy Memory")),

        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Zacian"), array_index(ITEMS, "Rusted Sword")),

        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Zamazenta"), array_index(ITEMS, "Rusted Shield")),

        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Great Tusk"), array_index(ITEMS, "Booster Energy")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Scream Tail"), array_index(ITEMS, "Booster Energy")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Brute Bonnet"), array_index(ITEMS, "Booster Energy")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Flutter Mane"), array_index(ITEMS, "Booster Energy")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Slither Wing"), array_index(ITEMS, "Booster Energy")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Sandy Shocks"), array_index(ITEMS, "Booster Energy")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Roaring Moon"), array_index(ITEMS, "Booster Energy")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Iron Treads"), array_index(ITEMS, "Booster Energy")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Iron Bundle"), array_index(ITEMS, "Booster Energy")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Iron Hands"), array_index(ITEMS, "Booster Energy")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Iron Jugulis"), array_index(ITEMS, "Booster Energy")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Iron Moth"), array_index(ITEMS, "Booster Energy")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Iron Thorns"), array_index(ITEMS, "Booster Energy")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Iron Valiant"), array_index(ITEMS, "Booster Energy")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Walking Wake"), array_index(ITEMS, "Booster Energy")),
        std::make_tuple<uint16_t, uint16_t>(array_index(SPECIES, "Iron Leaves"), array_index(ITEMS, "Booster Energy")),
    };
}