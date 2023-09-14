#pragma once

#include "externals/il2cpp-api.h"

#include "externals/MonsLv.h"

struct ZoneWork : ILClass<ZoneWork> {
    static inline int32_t TairyouHassei_ZoneID() {
        return external<int32_t>(0x017da6f0);
    }

    static inline int32_t SafariZonePosID(int32_t zone_id) {
        return external<int32_t>(0x017da660, zone_id);
    }
    
    static inline bool IsSpFishingZone(int32_t zone_id) {
        return external<bool>(0x017da600, zone_id);
    }
    
    static inline bool IsHillBackZone(int32_t zone_id) {
        return external<bool>(0x017da610, zone_id);
    }

    static inline MonsLv::Array* TairyouHassei_MonsLv(int32_t zoneid) {
        return external<MonsLv::Array*>(0x017da780, zoneid);
    }
};
