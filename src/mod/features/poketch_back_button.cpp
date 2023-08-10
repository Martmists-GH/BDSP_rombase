#include "exlaunch.hpp"

#include "externals/il2cpp-api.h"

#include "externals/Dpr/EvScript/EvDataManager.h"
#include "externals/Dpr/MsgWindow/MsgWindowManager.h"
#include "externals/Dpr/UI/PoketchAppBase.h"
#include "externals/Dpr/UI/PoketchButton.h"
#include "externals/Dpr/UI/PoketchWindow.h"
#include "externals/Dpr/UI/UIManager.h"
#include "externals/Dpr/UI/UIWindow.h"
#include "externals/FieldPoketch.h"
#include "externals/GameController.h"
#include "externals/PlayerWork.h"
#include "externals/System/ThrowHelper.h"
#include "externals/UnityEngine/Component.h"
#include "externals/UnityEngine/Input.h"
#include "externals/UnityEngine/Time.h"
#include "externals/UnityEngine/Touch.h"
#include "externals/UnityEngine/Transform.h"
#include "externals/UnityEngine/Vector2.h"

#include "logger/logger.h"

void goBackAction(Dpr::UI::PoketchWindow* __this) {
    __this->SelectApp(false);
}

HOOK_DEFINE_INLINE(IsInRange_Small) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        auto window = (Dpr::UI::PoketchWindow::Object*)ctx->X[19];
        auto forwardsButton = (Dpr::UI::PoketchButton::Object*)ctx->X[1];

        auto windowTransform = window->cast<UnityEngine::Component>()->get_transform();
        auto backwardsTransform = windowTransform->Find(System::String::Create("Window"))
                ->Find(System::String::Create("Poketch"))
                ->Find(System::String::Create("Body_02"))
                ->Find(System::String::Create("Mask"))
                ->Find(System::String::Create("Image_button2"));
        auto backwardsButton = backwardsTransform->GetComponent<Dpr::UI::PoketchButton>(window->fields._changeButton->klass);

        // Get float values from registers (not yet supported through ctx, see: https://github.com/shadowninja108/exlaunch/issues/1)
        float x, y;
        __asm(
            R"(
                mov %0.16B, v8.16B
                mov %1.16B, v9.16B
            )"
            : "=w"(x), "=w"(y)
        );

        if (backwardsButton != nullptr && window->IsInRange(backwardsButton, x, y))
        {
            backwardsButton->OnPush();
            ctx->X[0] = (uint64_t)false;
            return;
        }

        if (forwardsButton != nullptr)
        {
            ctx->X[0] = (uint64_t)window->IsInRange(forwardsButton, x, y);
            return;
        }
    }
};

HOOK_DEFINE_INLINE(IsInRange_Big) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        auto window = (Dpr::UI::PoketchWindow::Object*)ctx->X[19];
        auto buttonToCheck = (Dpr::UI::PoketchButton::Object*)ctx->X[1];

        auto windowTransform = window->cast<UnityEngine::Component>()->get_transform();
        auto backwardsTransform = windowTransform->Find(System::String::Create("Window"))
                ->Find(System::String::Create("Poketch"))
                ->Find(System::String::Create("Body_02"))
                ->Find(System::String::Create("Mask"))
                ->Find(System::String::Create("Image_button2"));
        auto backwardsButton = backwardsTransform->GetComponent<Dpr::UI::PoketchButton>(window->fields._changeButton->klass);

        // Get float values from registers (not yet supported through ctx, see: https://github.com/shadowninja108/exlaunch/issues/1)
        float x, y;
        __asm(
                R"(
                mov %0.16B, v8.16B
                mov %1.16B, v9.16B
            )"
                : "=w"(x), "=w"(y)
                );

        if (x != 0 && y != 0) Logger::log("Cursor is at x=%f y-%f\n", x, y);

        if (UnityEngine::_Object::op_Equality((UnityEngine::_Object::Object*)buttonToCheck, (UnityEngine::_Object::Object*)window->fields._changeButton))
        {
            if (backwardsButton != nullptr && window->IsInRange(backwardsButton, x, y))
            {
                Logger::log("Actually, this was the backwards button!\n");
                ctx->X[20] = (uint64_t)backwardsButton;
                ctx->W[0] = (uint64_t)true;
                return;
            }

            if (window->fields._changeButton != nullptr)
            {
                Logger::log("Forwards button!\n");
                ctx->W[0] = (uint64_t)window->IsInRange(window->fields._changeButton, x, y);
                return;
            }
        }

        ctx->W[0] = (uint64_t)window->IsInRange(buttonToCheck, x, y);
    }
};

