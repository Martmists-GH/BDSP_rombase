#include "exlaunch.hpp"

#include "externals/ContextMenuID.h"
#include "externals/Dpr/EvScript/EvDataManager.h"
#include "externals/Dpr/UI/ShopBoutique.h"
#include "externals/Dpr/UI/ShopBoutiqueChange.h"
#include "externals/Dpr/UI/UIBag.h"
#include "externals/Dpr/UI/UIManager.h"
#include "externals/SmartPoint/AssetAssistant/SingletonMonoBehaviour.h"

#include "logger/logger.h"

void UseIncenseBurner(int32_t itemId, bool fromBag, Dpr::UI::UIBag::__c__DisplayClass127_1::Object* bagDisplayClass)
{
    Dpr::EvScript::EvDataManager::Object* evDataManager = Dpr::EvScript::EvDataManager::get_Instanse();

    if (fromBag)
    {
        // TODO: Porting the Starlight coede... oh boy
    }
    else
    {
        System::String::Object * labelName = System::String::Create("ev_keyitem_incenseburner");
        evDataManager->JumpLabel(labelName, nullptr);
    }
}
