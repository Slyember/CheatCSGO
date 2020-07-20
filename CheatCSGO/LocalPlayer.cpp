#include "Includes.h"

DWORD LocalPlayer::LocalBaseaddress = 0;


DWORD LocalPlayer::getLocalPlayer() 
{
	return LocalPlayer::LocalBaseaddress;
}


void  LocalPlayer::setLocalPlayer() 
{
	LocalPlayer::LocalBaseaddress = rpm<DWORD>(baseAddress + dwLocalPlayer);
}


int LocalPlayer::getLocalHealth() 
{
	return rpm<int>(LocalPlayer::getLocalPlayer() + m_iHealth);
}


int LocalPlayer::getLocalTeam() 
{
	return rpm<int>(LocalPlayer::getLocalPlayer() + m_iTeamNum);
}

int LocalPlayer::getLocalFlags()
{
	return rpm<int>(LocalPlayer::getLocalPlayer() + netvars::m_fFlags);
}

void LocalPlayer::forceJump(int waitTime)
{
	wpm<int>(1, baseAddress + dwForceJump);
	Sleep(waitTime);
	wpm<int>(0, baseAddress + dwForceJump);
}



