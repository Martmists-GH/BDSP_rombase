#pragma once

#include "externals/PlayerWork.h"
#include "externals/System/Primitives.h"
#include "externals/UnityEngine/Color.h"

template <int32_t size>
struct ColorVariationSaveData {
    System::Int32 playerColorID[size];

    UnityEngine::Color::Object fSkinFace[size];
    UnityEngine::Color::Object fSkinMouth[size];
    UnityEngine::Color::Object fEyes[size];
    UnityEngine::Color::Object fEyebrows[size];
    UnityEngine::Color::Object fSkinBody[size];
    UnityEngine::Color::Object fHair[size];

    UnityEngine::Color::Object bSkinFace[size];
    UnityEngine::Color::Object bHairExtra[size];
    UnityEngine::Color::Object bEyeLeft[size];
    UnityEngine::Color::Object bEyeRight[size];
    UnityEngine::Color::Object bSkinBody[size];
    UnityEngine::Color::Object bHair[size];

    long GetByteCount() {
        return sizeof(ColorVariationSaveData<size>);
    }

    long ToBytes(char* buffer, long index) {
        memcpy((void*)(buffer+index), &playerColorID, sizeof(System::Int32)*size);
        index += sizeof(System::Int32)*size;

        memcpy((void*)(buffer+index), &fSkinFace, sizeof(UnityEngine::Color::Object) * size);
        index += sizeof(UnityEngine::Color::Object)*size;
        memcpy((void*)(buffer+index), &fSkinMouth, sizeof(UnityEngine::Color::Object) * size);
        index += sizeof(UnityEngine::Color::Object)*size;
        memcpy((void*)(buffer+index), &fEyes, sizeof(UnityEngine::Color::Object) * size);
        index += sizeof(UnityEngine::Color::Object)*size;
        memcpy((void*)(buffer+index), &fEyebrows, sizeof(UnityEngine::Color::Object) * size);
        index += sizeof(UnityEngine::Color::Object)*size;
        memcpy((void*)(buffer+index), &fSkinBody, sizeof(UnityEngine::Color::Object) * size);
        index += sizeof(UnityEngine::Color::Object)*size;
        memcpy((void*)(buffer+index), &fHair, sizeof(UnityEngine::Color::Object) * size);
        index += sizeof(UnityEngine::Color::Object)*size;

        memcpy((void*)(buffer+index), &bSkinFace, sizeof(UnityEngine::Color::Object) * size);
        index += sizeof(UnityEngine::Color::Object)*size;
        memcpy((void*)(buffer+index), &bHairExtra, sizeof(UnityEngine::Color::Object) * size);
        index += sizeof(UnityEngine::Color::Object)*size;
        memcpy((void*)(buffer+index), &bEyeLeft, sizeof(UnityEngine::Color::Object) * size);
        index += sizeof(UnityEngine::Color::Object)*size;
        memcpy((void*)(buffer+index), &bEyeRight, sizeof(UnityEngine::Color::Object) * size);
        index += sizeof(UnityEngine::Color::Object)*size;
        memcpy((void*)(buffer+index), &bSkinBody, sizeof(UnityEngine::Color::Object) * size);
        index += sizeof(UnityEngine::Color::Object)*size;
        memcpy((void*)(buffer+index), &bHair, sizeof(UnityEngine::Color::Object) * size);
        index += sizeof(UnityEngine::Color::Object)*size;

        return index;
    }

    long FromBytes(char* buffer, long buffer_size, long index) {
        if (buffer_size >= GetByteCount() + index)
        {
            memcpy(&playerColorID, (void*)(buffer+index), sizeof(System::Int32)*size);
            index += sizeof(System::Int32)*size;

            memcpy(&fSkinFace, (void*)(buffer + index), sizeof(UnityEngine::Color::Object) * size);
            index += sizeof(UnityEngine::Color::Object)*size;
            memcpy(&fSkinMouth, (void*)(buffer + index), sizeof(UnityEngine::Color::Object) * size);
            index += sizeof(UnityEngine::Color::Object)*size;
            memcpy(&fEyes, (void*)(buffer + index), sizeof(UnityEngine::Color::Object) * size);
            index += sizeof(UnityEngine::Color::Object)*size;
            memcpy(&fEyebrows, (void*)(buffer + index), sizeof(UnityEngine::Color::Object) * size);
            index += sizeof(UnityEngine::Color::Object)*size;
            memcpy(&fSkinBody, (void*)(buffer + index), sizeof(UnityEngine::Color::Object) * size);
            index += sizeof(UnityEngine::Color::Object)*size;
            memcpy(&fHair, (void*)(buffer + index), sizeof(UnityEngine::Color::Object) * size);
            index += sizeof(UnityEngine::Color::Object)*size;

            memcpy(&bSkinFace, (void*)(buffer + index), sizeof(UnityEngine::Color::Object) * size);
            index += sizeof(UnityEngine::Color::Object)*size;
            memcpy(&bHairExtra, (void*)(buffer + index), sizeof(UnityEngine::Color::Object) * size);
            index += sizeof(UnityEngine::Color::Object)*size;
            memcpy(&bEyeLeft, (void*)(buffer + index), sizeof(UnityEngine::Color::Object) * size);
            index += sizeof(UnityEngine::Color::Object)*size;
            memcpy(&bEyeRight, (void*)(buffer + index), sizeof(UnityEngine::Color::Object) * size);
            index += sizeof(UnityEngine::Color::Object)*size;
            memcpy(&bSkinBody, (void*)(buffer + index), sizeof(UnityEngine::Color::Object) * size);
            index += sizeof(UnityEngine::Color::Object)*size;
            memcpy(&bHair, (void*)(buffer + index), sizeof(UnityEngine::Color::Object) * size);
            index += sizeof(UnityEngine::Color::Object)*size;

            return index;
        }

        return index + GetByteCount();
    }
};

void loadColorVariations(PlayerWork::Object* playerWork);
void saveColorVariations(PlayerWork::Object* playerWork);
void restoreColorVariations(PlayerWork::Object* playerWork);