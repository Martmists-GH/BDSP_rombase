#pragma once

#include "externals/il2cpp-api.h"

#include "externals/System/Primitives.h"
#include "externals/UnityEngine/ScriptableObject.h"
#include "externals/XLSXContent/AttributeBlock.h"

namespace XLSXContent {
    struct AttributeBlock : ILClass<AttributeBlock> {
        struct Fields : UnityEngine::ScriptableObject::Fields {
            System::Int32_array* Attributes;
	        int32_t Width;
        };
    };
}
