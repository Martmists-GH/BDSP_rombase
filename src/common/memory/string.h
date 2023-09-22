#pragma once

#include <string>
#include "nn_allocator.hpp"

namespace nn {
    using string = std::basic_string<char, std::char_traits<char>, nn_allocator<char>>;
}