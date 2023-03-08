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

    struct Component : IlClass<Component, 0x04c57e88> {
        struct Fields : public UnityEngine::_Object::Fields {
            // TODO
        };

        static ILMethod<0x04c667d0, Dpr::UI::SettingMenuItem> Method$$SettingMenuItem$$GetComponent;
        static ILMethod<0x04c667e0, Dpr::UI::UIText> Method$$UIText$$GetComponent;
        static ILMethod<0x04c66970, UnityEngine::UI::HorizontalLayoutGroup> Method$$HorizontalLayoutGroup$$GetComponent;

        template <typename T>
        inline T::Object* GetComponent() {
            System::RuntimeTypeHandle::Object handle {};
            handle.fields.value = &T::getClass()->_1.byval_arg;
            auto type = System::Type::GetTypeFromHandle(handle);
            return external<typename T::Object*>(0x026a81c0, this, type);
        }

        template <intptr_t A, typename T>
        inline T::Object* GetComponent(ILMethod<A, T>& method) {
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
