#include "exlaunch.hpp"

#include "externals/PlayerWork.h"
#include "externals/RandomGroupWork.h"

#include "romdata/romdata.h"

HOOK_DEFINE_REPLACE(HoneyWork_GetMonsNo) {
    static int32_t Callback(int32_t tableType, int32_t tblMonsNo) {
        int32_t zoneID = PlayerWork::get_zoneID();
        int32_t slot = RandomGroupWork::RandomValue(10);
        return GetHoneyTreeMonsNo(zoneID, slot);
    }
};

HOOK_DEFINE_INLINE(HoneyWork_GetLevel) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        int32_t zoneID = PlayerWork::get_zoneID();
        ctx->X[0] = (uint64_t)GetHoneyTreeLevel(zoneID);
    }
};

void exl_honey_trees_main() {
    HoneyWork_GetMonsNo::InstallAtOffset(0x02cd9ab0);
    HoneyWork_GetLevel::InstallAtOffset(0x02c72e14);
}
