#include "exlaunch.hpp"

#include "save/save.h"

#include "logger/logger.h"

void exl_save_box_expansion_main() {
    // Patch box limit checks
    /*using namespace exl::armv8::inst;
    using namespace exl::armv8::reg;
    exl::patch::CodePatcher p(0);
    auto inst = nn::vector {
        // Dpr.Box.BoxPokemonWork
        std::make_pair<uint32_t, Instruction>(0x01d2fd90, CmpImmediate(W21, BoxCount - 1)),
        std::make_pair<uint32_t, Instruction>(0x01d31058, CmpImmediate(W21, BoxCount)),
        std::make_pair<uint32_t, Instruction>(0x01d3106c, CmpImmediate(W21, BoxCount)),
        std::make_pair<uint32_t, Instruction>(0x01d31394, CmpImmediate(W21, BoxCount)),
        std::make_pair<uint32_t, Instruction>(0x01d3139c, Movz(W8, BoxCount * 30)),
        std::make_pair<uint32_t, Instruction>(0x01d31460, CmpImmediate(W20, BoxCount)),
        std::make_pair<uint32_t, Instruction>(0x01d31468, Movz(W8, BoxCount * 30)),
        std::make_pair<uint32_t, Instruction>(0x01d3170c, CmpImmediate(W22, BoxCount - 1)),
        std::make_pair<uint32_t, Instruction>(0x01d31754, CmpImmediate(W22, BoxCount)),
        std::make_pair<uint32_t, Instruction>(0x01d30ba4, CmpImmediate(W24, BoxCount - 1)),
        std::make_pair<uint32_t, Instruction>(0x01d30bac, CmpImmediate(W22, BoxCount - 1)),
        std::make_pair<uint32_t, Instruction>(0x01d3010c, CmpImmediate(W23, BoxCount - 1)),
        std::make_pair<uint32_t, Instruction>(0x01d30150, CmpImmediate(W23, BoxCount)),
        std::make_pair<uint32_t, Instruction>(0x01d31c30, CmpImmediate(W20, BoxCount)),
        std::make_pair<uint32_t, Instruction>(0x01d308f0, CmpImmediate(W22, BoxCount - 1)),
        std::make_pair<uint32_t, Instruction>(0x01d30900, CmpImmediate(W21, BoxCount)),
        std::make_pair<uint32_t, Instruction>(0x01d309ec, CmpImmediate(W19, BoxCount - 1)),
        std::make_pair<uint32_t, Instruction>(0x01d309f4, CmpImmediate(W20, BoxCount)),
        std::make_pair<uint32_t, Instruction>(0x01d30da0, CmpImmediate(W21, BoxCount - 1)),

        // Dpr.Box.BoxWork
        std::make_pair<uint32_t, Instruction>(0x01d32438, CmpImmediate(W0, BoxCount - 1)),
        std::make_pair<uint32_t, Instruction>(0x01d32448, CmpImmediate(W2, BoxCount)),
        std::make_pair<uint32_t, Instruction>(0x01d320d0, CmpImmediate(W0, BoxCount - 1)),
        std::make_pair<uint32_t, Instruction>(0x01d320dc, CmpImmediate(W1, BoxCount - 1)),
        std::make_pair<uint32_t, Instruction>(0x01d33064, CmpImmediate(W0, BoxCount - 1)),
        std::make_pair<uint32_t, Instruction>(0x01d32c60, CmpImmediate(W0, BoxCount - 1)),
        std::make_pair<uint32_t, Instruction>(0x01d30610, Movz(X0, BoxCount)),
        std::make_pair<uint32_t, Instruction>(0x01d32370, CmpImmediate(W0, BoxCount)),
        std::make_pair<uint32_t, Instruction>(0x01d33f20, CmpImmediate(W0, BoxCount)),
        std::make_pair<uint32_t, Instruction>(0x01d32b00, CmpImmediate(W0, BoxCount - 1)),
        std::make_pair<uint32_t, Instruction>(0x01d32988, CmpImmediate(W0, BoxCount - 1)),
        std::make_pair<uint32_t, Instruction>(0x01d32a10, CmpImmediate(W0, BoxCount - 1)),
        std::make_pair<uint32_t, Instruction>(0x01d335c0, CmpImmediate(W0, BoxCount - 1)),
        std::make_pair<uint32_t, Instruction>(0x01d33600, CmpImmediate(W0, BoxCount - 1)),
        std::make_pair<uint32_t, Instruction>(0x01d33b20, CmpImmediate(W2, BoxCount - 1)),
        std::make_pair<uint32_t, Instruction>(0x01d31a6c, Nop()),
        std::make_pair<uint32_t, Instruction>(0x01d31a70, Nop()),
        std::make_pair<uint32_t, Instruction>(0x01d31a8c, Nop()),
        std::make_pair<uint32_t, Instruction>(0x01d31a90, Nop()),
        std::make_pair<uint32_t, Instruction>(0x01d322b0, CmpImmediate(W1, BoxCount)),
        std::make_pair<uint32_t, Instruction>(0x01d33e78, CmpImmediate(W0, BoxCount)),

        // Dpr.UI.BoxListPanel
        std::make_pair<uint32_t, Instruction>(0x01aaff54, CmpImmediate(W21, BoxCount)),
        std::make_pair<uint32_t, Instruction>(0x01aaff7c, Movz(W28, 4)),

        std::make_pair<uint32_t, Instruction>(0x01ab1cec, Movz(W25, BoxCount)),
    };
    p.WriteInst(inst);

    // Hardcode to always be considered to have "max" boxes (disables upgrades)
    p.Seek(0x01d3185c);
    p.WriteInst(CmpImmediate(W20, 0));*/

    // Double-check lVar7 in Dpr.Box.BoxPokemonWork$$SwapTray, weird numbers?
    // Double-check Dpr.Box.SaveBoxData$$Clear, see if I need to overwrite the array sizes
}