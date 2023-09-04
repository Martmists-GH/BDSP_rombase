#pragma once

#include "externals/il2cpp-api.h"
#include "externals/UnityEngine/Transform.h"

namespace Dpr::Battle::View {
    struct BtlvObjectFollowInfo : ILClass<BtlvObjectFollowInfo> {
        struct Fields {
            void* _HdlFollowModel_k__BackingField; //Dpr_Battle_View_ITranslationObject_o*
            UnityEngine::Transform::Object* _FollowJoint_k__BackingField;
            bool _FollowPos_k__BackingField;
            bool _FollowRot_k__BackingField;
            bool _FollowScl_k__BackingField;
            bool _FollowAnimScl_k__BackingField;
            bool _FollowLocalScl_k__BackingField;
        };
    };
}