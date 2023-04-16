#include "exlaunch.hpp"
#include "data/items.h"
#include "data/utils.h"
#include "externals/Dpr/EvScript/EvDataManager.h"
#include "externals/FlagWork.h"
#include "logger/logger.h"
#include "externals/Dpr/UI/UIManager.h"
#include "externals/Dpr/UI/ShopBoutique.h"
#include "externals/SmartPoint/AssetAssistant/SingletonMonoBehaviour.h"
#include "externals/Dpr/UI/ShopBoutiqueChange.h"
#include "externals/Dpr/UI/UIBag.h"
#include "externals/Dpr/UI/UIMsgWindowController.h"

void clearSoundFlags() {
    FlagWork::SetFlag(FLAG_UNOVA_SOUNDS, false);
    FlagWork::SetFlag(FLAG_KALOS_SOUNDS, false);
    FlagWork::SetFlag(FLAG_ALOLA_SOUNDS, false);
    FlagWork::SetFlag(FLAG_GALAR_SOUNDS, false);
    FlagWork::SetFlag(FLAG_MYSTERY_BOX, false);
}

bool CustomItemBehavior(int32_t itemId, bool fromBag) {
    switch(itemId) {
        case array_index(ITEMS, "Clothing Trunk"): {
            system_load_typeinfo(0x4485);
            SmartPoint::AssetAssistant::SingletonMonoBehaviour::getClass()->initIfNeeded();
            auto manager = Dpr::UI::UIManager::instance();
            auto boutique = manager->CreateUIWindow(0x20, Dpr::UI::UIManager::Method$$CreateUIWindow_ShopBoutiqueChange_);
            boutique->fields.onClosed = nullptr;
            if (!fromBag) {
                boutique->fields._prevWindowId = -2;
            }
            boutique->cast<Dpr::UI::ShopBoutique>()->Open();
            break;
        }
        case array_index(ITEMS, "Unova Sounds"): {
            clearSoundFlags();
            if (FlagWork::GetFlag(FLAG_UNOVA_SOUNDS)) {
                // Message disabled
            } else {
                FlagWork::SetFlag(FLAG_UNOVA_SOUNDS, true);
                // Message enabled
            }
            break;
        }
        case array_index(ITEMS, "Kalos Sounds"): {
            clearSoundFlags();
            if (FlagWork::GetFlag(FLAG_KALOS_SOUNDS)) {
                // Message disabled
            } else {
                FlagWork::SetFlag(FLAG_KALOS_SOUNDS, true);
                // Message enabled
            }
            break;
        }
        case array_index(ITEMS, "Alola Sounds"): {
            clearSoundFlags();
            if (FlagWork::GetFlag(FLAG_ALOLA_SOUNDS)) {
                // Message disabled
            } else {
                FlagWork::SetFlag(FLAG_ALOLA_SOUNDS, true);
                // Message enabled
            }
            break;
        }
        case array_index(ITEMS, "Galar Sounds"): {
            clearSoundFlags();
            if (FlagWork::GetFlag(FLAG_GALAR_SOUNDS)) {
                // Message disabled
            } else {
                FlagWork::SetFlag(FLAG_GALAR_SOUNDS, true);
                // Message enabled
            }
            break;
        }
        case array_index(ITEMS, "Mystery Box"): {
            clearSoundFlags();
            if (FlagWork::GetFlag(FLAG_MYSTERY_BOX)) {
                // Message disabled
            } else {
                FlagWork::SetFlag(FLAG_MYSTERY_BOX, true);
                // Message enabled
            }
            break;
        }
        default: {
            return false;
        }
    }
    return true;
}

HOOK_DEFINE_TRAMPOLINE(BagUseKeyItem) {
        static void Callback(Dpr::UI::UIBag::__c__DisplayClass127_1::Object* __this) {
            int32_t id = __this->fields.CS___8__locals1->fields.item->get_Id();

            if (CustomItemBehavior(id, true)) {
                return;
            }

            Orig(__this);
        }
};

HOOK_DEFINE_TRAMPOLINE(ShortcutUseKeyItem) {
        static int Callback(Dpr::EvScript::EvDataManager::Object* __this) {
            Logger::log("ShortcutUseKeyItem: seq %d\n", __this->fields._itemSequence);

            if (__this->fields._itemSequence == 0) {
                auto arg = __this->fields._evArg->m_Items[1].fields;

                int item = arg.data;
                if (arg.argType != 1) {
                    if (arg.argType != 2) {
                        return Orig(__this);
                    }
                    item = FlagWork::GetWork(arg.data);
                } else {
                    item = (int)*((float*)&item);
                }

                __this->fields._itemSequence = 1;
                int itemId = item & 0xffff;

                Logger::log("ShortcutUseKeyItem: %s\n", ITEMS[itemId]);

                if (CustomItemBehavior(itemId, false)) {
                    __this->fields._itemSequence = -1;
                }
            }

            return Orig(__this);
        }
};

void exl_key_items_main() {
    BagUseKeyItem::InstallAtOffset(0x01bde370);
    ShortcutUseKeyItem::InstallAtOffset(0x02c9f750);
}
