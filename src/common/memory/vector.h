#pragma once

#include <vector>
#include "nn_allocator.h"

namespace nn {
    template<typename T>
    using vector = std::vector<T, nn_allocator<T>>;
}