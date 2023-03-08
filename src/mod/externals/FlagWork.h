#pragma once

#include "il2cpp-api.h"
#include "FlagWork_Enums.h"

struct FlagWork : IlClass<FlagWork> {
    static inline int32_t GetWork(int32_t workno) {
        return external<int32_t>(0x02ccaca0, workno);
    }
    static inline int32_t GetWork(FlagWork_Work workno) {
        return external<int32_t>(0x02ccaca0, workno);
    }

    static inline bool GetFlag(FlagWork_Flag flagno) {
        return external<bool>(0x02cca6f0, flagno);
    }

    static inline void SetFlag(FlagWork_Flag flagno, bool value) {
        external<void>(0x02cca760, flagno, value);
    }

    static inline bool GetSysFlag(FlagWork_SysFlag flagno) {
        return external<bool>(0x02ccaad0, flagno);
    }
};
