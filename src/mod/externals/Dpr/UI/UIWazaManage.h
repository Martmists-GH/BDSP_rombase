#pragma once

#include "externals/il2cpp.h"

#include "externals/Dpr/UI/UIMsgWindowController.h"
#include "externals/Dpr/UI/UIText.h"
#include "externals/Dpr/UI/UIWindow.h"
#include "externals/Pml/PokePara/PokemonParam.h"
#include "externals/System/Action.h"
#include "externals/UnityEngine/GameObject.h"
#include "externals/UnityEngine/RectTransform.h"
#include "externals/UnityEngine/UI/Image.h"

namespace Dpr::UI {
    struct UIWazaManage : ILClass<UIWazaManage> {
        struct Param : ILStruct<Param> {
            struct Fields {
                int32_t BootType;
                bool IsOpenFromFieldScript;
                Pml::PokePara::PokemonParam::Object* PokemonParam;
                int32_t LearnWazaNo;
                System::Action::Object* ResultCallback;
            };
        };

        struct Fields : Dpr::UI::UIWindow::Fields {
            UnityEngine::GameObject::Object* bgObject;
            UnityEngine::GameObject::Object* withWazaBgObject;
            void* categoryTabs; // Dpr_UI_PokemonStatusTab_array*
            UnityEngine::GameObject::Array* statusPanelObjects;
            UnityEngine::UI::Image::Array* categoryTabCornerImages;
            void* wazaStatusPanels; // Dpr_UI_WazaManageWazaStatusPanel_array*
            UnityEngine::UI::Image::Object* pokemonInfoMonsterBallImage;
            UnityEngine::RectTransform::Object* pokemonInfoSelectArrowRoot;
            Dpr::UI::UIText::Object* pokemonInfoName;
            Dpr::UI::UIText::Object* pokemonInfoLevel;
            UnityEngine::UI::Image::Object* pokemonInfoSex;
            UnityEngine::UI::Image::Object* pokemonInfoLanguage;
            void* pokemonInfoSick; // Dpr_UI_PokemonSick_o*
            void* battlePokemonStatusPanel; // Dpr_UI_WazaManagePokemonStausPanel_o*
            void* contestPokemonStatusPanel; // Dpr_UI_WazaManagePokemonStausPanel_o*
            void* statusPanelCondition; // Dpr_UI_WazaManageCondition_o*
            Dpr::UI::UIMsgWindowController::Object* msgWindowController;
            void* activeTabs; // System_Collections_Generic_List_PokemonStatusTab__o*
            int32_t _animStateIn;
            int32_t _animStateOut;
            int32_t selectTabIndex;
            Dpr::UI::UIWazaManage::Param::Object param;
        };

        inline void Open(Dpr::UI::UIWazaManage::Param::Object param, MethodInfo* method) {
            external<void>(0x01dd3d80, this, param, method);
        }
    };
}
