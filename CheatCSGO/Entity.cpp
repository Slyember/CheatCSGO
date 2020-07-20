#include "Entity.h"
#include "NullMemory.h"
#include "GlowStruct.h"

using namespace hazedumper;
using namespace netvars;
using namespace signatures;


DWORD Entity::getEntBase(int index)
{
	const DWORD EntLoopDist = 0x10;
	return rpm<DWORD>(baseAddress + dwEntityList + (index * EntLoopDist));
}

int	Entity::getEntHp(DWORD playerBase)
{
	return rpm<int>(playerBase + m_iHealth);
}

bool Entity::isAlive(DWORD playerBase)
{
	if (getEntHp(playerBase) > 0 && getEntHp(playerBase) <= 100)
		return true;
	return false;
}

int	Entity::getEntTeam(DWORD playerBase)
{
	return rpm<int>(playerBase + m_iTeamNum);
}

int Entity::getGlowIndex(DWORD playerBase)
{
	return rpm<int>(playerBase + m_iGlowIndex);
}

bool Entity::isValid(DWORD playerBase)
{
	auto dormant = rpm<bool>(playerBase + m_bDormant);
	if ((Entity::isAlive(playerBase) && Entity::getEntTeam(playerBase) != 0) && !dormant)
		return true;
	return false;
}

DWORD Entity::getGlowObj()
{
	return rpm<DWORD>(baseAddress + dwGlowObjectManager);
}

void Entity::glowEsp(DWORD glowObj, int glowInd, float r, float g, float b, float a)
{
	GlowStruct glow = rpm<GlowStruct>(glowObj + (glowInd * sizeof(GlowStruct)));
	//GlowStruct glow;
	glow.r = r;
	glow.g = g;
	glow.b = b;
	glow.a = a;
	glow.RenderOccluded = true;
	glow.RenderUnoccluded = false;
	wpm<GlowStruct>(glow, glowObj + (glowInd * sizeof(GlowStruct)));
}

bool Entity::getSpotted(DWORD playerBase)
{
	return rpm<bool>(playerBase + m_bSpotted);
}

void Entity::setSpotted(DWORD playerBase, bool val)
{
	wpm<bool>(val, playerBase + m_bSpotted);
}

bool Entity::getEntDefusing(DWORD playerBase)
{
	return rpm<bool>(playerBase + m_bIsDefusing);
}


/*
Entity::Entity(Memory* mem) {
	this->mem = mem;
}

Entity::Entity() {}
Entity::~Entity() {}

void Entity::set(DWORD entity) {
	this->entity = entity;
}

DWORD Entity::get() {
	return entity;
}

DWORD Entity::getHealth() {
	return mem->Read<int>(entity + m_iHealth);
}

int Entity::getTeam() {
	return mem->Read<int>(entity + m_iTeamNum);
}

int Entity::getGlowIndex() {
	return mem->Read<int>(entity + m_iGlowIndex);
}

bool Entity::isDormant() {
	return mem->Read<bool>(entity + m_bDormant);
}

bool Entity::isDefusing() {
	return mem->Read<bool>(entity + m_bIsDefusing);
}

bool Entity::isSpotted() {
	return mem->Read<bool>(entity + m_bSpotted);
}

void Entity::setSpotted(bool isSpotted) {
	mem->Write<bool>(entity + m_bSpotted, isSpotted);
}*/