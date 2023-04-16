#pragma once


namespace UnityEngine {
    struct Quaternion : ILStruct<Quaternion> {
        struct Fields {
            float x;
            float y;
            float z;
            float w;
        };
    };
}
