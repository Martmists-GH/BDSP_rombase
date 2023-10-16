#include "exlaunch.hpp"

#include "data/clip_names.h"
#include "data/utils.h"
#include "externals/BaseEntity.h"
#include "externals/DG/Tweening/DOVirtual.h"
#include "externals/DG/Tweening/TweenCallback.h"
#include "externals/Dpr/Demo/Demo_Gosanke.h"
#include "externals/Dpr/Message/MessageWordSetHelper.h"
#include "externals/Dpr/SubContents/Utils.h"
#include "externals/PlayerWork.h"
#include "externals/Pml/PokePara/InitialSpec.h"
#include "externals/UnityEngine/Transform.h"
#include "romdata/romdata.h"
#include "utils/utils.h"

#include "logger/logger.h"

HOOK_DEFINE_REPLACE(PlayerWork_get_defaultPokeNo) {
    static int32_t Callback() {
        int32_t starter = PlayerWork::get_playerStatus()->fields.defaultPokeType;
        return GetStarter(starter).monsNo;
    }
};

HOOK_DEFINE_REPLACE(PlayerWork_get_defaultPokeType) {
    static int32_t Callback() {
        return PlayerWork::get_playerStatus()->fields.defaultPokeType;
    }
};

HOOK_DEFINE_REPLACE(PlayerWork_get_rivalPokeNo) {
    static int32_t Callback() {
        int32_t rivalStarter = PlayerWork::get_rivalPokeType();
        return GetStarter(rivalStarter).monsNo;
    }
};

HOOK_DEFINE_REPLACE(PlayerWork_get_rivalPokeType) {
    static int32_t Callback() {
        int32_t starter = PlayerWork::get_defaultPokeType();

        switch (starter)
        {
            case 0:
                return 1;
            case 1:
                return 2;
            case 2:
                return 0;

            default:
                return 1;
        }
    }
};

HOOK_DEFINE_REPLACE(PlayerWork_get_supportPokeNo) {
    static int32_t Callback() {
        int32_t supportStarter = PlayerWork::get_supportPokeType();
        return GetStarter(supportStarter).monsNo;
    }
};

HOOK_DEFINE_REPLACE(PlayerWork_get_supportPokeType) {
    static int32_t Callback() {
        int32_t starter = PlayerWork::get_defaultPokeType();

        switch (starter)
        {
            case 0:
                return 2;
            case 1:
                return 0;
            case 2:
                return 1;

            default:
                return 2;
        }
    }
};

HOOK_DEFINE_REPLACE(Demo_Starters_SelectPoke) {
    static void Callback(Dpr::Demo::Demo_Gosanke::Object* __this) {
        system_load_typeinfo(0x378b);

        int32_t cursor = __this->fields.nowCursolPosIndex;
        RomData::Starter starter = GetStarter(cursor);

        Dpr::SubContents::Utils::getClass()->initIfNeeded();
        Dpr::SubContents::Utils::PlayVoice(starter.monsNo, starter.formNo, 0, nullptr);
    }
};

HOOK_DEFINE_INLINE(Demo_Starters_SelectPoke_1) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        ctx->X[19] = ctx->X[0];
        ctx->X[21] = ctx->X[0];
    }
};

HOOK_DEFINE_INLINE(Demo_Starters_SelectPoke_2) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        auto __this = (Dpr::Demo::Demo_Gosanke::Object*)ctx->X[21];
        ctx->W[0] = GetStarter(__this->fields.nowCursolPosIndex).monsNo;
    }
};

HOOK_DEFINE_INLINE(Demo_Starters_Enter_Starter_0) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        auto spec = (Pml::PokePara::InitialSpec::Object*)ctx->X[23];

        RomData::Starter starter = GetStarter(0);
        ctx->W[8] = (uint32_t)starter.monsNo; // MonsNo is set on the next instruction
        spec->fields.formno = starter.formNo;
    }
};

