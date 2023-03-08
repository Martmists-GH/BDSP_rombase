#pragma once


namespace UnityEngine {
    struct Quaternion : IlStruct<Quaternion> {
        struct Fields {
            float x;
            float y;
            float z;
            float w;
        };
    };
}
