#pragma once

#include "externals/PlayerWork.h"

uint32_t GetBadgeCount()
{
  bool bVar1 = PlayerWork::GetSystemFlag(BADGE_ID_C02);
  bool bVar2 = PlayerWork::GetSystemFlag(BADGE_ID_C03);
  bool bVar3 = PlayerWork::GetSystemFlag(BADGE_ID_C04);
  bool bVar4 = PlayerWork::GetSystemFlag(BADGE_ID_C05);
  bool bVar5 = PlayerWork::GetSystemFlag(BADGE_ID_C06);
  bool bVar6 = PlayerWork::GetSystemFlag(BADGE_ID_C07);
  bool bVar7 = PlayerWork::GetSystemFlag(BADGE_ID_C08);
  bool bVar8 = PlayerWork::GetSystemFlag(BADGE_ID_C09);
  return (bVar2 & 1) + (bVar1 & 1) + (bVar3 & 1) + (bVar4 & 1) + (bVar5 & 1) + (bVar6 & 1) +
         (bVar7 & 1) + (bVar8 & 1);
}