HOOK_DEFINE_INLINE(ButtonInit) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        auto forwardsButton = (Dpr::UI::PoketchButton::Object*)ctx->X[0];
        auto forwardsAction = (UnityEngine::Events::UnityAction::Object*)ctx->X[1];
        auto forwardsSeEventId = (int32_t)ctx->W[2];

        forwardsButton->Initialize(forwardsAction, forwardsSeEventId);

        auto poketchWindow = (Dpr::UI::PoketchWindow::Object*)ctx->X[19];
        auto windowTransform = poketchWindow->cast<UnityEngine::Component>()->get_transform();
        auto mask = windowTransform->Find(System::String::Create("Window"))
                ->Find(System::String::Create("Poketch"))
                ->Find(System::String::Create("Body_02"))
                ->Find(System::String::Create("Mask"));

        auto backwardsButton = mask->Find(System::String::Create("Image_button2"))->GetComponent<Dpr::UI::PoketchButton>(poketchWindow->fields._changeButton->klass);
        ILMethod mi(forwardsAction->fields.method);
        auto backwardsAction = UnityEngine::Events::UnityAction::getClass(UnityEngine::Events::UnityAction::void_TypeInfo)->newInstance(poketchWindow, mi.copyWith((Il2CppMethodPointer) &goBackAction));

        backwardsButton->Initialize(backwardsAction, forwardsSeEventId);
    }
};

HOOK_DEFINE_TRAMPOLINE(OnRelease) {
    static void Callback(Dpr::UI::PoketchButton::Object* __this) {
        Logger::log("OnRelease: %08X\n", __this);
        Orig(__this);
    }
};

void joined_r0x007101e67668(Dpr::UI::PoketchWindow::Object* __this, float deltaTime) {
    int32_t currentApp = __this->fields._CurrentAppIndex_k__BackingField;
    if (__this->fields._poketchAppList->fields._size <= currentApp)
    {
        System::ThrowHelper::ThrowArgumentOutOfRangeException();
    }

    Dpr::UI::PoketchAppBase::Object* app = __this->fields._poketchAppList->fields._items->m_Items[currentApp];
    bool appNotNull = UnityEngine::_Object::op_Inequality((UnityEngine::_Object::Object*)app, nullptr);
    if (appNotNull)
    {
        app->OnUpdate(false, nullptr, (int32_t)Dpr::UI::PoketchWindow::TouchState::None);
    }
}

void joined_r0x007101e681a8(Dpr::UI::PoketchWindow::Object* __this, float deltaTime, Dpr::UI::PoketchButton::Object* target, Dpr::UI::PoketchWindow::TouchState touchState) {
    int32_t currentApp = __this->fields._CurrentAppIndex_k__BackingField;
    if (__this->fields._poketchAppList->fields._size <= currentApp)
    {
        System::ThrowHelper::ThrowArgumentOutOfRangeException();
    }

    Dpr::UI::PoketchAppBase::Object* app = __this->fields._poketchAppList->fields._items->m_Items[currentApp];
    bool appNotNull = UnityEngine::_Object::op_Inequality((UnityEngine::_Object::Object*)app, nullptr);
    if (appNotNull)
    {
        app->OnUpdate(false, target, (int32_t)touchState);
    }

    auto cursorTransform = __this->fields._cursor->cast<UnityEngine::Component>()->get_transform()->instance();
    UnityEngine::Vector3::Object cursorVector = cursorTransform->get_position();
    __this->fields._cursorX = cursorVector.fields.x;
    __this->fields._cursorY = cursorVector.fields.y;
    __this->fields._touchState = touchState;
}

