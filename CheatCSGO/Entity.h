#pragma once
#include <windows.h>
#include <cstddef>

namespace Entity
{
	extern void setSpotted(DWORD playerBase, bool val);
	extern void glowEsp(DWORD glowObj, int glowInd, float r, float g, float b, float a);

	extern DWORD getEntBase(int index);
	extern int getEntHp(DWORD playerBase);
	extern bool isAlive(DWORD playerBase);
	extern bool isValid(DWORD playerBase);
	extern bool getSpotted(DWORD playerBase);
	extern bool getEntDefusing(DWORD playerBase);
	extern int getEntTeam(DWORD playerBase);
	extern int getGlowIndex(DWORD playerBase);
	extern DWORD getGlowObj();
}