HOOK_DEFINE_INLINE(Demo_Starters_Enter_Starter_1) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        auto spec = (Pml::PokePara::InitialSpec::Object*)ctx->X[23];

        RomData::Starter starter = GetStarter(1);
        ctx->W[8] = (uint32_t)starter.monsNo; // MonsNo is set on the next instruction
        spec->fields.formno = starter.formNo;
    }
};

HOOK_DEFINE_INLINE(Demo_Starters_Enter_Starter_2) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        auto spec = (Pml::PokePara::InitialSpec::Object*)ctx->X[23];

        RomData::Starter starter = GetStarter(2);
        ctx->W[8] = (uint32_t)starter.monsNo; // MonsNo is set on the next instruction
        spec->fields.formno = starter.formNo;
    }
};

HOOK_DEFINE_TRAMPOLINE(Demo_Starters_ShowPokeView) {
    static void* Callback(Dpr::Demo::Demo_Gosanke::Object* __this, int32_t cursolIndex) {
        auto renderCamera = __this->fields.RenderCamera;

        RomData::Starter starter = GetStarter(cursolIndex);
        auto catalog = GetDefaultCatalog(starter.monsNo, starter.formNo);
        UnityEngine::Vector3::Object pos = catalog->fields.DistributionModelOffset;
        UnityEngine::Vector3::Object rot = catalog->fields.DistributionModelRotationAngle;
        float scale = catalog->fields.DistributionScale;

        pos.fields.y -= 0.35f;
        rot.fields.y += 180.0f;

        auto cameraTransform = ((UnityEngine::Component::Object*)renderCamera)->get_transform();
        auto cubeTransform = cameraTransform->Find(System::String::Create("Cube"));

        cubeTransform->set_localPosition(pos);
        cubeTransform->set_localEulerAngles(rot);
        cubeTransform->set_localScale({ .fields = { .x = scale, .y = scale, .z = scale, }});

        return Orig(__this, cursolIndex); // Returns DG_Tweening_Tweener_o*
    }
};

HOOK_DEFINE_INLINE(PokeRenderViewer_ShowPokeView) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        auto transform = *((UnityEngine::Transform::Object**)ctx->X[21]);
        auto baseEntity = *((BaseEntity::Object**)ctx->X[23]);
        UnityEngine::Transform::Object* entityTransform = baseEntity->get_transform();

        UnityEngine::Vector3::Object pos = transform->get_localPosition();
        entityTransform->set_localPosition(pos);

        UnityEngine::Vector3::Object rot = transform->get_localEulerAngles();
        entityTransform->set_localEulerAngles(rot);

        UnityEngine::Vector3::Object scale = transform->get_localScale();
        entityTransform->set_localScale(scale);
    }
};

HOOK_DEFINE_INLINE(Demo_Gosanke_PokeConfirm_Cry) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        auto callback = (DG::Tweening::TweenCallback::Object*)ctx->X[0];
        bool ignoreTimeScale = (bool)ctx->W[1];

        int32_t starterId = PlayerWork::get_defaultPokeType();
        RomData::Starter starter = GetStarter(starterId);
        Dpr::SubContents::Utils::getClass()->initIfNeeded();
        Dpr::SubContents::Utils::PlayVoice(starter.monsNo, starter.formNo, 0, nullptr);

        DG::Tweening::DOVirtual::DelayedCall(1.6f, callback, ignoreTimeScale);
    }
};

HOOK_DEFINE_INLINE(DemoBase_DrawMessage_SetMonTags) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        auto __this = (Dpr::Demo::DemoBase::Object*)ctx->X[0];
        auto NextMessageNo = (int32_t)ctx->W[1];

        int32_t starterId = NextMessageNo - 2;
        RomData::Starter starter = GetStarter(starterId);

        Dpr::Message::MessageWordSetHelper::SetGlossaryWord(0, System::String::Create("ss_zkn_type"), starter.monsNo);
        Dpr::Message::MessageWordSetHelper::SetMonsNameWord(1, starter.monsNo);

        __this->DrawMessage(2); // Always do the generalized Turtwig message
    }
};

