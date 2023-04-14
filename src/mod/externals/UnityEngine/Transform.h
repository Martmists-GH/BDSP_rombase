#pragma once

#include "externals/il2cpp-api.h"
#include "externals/UnityEngine/Component.h"
#include "Vector3.h"


namespace UnityEngine {
    struct Transform : ILClass<Transform> {
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

        inline UnityEngine::Transform::Object* GetParent() {
            return external<UnityEngine::Transform::Object*>(0x0299e290, this);
        }

        inline UnityEngine::Transform::Object* GetChild(int32_t index) {
            return external<UnityEngine::Transform::Object*>(0x0299f7d0, this, index);
        }

        inline void Translate(UnityEngine::Vector3* translation) {
            external<void>(0x0299e630, this, translation);
        }


        // utility functions
        UnityEngine::Transform::Object* GetChild(std::initializer_list<std::int32_t> index) {
            UnityEngine::Transform* transform = this;
            for (int32_t i : index) {
                transform = transform->GetChild(i);
            }
            return transform->instance();
        }

        template <typename T>
        inline T::Object* GetComponent() {
            return this->cast<UnityEngine::Component>()->GetComponent<T>();
        }

        template <typename T>
        inline T::Object* GetComponent(ILMethod<T>& method) {
            return this->cast<UnityEngine::Component>()->GetComponent<T>(method);
        }

        template <typename T>
        inline T::Object* GetComponent(T::Class* klass) {
            return this->cast<UnityEngine::Component>()->GetComponent<T>(klass);
        }
    };
}
