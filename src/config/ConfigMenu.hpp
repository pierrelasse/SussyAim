#pragma once

#include "../sacommon.hpp"
#include "Config.hpp"
#include "ConfigSaver.hpp"
#include "../rendering/Resources/Language.h"

namespace ConfigMenu
{
	void ResetToDefault()
	{
		// SussyAim::Cfg::Misc::SmokeColored = false;
		// SussyAim::Cfg::Misc::SmokeColor = ImColor(255, 0, 0, 255);
		// SussyAim::Cfg::Misc::NoSmoke = false;
		// SussyAim::Cfg::Misc::Jitter = false;
		// SussyAim::Cfg::ESP::ammoBar = true;
		// SussyAim::Cfg::ESP::drawBoxOutline = true;
		// SussyAim::Cfg::ESP::drawHealth = false;
		// SussyAim::Cfg::ESP::FilledColor = ImColor(255, 255, 255, 255);
		// SussyAim::Cfg::ESP::FilledColor2 = ImColor(255, 255, 255, 255);
		// SussyAim::Cfg::ESP::MultiColor = false;
		// SussyAim::Cfg::ESP::BoxFilledVisColor = ImColor(0, 0, 255, 255);
		// SussyAim::Cfg::ESP::FilledVisBox = false;
		// SussyAim::Cfg::Misc::MoneyService = false;
		// SussyAim::Cfg::Misc::ShowCashSpent = false;
		// SussyAim::Cfg::Misc::fovChanger = false;
		// SussyAim::Cfg::Misc::RadarHack = false;
		// SussyAim::Cfg::Misc::SpecList = false;
		// SussyAim::Cfg::Misc::BombTimerCol = ImColor(255, 120, 0, 255);
		// SussyAim::Cfg::Misc::bombTimer = false;
		// SussyAim::Cfg::ESP::VisibleColor = ImColor(255, 196, 0, 255);
		// SussyAim::Cfg::ESP::visibleCheck = false;
		// SussyAim::Cfg::Misc::EnemySensor = false;
		// SussyAim::Cfg::Menu::AirJump = false;
		// SussyAim::Cfg::theme = 0;
		// SussyAim::Cfg::Menu::WindowStyle = 0;
		// SussyAim::Cfg::ESP::boxAlpha = 0.0f;
		// SussyAim::Cfg::ESP::displayPreview = true;
		// SussyAim::Cfg::ESP::drawHeadBox = true;
		// SussyAim::Cfg::ESP::HeadBoxStyle = 0;
		// SussyAim::Cfg::ESP::HeadBoxColor = ImColor(255, 255, 255, 255);
		// SussyAim::Cfg::ESP::drawDistance = false;
		// SussyAim::Cfg::ESP::drawBones = true;
		// SussyAim::Cfg::ESP::drawBox = true;
		// SussyAim::Cfg::ESP::drawHealthBar = true;
		// SussyAim::Cfg::ESP::drawWeapon = true;
		// SussyAim::Cfg::ESP::drawEyeRay = false;
		// SussyAim::Cfg::ESP::drawName = true;
		// SussyAim::Cfg::ESP::boxRounding = 0.0f;
		// SussyAim::Cfg::Aimbot::enabled = false;
		// SussyAim::Cfg::Menu::AimAlways = false;
		// SussyAim::Cfg::Menu::AimToggleMode = false;
		// SussyAim::Cfg::Menu::AimPosition = 0;
		// SussyAim::Cfg::Menu::AimPositionIndex = BONEINDEX::head;
		// SussyAim::Cfg::Menu::BoxType = 0;
		// SussyAim::Cfg::Menu::HealthBarType = 0;
		// SussyAim::Cfg::ESP::BoneColor = ImColor(0, 255, 255, 255);
		// SussyAim::Cfg::ESP::FrameColor = ImColor(255, 80, 0, 255);
		// SussyAim::Cfg::ESP::EyeRayColor = ImVec4(255, 0, 0, 255);
		// SussyAim::Cfg::Menu::ShowMenu = true;
		// RadarCFG::ShowRadar = false;
		// RadarCFG::RadarRange = 150;
		// RadarCFG::ShowRadarCrossLine = true;
		// RadarCFG::RadarCrossLineColor = ImColor(220, 220, 220, 255);
		// RadarCFG::RadarType = 2;
		// RadarCFG::RadarPointSizeProportion = 1.f;
		// RadarCFG::RadarBgAlpha = 0.1f;
		// RadarCFG::Proportion = 3300;
		// SussyAim::Cfg::Menu::Triggerbot = false;
		// SussyAim::Cfg::Menu::TriggerAlways = false;
		// SussyAim::Cfg::Menu::TeamCheck = true;
		// SussyAim::Cfg::Menu::StreamProof = true;
		// SussyAim::Cfg::Menu::VisibleCheck = true;
		// SussyAim::Cfg::Menu::ShowHeadShootLine = false;
		// SussyAim::Cfg::Menu::HeadShootLineColor = ImColor(255, 255, 255, 200);
		// SussyAim::Cfg::Menu::AimbotHotKey = 0;
		// AimControl::SetHotKey(SussyAim::Cfg::Menu::AimbotHotKey);
		// SussyAim::Cfg::ESP::drawTracers = false;
		// SussyAim::Cfg::Menu::FovLineSize = 60.0f;
		// Triggerbot::TriggerDelay = 90;
		// Triggerbot::FakeShotDelay = 500;
		// RCS::RCSBullet = 1;
		// SussyAim::Cfg::Menu::TriggerHotKey = 0;
		// Triggerbot::SetHotKey(SussyAim::Cfg::Menu::TriggerHotKey);
		// AimControl::RCSScale = ImVec2(1.2f, 1.4f);
		// AimControl::ScopeOnly = false;
		// SussyAim::Cfg::Menu::FovLineColor = ImVec4(55, 55, 55, 220);
		// SussyAim::Cfg::ESP::tracerColor = ImVec4(255, 255, 255, 220);
		// CrosshairsCFG::ShowCrossHair = true;
		// CrosshairsCFG::CrossHairColor = ImColor(0, 255, 0, 255);
		// CrosshairsCFG::CrossHairSize = 75;
		// CrosshairsCFG::drawDot = true;
		// CrosshairsCFG::tStyle = false;
		// CrosshairsCFG::HorizontalLength = 6;
		// CrosshairsCFG::VerticalLength = 6;
		// CrosshairsCFG::drawOutLine = true;
		// CrosshairsCFG::Gap = 8;
		// CrosshairsCFG::drawCrossline = true;
		// CrosshairsCFG::drawCircle = false;
		// SussyAim::Cfg::Menu::TargetingCrosshairs = false;
		// CrosshairsCFG::TargetedColor = ImColor(255, 0, 0, 255);
		// CrosshairsCFG::CircleRadius = 3.f;
		// CrosshairsCFG::DynamicGap = false;
		// CrosshairsCFG::DotSize = 1.0f;
		// CrosshairsCFG::Thickness = 1;
		// CrosshairsCFG::TeamCheck = true;
		// SussyAim::Cfg::Misc::BunnyHop = false;
		// SussyAim::Cfg::Misc::WorkInSpec = true;
		// SussyAim::Cfg::Misc::NoFlash = false;
		// SussyAim::Cfg::Misc::WaterMark = false;
		// SussyAim::Cfg::Misc::HitSound = false;
		// SussyAim::Cfg::Misc::FastStop = false;

		// SussyAim::Cfg::ESP::enabled = false;
		// SussyAim::Cfg::ESP::DrawFov = true;
		// SussyAim::Cfg::Menu::FovCircleColor = ImColor(255, 255, 255, 255);
	}
}
