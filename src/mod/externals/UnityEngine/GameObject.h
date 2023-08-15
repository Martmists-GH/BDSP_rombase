#pragma once

#include "externals/il2cpp-api.h"

#include "externals/System/String.h"
#include "externals/System/Type.h"
#include "externals/UnityEngine/_Object.h"
#include "externals/UnityEngine/Transform.h"

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

        static inline GameObject::Object* get_gameObject() {
            return external<GameObject::Object*>(0x026b1fa0);
        }

        static inline void SetActive(bool value) {
            return external<void>(0x026b19c0, value);
        }

        template <typename T>
        inline T::Object* GetComponent() {
            return GetComponent(T::getClass());
        }

        template <typename T>
        inline T::Object* GetComponent(T::Class* type) {
            System::RuntimeTypeHandle::Object handle {};
            handle.fields.value = &type->_1.byval_arg;
            return external<typename T::Object*>(0x026a8240, this, System::Type::GetTypeFromHandle(handle));
        }

        template <typename T>
        inline T::Object* GetComponent(ILMethod<T>& method) {
            return external<typename T::Object*>(0x01f48980, this, *method);
        }
    };
}
