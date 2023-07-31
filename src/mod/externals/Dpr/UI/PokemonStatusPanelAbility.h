#pragma once

#include "externals/il2cpp-api.h"
#include "externals/Dpr/UI/PokemonStatusPanel.h"
#include "externals/UnityEngine/Color.h"
#include "externals/Dpr/UI/UIText.h"
#include "externals/System/Array.h"

namespace Dpr::UI {
    struct PokemonStatusPanelAbility : ILClass<PokemonStatusPanelAbility> {
        struct Fields : Dpr::UI::PokemonStatusPanel::Fields {
            void * _chartItems; //Dpr_UI_PokemonStatusPanelAbility_ChartItem_array*
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
            System::Array<int32_t> * _powerIdMap;
        };
    };
}