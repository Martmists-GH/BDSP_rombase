#pragma once

#include "externals/PlayerWork.h"

uint32_t GetBadgeCount()
{
  bool bVar1 = PlayerWork::GetSystemFlag(0x81);
  bool bVar2 = PlayerWork::GetSystemFlag(0x7c);
  bool bVar3 = PlayerWork::GetSystemFlag(0x7d);
  bool bVar4 = PlayerWork::GetSystemFlag(0x80);
  bool bVar5 = PlayerWork::GetSystemFlag(0x7f);
  bool bVar6 = PlayerWork::GetSystemFlag(0x7e);
  bool bVar7 = PlayerWork::GetSystemFlag(0x83);
  bool bVar8 = PlayerWork::GetSystemFlag(0x82);
  return (bVar2 & 1) + (bVar1 & 1) + (bVar3 & 1) + (bVar4 & 1) + (bVar5 & 1) + (bVar6 & 1) +
         (bVar7 & 1) + (bVar8 & 1);
}