#include "exlaunch.hpp"

#include "romdata/romdata.h"

HOOK_DEFINE_REPLACE(DecideFormNoFromHoldItem) {
    static bool Callback(int32_t monsno, uint32_t holdItemno, uint16_t *formno) {
        auto formHeldItems = GetFormHeldItemMons();
        auto defaultForms = GetFormHeldItemMonsDefault();
        bool affectedMon = false;

        for (auto i : formHeldItems)
        {
            if (monsno == std::get<0>(i))
            {
                affectedMon = true;

                // If the item is one that changes the mon's form, change the form.
                if (holdItemno == std::get<1>(i))
                {
                    *formno = std::get<2>(i);
                    return true;
                }
            }
        }

        // This mon's form is affected by held items, but it's not holding one of them.
        if (affectedMon)
        {
            // Default to 0, then check for default form.
            *formno = 0;
            for (auto i : defaultForms)
            {
                if (monsno == std::get<0>(i))
                {
                    *formno = std::get<1>(i);
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }
};

HOOK_DEFINE_REPLACE(CheckUnbreakablePokeItem) {
    static bool Callback(uint16_t monsno, uint16_t itemID) {
        auto unbreakableItems = GetUnbreakablePokeItems();

        for (auto i : unbreakableItems)
        {
            if (monsno == std::get<0>(i) && itemID == std::get<1>(i))
            {
                return true;
            }
        }
    }
};

void exl_form_change_held_items_main(){
    DecideFormNoFromHoldItem::InstallAtOffset(0x024aeb90);
    CheckUnbreakablePokeItem::InstallAtOffset(0x01d0d780);
};