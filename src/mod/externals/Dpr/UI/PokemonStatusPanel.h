#pragma once

#include "externals/il2cpp-api.h"

#include "externals/Dpr/UI/UIInputController.h"
#include "externals/Pml/PokePara/PokemonParam.h"
#include "externals/UnityEngine/Events/UnityAction.h"
#include "externals/UnityEngine/GameObject.h"
#include "externals/UnityEngine/MonoBehaviour.h"

namespace Dpr::UI {
    struct PokemonStatusPanel : ILClass<PokemonStatusPanel> {
        struct Fields : UnityEngine::MonoBehaviour::Fields {
            Pml::PokePara::PokemonParam::Object* _pokemonParam;
            UnityEngine::GameObject::Object* _aButtonGuide;
            Dpr::UI::UIInputController::Object* input;
            void * statusParam; //Dpr_UI_PokemonStatusWindow_Param_o*
            UnityEngine::Events::UnityAction::Object* onChangeMemberSelectArrow;
            UnityEngine::Events::UnityAction::Object* onChangeAbuttonGuide;
            UnityEngine::Events::UnityAction::Object* onOpenBag;
            UnityEngine::Events::UnityAction::Object* onOpenBagOfWazaMachine;
            UnityEngine::Events::UnityAction::Object* onOpenPofinCase;
            UnityEngine::Events::UnityAction::Object* onOpenMessageWindow;
            UnityEngine::Events::UnityAction::Object* onForceClosed;
        };
    };
}