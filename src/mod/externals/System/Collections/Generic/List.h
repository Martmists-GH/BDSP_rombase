#pragma once

#include "externals/il2cpp-api.h"

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
    };
}
