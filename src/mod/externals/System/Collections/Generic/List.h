#pragma once

#include "externals/il2cpp-api.h"

#include "externals/System/Primitives.h"

namespace System::Collections::Generic {
    template <typename T, typename E>
    struct List : ILClass<T> {
        struct Fields {
            E::Array* _items;
            int32_t _size;
            int32_t _version;
            Il2CppObject* _syncRoot;
        };

        void swap(int32_t i, int32_t j) {
            auto arr = this->instance()->fields._items->m_Items;
            auto tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }

        inline void Add(E* item) {
            ILClass<T>::template external<void>(0x02a3c680, this, item, *T::Method$$Add);
        }

        inline E::Array* ToArray() {
            return system_array_new((Il2CppClass*)this->instance()->klass, this->instance()->fields._size);
        }
    };

    struct List$$Int32 : ILClass<List$$Int32, 0x04c56ea0> {
        struct Fields {
            System::Int32_array* _items;
            int32_t _size;
            int32_t _version;
            Il2CppObject* _syncRoot;
        };

        static inline StaticILMethod<0x04c8a3a8, int32_t> Method$$Add {};

        void swap(int32_t i, int32_t j) {
            auto arr = this->instance()->fields._items->m_Items;
            auto tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }

        inline void ctor() {
            external<void>(0x02a6fde0, this);
        }

        inline void Add(int32_t item) {
            external<void>(0x02a3c680, this, item, Method$$Add);
        }

        inline System::Int32_array* ToArray() {
            return (System::Int32_array*)system_array_new((Il2CppClass*)this->instance()->klass, this->instance()->fields._size);
        }
    };
}
