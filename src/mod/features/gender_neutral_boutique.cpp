#include "exlaunch.hpp"
#include "externals/il2cpp-api.h"

#include "data/outfits.h"
#include "data/utils.h"
#include "externals/Dpr/UI/ShopBoutiqueItemItem.h"
#include "externals/GameData/DataManager.h"

void AddList_ShopBoutiqueItemItem_Param(System::Collections::Generic::List$$ShopBoutiqueItemItem_Param::Object *itemParams, int32_t dressId) {
    Dpr::UI::ShopBoutiqueItemItem::Param::Object * item = Dpr::UI::ShopBoutiqueItemItem::Param::newInstance();

    item->fields.data = GameData::DataManager::GetBoutiqueShopData(dressId);
    item->fields.dressData = GameData::DataManager::GetCharacterDressData(dressId);
    itemParams->Add(item);
}

HOOK_DEFINE_REPLACE(Dpr_UI_ShopBoutiqueChange_SetupBoutiqueItemParams) {
    static int32_t Callback(System::Collections::Generic::List$$ShopBoutiqueItemItem_Param::Object *itemParams) {
        system_load_typeinfo(0x7cbb);

        for (int32_t dressId = 0; dressId < OUTFIT_COUNT; dressId++) {
            if (dressId == array_index(OUTFITS, "Contest Style")) {
                // Don't add Contest Style just yet, missing animations
                continue;
            }

            if (dressId == array_index(OUTFITS, "Everyday Style - Bike Outfit")) {
                // Don't add bike outfit
                continue;
            }

            if (dressId == array_index(OUTFITS, "New Cyber Style")) {
                // Only add feminine new cyber style
                AddList_ShopBoutiqueItemItem_Param(itemParams, (dressId) + 100); // Feminine Outfits
                continue;
            }

            AddList_ShopBoutiqueItemItem_Param(itemParams, (dressId)); // Masculine Outfits
            AddList_ShopBoutiqueItemItem_Param(itemParams, (dressId) + 100); // Feminine Outfits
        }

        return 0; // Returning zero never hurt anyone right?
    }
};

void exl_gender_neutral_boutique_main() {
    Dpr_UI_ShopBoutiqueChange_SetupBoutiqueItemParams::InstallAtOffset(0x01d46b00);

    // Remove bike outfit override for battles on cycling road
    using namespace exl::armv8::inst;
    using namespace exl::armv8::reg;
    exl::patch::CodePatcher p(0x0202f120);
    p.WriteInst(Movz(X0, 0));
};