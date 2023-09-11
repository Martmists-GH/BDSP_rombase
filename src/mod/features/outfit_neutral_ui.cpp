#include "exlaunch.hpp"
#include "externals/il2cpp-api.h"

#include "externals/Dpr/UI/UIManager.h"
#include "externals/PlayerWork.h"
#include "externals/XLSXContent/UIDatabase.h"

#include "logger/logger.h"

System::String::Object* GetWeightSpriteName() {
    if (PlayerWork::get_playerSex())
    {
        // Lucas
        return System::String::Create("dex_ico_compare_player_01_000_00");
    }
    else
    {
        // Dawn
        return System::String::Create("dex_ico_compare_player_01_100_00");
    }
}

System::String::Object* GetTownMapSpriteName() {
    if (PlayerWork::get_playerSex())
    {
        // Lucas
        return System::String::Create("map_ico_player_01_000_00");
    }
    else
    {
        // Dawn
        return System::String::Create("map_ico_player_01_100_00");
    }
}

System::String::Object* GetEncSeqPath() {
    if (PlayerWork::get_playerSex())
    {
        // Lucas
        return System::String::Create("encseq/tex/p0000");
    }
    else
    {
        // Dawn
        return System::String::Create("encseq/tex/p0100");
    }
}

XLSXContent::UIDatabase::SheetCharacterBag::Object* FindBagDataById(XLSXContent::UIDatabase::SheetCharacterBag::Array* source, int id)
{
    for (uint64_t i=0; i<source->max_length; i++)
    {
        XLSXContent::UIDatabase::SheetCharacterBag::Object* item = source->m_Items[i];
        if (item->fields.Index == id) return item;
    }

    Logger::log("Could not find bag data for id: %d\n", id);
    return nullptr;
}

HOOK_DEFINE_REPLACE(Dpr_UI_UIManager_GetCharacterBagData) {
    static XLSXContent::UIDatabase::SheetCharacterBag::Object* Callback(Dpr::UI::UIManager::Object* __this, int32_t characterDressId) {
        system_load_typeinfo(0x9bd6);

        XLSXContent::UIDatabase::SheetCharacterBag::Array* characterBags = __this->fields._mdUis->fields.CharacterBag;

        if (PlayerWork::get_playerSex())
        {
            // Lucas
            XLSXContent::UIDatabase::SheetCharacterBag::Object* item = FindBagDataById(characterBags, 0);
            if (item != nullptr) return item;
            else return characterBags->m_Items[0]; // Shouldn't happen
        }
        else
        {
            // Dawn
            XLSXContent::UIDatabase::SheetCharacterBag::Object* item = FindBagDataById(characterBags, 100);
            if (item != nullptr) return item;
            else return characterBags->m_Items[0]; // Shouldn't happen
        }
    }
};

void exl_outfit_neutral_ui_main() {
    Dpr_UI_UIManager_GetCharacterBagData::InstallAtOffset(0x017c5710);

    using namespace exl::armv8::inst;
    using namespace exl::armv8::reg;
    exl::patch::CodePatcher p(0);

    p.Seek(0x01bb17b8);
    p.BranchLinkInst((void*)&GetWeightSpriteName);

    p.Seek(0x0184fc08);
    p.BranchLinkInst((void*)&GetTownMapSpriteName);

    p.Seek(0x01f07380);
    p.BranchLinkInst((void*)&GetEncSeqPath);
    p.Seek(0x01f077e0);
    p.BranchLinkInst((void*)&GetEncSeqPath);
};