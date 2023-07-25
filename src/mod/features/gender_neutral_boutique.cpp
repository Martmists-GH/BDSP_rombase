#include "exlaunch.hpp"
#include "externals/il2cpp-api.h"
#include "data/outfits.h"
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

    for (int32_t dressId = 0; dressId < OUTFIT_COUNT - 1; dressId++) {
        if (dressId == 1) {
            continue;
        }
        AddList_ShopBoutiqueItemItem_Param(itemParams, dressId); // Male Outfits
        AddList_ShopBoutiqueItemItem_Param(itemParams, dressId + 100); // Female Outfits
    }

    return 0; // Returning zero never hurt anyone right?
    }
};

void exl_gender_neutral_boutique_main(){
    Dpr_UI_ShopBoutiqueChange_SetupBoutiqueItemParams::InstallAtOffset(0x01d46b00);
};