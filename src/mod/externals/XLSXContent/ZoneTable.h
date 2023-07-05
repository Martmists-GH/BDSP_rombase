#pragma once

#include "externals/il2cpp-api.h"

#include "externals/UnityEngine/ScriptableObject.h"
#include "externals/XLSXContent/AttributeBlock.h"

namespace XLSXContent {
    struct ZoneTable : ILClass<ZoneTable> {
        struct Fields : UnityEngine::ScriptableObject::Fields {
            System::Int32_array* ZoneIDs;
	        int32_t Width;
        };
    };
}
