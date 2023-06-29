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
    /*Logger::log("UseDualSlotIncense\n");
    Logger::log("Dpr::UI::UIBag_Displayclass144_TypeInfo: %08X\n", Dpr::UI::UIBag_Displayclass144_TypeInfo);
    Logger::log("BASE_FORMCHANGE_ONSELECTED_METHODINFO: %08X\n", BASE_FORMCHANGE_ONSELECTED_METHODINFO);
    // Base on Dpr.UI.UIBag$$UseFormChangeItem
    // TODO: Populate context menu
    // and route to onSelected method. Hope it properly handles inputs

    // Needs to be this disp class to match the System.Action I am copying
    Dpr::UI::UIBag_Displayclass144_o * dispClass144 = (Dpr::UI::UIBag_Displayclass144_o *) il2cpp_object_new(Dpr::UI::UIBag_Displayclass144_TypeInfo);
    // Copy over the UIBag object to this dispClass
    // Don't need to copy over the other fields because we don't use them in our custom function
    // Use sytem_array_init on this to ensure that there is no stone unturned
    dispClass144->fields.__4__this = sUIBag;
    il2cpp_object_init(&dispClass->fields, sUIBag);

    ContextMenuIDList* contextMenuID_List = (ContextMenuIDList *) il2cpp_object_new(ContextMenuIDList_TypeInfo);
    contextMenuID_List->ctor(ContextMenuIDList_ctor_MethodInfo);

    // Build the menu so that you have every option except what you have currently selected.
    int32_t work = PlayerWork::GetInt(DOUBLE_SLOT_WORK, nullptr);
    if (work != 0)
    {
        contextMenuID_List->Add(ContextMenuID::INCENSE_DISABLE, ContextMenuIDList_Add_MethodInfo);
    }

    for (int i = 1; i <= 5; i++)
    {
        bool flowerEnabled = PlayerWork::GetBool(DOUBLE_SLOT_FLAG + i - 1, nullptr);
        if (i == work || !flowerEnabled)
        {
            continue;
        }
        contextMenuID_List->Add((int32_t)ContextMenuID::INCENSE_DISABLE + i, ContextMenuIDList_Add_MethodInfo);
    }
    contextMenuID_List->Add((int32_t)ContextMenuID::INCENSE_DISABLE + 6, ContextMenuIDList_Add_MethodInfo);

    System_Action_ContextMenuID__o * onSelected = (System_Action_ContextMenuID__o *) il2cpp_object_new(System_Action_ContextMenuID_TypeInfo);
    onSelected->ctor(dispClass144, getFormChangeOnSelectedMethodInfo(), System_Action_ContextMenuID__o_ctor_MethodInfo);
    System_Action_o * onClosed = nullptr; // Don't need to do anything on close
    bool isNoDecideSe = false;
    bool isNoCancelSe = false;

    UnityEngine_Vector2_o pivot = (UnityEngine_Vector2_o) {
        .fields = {
            .x = 0.5,
            .y = 0.5,
        }
    };

    UnityEngine_Vector3_o pos = (UnityEngine_Vector3_o) {
        .fields = {
            .x = 1040.0,
            .y = 360.0,
            .z = 0.0
        }
    };

    System::Array<int32_t> * contextMenuIDs = contextMenuID_List->ToArray(ContextMenuIDList_ToArray_MethodInfo);

    // Open up our context menu we've spent so much time trying to make.
    sUIBag->OpenContextMenu(contextMenuIDs, onSelected, pivot, pos, onClosed, isNoDecideSe, isNoCancelSe, nullptr);
    System::String * SS_bag_368 = System::String::CreateString("SS_bag_368");
    sUIBag->fields.msgWindowController->OpenMsgWindow(0, SS_bag_368, false, true, nullptr, nullptr, nullptr);*/
}
