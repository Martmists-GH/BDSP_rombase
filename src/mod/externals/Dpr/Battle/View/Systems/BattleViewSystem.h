#pragma once

#include "externals/il2cpp-api.h"

#include "externals/Dpr/Battle/Logic/BattleViewBase.h"
#include "externals/Dpr/Battle/View/BtlvBallInfo.h"
#include "externals/Dpr/Battle/View/Systems/BTLV_WAZA_EFF_PARAM.h"
#include "externals/System/String.h"

namespace Dpr::Battle::View::Systems {
    struct BattleViewSystem : ILClass<BattleViewSystem> {
        struct Fields : Dpr::Battle::Logic::BattleViewBase::Fields {
            bool m_isFinalize;
            bool m_isFinalizeFadeSkip;
            bool m_isFinishLoadObjects;
            void* m_iPtrSequenceSystem;
            void* m_iPtrCharacterSystem;
            void* m_iPtrCameraSystem;
            void* m_iPtrWeatherSystem;
            void* m_iPtrBattleGroundEffectSystem;
            void* m_iPtrStatusEffectObserverSystem;
            void* m_battleDataTable;
            void* m_defaultPlacementData;
            void* m_iPtrScreenObject;
            void* m_skrtModelDict;
            Dpr::Battle::View::Systems::BTLV_WAZA_EFF_PARAM::Object m_wazaParam;
            void* m_comTargetPoke;
            void* m_comTargetDamage;
            void* m_comTargetTrainer;
            int32_t m_comEffectId;
            void* m_effectBallId;
            Dpr::Battle::View::BtlvBallInfo::Array* m_effectBallInfo;
            int32_t m_comIsVisibleTame;
            bool m_comIsMigawari;
            bool m_comMigawariReserve;
            int32_t m_comMigawariReserveTarget;
            int32_t m_comRepeatNum;
            bool m_comIsSuccsess;
            bool m_comIsCritical;
            int32_t m_subSequence;
            int32_t m_sequenceSeq;
            bool m_seqKeepResource;
            System::String::Object* m_playingSeqFileNameHash;
            void* m_pComWaitFunc;
            bool m_isStartMsgDisplay;
            int32_t m_wazaMsgFrame;
            int32_t m_beforePlayEffPos;
            int32_t m_beforePlayEffNo;
            bool m_isFieldIndoor;
            bool m_isFieldStadium;
            bool m_isFieldRoseTower;
            bool m_isFieldStadiumWide;
            bool m_isFieldWaitcamExcept;
            bool m_reqCheckPinch;
            bool m_canChangePinch;
            bool m_isSoundPlayingFinishCheckInvalid;
            int32_t m_soundPlayingFinishWaitCount;
            void* m_pokePinchSound;
            bool m_preUpdateAudioListenerByMainCamera;
            // TODO rest of the fields
        };

        static_assert(offsetof(Fields, m_effectBallInfo) == 0xE0);
    };
}

