#pragma once

#include "externals/il2cpp-api.h"
#include "externals/UnityEngine/Vector3.h"
#include "externals/System/String.h"
#include "externals/Dpr/Battle/View/PokeFollowInfo.h"
#include "externals/Dpr/Battle/View/BtlvObjectFollowInfo.h"
#include "externals/System/String.h"

namespace Dpr::Battle::View::Objects {
    struct BtlvPureObject : ILClass<BtlvPureObject> {
        struct Fields {
            UnityEngine::Vector3::Object _translation;
            UnityEngine::Vector3::Object _translationOffset;
            UnityEngine::Vector3::Object _scale;
            UnityEngine::Vector3::Object _scaleOffset;
            UnityEngine::Vector3::Object _rotVec;
            UnityEngine::Vector3::Object _rotVecOffset;
            bool _isSuspendUpdate;
            System::String::Object* _name;
            Dpr::Battle::View::PokeFollowInfo::Object* _pokeFollowInfo;
            Dpr::Battle::View::BtlvObjectFollowInfo::Object* _objectFollowInfo;
        };
    };
}