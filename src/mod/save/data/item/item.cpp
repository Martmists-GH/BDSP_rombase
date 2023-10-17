#include "save/save.h"

static Dpr::Item::SaveItem::Array* cache_items;

static Dpr::Item::SaveItem::Array* tmp_items;

void loadItems(PlayerWork::Object* playerWork)
{
    auto saveItemCls = Dpr::Item::SaveItem_array_TypeInfo();

    // Create new array
    auto newItems = (Dpr::Item::SaveItem::Array*) system_array_new(saveItemCls, SaveItemCount);

    // Fill the new array with the custom save data
    memcpy(newItems->m_Items, getCustomSaveData()->items.items, sizeof(getCustomSaveData()->items.items));

    // Cache the data that is in the vanilla save
    auto& savedata = playerWork->fields._saveData.fields;
    cache_items = savedata.saveItem;

    // Set the data in PlayerWork to our custom save data
    savedata.saveItem = newItems;
}

void saveItems(PlayerWork::Object* playerWork)
{
    auto& savedata = playerWork->fields._saveData.fields;

    // Copy PlayerWork data to our Custom save data
    memcpy(getCustomSaveData()->items.items, savedata.saveItem->m_Items, sizeof(getCustomSaveData()->items.items));

    // Create a temp copy of the PlayerWork data
    tmp_items = savedata.saveItem;

    // Set PlayerWork to our cached data
    savedata.saveItem = cache_items;
}

void restoreItems(PlayerWork::Object* playerWork)
{
    auto& savedata = playerWork->fields._saveData.fields;

    // Restore PlayerWork to our temp copy
    savedata.saveItem = tmp_items;
}