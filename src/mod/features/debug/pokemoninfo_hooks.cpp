#include "exlaunch.hpp"

#include "externals/XLSXContent/PokemonInfo.h"

#include "logger/logger.h"

HOOK_DEFINE_TRAMPOLINE(PokemonInfo_Catalog_Checked) {
    static XLSXContent::PokemonInfo::SheetCatalog::Object* Callback(int32_t uniqueId) {
        Logger::log("Checking Catalog of %d\n", uniqueId);
        auto catalog = Orig(uniqueId);
        /*if (catalog != nullptr)
            Logger::log("Menu Scale is %f\n", catalog->fields.MenuScale);
        else
            Logger::log("No Menu Scale, catalog is null\n");*/
        return catalog;
    }
};

void exl_pokemoninfo_hooks_main() {
    PokemonInfo_Catalog_Checked::InstallAtOffset(0x02cccf40);
}
