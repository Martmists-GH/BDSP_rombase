#include "exlaunch.hpp"

#include "romdata/data/ColorSet.h"

RomData::ColorSet GetColorSet(int32_t index)
{
    switch (index)
    {
        default:
        case 0:
            return { // White skin Player (DPPt colors)
                .skinFace =     { .fields = { 0.9490196, 0.76862746, 0.6627451, 1 } },    // White skin
                .skinMouth =    { .fields = { 0.9490196, 0.76862746, 0.6627451, 1 } },    // White skin
                .eyes =         { .fields = { 0.72156864, 0.79607844, 0.9019608, 1 } },   // Baby blue
                .eyebrows =     { .fields = { 0.23921569, 0.27450982, 0.36862746, 1 } },  // Navy blue
                .skinBody =     { .fields = { 0.9490196, 0.76862746, 0.6627451, 1 } },    // White skin
                .hair =         { .fields = { 0.23921569, 0.27450982, 0.36862746, 1 } },  // Navy blue
            };
        case 1:
            return { // Darker brown skin Player
                .skinFace =     { .fields = { 0.4509804, 0.34117648, 0.24705882, 1 } },   // Darker brown skin
                .skinMouth =    { .fields = { 0.4509804, 0.34117648, 0.24705882, 1 } },   // Darker brown skin
                .eyes =         { .fields = { 0.5254902, 0.34901962, 0.28235295, 1 } },   // Brown
                .eyebrows =     { .fields = { 0.23921569, 0.25490198, 0.29803923, 1 } },  // Black
                .skinBody =     { .fields = { 0.4509804, 0.34117648, 0.24705882, 1 } },   // Darker brown skin
                .hair =         { .fields = { 0.23921569, 0.25490198, 0.29803923, 1 } },  // Black
            };
        case 2:
            return { // Blonde white skin Player
                .skinFace =     { .fields = { 0.9019608, 0.7882353, 0.78039217, 1 } },    // Pale skin
                .skinMouth =    { .fields = { 0.9019608, 0.7882353, 0.78039217, 1 } },    // Pale skin
                .eyes =         { .fields = { 0.67058825, 0.8901961, 1, 1 } },            // Bright blue
                .eyebrows =     { .fields = { 0.8392157, 0.7607843, 0.5294118, 1 } },     // Blonde
                .skinBody =     { .fields = { 0.9019608, 0.7882353, 0.78039217, 1 } },    // Pale skin
                .hair =         { .fields = { 0.8392157, 0.7607843, 0.5294118, 1 } },     // Blonde
            };
        case 3:
            return { // Light brown skin Player
                .skinFace =     { .fields = { 0.69803923, 0.5647059, 0.49019608, 1 } },   // Light brown skin
                .skinMouth =    { .fields = { 0.69803923, 0.5647059, 0.49019608, 1 } },   // Light brown skin
                .eyes =         { .fields = { 0.8039216, 0.45490196, 0.53333336, 1 } },   // Pink
                .eyebrows =     { .fields = { 0.25490198, 0.2, 0.2, 1 } },                // Dark brown
                .skinBody =     { .fields = { 0.69803923, 0.5647059, 0.49019608, 1 } },   // Light brown skin
                .hair =         { .fields = { 0.25490198, 0.2, 0.2, 1 } },                // Dark brown
            };
        case 4:
            return { // Ace Trainer F
                .skinFace =     { .fields = { 0.9490196, 0.8, 0.7058824, 1 } },           // White skin
                .skinMouth =    { .fields = { 0.9490196, 0.8, 0.7058824, 1 } },           // White skin
                .eyes =         { .fields = { 0.4862745, 0.7294118, 0.40784314, 1 } },    // Green
                .eyebrows =     { .fields = { 0.4862745, 0.7294118, 0.40784314, 1 } },    // Green
                .skinBody =     { .fields = { 0.9490196, 0.8, 0.7058824, 1 } },           // White skin
                .hair =         { .fields = { 0.4862745, 0.7294118, 0.40784314, 1 } },    // Green
            };
        case 5:
            return {
                .skinFace =     { .fields = { 0.4509804, 0.34117648, 0.24705882, 1 } },   // Darker brown skin
                .skinMouth =    { .fields = { 0.4509804, 0.34117648, 0.24705882, 1 } },   // Darker brown skin
                .eyes =         { .fields = { 0.5254902, 0.34901962, 0.28235295, 1 } },   // Brown
                .eyebrows =     { .fields = { 0.8392157, 0.7607843, 0.5294118, 1 } },     // Blonde
                .skinBody =     { .fields = { 0.4509804, 0.34117648, 0.24705882, 1 } },   // Darker brown skin
                .hair =         { .fields = { 0.8392157, 0.7607843, 0.5294118, 1 } },     // Blonde
            };
        case 6:
            return {
                .skinFace =     { .fields = { 0.69803923, 0.5647059, 0.49019608, 1 } },   // Light brown skin
                .skinMouth =    { .fields = { 0.69803923, 0.5647059, 0.49019608, 1 } },   // Light brown skin
                .eyes =         { .fields = { 0.5254902, 0.34901962, 0.28235295, 1 } },   // Brown
                .eyebrows =     { .fields = { 0.8392157, 0.7607843, 0.5294118, 1 } },     // Blonde
                .skinBody =     { .fields = { 0.69803923, 0.5647059, 0.49019608, 1 } },   // Light brown skin
                .hair =         { .fields = { 0.8392157, 0.7607843, 0.5294118, 1 } },     // Blonde
            };
        case 7:
            return {
                .skinFace =     { .fields = { 0.9019608, 0.7882353, 0.78039217, 1 } },    // Pale skin
                .skinMouth =    { .fields = { 0.9019608, 0.7882353, 0.78039217, 1 } },    // Pale skin
                .eyes =         { .fields = { 0.67058825, 0.8901961, 1, 1 } },            // Bright blue
                .eyebrows =     { .fields = { 0.8, 0.513725, 0.294118, 1 } },             // Orange
                .skinBody =     { .fields = { 0.9019608, 0.7882353, 0.78039217, 1 } },    // Pale skin
                .hair =         { .fields = { 0.8, 0.513725, 0.294118, 1 } },             // Orange
            };
        case 8:
            return {
                .skinFace =     { .fields = { 0.9490196, 0.76862746, 0.6627451, 1 } },    // White skin
                .skinMouth =    { .fields = { 0.9490196, 0.76862746, 0.6627451, 1 } },    // White skin
                .eyes =         { .fields = { 0.72156864, 0.79607844, 0.9019608, 1 } },   // Baby blue
                .eyebrows =     { .fields = { 0.447059, 0.337255, 0.247059, 1 } },        // Brown
                .skinBody =     { .fields = { 0.9490196, 0.76862746, 0.6627451, 1 } },    // White skin
                .hair =         { .fields = { 0.447059, 0.337255, 0.247059, 1 } },        // Brown
            };
        case 9:
            return {
                .skinFace =     { .fields = { 0.9490196, 0.76862746, 0.6627451, 1 } },    // White skin
                .skinMouth =    { .fields = { 0.9490196, 0.76862746, 0.6627451, 1 } },    // White skin
                .eyes =         { .fields = { 0.447059, 0.337255, 0.247059, 1 } },        // Brown
                .eyebrows =     { .fields = { 0.447059, 0.337255, 0.247059, 1 } },        // Brown
                .skinBody =     { .fields = { 0.9490196, 0.76862746, 0.6627451, 1 } },    // White skin
                .hair =         { .fields = { 0.447059, 0.337255, 0.247059, 1 } },        // Brown
            };
    }
}
