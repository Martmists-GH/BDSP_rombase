#pragma once

// The function choosing which features to use.
void exl_features_main();


// Applies some basic ability changes.
void exl_ability_changes_main();

// Swaps the badges to the Platinum order.
void exl_badge_check_main();

// Adds support for new Poké Balls.
void exl_balls_main();

// Makes the battle menu scroll instead of the cursor.
void exl_battle_revolver_main();

// Adds support for new ev_script commands.
void exl_commands_main();

// Extends the Pokédex to 1010 Pokémon.
// Patches many checks for max Pokédex size.
void exl_dex_expansion_main();

// Rewrites the methods that deal with determining a zone's encounter slots.
// Defaults to changing slots how Luminescent does it.
void exl_encounter_slots_main();

// Adds functionality to the Exp. Share item.
void exl_exp_share_main();

// Reroutes IL2CPP logs to the ExLaunch logger.
void exl_il2cpp_log_main();

// Adds new key item functionality.
void exl_key_items_main();

// Adds the Level Cap functionality.
void exl_level_cap_main();

// Applies multiple small one-line patches.
void exl_patches_main();

// Adds support for two-button Pokétch.
void exl_poketch_main();

// Remaps the controls.
void exl_remap_main();

// Adds support for new settings.
void exl_settings_main();

// Adds support for Sigma Platinum-style Sound encounters.
void exl_sounds_main();

// Makes TMs infinite use.
void exl_tms_main();

// Reroutes Unity logs to the ExLaunch logger.
void exl_unity_log_main();

// Adds support for wild Pokémon of any form number.
void exl_wild_forms_main();

// Rewrites the method that sets a wild Pokémon's held item to use consistent rates (50% / 5% / 45%).
// Also adds "Frisk" as an ability that raises wild Pokémon's held item rate.
void exl_wild_held_items_main();