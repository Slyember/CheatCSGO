#pragma once

#include <Windows.h>

namespace  LocalPlayer
{
	extern DWORD getLocalPlayer();
	extern int   getLocalHealth();
	extern int   getLocalTeam();
	extern int	 getLocalFlags();

	extern void  setLocalPlayer();
	extern void	 forceJump(int waitTime = 35);

	extern DWORD LocalBaseaddress;
}

