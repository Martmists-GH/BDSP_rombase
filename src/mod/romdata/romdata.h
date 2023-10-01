#pragma once

#include "memory/vector.h"
#include "romdata/data/ColorSet.h"
#include "romdata/data/FormHeldItemMon.h"
#include "romdata/data/HoneyTreeEncounters.h"
#include "romdata/data/UnbreakablePokeItem.h"

// Returns the Max level based on the given level cap index.
uint32_t GetLevelCapData(uint32_t index);

// Returns the list of Pokémon affected by held item form changes.
nn::vector<RomData::FormHeldItemMon> GetFormHeldItemMons();

// Returns the list of default forms for Pokémon affected by held item form changes.
nn::vector<RomData::FormHeldItemMon> GetFormHeldItemMonsDefault();

// Returns the list of Pokémon and held item pairs that can't be separated.
nn::vector<RomData::UnbreakablePokeItem> GetUnbreakablePokeItems();

// Returns the honey tree Pokémon at the given zoneID and slot.
RomData::HoneyTreeSlot GetHoneyTreeSlot(int32_t zoneID, int32_t slot);

// Returns a predefined color set for color variations.
RomData::ColorSet GetColorSet(int32_t index);