#pragma once

#include "memory/vector.h"
#include "romdata/data/ColorSet.h"
#include "romdata/data/FormHeldItemMon.h"
#include "romdata/data/HoneyTreeEncounters.h"
#include "romdata/data/UnbreakablePokeItem.h"

// Returns the max level based on the given level cap index.
uint32_t GetLevelCapLevel(uint32_t index);

// Returns the index of the current level cap.
uint32_t GetLevelCapIndex();

// Returns the max level of the current level cap.
uint32_t GetMaxLevel();

// Returns the level cap index of the next cap based on the given level.
uint32_t GetLevelCapIndexOfLevel(uint32_t level);

// Returns the list of items that change a specific Pokémon's form when held.
RomData::FormHeldItemMon GetFormHeldItemMon(int32_t monsNo);

// Returns the list of held item that a can't be separated from a specific Pokémon.
RomData::UnbreakablePokeItem GetUnbreakablePokeItems(int32_t monsNo);

// Returns the honey tree Pokémon at the given zoneID and slot.
RomData::HoneyTreeSlot GetHoneyTreeSlot(int32_t zoneID, int32_t slot);

// Returns a predefined color set for color variations.
RomData::ColorSet GetColorSet(int32_t index);