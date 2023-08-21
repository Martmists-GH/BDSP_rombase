#include "exlaunch.hpp"

#include "romdata/data/ColorSet.h"

RomData::ColorSet GetColorSet(int32_t index)
{
    switch (index)
    {
        default:
        case 0:
            return { // White skin Player (DPPt colors)
                .fSkinFace =     { .fields = { 0.9490196, 0.76862746, 0.6627451, 1 } },    // White skin
                .fSkinMouth =    { .fields = { 0.9490196, 0.76862746, 0.6627451, 1 } },    // White skin
                .fEyes =         { .fields = { 0.72156864, 0.79607844, 0.9019608, 1 } },   // Baby blue
                .fEyebrows =     { .fields = { 0.23921569, 0.27450982, 0.36862746, 1 } },  // Navy blue
                .fSkinBody =     { .fields = { 0.9490196, 0.76862746, 0.6627451, 1 } },    // White skin
                .fHair =         { .fields = { 0.23921569, 0.27450982, 0.36862746, 1 } },  // Navy blue

                .bSkinFace =     { .fields = { 0.9490196, 0.76862746, 0.6627451, 1 } },    // White skin
                .bHairExtra =    { .fields = { 0.23921569, 0.27450982, 0.36862746, 1 } },  // Navy blue
                .bEyeLeft =      { .fields = { 0.72156864, 0.79607844, 0.9019608, 1 } },   // Baby blue
                .bEyeRight =     { .fields = { 0.72156864, 0.79607844, 0.9019608, 1 } },   // Baby blue
                .bSkinBody =     { .fields = { 0.9490196, 0.76862746, 0.6627451, 1 } },    // White skin
                .bHair =         { .fields = { 0.23921569, 0.27450982, 0.36862746, 1 } },  // Navy blue
            };
        case 1:
            return { // Darker brown skin Player
                .fSkinFace =     { .fields = { 0.4509804, 0.34117648, 0.24705882, 1 } },   // Darker brown skin
                .fSkinMouth =    { .fields = { 0.4509804, 0.34117648, 0.24705882, 1 } },   // Darker brown skin
                .fEyes =         { .fields = { 0.5254902, 0.34901962, 0.28235295, 1 } },   // Brown
                .fEyebrows =     { .fields = { 0.23921569, 0.25490198, 0.29803923, 1 } },  // Black
                .fSkinBody =     { .fields = { 0.4509804, 0.34117648, 0.24705882, 1 } },   // Darker brown skin
                .fHair =         { .fields = { 0.23921569, 0.25490198, 0.29803923, 1 } },  // Black

                .bSkinFace =     { .fields = { 0.4509804, 0.34117648, 0.24705882, 1 } },   // Darker brown skin
                .bHairExtra =    { .fields = { 0.23921569, 0.25490198, 0.29803923, 1 } },  // Black
                .bEyeLeft =      { .fields = { 0.5254902, 0.34901962, 0.28235295, 1 } },   // Brown
                .bEyeRight =     { .fields = { 0.5254902, 0.34901962, 0.28235295, 1 } },   // Brown
                .bSkinBody =     { .fields = { 0.4509804, 0.34117648, 0.24705882, 1 } },   // Darker brown skin
                .bHair =         { .fields = { 0.23921569, 0.25490198, 0.29803923, 1 } },  // Black
            };
        case 2:
            return { // Blonde white skin Player
                .fSkinFace =     { .fields = { 0.9019608, 0.7882353, 0.78039217, 1 } },    // Pale skin
                .fSkinMouth =    { .fields = { 0.9019608, 0.7882353, 0.78039217, 1 } },    // Pale skin
                .fEyes =         { .fields = { 0.67058825, 0.8901961, 1, 1 } },            // Bright blue
                .fEyebrows =     { .fields = { 0.8392157, 0.7607843, 0.5294118, 1 } },     // Blonde
                .fSkinBody =     { .fields = { 0.9019608, 0.7882353, 0.78039217, 1 } },    // Pale skin
                .fHair =         { .fields = { 0.8392157, 0.7607843, 0.5294118, 1 } },     // Blonde

                .bSkinFace =     { .fields = { 0.9019608, 0.7882353, 0.78039217, 1 } },    // Pale skin
                .bHairExtra =    { .fields = { 0.8392157, 0.7607843, 0.5294118, 1 } },     // Blonde
                .bEyeLeft =      { .fields = { 0.67058825, 0.8901961, 1, 1 } },            // Bright blue
                .bEyeRight =     { .fields = { 0.67058825, 0.8901961, 1, 1 } },            // Bright blue
                .bSkinBody =     { .fields = { 0.9019608, 0.7882353, 0.78039217, 1 } },    // Pale skin
                .bHair =         { .fields = { 0.8392157, 0.7607843, 0.5294118, 1 } },     // Blonde
            };
        case 3:
            return { // Light brown skin Player
                .fSkinFace =     { .fields = { 0.69803923, 0.5647059, 0.49019608, 1 } },   // Light brown skin
                .fSkinMouth =    { .fields = { 0.69803923, 0.5647059, 0.49019608, 1 } },   // Light brown skin
                .fEyes =         { .fields = { 0.8039216, 0.45490196, 0.53333336, 1 } },   // Pink
                .fEyebrows =     { .fields = { 0.25490198, 0.2, 0.2, 1 } },                // Dark brown
                .fSkinBody =     { .fields = { 0.69803923, 0.5647059, 0.49019608, 1 } },   // Light brown skin
                .fHair =         { .fields = { 0.25490198, 0.2, 0.2, 1 } },                // Dark brown

                .bSkinFace =     { .fields = { 0.69803923, 0.5647059, 0.49019608, 1 } },   // Light brown skin
                .bHairExtra =    { .fields = { 0.25490198, 0.2, 0.2, 1 } },                // Dark brown
                .bEyeLeft =      { .fields = { 0.8039216, 0.45490196, 0.53333336, 1 } },   // Pink
                .bEyeRight =     { .fields = { 0.8039216, 0.45490196, 0.53333336, 1 } },   // Pink
                .bSkinBody =     { .fields = { 0.69803923, 0.5647059, 0.49019608, 1 } },   // Light brown skin
                .bHair =         { .fields = { 0.25490198, 0.2, 0.2, 1 } },                // Dark brown
            };
        case 4:
            return { // Ace Trainer F
                .fSkinFace =     { .fields = { 0.9490196, 0.8, 0.7058824, 1 } },           // White skin
                .fSkinMouth =    { .fields = { 0.9490196, 0.8, 0.7058824, 1 } },           // White skin
                .fEyes =         { .fields = { 0.4862745, 0.7294118, 0.40784314, 1 } },    // Green
                .fEyebrows =     { .fields = { 0.4862745, 0.7294118, 0.40784314, 1 } },    // Green
                .fSkinBody =     { .fields = { 0.9490196, 0.8, 0.7058824, 1 } },           // White skin
                .fHair =         { .fields = { 0.4862745, 0.7294118, 0.40784314, 1 } },    // Green

                .bSkinFace =     { .fields = { 0.9490196, 0.8, 0.7058824, 1 } },           // White skin
                .bHairExtra =    { .fields = { 0.4862745, 0.7294118, 0.40784314, 1 } },    // Green
                .bEyeLeft =      { .fields = { 0.4862745, 0.7294118, 0.40784314, 1 } },    // Green
                .bEyeRight =     { .fields = { 0.4862745, 0.7294118, 0.40784314, 1 } },    // Green
                .bSkinBody =     { .fields = { 0.9490196, 0.8, 0.7058824, 1 } },           // White skin
                .bHair =         { .fields = { 0.4862745, 0.7294118, 0.40784314, 1 } },    // Green
            };
        case 5:
            return {
                .fSkinFace =     { .fields = { 0.4509804, 0.34117648, 0.24705882, 1 } },   // Darker brown skin
                .fSkinMouth =    { .fields = { 0.4509804, 0.34117648, 0.24705882, 1 } },   // Darker brown skin
                .fEyes =         { .fields = { 0.5254902, 0.34901962, 0.28235295, 1 } },   // Brown
                .fEyebrows =     { .fields = { 0.8392157, 0.7607843, 0.5294118, 1 } },     // Blonde
                .fSkinBody =     { .fields = { 0.4509804, 0.34117648, 0.24705882, 1 } },   // Darker brown skin
                .fHair =         { .fields = { 0.8392157, 0.7607843, 0.5294118, 1 } },     // Blonde

                .bSkinFace =     { .fields = { 0.4509804, 0.34117648, 0.24705882, 1 } },   // Darker brown skin
                .bHairExtra =    { .fields = { 0.8392157, 0.7607843, 0.5294118, 1 } },     // Blonde
                .bEyeLeft =      { .fields = { 0.5254902, 0.34901962, 0.28235295, 1 } },   // Brown
                .bEyeRight =     { .fields = { 0.5254902, 0.34901962, 0.28235295, 1 } },   // Brown
                .bSkinBody =     { .fields = { 0.4509804, 0.34117648, 0.24705882, 1 } },   // Darker brown skin
                .bHair =         { .fields = { 0.8392157, 0.7607843, 0.5294118, 1 } },     // Blonde
            };
        case 6:
            return {
                .fSkinFace =     { .fields = { 0.69803923, 0.5647059, 0.49019608, 1 } },   // Light brown skin
                .fSkinMouth =    { .fields = { 0.69803923, 0.5647059, 0.49019608, 1 } },   // Light brown skin
                .fEyes =         { .fields = { 0.5254902, 0.34901962, 0.28235295, 1 } },   // Brown
                .fEyebrows =     { .fields = { 0.8392157, 0.7607843, 0.5294118, 1 } },     // Blonde
                .fSkinBody =     { .fields = { 0.69803923, 0.5647059, 0.49019608, 1 } },   // Light brown skin
                .fHair =         { .fields = { 0.8392157, 0.7607843, 0.5294118, 1 } },     // Blonde

                .bSkinFace =     { .fields = { 0.69803923, 0.5647059, 0.49019608, 1 } },   // Light brown skin
                .bHairExtra =    { .fields = { 0.8392157, 0.7607843, 0.5294118, 1 } },     // Blonde
                .bEyeLeft =      { .fields = { 0.5254902, 0.34901962, 0.28235295, 1 } },   // Brown
                .bEyeRight =     { .fields = { 0.5254902, 0.34901962, 0.28235295, 1 } },   // Brown
                .bSkinBody =     { .fields = { 0.69803923, 0.5647059, 0.49019608, 1 } },   // Light brown skin
                .bHair =         { .fields = { 0.8392157, 0.7607843, 0.5294118, 1 } },     // Blonde
            };
        case 7:
            return {
                .fSkinFace =     { .fields = { 0.9019608, 0.7882353, 0.78039217, 1 } },    // Pale skin
                .fSkinMouth =    { .fields = { 0.9019608, 0.7882353, 0.78039217, 1 } },    // Pale skin
                .fEyes =         { .fields = { 0.67058825, 0.8901961, 1, 1 } },            // Bright blue
                .fEyebrows =     { .fields = { 0.8, 0.513725, 0.294118, 1 } },             // Orange
                .fSkinBody =     { .fields = { 0.9019608, 0.7882353, 0.78039217, 1 } },    // Pale skin
                .fHair =         { .fields = { 0.8, 0.513725, 0.294118, 1 } },             // Orange

                .bSkinFace =     { .fields = { 0.9019608, 0.7882353, 0.78039217, 1 } },    // Pale skin
                .bHairExtra =    { .fields = { 0.8, 0.513725, 0.294118, 1 } },             // Orange
                .bEyeLeft =      { .fields = { 0.67058825, 0.8901961, 1, 1 } },            // Bright blue
                .bEyeRight =     { .fields = { 0.67058825, 0.8901961, 1, 1 } },            // Bright blue
                .bSkinBody =     { .fields = { 0.9019608, 0.7882353, 0.78039217, 1 } },    // Pale skin
                .bHair =         { .fields = { 0.8, 0.513725, 0.294118, 1 } },             // Orange
            };
        case 8:
            return {
                .fSkinFace =     { .fields = { 0.9490196, 0.76862746, 0.6627451, 1 } },    // White skin
                .fSkinMouth =    { .fields = { 0.9490196, 0.76862746, 0.6627451, 1 } },    // White skin
                .fEyes =         { .fields = { 0.72156864, 0.79607844, 0.9019608, 1 } },   // Baby blue
                .fEyebrows =     { .fields = { 0.447059, 0.337255, 0.247059, 1 } },        // Brown
                .fSkinBody =     { .fields = { 0.9490196, 0.76862746, 0.6627451, 1 } },    // White skin
                .fHair =         { .fields = { 0.447059, 0.337255, 0.247059, 1 } },        // Brown

                .bSkinFace =     { .fields = { 0.9490196, 0.76862746, 0.6627451, 1 } },    // White skin
                .bHairExtra =    { .fields = { 0.447059, 0.337255, 0.247059, 1 } },        // Brown
                .bEyeLeft =      { .fields = { 0.72156864, 0.79607844, 0.9019608, 1 } },   // Baby blue
                .bEyeRight =     { .fields = { 0.72156864, 0.79607844, 0.9019608, 1 } },   // Baby blue
                .bSkinBody =     { .fields = { 0.9490196, 0.76862746, 0.6627451, 1 } },    // White skin
                .bHair =         { .fields = { 0.447059, 0.337255, 0.247059, 1 } },        // Brown
            };
        case 9:
            return {
                .fSkinFace =     { .fields = { 0.9490196, 0.76862746, 0.6627451, 1 } },    // White skin
                .fSkinMouth =    { .fields = { 0.9490196, 0.76862746, 0.6627451, 1 } },    // White skin
                .fEyes =         { .fields = { 0.447059, 0.337255, 0.247059, 1 } },        // Brown
                .fEyebrows =     { .fields = { 0.447059, 0.337255, 0.247059, 1 } },        // Brown
                .fSkinBody =     { .fields = { 0.9490196, 0.76862746, 0.6627451, 1 } },    // White skin
                .fHair =         { .fields = { 0.447059, 0.337255, 0.247059, 1 } },        // Brown

                .bSkinFace =     { .fields = { 0.9490196, 0.76862746, 0.6627451, 1 } },    // White skin
                .bHairExtra =    { .fields = { 0.447059, 0.337255, 0.247059, 1 } },        // Brown
                .bEyeLeft =      { .fields = { 0.447059, 0.337255, 0.247059, 1 } },        // Brown
                .bEyeRight =     { .fields = { 0.447059, 0.337255, 0.247059, 1 } },        // Brown
                .bSkinBody =     { .fields = { 0.9490196, 0.76862746, 0.6627451, 1 } },    // White skin
                .bHair =         { .fields = { 0.447059, 0.337255, 0.247059, 1 } },        // Brown
            };
    }
}
