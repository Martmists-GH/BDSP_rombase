#pragma once

#include <cstdint>
#include <array>

template <int N>
consteval bool array_contains(const char* const (&arr)[N], const char* element) {
    for (int i = 0; i < N; i++) {
        if (std::string_view(element) == arr[i]) {
            return true;
        }
    }
    return false;
}

// non-constexpr function, that way we error at compile-time if incorrect
static NORETURN void NOT_IN_ARRAY() { }

template <int N>
constexpr int array_index(const char* const (&arr)[N], const char* element) {
    // static_assert(array_contains(arr, element), "Element not in array");

    for (int i = 0; i < N; ++i) {
        if (std::string_view(element) == arr[i]) {
            return i;
        }
    }

    NOT_IN_ARRAY();  // invalid parameter passed to array_index
}
