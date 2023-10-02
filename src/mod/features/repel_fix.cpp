#include "exlaunch.hpp"

#include "externals/Dpr/EvScript/EvDataManager.h"
#include "externals/ItemWork.h"
#include "externals/PlayerWork.h"

#include "logger/logger.h"

const int32_t REPEL_ITEM_ID = 79;
const int32_t SUPER_REPEL_ITEM_ID = 76;
const int32_t MAX_REPEL_ITEM_ID = 77;

const int32_t INFINITE_REPEL_FLAG = 2195;

// Dpr.EvScript.EvDataManager$$
HOOK_DEFINE_INLINE(RepelInventoryOverride){
    static void Callback(exl::hook::nx64::InlineCtx* ctx)
    {
        auto evDataManager = (Dpr::EvScript::EvDataManager::Object*)ctx->X[0];
        if (evDataManager->fields._eventListIndex == 0xFFFFFFFF)
        {
            auto label = (System::String::Object*)ctx->X[1];
            auto callback = (Dpr::EvScript::EvDataManager::EventEndDelegate::Object*)ctx->X[2];
            evDataManager->JumpLabel(label, callback);
        }
    }
};

HOOK_DEFINE_REPLACE(EncDataSave_CanUseSpray){
    static bool Callback(MethodInfo *method)
    {
        system_load_typeinfo(0x3f33);

        DPData::ENC_SV_DATA::Object encData = PlayerWork::get_Enc_SV_Data();
        bool repelRemaining = encData.fields.SprayCount > 0;
        bool infiniteRepelOn = PlayerWork::GetBool(INFINITE_REPEL_FLAG);
        return repelRemaining || infiniteRepelOn;

    }
};

HOOK_DEFINE_TRAMPOLINE(IsUseSpray){
    static bool Callback(uint16_t *itemno, MethodInfo *method)
    {
        bool isRegularRepelInUse = Orig(itemno, method);
        bool infiniteRepelOn = PlayerWork::GetBool(INFINITE_REPEL_FLAG);
        return isRegularRepelInUse || infiniteRepelOn;
    }
};


void exl_repel_fix_main(){
    RepelInventoryOverride::InstallAtOffset(0x02c550b8);
    EncDataSave_CanUseSpray::InstallAtOffset(0x01f08ac0);
    IsUseSpray::InstallAtOffset(0x01aeb720);
}