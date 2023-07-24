#pragma once

#include "externals/il2cpp-api.h"

#include "externals/Dpr/UI/PokemonPartyItem.h"
#include "externals/Dpr/UI/PokemonWindowBase.h"
#include "externals/Pml/PokePara/PokemonParam.h"
#include "externals/System/Action.h"
#include "externals/UnityEngine/Coroutine.h"
#include "externals/UnityEngine/RectTransform.h"

namespace Dpr::UI {
    struct PokemonWindow : ILClass<PokemonWindow> {
        struct Param : ILClass<Param> {
            struct Fields : Dpr::UI::PokemonWindowBase::BaseParam::Fields {
            };
        };

        struct DisplayClass25_0 : ILClass<DisplayClass25_0> {
            struct Fields {
                Dpr::UI::PokemonWindow::Object* __4__this;
                int32_t selectIndex;
                Dpr::UI::PokemonPartyItem::Object* partyItem;
                Pml::PokePara::PokemonParam::Object* pokemonParam;
                void* param; // Dpr_UI_ContextMenuWindow_Param_o*
                void* __9__6; // UnityEngine_Events_UnityAction_UnityAction_UIWindow___o*
                System::Action::Object* __9__5;
                void* __9__8; // UnityEngine_Events_UnityAction_UnityAction_UIWindow___o*
                System::Action::Object* __9__12;
                void* __9__11; // System_Func_ContextMenuItem__bool__o*
            };
        };

        struct Fields : Dpr::UI::PokemonWindowBase::Fields {
            void* _modelView; // Dpr_UI_PokemonModelView_o
            UnityEngine::RectTransform::Object* _gotoBox;
            int32_t _fieldWazaNo;
            Dpr::UI::PokemonPartyItem::Object* _fieldWazaPartyItem;
            bool _isFieldWazaExecuting;
            bool _itemSwapSelect;
            int32_t _checkFormChangeCount;
            UnityEngine::Coroutine::Object* _coroutineFormChangeLoadModel;
            Dpr::UI::PokemonWindow::Param::Object* _param;
        };
    };
}