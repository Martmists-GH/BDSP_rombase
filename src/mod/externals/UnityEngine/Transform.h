#pragma once

#include "externals/il2cpp-api.h"
#include "externals/UnityEngine/Component.h"


namespace UnityEngine {
    struct Transform : IlClass<Transform> {
        struct Fields : UnityEngine::Component::Fields {

        };

        inline void SetParent(UnityEngine::Transform* parent, bool worldPositionStays) {
            external<void>(0x0299e340, this, parent, worldPositionStays);
        }

        inline void SetSiblingIndex(int32_t index) {
            external<void>(0x0299f400, this, index);
        }

        inline int32_t get_childCount() {
            return external<int32_t>(0x0299f2c0, this);
        }

        inline UnityEngine::Transform::Object* GetChild(int32_t index) {
            return external<UnityEngine::Transform::Object*>(0x0299f7d0, this, index);
        }

        inline UnityEngine::Transform::Object* Find(System::String* name) {
            return external<UnityEngine::Transform::Object*>(0x0299f500, this, name);
        }
    };
}
