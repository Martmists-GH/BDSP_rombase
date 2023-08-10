#pragma once

#include "externals/il2cpp-api.h"
#include "externals/Dpr/UI/PokemonStatusPanel.h"
#include "externals/UnityEngine/Color.h"
#include "externals/Dpr/UI/UIText.h"

namespace Dpr::UI {
    struct PokemonStatusPanelAbility : ILClass<PokemonStatusPanelAbility> {
        struct ChartItem : ILClass <ChartItem>{
            Dpr::UI::UIText::Object* name;
            Dpr::UI::UIText::Object* text;
            void* icon; //UnityEngine_UI_Image_o*
            void* effectRoot; //UnityEngine_RectTransform_o*
        };

        struct Fields : Dpr::UI::PokemonStatusPanel::Fields {
            Dpr::UI::PokemonStatusPanelAbility::ChartItem::Array* _chartItems;
            Dpr::UI::UIText::Object* _tokuseiName;
            Dpr::UI::UIText::Object* _tokuseiDescription;
            UnityEngine::Color::Array* _raderColors; //Pokemon Grid Colors
            void * _raderChartRoot; //UnityEngine_RectTransform_o*
            void * _raders; //Dpr_UI_RaderChart_array*
            void * _spriteUpDowns; //UnityEngine_Sprite_array*
            UnityEngine::Color::Array* _colorUpDowns; //Pokemon Stat Name Colors
            void * _curveAbility; //UnityEngine_AnimationCurve_o*
            int32_t _selectRaderChartIndex;
            void * _effects; //System_Collections_Generic_List_EffectInstance__o*
            System::Int32_array* _powerIdMap;

            inline void Setup(PokemonStatusPanelAbility::Object *__this, Pml::PokePara::PokemonParam::Object *pokemonParam) {
                external<void>(0x01d98280, this, pokemonParam);
            }
        };
    };
}