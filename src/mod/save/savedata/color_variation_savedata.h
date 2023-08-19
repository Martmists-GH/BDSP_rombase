#pragma once

#include "externals/System/Primitives.h"
#include "externals/UnityEngine/Color.h"

template <int32_t size>
struct ColorVariationSaveData {
    System::Int32 playerColorID[size];

    UnityEngine::Color::Object skinFace[size];
    UnityEngine::Color::Object skinMouth[size];
    UnityEngine::Color::Object eyes[size];
    UnityEngine::Color::Object eyebrows[size];
    UnityEngine::Color::Object skinBody[size];
    UnityEngine::Color::Object hair[size];

    long GetByteCount() {
        return sizeof(ColorVariationSaveData<size>);
    }

    long ToBytes(char* buffer, long index) {
        memcpy((void*)(buffer+index), &playerColorID, sizeof(System::Int32)*size);
        index += sizeof(System::Int32)*size;

        memcpy((void*)(buffer+index), &skinFace, sizeof(UnityEngine::Color::Object)*size);
        index += sizeof(UnityEngine::Color::Object)*size;
        memcpy((void*)(buffer+index), &skinMouth, sizeof(UnityEngine::Color::Object)*size);
        index += sizeof(UnityEngine::Color::Object)*size;
        memcpy((void*)(buffer+index), &eyes, sizeof(UnityEngine::Color::Object)*size);
        index += sizeof(UnityEngine::Color::Object)*size;
        memcpy((void*)(buffer+index), &eyebrows, sizeof(UnityEngine::Color::Object)*size);
        index += sizeof(UnityEngine::Color::Object)*size;
        memcpy((void*)(buffer+index), &skinBody, sizeof(UnityEngine::Color::Object)*size);
        index += sizeof(UnityEngine::Color::Object)*size;
        memcpy((void*)(buffer+index), &hair, sizeof(UnityEngine::Color::Object)*size);
        index += sizeof(UnityEngine::Color::Object)*size;

        return index;
    }

    long FromBytes(char* buffer, long buffer_size, long index) {
        if (buffer_size >= GetByteCount() + index)
        {
            memcpy(&playerColorID, (void*)(buffer+index), sizeof(System::Int32)*size);
            index += sizeof(System::Int32)*size;

            memcpy(&skinFace, (void*)(buffer+index), sizeof(UnityEngine::Color::Object)*size);
            index += sizeof(UnityEngine::Color::Object)*size;
            memcpy(&skinMouth, (void*)(buffer+index), sizeof(UnityEngine::Color::Object)*size);
            index += sizeof(UnityEngine::Color::Object)*size;
            memcpy(&eyes, (void*)(buffer+index), sizeof(UnityEngine::Color::Object)*size);
            index += sizeof(UnityEngine::Color::Object)*size;
            memcpy(&eyebrows, (void*)(buffer+index), sizeof(UnityEngine::Color::Object)*size);
            index += sizeof(UnityEngine::Color::Object)*size;
            memcpy(&skinBody, (void*)(buffer+index), sizeof(UnityEngine::Color::Object)*size);
            index += sizeof(UnityEngine::Color::Object)*size;
            memcpy(&hair, (void*)(buffer+index), sizeof(UnityEngine::Color::Object)*size);
            index += sizeof(UnityEngine::Color::Object)*size;

            return index;
        }

        return index + GetByteCount();
    }
};
