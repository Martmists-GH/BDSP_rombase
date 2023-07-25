#include "exlaunch.hpp"
#include "externals/il2cpp-api.h"
#include "data/outfits.h"
#include "externals/Dpr/UI/ShopBoutiqueItemItem.h"
#include "externals/GameData/DataManager.h"
#include "logger/logger.h"

void AddList_ShopBoutiqueItemItem_Param(System::Collections::Generic::List$$ShopBoutiqueItemItem_Param::Object *itemParams, int32_t dressId) {

    Logger::log("Add list - Shop Boutique ItemItem Param\n");
    Dpr::UI::ShopBoutiqueItemItem::Param::Object * item = Dpr::UI::ShopBoutiqueItemItem::Param::newInstance();
    Logger::log("Created new instance..\n");

    item->fields.data = GameData::DataManager::GetBoutiqueShopData(dressId);
    Logger::log("Got dress ID.\n");
    item->fields.dressData = GameData::DataManager::GetCharacterDressData(dressId);
    Logger::log("Got dress data.\n");
    itemParams->Add(item);
    Logger::log("Added item.\n");

    }

HOOK_DEFINE_REPLACE(Dpr_UI_ShopBoutiqueChange_SetupBoutiqueItemParams) {
    static int32_t Callback(System::Collections::Generic::List$$ShopBoutiqueItemItem_Param::Object *itemParams) {

    system_load_typeinfo(0x7cbb);

    Logger::log("Setup Boutique Item Item Param\n");

    for (int32_t dressId = 0; dressId < OUTFIT_COUNT - 1; dressId++) {
        if (dressId == 1) {
            continue;
        }
        Logger::log("Adding dress ID to list: %D\n", dressId);
        AddList_ShopBoutiqueItemItem_Param(itemParams, dressId); // Male Outfits
        AddList_ShopBoutiqueItemItem_Param(itemParams, dressId + 100); // Female Outfits
    }

    return 0; // Returning zero never hurt anyone right?
    }
};

void exl_gender_neutral_boutique_main(){
    Dpr_UI_ShopBoutiqueChange_SetupBoutiqueItemParams::InstallAtOffset(0x01d46b00);
};