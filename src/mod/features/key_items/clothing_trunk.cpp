#include "exlaunch.hpp"

#include "externals/Dpr/EvScript/EvDataManager.h"
#include "externals/Dpr/UI/ShopBoutique.h"
#include "externals/Dpr/UI/ShopBoutiqueChange.h"
#include "externals/Dpr/UI/UIBag.h"
#include "externals/Dpr/UI/UIManager.h"
#include "externals/SmartPoint/AssetAssistant/SingletonMonoBehaviour.h"
#include "externals/UnityEngine/Events/UnityAction.h"

void UseClothingTrunk(int32_t itemId, bool fromBag, Dpr::UI::UIBag::__c__DisplayClass127_1::Object* bagDisplayClass)
{
    Dpr::EvScript::EvDataManager::Object* evDataManager = Dpr::EvScript::EvDataManager::get_Instanse();

    if (fromBag)
    {
        System::String::Object * labelName = System::String::Create("ev_keyitem_clothingtrunk_bag");
        evDataManager->JumpLabel(labelName, nullptr);
    }
    else
    {
        System::String::Object * labelName = System::String::Create("ev_keyitem_clothingtrunk");
        evDataManager->JumpLabel(labelName, nullptr);
    }
}
