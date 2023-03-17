#pragma once

#include "externals/Pml/PokeParty.h"
#include "externals/SmartPoint/Components/PlayerPrefsProvider_PlayerWork_.h"
#include "externals/System/Nullable.h"
#include "externals/System/String.h"
#include "externals/Pml/PokePara/SavePokeParty.h"
#include "externals/Dpr/Box/SaveBoxData.h"
#include "externals/DPData/PLAYER_DATA.h"
#include "externals/DPData/ZUKAN_WORK.h"
#include "externals/DPData/TR_BATTLE_DATA.h"
#include "externals/DPData/TOPMENU_WORK.h"
#include "externals/DPData/_FIELDOBJ_SAVE.h"
#include "externals/DPData/RECORD.h"
#include "externals/DPData/ENC_SV_DATA.h"
#include "externals/DPData/PLAYER_SAVE_DATA.h"
#include "externals/Dpr/BallDeco/SaveBallDecoData.h"
#include "externals/DPData/_RANDOM_GROUP.h"
#include "externals/DPData/FieldGimmickSaveData.h"
#include "externals/DPData/KinomiGrowSaveData.h"
#include "externals/DPData/PoffinSaveData.h"
#include "externals/DPData/BTLTOWER_SAVEWORK.h"
#include "externals/DPData/SYSTEMDATA.h"
#include "externals/DPData/POKETCH_DATA.h"
#include "externals/AzukariyaData.h"
#include "externals/DPData/_DENDOU_SAVEDATA.h"
#include "externals/DPData/BadgeSaveData.h"
#include "externals/DPData/BoukenNote.h"
#include "externals/DPData/UgSaveData.h"
#include "externals/DPData/GMS_DATA.h"
#include "externals/DPData/PLAYER_NETWORK_DATA.h"
#include "externals/DPData/UnionSaveData.h"
#include "externals/DPData/CON_PHOTO_LANG_DATA.h"
#include "externals/DPData/ZUKAN_PERSONAL_RND_DATA.h"
#include "externals/DPData/UgCountRecord.h"
#include "externals/ReBuffnameData.h"
#include "externals/DPData/RECORD_ADD_DATA.h"
#include "externals/DPData/MysteryGiftSaveData.h"
#include "externals/DPData/POKETCH_POKETORE_COUNT.h"
#include "externals/PLAYREPORT_DATA.h"
#include "externals/MT_DATA.h"
#include "externals/DPData/DENDOU_SAVE_ADD.h"
#include "externals/DPData/TV_DATA.h"
#include "externals/Dpr/BallDeco/SaveBallDecoExtraData.h"

