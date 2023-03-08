#pragma once

#include <cstdint>
#include <cstddef>
#include "imgui.h"
#include "exlaunch.hpp"
#include "il2cpp.h"

extern void (*system_load_typeinfo)(long obj);
extern void* (*system_array_new)(long type, long length);
extern void* (*il2cpp_object_new)(void* klass);
extern void (*il2cpp_runtime_class_init)(void* klass);


struct _IlExternal {
    char _zeroSizedFilled[0];

    template <typename Ret, typename... Args>
    inline static Ret external(long addr, Args... args) {
        return reinterpret_cast<Ret(*)(Args...)>(exl::util::modules::GetTargetOffset(addr))(args...);
    }
};

template <typename T>
struct IlStruct : _IlExternal  {
public:
    struct Fields { };

    struct Object : T {
        T::Fields fields;
    };

    struct Array {
        Il2CppObject obj;
        Il2CppArrayBounds* bounds;
        uint64_t max_length;
        T::Object m_Items[1];

        inline void copyInto(T::Object* dst) {
            for (long i = 0; i < max_length; i++) {
                dst[i] = m_Items[i];
            }
        }
    };
};

template <typename T, long TypeInfo = 0>
struct IlClass : _IlExternal {
private:
    static inline void* il2cpp_object_new(void* klass) {
        return external<void*>(0x00266700);
    }

    static inline void il2cpp_runtime_class_init(void* klass) {
        external<void>(0x002afbe0, klass);
    }

protected:
    IlClass() = default;

public:
    struct StaticFields { };
    struct RGCTXs { };
    struct VTable { };
    struct Fields { };

    struct Class {
        Il2CppClass_1 _1;
        T::StaticFields* static_fields;
        T::RGCTXs* rgctx_data;
        Il2CppClass_2 _2;
        T::VTable* vtable;

        inline void initIfNeeded() {
            if ((_2.bitflags2 >> 1 & 1) && (_2.cctor_finished == 0)) {
                il2cpp_runtime_class_init(this);
            }
        }
    };

    struct Object : T {
        T::Class* klass;
        void* monitor;
        T::Fields fields;
    };

//    static_assert(offsetof(_Object, klass) == 0, "_Object::klass offset is incorrect");

    struct Array {
        Il2CppObject obj;
        Il2CppArrayBounds* bounds;
        uint64_t max_length;
        T::Object* m_Items[1];

        inline void copyInto(T::Object* dst) {
            for (long i = 0; i < max_length; i++) {
                dst[i] = m_Items[i];
            }
        }
    };

    template <typename Target>
    Target::Object* cast() {
        static_assert(std::is_base_of<typename Target::Fields, typename T::Fields>::value, "T cannot be cast to Target");
        return reinterpret_cast<Target::Object*>(this);
    }

    Object* instance() {
        return reinterpret_cast<Object*>(this);
    }

    template <typename... Args>
    static Object* newInstance(Args... args) {
        auto klass = getClass();
        klass->initIfNeeded();
        auto obj = reinterpret_cast<T::Object*>(il2cpp_object_new(klass));
        obj->ctor(args...);
        return obj;
    }

    static Class* getClass() {
        static_assert(TypeInfo != 0, "TypeInfo address not set");
        return *reinterpret_cast<T::Class**>(exl::util::modules::GetTargetOffset(TypeInfo));
    }
};

#define PRIMITIVE_ARRAY(name)                               \
struct name##_array {                                       \
    Il2CppObject obj;                                       \
    Il2CppArrayBounds* bounds;                              \
    uint64_t max_length;                                    \
    name m_Items[65535];                                    \
    inline void copyInto(name* dst) {                       \
        for (uint64_t i = 0; i < max_length; i++) {         \
            dst[i] = m_Items[i];                            \
        }                                                   \
    }                                                       \
};

template <long MI, typename... Args>
struct ILMethod {
    inline MethodInfo& operator*() {
        return **reinterpret_cast<MethodInfo**>(exl::util::modules::GetTargetOffset(MI));
    }

    MethodInfo* getCopy(Il2CppMethodPointer function) {
        auto m = new MethodInfo;
        memcpy(m, *this, sizeof(MethodInfo));
        m->methodPointer = function;
        return m;
    }
};
