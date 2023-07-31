#pragma once

#include "externals/il2cpp-api.h"
#include "externals/UnityEngine/MonoBehaviour.h"
#include "externals/Pml/PokePara/PokemonParam.h"

namespace Dpr::UI {
    struct PokemonStatusPanel : ILClass<PokemonStatusPanel> {
        struct Fields : UnityEngine::MonoBehaviour::Fields {
            struct Pml::PokePara::PokemonParam::Object* _pokemonParam;
            void * _aButtonGuide; //UnityEngine::GameObject_o*
            void * input; //Dpr_UI_UIInputController_o*
            void * statusParam; //Dpr_UI_PokemonStatusWindow_Param_o*
            void * onChangeMemberSelectArrow; //UnityEngine_Events_UnityAction_bool__o*
            void * onChangeAbuttonGuide; //UnityEngine_Events_UnityAction_bool__string__string__o*
            void * onOpenBag; //UnityEngine_Events_UnityAction_o*
            void * onOpenBagOfWazaMachine; //UnityEngine_Events_UnityAction_bool__o*
            void * onOpenPofinCase; //UnityEngine_Events_UnityAction_o*
            void * onOpenMessageWindow; //UnityEngine_Events_UnityAction_MsgWindowParam__o*
            void * onForceClosed; //UnityEngine_Events_UnityAction_o*
        };
    };
}