#pragma once

#include "externals/XLSXContent/PokemonInfo.h"

// Returns the "default" catalog for a monsno + formno combo.
// "Default" here is male (female if female-only, genderless if genderless), non-shiny, non-egg.
XLSXContent::PokemonInfo::SheetCatalog::Object* GetDefaultCatalog(int32_t monsno, int32_t formno);