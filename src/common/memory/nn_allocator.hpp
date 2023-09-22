#pragma once

#include <limits>

#include "imgui.h"
#include "logger/logger.h"

template<class T>
struct nn_allocator
{
    typedef T value_type;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;

    nn_allocator() = default;
    nn_allocator(nn_allocator const&) {}

    template<class U>
    constexpr nn_allocator(const nn_allocator <U>&) noexcept {}

    inline pointer address(reference r) {
        return &r;
    }

    inline const_pointer address(const_reference r) {
        return &r;
    }

    T* allocate(std::size_t n)
    {
        if (n > std::numeric_limits<std::size_t>::max() / sizeof(T))
            //throw std::bad_array_new_length();
            Logger::log("BAD ARRAY NEW LENGTH!!!!!!!\n");

        if (auto p = static_cast<T*>(IM_ALLOC(n * sizeof(T))))
        {
            report(p, n);
            return p;
        }

        //throw std::bad_alloc();
        Logger::log("BAD ALLOC!!!!!!!\n");
        return nullptr;
    }

    void deallocate(T* p, std::size_t n) noexcept
    {
        report(p, n, 0);
        IM_FREE(p);
    }

    inline size_type max_size() const {
        return std::numeric_limits<size_type>::max() / sizeof(T);
    }

    bool operator==(nn_allocator const& a) { return this == &a; }
    bool operator!=(nn_allocator const& a) { return !operator==(a); }

private:
    void report(T* p, std::size_t n, bool alloc = true) const
    {
        //Logger::log("%s: %d bytes at %08X\n", alloc ? "Alloc" : "Dealloc", sizeof(T) * n, p);
    }
};