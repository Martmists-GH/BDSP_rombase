#pragma once

#include <nlohmann/json.hpp>
#include "string.h"

#define JSON_TEMPLATE_PARAMS \
        template<typename, typename, typename...> class ObjectType,   \
        template<typename, typename...> class ArrayType,              \
        class StringType, class BooleanType, class NumberIntegerType, \
        class NumberUnsignedType, class NumberFloatType,              \
        template<typename> class AllocatorType,                       \
        template<typename, typename = void> class JSONSerializer

#define JSON_TEMPLATE template<JSON_TEMPLATE_PARAMS>

#define GENERIC_JSON                                                              \
        nlohmann::basic_json<ObjectType, ArrayType, StringType, BooleanType,      \
        NumberIntegerType, NumberUnsignedType, NumberFloatType,                   \
        AllocatorType, JSONSerializer>

namespace nn {
    using json = nlohmann::basic_json<std::map, std::vector, nn::string, bool, int64_t, uint64_t, float, nn_allocator, nlohmann::adl_serializer>;
}