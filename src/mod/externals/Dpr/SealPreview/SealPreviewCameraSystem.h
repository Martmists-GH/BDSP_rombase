#pragma once

#include "externals/il2cpp-api.h"
#include "externals/Dpr/SequenceEditor/SequenceCameraSystem.h"

namespace Dpr::SealPreview {
    struct SealPreviewCameraSystem : ILClass<SealPreviewCameraSystem> {
        struct Fields : Dpr::SequenceEditor::SequenceCameraSystem::Fields {
        };
    };
}