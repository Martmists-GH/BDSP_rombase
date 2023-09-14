#pragma once

#include "externals/il2cpp-api.h"

namespace Dpr::SequenceEditor {
    struct SequenceCameraSystem : ILClass<SequenceCameraSystem> {
        struct Fields {
            void* _viewSystem; //Dpr_SequenceEditor_ISequenceViewSystem_o*
            void* m_pCamearaAnimeComponent; //Dpr_Battle_View_Playables_CameraFilePlayable_o*
            bool _isCheckGround;
            bool _isPosOverCheck;
            void* Cameras; //Dpr_SequenceEditor_SequenceCameraObject_array*
            int32_t _CameraState_k__BackingField;
            bool IsPlayingCameraAnimation;
        };
    };
}