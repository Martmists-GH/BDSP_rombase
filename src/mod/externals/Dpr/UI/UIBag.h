#pragma once

#include "externals/il2cpp.h"
#include "externals/Dpr/Item/ItemInfo.h"
#include "externals/Dpr/UI/UIMsgWindowController.h"
#include "externals/Dpr/UI/UIWindow.h"
#include "externals/Pml/PokePara/PokemonParam.h"
#include "externals/Pml/PokeParty.h"
#include "externals/UnityEngine/RectTransform.h"

namespace Dpr::UI {
    struct UIBag : ILClass<UIBag> {
        struct __c__DisplayClass127_0 : ILClass<__c__DisplayClass127_0> {
            struct Fields {
                Dpr::UI::UIBag::Object* __4__this;
                Dpr::Item::ItemInfo::Object* item;
                void* useItemAction;
                void* equipItemAction;
                void* __9__12;
                void* __9__17;
                void* __9__13;
                void* __9__19;
            };

            static inline StaticILMethod<0x04c80068> Method$$ShowItemContextMenu_EndUseAction {};
        };

        struct __c__DisplayClass127_1 : ILClass<__c__DisplayClass127_1> {
            struct Fields {
                uint32_t fieldFuncType;
                Dpr::UI::UIBag::__c__DisplayClass127_0::Object* CS___8__locals1;
            };
        };

        struct __c__DisplayClass134_0 : ILClass<__c__DisplayClass134_0> {
            inline void _UseWazaMachine_b__3(int32_t index) {
                external<void>(0x01be0fa0, this, index);
            }
        };

        struct BattleBootParam : ILStruct<BattleBootParam> {
            struct Fields {
                int32_t TopMemberIndex;
                bool IsTrainerBattle;
                bool isDouble;
                System::Boolean_array* SasiosaeFlags;
            };
        };

        struct Fields : Dpr::UI::UIWindow::Fields {
            void * bagItemPanel; // BagItemPanel_o
            void * pokemonParty; // PokemonParty_o
            void * wazaSelectPanel; // BagWazaSelectPanel_o
            UnityEngine::RectTransform::Object * effectRoot;
            int32_t _animStateIn;
            int32_t _animStateOut;
            int32_t bootType;
            int32_t modeType;
            Pml::PokePara::PokemonParam::Object * onlyViewPokemonParam;
            int32_t onlyViewPartyIndex;
            int32_t onlyViewBattlePokemonId;
            BattleBootParam::Object battleBootParam;
            void * onSelectedKinomiItem; // System_Action_int__o
            void * onCompleteAutoPilot; // System_Action_o
            Dpr::UI::UIMsgWindowController::Object * msgWindowController;
            void * pokemonPartyParam; // PokemonParty_Param_o
            int32_t displayMoney;
            bool isWaitUpdate;
            bool isWaitPokemonParty;
            bool isKinomiContact;
            bool isDontBuryNuts;
            bool isAutoPilot;
            bool _IsOpenFromBattleTeam_k__BackingField;
        };

        inline void Close(void* onClosed, int32_t nextWindowId, bool isPlayCloseSe) {
            external<void>(0x01859870, this, onClosed, nextWindowId, isPlayCloseSe);
        }
    };
}
