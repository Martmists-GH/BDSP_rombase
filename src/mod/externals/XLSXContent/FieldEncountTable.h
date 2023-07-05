#pragma once

#include "externals/il2cpp-api.h"

#include "externals/MonsLv.h"
#include "externals/System/Primitives.h"
#include "externals/System/String.h"
#include "externals/UnityEngine/ScriptableObject.h"

namespace XLSXContent {
    struct FieldEncountTable : ILClass<FieldEncountTable> {
        struct Sheettable : ILClass<Sheettable> {
            struct Fields {
                int32_t zoneID;
                int32_t encRate_gr;
                MonsLv::Array* ground_mons;
                MonsLv::Array* tairyo;
                MonsLv::Array* day;
                MonsLv::Array* night;
                MonsLv::Array* swayGrass;
                System::Int32_array* FormProb;
                System::Int32_array* Nazo;
                System::Int32_array* AnnoonTable;
                MonsLv::Array* gbaRuby;
                MonsLv::Array* gbaSapp;
                MonsLv::Array* gbaEme;
                MonsLv::Array* gbaFire;
                MonsLv::Array* gbaLeaf;
                int32_t encRate_wat;
                MonsLv::Array* water_mons;
                int32_t encRate_turi_boro;
                MonsLv::Array* boro_mons;
                int32_t encRate_turi_ii;
                MonsLv::Array* ii_mons;
                int32_t encRate_sugoi;
                MonsLv::Array* sugoi_mons;
            };
        };

        struct Sheeturayama : ILClass<Sheeturayama> {
            struct Fields {
                int32_t monsNo;
            };
        };

        struct Sheetmistu : ILClass<Sheetmistu> {
            struct Fields {
                int32_t Rate;
                int32_t Normal;
                int32_t Rare;
                int32_t SuperRare;
            };
        };

        struct Sheethoneytree : ILClass<Sheethoneytree> {
            struct Fields {
                int32_t Normal;
	            int32_t Rare;
            };
        };

        struct Sheetsafari : ILClass<Sheetsafari> {
            struct Fields {
                int32_t MonsNo;
            };
        };

        struct Sheetmvpoke : ILClass<Sheetmvpoke> {
            struct Fields {
                int32_t zoneID;
                int32_t nextCount;
                System::Int32_array* nextZoneID;
            };
        };

        struct Sheetlegendpoke : ILClass<Sheetlegendpoke> {
            struct Fields {
                int32_t monsNo;
                int32_t formNo;
                bool isFixedEncSeq;
                System::String::Object* encSeq;
                bool isFixedBGM;
                System::String::Object* bgmEvent;
                bool isFixedBtlBg;
                int32_t btlBg;
                bool isFixedSetupEffect;
                int32_t setupEffect;
                int32_t waza1;
                int32_t waza2;
                int32_t waza3;
                int32_t waza4;
            };
        };

        struct Sheetzui : ILClass<Sheetzui> {
            struct Fields {
                int32_t zoneID;
	            System::Boolean_array* form;
            };
        };

        struct Fields : UnityEngine::ScriptableObject::Fields {
            XLSXContent::FieldEncountTable::Sheettable::Array* table;
            XLSXContent::FieldEncountTable::Sheeturayama::Array* urayama;
            XLSXContent::FieldEncountTable::Sheetmistu::Array* mistu;
            XLSXContent::FieldEncountTable::Sheethoneytree::Array* honeytree;
            XLSXContent::FieldEncountTable::Sheetsafari::Array* safari;
            XLSXContent::FieldEncountTable::Sheetmvpoke::Array* mvpoke;
            XLSXContent::FieldEncountTable::Sheetlegendpoke::Array* legendpoke;
            XLSXContent::FieldEncountTable::Sheetzui::Array* zui;
        };
    };
}
