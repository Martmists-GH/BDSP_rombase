#pragma once

#include "externals/System/String.h"
#include "externals/UnityEngine/_Object.h"

namespace UnityEngine {
    struct GameObject : ILClass<GameObject> {
        struct Fields : UnityEngine::_Object::Fields {

        };

        inline UnityEngine::Transform::Object* get_transform() {
            return external<UnityEngine::Transform::Object*>(0x026b18d0, this);
        }

        static inline GameObject::Object* Find(System::String::Object *name) {
            return external<GameObject::Object*>(0x026b1ea0, name);
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
