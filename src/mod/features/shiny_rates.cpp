#include "exlaunch.hpp"

#include "data/items.h"
#include "data/utils.h"
#include "externals/Dpr/Item/ItemInfo.h"
#include "externals/ItemWork.h"
#include "externals/Pml/Local/Random.h"
#include "externals/Pml/Local/RandomGenerator.h"
#include "externals/Pml/PokePara/CalcTool.h"
#include "externals/Pml/PokePara/InitialSpec.h"

uint32_t ShinyRolls(Pml::PokePara::InitialSpec::Object* pFixSpec, Pml::Local::RandomGenerator::Object* rng)
{
    uint32_t rareTryCount = pFixSpec->fields.rareTryCount;
    uint32_t rareRnd = 0;
    uint32_t id = pFixSpec->fields.id;

    // Base rolls
    rareTryCount += 8;

    // Shiny charm rolls
    Dpr::Item::ItemInfo::Object* item = ItemWork::GetItemInfo(array_index(ITEMS, "Shiny Charm"));
    if (item != nullptr && item->get_count() > 0)
    {
        rareTryCount += 2;
    }

    for (uint32_t i=0; i<rareTryCount; i++)
    {
        if (rng == nullptr) rareRnd = Pml::Local::Random::GetValue();
        else rareRnd = rng->GetRand();

        if (Pml::PokePara::CalcTool::IsRareColor(id, rareRnd))
        {
            break;
        }
    }

    // Make sure that we don't keep looping
    pFixSpec->fields.rareTryCount = 0;

    return rareRnd;
}

HOOK_DEFINE_INLINE(Shiny_GetValue) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        auto pFixSpec = (Pml::PokePara::InitialSpec::Object*)ctx->X[19];

        ctx->X[0] = (uint64_t)ShinyRolls(pFixSpec, nullptr);
    }
};

HOOK_DEFINE_INLINE(Shiny_GetRand) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        auto pFixSpec = (Pml::PokePara::InitialSpec::Object*)ctx->X[20];
        auto rng = (Pml::Local::RandomGenerator::Object*)ctx->X[19];

        ctx->X[0] = (uint64_t)ShinyRolls(pFixSpec, rng);
    }
};

void exl_shiny_rates_main() {
    // != 0xffffffffffffffff
    Shiny_GetValue::InstallAtOffset(0x0205393c);
    Shiny_GetRand::InstallAtOffset(0x0205391c);

    // 0xffffffffffffffff
    Shiny_GetValue::InstallAtOffset(0x02053928);
    Shiny_GetRand::InstallAtOffset(0x020538f8);

    // 0x1ffffffff
    Shiny_GetValue::InstallAtOffset(0x02053ab0);
    Shiny_GetRand::InstallAtOffset(0x02053a58);

    // 0x2ffffffff
    Shiny_GetValue::InstallAtOffset(0x02053adc);
    Shiny_GetRand::InstallAtOffset(0x02053a88);

    // 0x3ffffffff
    Shiny_GetValue::InstallAtOffset(0x02053a08);
    Shiny_GetRand::InstallAtOffset(0x020539a0);

    // Assembly Patches
    using namespace exl::armv8::inst;
    using namespace exl::armv8::reg;
    exl::patch::CodePatcher p(0);
    auto inst = std::vector {
        std::make_pair<uint32_t, Instruction>(0x02050880, AddImmediate(W9, W8, 0)), // Remove shiny charm effect from egg-only methods
        std::make_pair<uint32_t, Instruction>(0x02050874, Movz(W8, 6)), // Change amount of masuda rolls for eggs (6 in vanilla)
    };
    p.WriteInst(inst);
}
