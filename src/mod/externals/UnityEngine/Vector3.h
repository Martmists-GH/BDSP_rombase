#pragma once

namespace UnityEngine {
    struct Vector3 : IlStruct<Vector3> {
        struct Fields {
            float x;
            float y;
            float z;
        };
    };
}
