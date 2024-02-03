#pragma once
#include "Game.h"
#include "Entity.h"
#include "AimBot.hpp"
#include "Radar/Radar.h"
#include "TriggerBot.h"

#include "Features/Glow.h"
#include "Features/Misc.h"

namespace Menu
{
	void KeyCheckThread();

	void RenderCrossHair(ImDrawList* drawList) noexcept;

	void RadarSetting(Base_Radar& Radar);
	void Init();
}

struct {
	ImFont* normal15px = nullptr;
} fonts;