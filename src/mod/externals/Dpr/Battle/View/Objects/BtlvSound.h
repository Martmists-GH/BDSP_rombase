#pragma once

#include "externals/il2cpp-api.h"
#include "externals/Audio/AudioInstance.h"
#include "externals/System/Action.h"
#include "externals/Dpr/Battle/View/Objects/BtlvPureObject.h"

namespace Dpr::Battle::View::Objects {
    struct BtlvSound : ILClass<BtlvSound> {
        struct Fields : Dpr::Battle::View::Objects::BtlvPureObject::Fields {
            Audio::AudioInstance::Object* _instance;
            uint32_t _playEventId;
            bool _isPerpetuate;
            System::Action::Object* _onComplete;
            bool isVoice;
            bool _IsPlaying_k__BackingField;
        };
    };
}