void exl_alt_starters_main() {
    PlayerWork_get_defaultPokeNo::InstallAtOffset(0x02cf13d0);
    PlayerWork_get_defaultPokeType::InstallAtOffset(0x02cf1320);
    PlayerWork_get_rivalPokeNo::InstallAtOffset(0x02cf1750);
    PlayerWork_get_rivalPokeType::InstallAtOffset(0x02cf1590);
    PlayerWork_get_supportPokeNo::InstallAtOffset(0x02cf19c0);
    PlayerWork_get_supportPokeType::InstallAtOffset(0x02cf1910);

    Demo_Starters_SelectPoke::InstallAtOffset(0x01ad0560);

    Demo_Starters_Enter_Starter_0::InstallAtOffset(0x01ad0bf8);
    Demo_Starters_Enter_Starter_1::InstallAtOffset(0x01ad0c28);
    Demo_Starters_Enter_Starter_2::InstallAtOffset(0x01ad0c5c);

    Demo_Starters_ShowPokeView::InstallAtOffset(0x01ad0210);
    PokeRenderViewer_ShowPokeView::InstallAtOffset(0x01997dcc);

    Demo_Gosanke_PokeConfirm_Cry::InstallAtOffset(0x01ad1800);

    DemoBase_DrawMessage_SetMonTags::InstallAtOffset(0x01ad1548);

    int32_t idleAnim1 = array_index(FIELD_MON_CLIPS, "Idle");         // Starter idle anim, Priority 1
    int32_t idleAnim2 = array_index(FIELD_MON_CLIPS, "Kw_Wait");      // Starter idle anim, Priority 2
    int32_t idleAnim3 = array_index(FIELD_MON_CLIPS, "FieldWait1");   // Starter idle anim, Priority 3
    int32_t confirmAnim = array_index(FIELD_MON_CLIPS, "Roar01");     // Starter selection anim

    using namespace exl::armv8::inst;
    using namespace exl::armv8::reg;
    exl::patch::CodePatcher p(0);
    auto inst = nn::vector<exl::patch::Instruction> {
        { 0x01ad1780, Movz(W0, 0) }, // Starter 0 value to save
        { 0x01ad1650, Movz(W0, 1) }, // Starter 1 value to save
        { 0x01ad1798, Movz(W0, 2) }, // Starter 2 value to save

        { 0x01997dd0, Branch(0x4c) }, // PokeRenderViewer_ShowPokeView skip some re-written code

        { 0x0199899c, CmpImmediate(W9, idleAnim1) },                         // Change animation on starter idle (Priority 1)
        { 0x019989ec, Movz(W1, idleAnim1) },                                 // Change animation on starter idle (Priority 1)
        { 0x019989a8, LdrRegisterImmediate(X20, X8, idleAnim1 + 0x4) },  // Change animation on starter idle (Priority 1)
        { 0x019989fc, CmpImmediate(W9, idleAnim2) },                         // Change animation on starter idle (Priority 2)
        { 0x01998a4c, Movz(W1, idleAnim2) },                                 // Change animation on starter idle (Priority 2)
        { 0x01998a08, LdrRegisterImmediate(X20, X8, idleAnim2 + 0x4) },  // Change animation on starter idle (Priority 2)
        { 0x01998a8c, CmpImmediate(W9, idleAnim3) },                         // Change animation on starter idle (Priority 3)
        { 0x01998ad4, Movz(W1, idleAnim3) },                                 // Change animation on starter idle (Priority 3)
        { 0x01998a98, LdrRegisterImmediate(X20, X8, idleAnim3 + 0x4) },  // Change animation on starter idle (Priority 3)

        { 0x01ad17a8, Movz(W9, confirmAnim) }, // Change animation on starter selection
    };
    p.WriteInst(inst);
}
