#pragma once

#include "externals/il2cpp-api.h"

namespace GameData {
    struct DataManager : IlClass<DataManager, 0x04c59d70> {
        struct StaticFields {
            void* CharacterGraphics;
            void* TrainerTable;
            void* PlaceData;
            void* MapWarpData;
            void* StopData;
            void* GimmickGraphics;
            void* PokemonInfo;
            void* ContestWazaInfo;
            void* ShopTable;
            void* CharacterDressData;
            void* KinomiData;
            void* KinomiPlaceData;
            void* HoneyTree;
            void* MonohiroiTable;
            void* UgJumpPos;
            void* TowerTrainerTable;
            void* TowerMatchingTable;
            void* TowerSingleStockTable;
            void* TowerDoubleStockTable;
            void* AdventureNoteData;
            System::Collections::Generic::Dictionary$$int$$List_AdventureNoteData_SheetData::Object* AdventureNoteDataDict;
            void* TowerBattlePoint;
            void* TagPlaceData;
            void* LocalKoukanData;
            void* ContestCommonData;
            void* TvDataTable;
            void* TvSchedule;
            void* onPostLoadData;
            void* FieldCommonParam;
            void* FieldWazaCutInParam;
            void* ZenmetuZone;
            void* MoveAfterSaveGrid;
            void* _comparerCatalog;
            void* _comparerKinomi;
            void* statueEffectRawData;
        };
    };
}
