#pragma once

namespace DPData {
    struct TR_BATTLE_DATA : IlStruct<TR_BATTLE_DATA> {
        struct Fields {
            bool IsWin;
            bool IsBattleSearcher;
        };
    };
}
