#pragma once

#include "externals/il2cpp-api.h"

#include "externals/Dpr/Battle/Logic/BattleViewBase.h"
#include "externals/Dpr/Battle/View/BtlvBallInfo.h"
#include "externals/Dpr/Battle/View/Systems/BTLV_WAZA_EFF_PARAM.h"
#include "externals/System/String.h"

namespace Dpr::SealPreview {
    struct SealPreviewViewSystem : ILClass<SealPreviewViewSystem> {
        struct Fields {
            bool m_isFinalize;
            Dpr::Battle::View::Systems::BTLV_WAZA_EFF_PARAM::Object m_wazaParam;
            int32_t m_sequenceSeq;
            bool m_seqKeepResource;
            bool m_isStartMsgDisplay;
            int32_t m_wazaMsgFrame;
            bool m_reqCheckPinch;
            bool m_canChangePinch;
            bool m_isSoundPlayingFinishCheckInvalid;
            int32_t m_soundPlayingFinishWaitCount;
            System::String::Object* m_playingSeqFileNameHash;
            void* m_battleDataTable;
            void* m_defaultPlacementData;
            void* m_comTargetPoke;
            void* m_comTargetDamage;
            void* m_comTargetTrainer;
            void* m_effectBallId;
            Dpr::Battle::View::BtlvBallInfo::Array* m_effectBallInfo;
            // TODO rest of the fields
        };

        static_assert(offsetof(Fields, m_effectBallInfo) == 0x88);
    };
}

