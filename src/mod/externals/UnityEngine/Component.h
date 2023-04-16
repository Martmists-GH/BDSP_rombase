#pragma once

#include "externals/il2cpp.h"
#include "externals/UnityEngine/_Object.h"
#include "externals/System/Collections/Generic/List.h"
#include "externals/System/Type.h"
#include "externals/System/_Object.h"

namespace System::Collections::Generic {
    struct List$$Component;
}

namespace UnityEngine::UI {
    struct HorizontalLayoutGroup;
}

namespace Dpr::UI {
    struct SettingMenuItem;
    struct UIText;
}

namespace UnityEngine {
    struct Transform;
    struct RectTransform;

    struct Component : ILClass<Component, 0x04c57e88> {
        struct Fields : public UnityEngine::_Object::Fields {

        };

        static inline StaticILMethod<0x04c667d0, Dpr::UI::SettingMenuItem> Method$$SettingMenuItem$$GetComponent {};
        static inline StaticILMethod<0x04c667e0, Dpr::UI::UIText> Method$$UIText$$GetComponent {};
        static inline StaticILMethod<0x04c66970, UnityEngine::UI::HorizontalLayoutGroup> Method$$HorizontalLayoutGroup$$GetComponent {};
        static inline StaticILMethod<0x04c66918, UnityEngine::RectTransform> Method$$RectTransform$$GetComponent {};

        template <typename T>
        inline T::Object* GetComponent() {
            return GetComponent(T::getClass());
        }

        template <typename T>
        inline T::Object* GetComponent(T::Class* type) {
            System::RuntimeTypeHandle::Object handle {};
            handle.fields.value = &type->_1.byval_arg;
            return external<typename T::Object*>(0x026a81c0, this, System::Type::GetTypeFromHandle(handle));
        }

        template <typename T>
        inline T::Object* GetComponent(ILMethod<T>& method) {
            return external<typename T::Object*>(0x01f48340, this, *method);
        }

        void GetComponents(System::Type* type, System::Collections::Generic::List$$Component* results) {
            external<void>(0x026a8510, this, type, results);
        }

        UnityEngine::Transform* get_transform() {
            return external<UnityEngine::Transform*>(0x026a8120, this);
        }
    };
}

namespace System::Collections::Generic {
    struct List$$Component : List<List$$Component, UnityEngine::Component> {

    };
}
