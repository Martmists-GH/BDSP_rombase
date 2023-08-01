#pragma once

#include "externals/il2cpp-api.h"
#include "externals/SmartPoint/AssetAssistant/SingletonMonoBehaviour.h"
#include "externals/System/String.h"


namespace Dpr::Message {
    struct MessageManager : ILClass<MessageManager> {
        struct Fields {
            void* msbtLoader; //Dpr_Message_MsgDataFileLoader_o*
            void* dataModel; //Dpr_Message_MessageDataModel_o*
            void* tagWordBuffer; //Dpr_Message_TagWordBuffer_o*
            void* wordDataPool; //Dpr_Message_MessageWordDataPool_o*
        };

        static inline System::String::Object * GetSimpleMessage(System::String::Object *fileName,System::String::Object *label) {
            return external<System::String::Object *>(0x0210d000, fileName, label);
        }
    };
}