struct PlayerWork : IlClass<PlayerWork, 0x04c59b58> {
    struct SaveData : IlStruct<SaveData> {
        struct Fields {
            int32_t version;
            void* intValues;
            void* boolValues;
            void* systemFlags;
            System::String::Object* rivalName;
            int32_t zoneID;
            float timeScale;
            void* saveItem;
            void* saveUgItem;
            void* saveItemShortcut;
            Pml::PokePara::SavePokeParty::Object playerParty;
            Dpr::Box::SaveBoxData::Object boxData;
            void* boxTray;
            DPData::PLAYER_DATA::Object playerData;
            DPData::ZUKAN_WORK::Object zukanData;
            DPData::TR_BATTLE_DATA::Array* tr_battleData;
            DPData::TOPMENU_WORK::Object topMenuData;
            DPData::_FIELDOBJ_SAVE::Object fieldObj_Save;
            DPData::RECORD_ARRAY::Object record;
            DPData::ENC_SV_DATA::Object enc_sv_data;
            DPData::PLAYER_SAVE_DATA::Object player_save_data;
            Dpr::BallDeco::SaveBallDecoData::Object ballDecoData;
            void* saveSeal;
            DPData::_RANDOM_GROUP::Object randomGroup;
            DPData::FieldGimmickSaveData::Object fieldGimmickSaveData;
            DPData::KinomiGrowSaveData::Object kinomiGrowSaveData;
            DPData::PoffinSaveData::Object poffinSaveData;
            DPData::BTLTOWER_SAVEWORK::Object btlTowerSave;
            DPData::SYSTEMDATA::Object systemData;
            DPData::POKETCH_DATA::Object poketchData;
            AzukariyaData::Object azukariyaData;
            DPData::_DENDOU_SAVEDATA::Object dendoudata;
            DPData::BadgeSaveData::Object badgeSaveData;
            DPData::BoukenNote::Object boukenNote;
            void* tvDataOld;
            DPData::UgSaveData::Object ugSaveData;
            DPData::GMS_DATA::Object gmsdata;
            DPData::PLAYER_NETWORK_DATA::Object networkdata;
            DPData::UnionSaveData::Object unionSaveData;
            DPData::CON_PHOTO_LANG_DATA::Object contstPhotoLangData;
            DPData::ZUKAN_PERSONAL_RND_DATA::Object zukanPersonalRndData;
            void* contestPhotoExtData;
            void* gmsPointExtData;
            DPData::UgCountRecord::Object ugCountRecord;
            ReBuffnameData::Object reBuffNameData;
            void* saveDataHash;
            DPData::RECORD_ADD_DATA::Object recodeAddData;
            DPData::MysteryGiftSaveData::Object mysteryGiftSaveData;
            DPData::POKETCH_POKETORE_COUNT_ARRAY::Object poketoreCountArray;
            PLAYREPORT_DATA::Object playReportData;
            MT_DATA::Object mtData;
            DPData::DENDOU_SAVE_ADD::Object dendouSaveAdd;
            DPData::TV_DATA::Object tvData;
            Dpr::BallDeco::SaveBallDecoExtraData::Object ballDecoExtraData;
        };
    };

    struct Fields : SmartPoint::Components::PlayerPrefsProvider_PlayerWork_::Fields {
        PlayerWork::SaveData::Object _saveData;
        int32_t _transitionZoneID;
        int32_t _locatorIndex;
        System::Nullable<DPData::LOCATION_WORK::Object>::Object _transitionLocation;
        bool _isBattling;
        bool _isContest;
        bool _isSealPreview;
        bool _isEvolveDemo;
        bool _isHatchDemo;
        bool _isMass;
        bool _isEncount;
        bool _isDigFossil;
        bool _isGMS;
        int32_t _loadResult;
        void* _battleSetupParam;
        Pml::PokeParty::Object* _playerParty;
        Pml::PokePara::PokemonParam::Object* _capturedPokemon;
        void* _evolveRequets;
        void* _writeSrcBuffer;
        bool _isMainSave;
        bool _isBackupSave;
        bool _autosaveCoroutineIsBusy;
        bool _autosaveWindowCoroutineIsBusy;
        void* _autosaveWindow;
        float _autosaveWindowCloseOpenTime;
    };

    static inline Pml::PokeParty::Object* get_playerParty() {
        return external<Pml::PokeParty::Object*>(0x02ce2b50);
    }

    static inline DPData::CONFIG::Object* get_config() {
        return external<DPData::CONFIG::Object*>(0x02ceb800);
    }

    static inline DPData::ZUKAN_WORK::Object* get_zukan() {
        return external<DPData::ZUKAN_WORK::Object*>(0x02cf1040);
    }

    static inline DPData::TR_BATTLE_DATA::Array** get_tr_battleData() {
        return external<DPData::TR_BATTLE_DATA::Array**>(0x02cf1bd0);
    }

    static inline void SetWarpSorawotobu(int32_t mapID, int32_t warpID) {
        external<void>(0x02cee520, mapID, warpID);
    }

    static inline void SetMoney(int32_t money) {
        external<void>(0x02cefc80, money);
    }
};
