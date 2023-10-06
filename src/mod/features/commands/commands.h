#pragma once

#include "externals/Dpr/EvScript/EvDataManager.h"

// Sets the weather.
// Arguments:
//   [Work, Number] weather: The ID of the weather to change to.
bool SetWeather(Dpr::EvScript::EvDataManager::Object* manager);

// Plays the starter selection scene.
// Arguments:
//   None.
bool FirstPokeSelectProc(Dpr::EvScript::EvDataManager::Object* manager);

// Sets the data for the current honey tree encounter.
// Arguments:
//   None.
bool HoneyTreeBattleSet(Dpr::EvScript::EvDataManager::Object* manager);

// Stops a Field Effect.
// Arguments:
//   [Work, Number] index: The index of the field effect to stop. 0-10
//   [Work, Number] isForce: Unknown use.
//   [Work, Number] fadeTime: The time in seconds it takes for the effect to fade.
bool StopEffect(Dpr::EvScript::EvDataManager::Object* manager);

// Returns the form id of the Pokémon at the given index in the party.
// Arguments:
//   [Work, Number] index: The index that points to the given Pokémon.
//   [Work] result: The work in which to put the result in. -1 if the chosen Pokémon is null or an egg.
bool PartyFormNo(Dpr::EvScript::EvDataManager::Object* manager);

// Returns the form id of the Pokémon at the given index and tray index.
// Arguments:
//   [Work, Number] index: The index that points to the given Pokémon.
//   [Work, Number] trayIndex: The tray index in which to look for the given Pokémon.
//   [Work] result: The work in which to put the result in. -1 if the chosen Pokémon is null or an egg.
bool PartyBoxFormNo(Dpr::EvScript::EvDataManager::Object* manager);

// Returns the nature id of the Pokémon at the given index and tray index.
// Arguments:
//   [Work, Number] index: The index that points to the given Pokémon.
//   [Work, Number] trayIndex: The tray index in which to look for the given Pokémon.
//   [Work] result: The work in which to put the result in. -1 if the chosen Pokémon is null or an egg.
bool PartyBoxNature(Dpr::EvScript::EvDataManager::Object* manager);

// Releases the Pokémon at the given index and tray index.
// Arguments:
//   [Work, Number] index: The index that points to the given Pokémon.
//   [Work, Number] trayIndex: The tray index in which to look for the given Pokémon.
bool PartyBoxRelease(Dpr::EvScript::EvDataManager::Object* manager);

// Toggles a BoxCollider of the given name on the current map.
// Arguments:
//   [Label] label: The name of the BoxCollider to toggle.
bool ToggleCollisionBox(Dpr::EvScript::EvDataManager::Object* manager);

// Sets the given work to 69. Acts as a check for a proper installation.
// Arguments:
//   [Work] work: The work to set.
bool InstallCheck(Dpr::EvScript::EvDataManager::Object* manager);

// Sets the player's ColorVariation id.
// Arguments:
//   [Work, Number] variation: The ColorVariation id to set the player to.
bool SetPlayerColorIndex(Dpr::EvScript::EvDataManager::Object* manager);