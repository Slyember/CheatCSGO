#pragma once

struct GlowStruct
{
	uintptr_t Base;
	float r;
	float g;
	float b;
	float a;
	uint8_t padding[16];
	bool RenderOccluded;
	bool RenderUnoccluded;
	bool FullBloom;
	uint8_t padding2[14];
};
