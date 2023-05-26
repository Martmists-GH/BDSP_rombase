#include "exlaunch.hpp"
#include "save/save.h"

void exl_dex_expansion_main() {
    // Patch dex limit checks
    using namespace exl::armv8::inst;
    using namespace exl::armv8::reg;

    exl::patch::CodePatcher p(0);
    auto inst = std::vector {
        std::make_pair<uint32_t, Instruction>(0x0199ca88, AddImmediate(W8, W8, DexSize - 1)),
        std::make_pair<uint32_t, Instruction>(0x018D372C, CmpImmediate(W0, 0)),
        std::make_pair<uint32_t, Instruction>(0x024a09c4, CmpImmediate(W0, DexSize)),
        std::make_pair<uint32_t, Instruction>(0x017dcc10, CmpImmediate(W19, DexSize - 1)),
        std::make_pair<uint32_t, Instruction>(0x017dc9d0, CmpImmediate(W19, DexSize - 1)),
        std::make_pair<uint32_t, Instruction>(0x017dca90, CmpImmediate(W19, DexSize - 1)),
        std::make_pair<uint32_t, Instruction>(0x017dcb50, CmpImmediate(W19, DexSize - 1)),
        std::make_pair<uint32_t, Instruction>(0x017dbd3c, CmpImmediate(W19, DexSize - 1)),
        std::make_pair<uint32_t, Instruction>(0x017dcf78, CmpImmediate(W19, DexSize - 1)),
        std::make_pair<uint32_t, Instruction>(0x024a0f54, CmpImmediate(W19, DexSize)),
        std::make_pair<uint32_t, Instruction>(0x024a2acc, CmpImmediate(W19, DexSize)),
        std::make_pair<uint32_t, Instruction>(0x024a2bc8, CmpImmediate(W19, DexSize)),
        std::make_pair<uint32_t, Instruction>(0x017dcd34, CmpImmediate(W20, DexSize - 1)),
        std::make_pair<uint32_t, Instruction>(0x017dd030, CmpImmediate(W20, DexSize - 1)),
        std::make_pair<uint32_t, Instruction>(0x02051ba0, CmpImmediate(W21, DexSize + 1)),
        std::make_pair<uint32_t, Instruction>(0x01a39760, CmpImmediate(W22, DexSize + 1)),
        std::make_pair<uint32_t, Instruction>(0x024a09b4, CmpImmediate(W8, DexSize + 1)),
        std::make_pair<uint32_t, Instruction>(0x024a0a5c, CmpImmediate(W8, DexSize + 1)),
        std::make_pair<uint32_t, Instruction>(0x024a0b64, CmpImmediate(W8, DexSize + 1)),
        std::make_pair<uint32_t, Instruction>(0x01cd637c, CmpImmediate(W8, DexSize - 1)),
        std::make_pair<uint32_t, Instruction>(0x01cd6628, CmpImmediate(W8, DexSize - 1)),
        std::make_pair<uint32_t, Instruction>(0x01cd6ecc, CmpImmediate(W8, DexSize - 1)),
        std::make_pair<uint32_t, Instruction>(0x01cd799c, CmpImmediate(W8, DexSize - 1)),
        std::make_pair<uint32_t, Instruction>(0x01cd8b1c, CmpImmediate(W8, DexSize - 1)),
        std::make_pair<uint32_t, Instruction>(0x01cd8cd8, CmpImmediate(W8, DexSize - 1)),
        std::make_pair<uint32_t, Instruction>(0x01cd8f68, CmpImmediate(W8, DexSize - 1)),
        std::make_pair<uint32_t, Instruction>(0x01cd6494, CmpImmediate(W8, DexSize)),
        std::make_pair<uint32_t, Instruction>(0x0199ca48, CmpImmediate(W9, DexSize + 1)),
        std::make_pair<uint32_t, Instruction>(0x020494ec, Movz(W0, DexSize + 1)),
        std::make_pair<uint32_t, Instruction>(0x0204ea40, Movz(W0, DexSize + 1)),
        std::make_pair<uint32_t, Instruction>(0x024a6b38, Movz(W0, DexSize + 1)),
        std::make_pair<uint32_t, Instruction>(0x017ddee0, Movz(W1, DexSize)),
        std::make_pair<uint32_t, Instruction>(0x0202faf0, Movz(W26, DexSize + 1)),
        std::make_pair<uint32_t, Instruction>(0x02052220, Movz(W8, DexSize + 1)),
        std::make_pair<uint32_t, Instruction>(0x01f7b440, Movz(W8, DexSize)),
        std::make_pair<uint32_t, Instruction>(0x024a0a60, Movz(W8, DexSize)),
        std::make_pair<uint32_t, Instruction>(0x024a0b68, Movz(W8, DexSize)),
        std::make_pair<uint32_t, Instruction>(0x024a3b48, Movz(W9, DexSize + 1)),
        std::make_pair<uint32_t, Instruction>(0x0199ca54, SubImmediate(W8, W8, DexSize - 1)),
    };
    p.WriteInst(inst);
}