HOOK_DEFINE_REPLACE(PoketchWindow_OnUpdate) {
    static void Callback(Dpr::UI::PoketchWindow::Object* __this, float deltaTime) {
        Logger::log("PoketchWindow_OnUpdate Start\n");
        system_load_typeinfo(0x6f3e);
        system_load_typeinfo(0x6f47);

        Dpr::UI::PoketchWindow::TouchState touchState;
        Dpr::UI::PoketchButton::Object * target;

        float voiceTimer = __this->fields._voiceTimer;
        if (0.0 < voiceTimer)
        {
            __this->fields._voiceTimer = voiceTimer - UnityEngine::Time::get_deltaTime();
        }

        FieldPoketch::getClass()->initIfNeeded();

        if (FieldPoketch::IsRejectPoketch())
        {
            __this->Close(__this->fields.onClosed);
            return;
        }

        if (FieldPoketch::IsCloseOncePoketch())
        {
            __this->Close(nullptr);
            return;
        }

        auto uiManager = Dpr::UI::UIManager::instance();
        auto currentWindow = (UnityEngine::_Object::Object *)uiManager->GetCurrentUIWindow<Dpr::UI::UIWindow>(Dpr::UI::UIManager::Method$$GetCurrentUIWindow_UIWindow_);
        bool isCurrentWindowPoketch = !UnityEngine::_Object::op_Inequality(currentWindow, (UnityEngine::_Object::Object *)__this);
        if (isCurrentWindowPoketch)
        {
            Dpr::EvScript::EvDataManager::getClass()->initIfNeeded();
            auto evManager = Dpr::EvScript::EvDataManager::get_Instanse();
            if (!evManager->IsRunningEvent() && !Dpr::MsgWindow::MsgWindowManager::get_IsOpenWindow())
            {
                if (__this->fields._isSizeChanging)
                {
                    return;
                }
                PlayerWork::getClass()->initIfNeeded();
                if (PlayerWork::get_isPlayerInputActive() && __this->fields._IsLarge_k__BackingField)
                {
                    __this->ChangePoketchSize(false, nullptr);
                    return;
                }

                __this->fields._buttonR->OnUpdate(deltaTime);
                __this->fields._buttonSR->OnUpdate(deltaTime);
                bool isPrevTouch = __this->fields._isTouch;
                UnityEngine::Vector2::Object touchVec2 = UnityEngine::Vector2::get_zero();
                if (UnityEngine::Input::get_touchCount() > 0)
                {
                    UnityEngine::Touch::Object __this_00 = UnityEngine::Input::GetTouch(0);
                    touchVec2 = __this_00.get_position();
                }

                UnityEngine::Vector2::Object zero = UnityEngine::Vector2::get_zero();
                bool isCurrentTouch = !UnityEngine::Vector2::op_Equality(touchVec2, zero);

                __this->fields._isTouch = isCurrentTouch;
                if (!__this->fields._IsLarge_k__BackingField && !__this->fields._IsPauseContinue_k__BackingField)
                {
                    if (!isPrevTouch & isCurrentTouch)
                    {
                        if (__this->IsInRange(__this->fields._changeButton, touchVec2.fields.x, touchVec2.fields.y))
                        {
                            __this->fields._changeButton->OnPush();
                        }
                    }
                    joined_r0x007101e67668(__this, deltaTime);
                    return;
                }

                GameController::getClass()->initIfNeeded();

                float cursorX = touchVec2.fields.x;
                float cursorY = touchVec2.fields.y;

                float changeX = 0.0;
                float changeY = 0.0;

                bool movingCursor = UnityEngine::Vector2::op_Inequality(GameController::getClass()->static_fields->analogStickL, UnityEngine::Vector2::get_zero());
                if (!movingCursor)
                {
                    if ((uiManager->klass->static_fields->StickLLeft & GameController::getClass()->static_fields->accel) != 0)
                    {
                        changeX = -__this->fields._cursolMoveValue;
                    }
                    else if ((uiManager->klass->static_fields->StickLRight & GameController::getClass()->static_fields->accel) != 0)
                    {
                        changeX = __this->fields._cursolMoveValue;
                    }
                    else
                    {
                        changeX = 0.0;
                    }

                    if ((uiManager->klass->static_fields->StickLUp & GameController::getClass()->static_fields->accel) != 0)
                    {
                        changeY = __this->fields._cursolMoveValue;
                    }
                    else if ((uiManager->klass->static_fields->StickLDown & GameController::getClass()->static_fields->accel) != 0)
                    {
                        changeY = -__this->fields._cursolMoveValue;
                    }
                    else
                    {
                        changeY = 0.0;
                    }
                }
                else
                {
                    float cursorMove = __this->fields._cursolMoveValue;
                    changeX = changeX * cursorMove;
                    changeY = changeY * cursorMove;
                }

                if (__this->fields._isTouch)
                {
                    __this->SetCursorPosition(cursorX, cursorY);
                }
                else
                {
                    if (changeX != 0.0 || changeY != 0.0)
                    {
                        UnityEngine::Transform::Object* cursorTransform = __this->fields._cursor->cast<UnityEngine::Component>()->get_transform()->instance();
                        UnityEngine::Vector3::Object cursorVec3 = cursorTransform->get_position();
                        cursorX = changeX + cursorVec3.fields.x;
                        cursorY = changeY + cursorVec3.fields.y;
                        __this->SetCursorPosition(cursorX, cursorY);
                    }
                }

                int32_t currentApp = __this->fields._CurrentAppIndex_k__BackingField;
                if (__this->fields._poketchAppList->fields._size <= currentApp)
                {
                    System::ThrowHelper::ThrowArgumentOutOfRangeException();
                }
                Dpr::UI::PoketchAppBase::Object* app = __this->fields._poketchAppList->fields._items->m_Items[currentApp];

                if (UnityEngine::_Object::op_Inequality((UnityEngine::_Object::Object*)app, nullptr))
                {
                    if (app->fields.Buttons != nullptr)
                    {
                        Dpr::UI::PoketchButton::Object* btn27 = nullptr;

                        for (uint64_t j=0; j<app->fields.Buttons->max_length+1; j++)
                        {
                            Dpr::UI::PoketchButton::Object** currentButtonPtr1 = &__this->fields._preButton;

                            Dpr::UI::PoketchButton::Object** currentButtonPtr11 = &__this->fields._changeButton;
                            if (j < app->fields.Buttons->max_length)
                            {
                                currentButtonPtr11 = &app->fields.Buttons->m_Items[j];
                            }
                            target = *currentButtonPtr11;

                            UnityEngine::Transform::Object* cursorTransform = __this->fields._cursor->cast<UnityEngine::Component>()->get_transform()->instance();
                            UnityEngine::Vector3::Object cursorVec3 = cursorTransform->get_position();
                            if (!__this->IsInRange(target, cursorVec3.fields.x, cursorVec3.fields.y))
                            {
                                if (UnityEngine::_Object::op_Equality((UnityEngine::_Object::Object*)target, (UnityEngine::_Object::Object*)*currentButtonPtr1))
                                {
                                    if (!__this->fields._isTouch)
                                    {
                                        if ((uiManager->klass->static_fields->ButtonA & GameController::getClass()->static_fields->on) == 0)
                                        {
                                            (*currentButtonPtr1)->SetRelease();
                                            *currentButtonPtr1 = nullptr;
                                            target = btn27;
                                            touchState = Dpr::UI::PoketchWindow::TouchState::Release;
                                            joined_r0x007101e681a8(__this, deltaTime, target, touchState);
                                            return;
                                        }
                                    }

                                    if (target->fields._canDrag)
                                    {
                                        if (UnityEngine::_Object::op_Inequality((UnityEngine::_Object::Object*)*currentButtonPtr1, nullptr))
                                        {
                                            if (cursorVec3.fields.x < __this->fields._cursorMaxX + 1.0)
                                            {
                                                UnityEngine::Transform::Object* targetTransform = target->cast<UnityEngine::Component>()->get_transform()->instance();

                                                UnityEngine::Vector3::Object newCursorVec = {};
                                                newCursorVec.ctor(cursorVec3.fields.x, cursorVec3.fields.y, 0.0);
                                                targetTransform->set_position(newCursorVec);

                                                touchState = Dpr::UI::PoketchWindow::TouchState::Hold;
                                                joined_r0x007101e681a8(__this, deltaTime, target, touchState);
                                                return;
                                            }
                                        }
                                    }

                                    (*currentButtonPtr1)->SetRelease();
                                    *currentButtonPtr1 = nullptr;
                                    touchState = Dpr::UI::PoketchWindow::TouchState::Release;
                                    target = btn27;
                                    joined_r0x007101e681a8(__this, deltaTime, target, touchState);
                                    return;
                                }

                                continue;
                            }

                            if (cursorX > __this->fields._cursorMaxX && cursorY < __this->fields._cursorMaxY - 16.0)
                            {
                                *currentButtonPtr1 = nullptr;

                                if ((uiManager->klass->static_fields->ButtonA & GameController::getClass()->static_fields->push) != 0)
                                {
                                    *currentButtonPtr1 = target;
                                    target->SetTouch();
                                    touchState = Dpr::UI::PoketchWindow::TouchState::Touch;
                                    joined_r0x007101e681a8(__this, deltaTime, target, touchState);
                                    return;
                                }

                                btn27 = target;
                                if ((uiManager->klass->static_fields->ButtonA & GameController::getClass()->static_fields->push) == 0)
                                {
                                    if ((uiManager->klass->static_fields->ButtonA & GameController::getClass()->static_fields->release) != 0)
                                    {
                                        btn27 = *currentButtonPtr1;
                                        if (!UnityEngine::_Object::op_Equality((UnityEngine::_Object::Object*)btn27, (UnityEngine::_Object::Object*)target))
                                        {
                                            touchState = Dpr::UI::PoketchWindow::TouchState::Release;
                                        }
                                        else
                                        {
                                            __this->fields._preButton = nullptr;
                                            target->SetRelease();
                                            if (__this->fields._isSizeChanging)
                                            {
                                                return;
                                            }
                                            target->OnPush();
                                            touchState = Dpr::UI::PoketchWindow::TouchState::Push;
                                        }
                                        joined_r0x007101e681a8(__this, deltaTime, target, touchState);
                                        return;
                                    }
                                }
                                else
                                {
                                    if (UnityEngine::_Object::op_Inequality((UnityEngine::_Object::Object*)target, nullptr))
                                    {
                                        if (UnityEngine::_Object::op_Equality((UnityEngine::_Object::Object*)*currentButtonPtr1, (UnityEngine::_Object::Object*)target))
                                        {
                                            if (target->fields._canDrag)
                                            {
                                                float clampedCursorX = __this->fields._cursorMaxX;
                                                if (clampedCursorX > cursorVec3.fields.x)
                                                {
                                                    clampedCursorX = cursorVec3.fields.x;
                                                }

                                                UnityEngine::Transform::Object* targetTransform = target->cast<UnityEngine::Component>()->get_transform()->instance();

                                                UnityEngine::Vector3::Object newCursorVec = {};
                                                newCursorVec.ctor(clampedCursorX, cursorVec3.fields.y, 0.0);
                                                targetTransform->set_position(newCursorVec);
                                            }
                                            touchState = Dpr::UI::PoketchWindow::TouchState::Hold;
                                            joined_r0x007101e681a8(__this, deltaTime, target, touchState);
                                            return;
                                        }
                                    }
                                }

                                continue;
                            }

                            if (!__this->fields._isTouch)
                            {
                                if (!isPrevTouch)
                                {
                                    if ((uiManager->klass->static_fields->ButtonA & GameController::getClass()->static_fields->push) != 0)
                                    {
                                        *currentButtonPtr1 = target;
                                        target->SetTouch();
                                        touchState = Dpr::UI::PoketchWindow::TouchState::Touch;
                                        joined_r0x007101e681a8(__this, deltaTime, target, touchState);
                                        return;
                                    }

                                    btn27 = target;
                                    if ((uiManager->klass->static_fields->ButtonA & GameController::getClass()->static_fields->push) == 0)
                                    {
                                        if ((uiManager->klass->static_fields->ButtonA & GameController::getClass()->static_fields->release) != 0)
                                        {
                                            btn27 = *currentButtonPtr1;
                                            if (!UnityEngine::_Object::op_Equality((UnityEngine::_Object::Object*)btn27, (UnityEngine::_Object::Object*)target))
                                            {
                                                touchState = Dpr::UI::PoketchWindow::TouchState::Release;
                                            }
                                            else
                                            {
                                                __this->fields._preButton = nullptr;
                                                target->SetRelease();
                                                if (__this->fields._isSizeChanging)
                                                {
                                                    return;
                                                }
                                                target->OnPush();
                                                touchState = Dpr::UI::PoketchWindow::TouchState::Push;
                                            }
                                            joined_r0x007101e681a8(__this, deltaTime, target, touchState);
                                            return;
                                        }
                                    }
                                    else
                                    {
                                        if (UnityEngine::_Object::op_Inequality((UnityEngine::_Object::Object*)target, nullptr))
                                        {
                                            if (UnityEngine::_Object::op_Equality((UnityEngine::_Object::Object*)*currentButtonPtr1, (UnityEngine::_Object::Object*)target))
                                            {
                                                if (target->fields._canDrag)
                                                {
                                                    float clampedCursorX = __this->fields._cursorMaxX;
                                                    if (clampedCursorX > cursorVec3.fields.x)
                                                    {
                                                        clampedCursorX = cursorVec3.fields.x;
                                                    }

                                                    UnityEngine::Transform::Object* targetTransform = target->cast<UnityEngine::Component>()->get_transform()->instance();

                                                    UnityEngine::Vector3::Object newCursorVec = {};
                                                    newCursorVec.ctor(clampedCursorX, cursorVec3.fields.y, 0.0);
                                                    targetTransform->set_position(newCursorVec);
                                                }
                                                touchState = Dpr::UI::PoketchWindow::TouchState::Hold;
                                                joined_r0x007101e681a8(__this, deltaTime, target, touchState);
                                                return;
                                            }
                                        }
                                    }

                                    continue;
                                }

                                btn27 = *currentButtonPtr1;
                                if (!UnityEngine::_Object::op_Equality((UnityEngine::_Object::Object*)btn27, (UnityEngine::_Object::Object*)target))
                                {
                                    touchState = Dpr::UI::PoketchWindow::TouchState::Release;
                                }
                                else
                                {
                                    __this->fields._preButton = nullptr;
                                    target->SetRelease();
                                    if (__this->fields._isSizeChanging)
                                    {
                                        return;
                                    }
                                    target->OnPush();
                                    touchState = Dpr::UI::PoketchWindow::TouchState::Push;
                                }
                                joined_r0x007101e681a8(__this, deltaTime, target, touchState);
                                return;
                            }

                            if (!isPrevTouch)
                            {
                                *currentButtonPtr1 = target;
                                target->SetTouch();
                                touchState = Dpr::UI::PoketchWindow::TouchState::Touch;
                                joined_r0x007101e681a8(__this, deltaTime, target, touchState);
                                return;
                            }

                            btn27 = *currentButtonPtr1;
                            if (!UnityEngine::_Object::op_Equality((UnityEngine::_Object::Object*)btn27, (UnityEngine::_Object::Object*)target))
                            {
                                if ((uiManager->klass->static_fields->ButtonA & GameController::getClass()->static_fields->push) != 0)
                                {
                                    *currentButtonPtr1 = target;
                                    target->SetTouch();
                                    touchState = Dpr::UI::PoketchWindow::TouchState::Touch;
                                    joined_r0x007101e681a8(__this, deltaTime, target, touchState);
                                    return;
                                }

                                btn27 = target;
                                if ((uiManager->klass->static_fields->ButtonA & GameController::getClass()->static_fields->push) == 0)
                                {
                                    if ((uiManager->klass->static_fields->ButtonA & GameController::getClass()->static_fields->release) != 0)
                                    {
                                        btn27 = *currentButtonPtr1;
                                        if (!UnityEngine::_Object::op_Equality((UnityEngine::_Object::Object*)btn27, (UnityEngine::_Object::Object*)target))
                                        {
                                            touchState = Dpr::UI::PoketchWindow::TouchState::Release;
                                        }
                                        else
                                        {
                                            __this->fields._preButton = nullptr;
                                            target->SetRelease();
                                            if (__this->fields._isSizeChanging)
                                            {
                                                return;
                                            }
                                            target->OnPush();
                                            touchState = Dpr::UI::PoketchWindow::TouchState::Push;
                                        }
                                        joined_r0x007101e681a8(__this, deltaTime, target, touchState);
                                        return;
                                    }
                                }
                                else
                                {
                                    if (UnityEngine::_Object::op_Inequality((UnityEngine::_Object::Object*)target, nullptr))
                                    {
                                        if (UnityEngine::_Object::op_Equality((UnityEngine::_Object::Object*)*currentButtonPtr1, (UnityEngine::_Object::Object*)target))
                                        {
                                            if (target->fields._canDrag)
                                            {
                                                float clampedCursorX = __this->fields._cursorMaxX;
                                                if (clampedCursorX > cursorVec3.fields.x)
                                                {
                                                    clampedCursorX = cursorVec3.fields.x;
                                                }

                                                UnityEngine::Transform::Object* targetTransform = target->cast<UnityEngine::Component>()->get_transform()->instance();

                                                UnityEngine::Vector3::Object newCursorVec = {};
                                                newCursorVec.ctor(clampedCursorX, cursorVec3.fields.y, 0.0);
                                                targetTransform->set_position(newCursorVec);
                                            }
                                            touchState = Dpr::UI::PoketchWindow::TouchState::Hold;
                                            joined_r0x007101e681a8(__this, deltaTime, target, touchState);
                                            return;
                                        }
                                    }
                                }

                                continue;
                            }

                            if (target->fields._canDrag)
                            {
                                float clampedCursorX = __this->fields._cursorMaxX;
                                if (cursorVec3.fields.x < clampedCursorX)
                                {
                                    clampedCursorX = cursorVec3.fields.x;
                                }

                                UnityEngine::Transform::Object* targetTransform = target->cast<UnityEngine::Component>()->get_transform()->instance();
                                UnityEngine::Vector3::Object newCursorVec = {};
                                newCursorVec.ctor(clampedCursorX, cursorVec3.fields.y, 0.0);
                                targetTransform->set_position(newCursorVec);
                            }

                            touchState = Dpr::UI::PoketchWindow::TouchState::Hold;
                            joined_r0x007101e681a8(__this, deltaTime, target, touchState);
                            return;
                        }

                        touchState = Dpr::UI::PoketchWindow::TouchState::None;
                        target = btn27;
                        joined_r0x007101e681a8(__this, deltaTime, target, touchState);
                        return;
                    }
                }

                target = nullptr;
                touchState = Dpr::UI::PoketchWindow::TouchState::None;
                joined_r0x007101e681a8(__this, deltaTime, target, touchState);
                return;
            }
        }

        if (__this->fields._IsLarge_k__BackingField)
        {
            __this->ChangePoketchSize(false, nullptr);
        }

        joined_r0x007101e67668(__this, deltaTime);
    }
};

void exl_poketch_main() {
    //IsInRange_Small::InstallAtOffset(0x01e67a3c);
    //IsInRange_Big::InstallAtOffset(0x01e67d54);
    //ButtonInit::InstallAtOffset(0x01e66b5c);
    //OnRelease::InstallAtOffset(0x01e66280);

    PoketchWindow_OnUpdate::InstallAtOffset(0x01e67480);

    // Make our CheckOnPush hook get called one extra time, for the backwards button
    /*using namespace exl::armv8::inst;
    using namespace exl::armv8::reg;
    exl::patch::CodePatcher p(0x01e67c64);
    p.WriteInst(Nop());
    p.WriteInst(AddImmediate(X8, X8, 0x2));
    p.WriteInst(0xeb08037f);*/ // cmp x27, x8
}
