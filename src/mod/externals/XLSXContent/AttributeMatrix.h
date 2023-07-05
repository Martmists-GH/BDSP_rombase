#pragma once

#include "externals/il2cpp-api.h"

#include "externals/UnityEngine/ScriptableObject.h"
#include "externals/XLSXContent/AttributeBlock.h"

namespace XLSXContent {
    struct AttributeMatrix : ILClass<AttributeMatrix> {
        struct Fields : UnityEngine::ScriptableObject::Fields {
            XLSXContent::AttributeBlock::Array* AttributeBlocks;
	        int32_t Width;
        };
    };
}
