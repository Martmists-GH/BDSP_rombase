#pragma once

#include "externals/il2cpp-api.h"

#include "externals/Pml/PokePara/Accessor.h"
#include "externals/Pml/WazaNo.h"

namespace Pml::PokePara {
    struct CoreParam : ILClass<CoreParam> {
        struct Fields {
            void* m_coreData;
            void* m_calcData;
            Pml::PokePara::Accessor::Object* m_accessor;
        };

        inline int32_t GetWazaNo(uint8_t index) {
            return external<int32_t>(0x02045e00, this, index);
        }

        inline void SetWaza(uint32_t index, uint32_t wazaId) {
            external<void>(0x020464e0, this, index, wazaId);
        }

        inline uint32_t GetLangId() {
            return external<uint32_t>(0x0204b810, this);
        }

        inline bool IsNull() {
            return external<bool>(0x0204c9d0, this);
        }

        inline bool IsEgg(int32_t type) {
            return external<bool>(0x02049370, this, type);
        }

        inline int32_t GetSeikaku() {
            return external<int32_t>(0x02048740, this);
        }

        inline bool IsHpZero() {
            return external<bool>(0x02043bd0, this);
        }

        inline uint32_t GetLevel() {
            return external<uint32_t>(0x02043e30, this);
        }

        inline int32_t GetMonsNo() {
            return external<int32_t>(0x02044240, this);
        }

        inline uint16_t GetFormNo() {
            return external<uint16_t>(0x02044250, this);
        }

        inline uint16_t GetItem() {
            return external<uint16_t>(0x02049660, this);
        }

        inline uint16_t GetTokuseiNo() {
            return external<uint16_t>(0x020488a0, this);
        }

        inline void SetItem(uint16_t itemno) {
            external<void>(0x02049680, this, itemno);
        }

        inline uint8_t GetSex() {
            return external<uint8_t>(0x02048540, this);
        }

        inline void SetNickName(System::String::Object* nickName) {
            external<void>(0x02048e90, this, nickName);
        }

        inline System::Collections::Generic::HashSet$$Pml_WazaNo::Object* CollectRemindableWaza() {
            return external< System::Collections::Generic::HashSet$$Pml_WazaNo::Object*>(0x02047aa0, this);
        }

        inline int32_t AddWazaIfEmptyExist(int32_t wazano) {
            return external<int32_t>(0x02047370, this, wazano);
        }

        inline bool CheckWazaMachine(uint32_t machineNo) {
            return external<bool>(0x02046b40, this, machineNo);
        }
    };
}
