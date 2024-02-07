#pragma once

#include "../sacommon.hpp"
#include "../game/Bone.h"
#include "../game/Game.h"
#include "../utils/Random.h"

namespace SussyAim
{
	namespace Cfg
	{
		inline std::string dir;
		inline std::string dirSounds;
		inline int page = 0; // 0: Visual 1: Aimbot 2: Misc 3: Config
		inline int theme = 0;

		struct
			{
				ImVec2 LogoPos = ImVec2(30.f, 30.f);
				ImVec2 Logo2Pos = ImVec2(25.f, 25.f);
				ImVec2 Button1Pos = ImVec2(30.f, 142.f);
				ImVec2 Button2Pos = ImVec2(30.f, 142.f + 90.f);
				ImVec2 Button3Pos = ImVec2(30.f, 142.f + 180.f);
				ImVec2 Button4Pos = ImVec2(30.f, 142.f + 270.f);
				ImVec2 ChildPos = ImVec2(257.f, 20.f);
				ImVec2 ChildSize = ImVec2(574.f, 474.f);
				ImColor BorderColor_Yellow = ImColor(127, 18, 39, 200);
				ImColor BorderColor_Purple = ImColor(255, 0, 238, 255);
			} WCS; // Window Component Settings

		// namespace Visual
		// {
		// }

		namespace Aimbot {
			inline bool enabled = true;

			inline bool always = false;
			inline bool AimToggleMode = false;
			inline int AimbotHotKey = 0;
			inline int AimPosition = 0; // 0: head 1: neck 3: spine
			inline DWORD AimPositionIndex = BONEINDEX::head;
			inline bool VisibleCheck = true;

			inline bool RCS = true;
		}

		namespace Triggerbot {
			inline bool enabled = false;
			inline bool always = false;
			inline int hotkey = 0;
		}

		// namespace Misc {
		// }

		// namespace Config {
		// }

		namespace Menu
		{
			inline bool AirJump = false;
			inline float ComboWidth = 100.f;
			inline float SliderWidth = 150.f;
			// 0: Window 1: Collapse
			inline int WindowStyle = 0;

			
			inline bool Bhop = false;

			// inline int BoxType = 1;

			// 0: Vertical 1: Horizontal
			inline int HealthBarType = 0;

			inline ImColor FovCircleColor = ImColor(255, 255, 255, 200);

			inline bool ShowMenu = true;

			inline bool TeamCheck = true;

			inline bool ShowHeadShootLine = false;
			inline ImColor HeadShootLineColor = ImColor(255, 255, 255, 200);

			inline bool ShowFovLine = false;
			inline ImColor FovLineColor = ImColor(55, 55, 55, 220);
			inline float FovLineSize = 60.f;

			inline bool StreamProof = true;
			inline bool TargetingCrosshairs = false;

			inline ImColor ButtonBorderColor = ImColor(255, 204, 0, 255);
		}

		namespace ESP
		{
			inline bool enabled = true;

			inline bool drawName = true;

			inline bool drawBox = true;
			inline bool drawBoxOutline = true;
			inline float boxRounding = RandomPara<float>(0.0f, 0.0f);
			inline float boxAlpha = 0.35f;
			inline ImColor FrameColor = ImColor(10, 10, 10, 80);
			inline int boxType = 1; // 0: normal 1: dynamic 2: Flat

			inline bool drawBones = true;
			inline ImColor BoneColor = ImColor(0, 255, 255, 255);

			inline bool drawEyeRay = false;
			inline ImColor EyeRayColor = ImColor(255, 0, 0, 255);

			inline bool drawHeadBox = true;
			inline int HeadBoxStyle = 0;
			inline ImColor HeadBoxColor = ImColor(0, 255, 255, 255);

			inline bool drawDistance = false;

			inline bool drawWeapon = true;
			inline bool ammoBar = true;

			inline bool drawHealthBar = true;
			inline bool drawHealth = false;

			inline bool drawTracers = false;
			inline ImColor tracerColor = ImColor(255, 255, 255, 220);
			inline int tracerPos = 0; // 0: Top 1: Center 2: Bottom

			inline bool displayPreview = true;
			inline bool visibleCheck = true;
			inline bool FilledBox = false;
			inline bool FilledVisBox = false;
			inline bool MultiColor = false;
			// 0: normal 1: Flat

			inline ImColor VisibleColor = ImColor(255, 10, 20, 200);
			inline ImColor FilledColor = ImColor(255, 255, 255, 128);
			inline ImColor BoxFilledVisColor = ImColor(0, 0, 255, 255);
			inline ImColor FilledColor2 = ImColor(0, 255, 102, 255);

			inline bool DrawFov = true; // aimbot?
		}

		namespace DebuggerConfig
		{
			inline bool Debug = false;
		}

		namespace Crosshair
		{
			inline float CrossHairSize = 75;

			inline bool ShowCrossHair = true;
			inline bool drawDot = true;
			inline bool drawCrossline = true;
			inline bool tStyle = false;
			inline bool drawCircle = false;
			inline bool drawOutLine = true;
			inline bool DynamicGap = false;
			inline bool TeamCheck = true;

			inline int crosshairPreset = 0;
			inline int Gap = 8;
			inline int HorizontalLength = 6;
			inline int VerticalLength = 6;
			inline int Thickness = 1.0f;
			inline float DotSize = 1.0f;
			inline float CircleRadius = 3.f;

			inline bool isAim = false;
			inline bool isJump = false;

			inline ImColor CrossHairColor = ImColor(0, 255, 0, 255);
			inline ImColor TargetedColor = ImColor(255, 0, 0, 255);
		}

		namespace Radar
		{
			inline bool ShowRadar = false;
			inline float RadarRange = 150;
			inline float RadarPointSizeProportion = 1.f;
			inline bool ShowRadarCrossLine = false;
			inline ImColor RadarCrossLineColor = ImColor(220, 220, 220, 255);
			inline int RadarType = 2; // 0: circle 1: arrow 2: circle with arrow
			inline float Proportion = 3300.f;
			inline bool customRadar = false;
			inline float RadarBgAlpha = 0.1f;
		}

		namespace Misc
		{
			inline bool BunnyHop = false;
			inline bool WorkInSpec = true;
			inline bool NoFlash = false;
			inline bool WaterMark = false;
			inline bool CheatList = false;
			inline bool HitSound = false;
			inline bool SkinChanger = false;
			inline bool bombTimer = true;
			inline bool FastStop = false;
			inline bool SpecList = false;
			inline bool EnemySensor = false;
			inline bool RadarHack = false;
			inline bool MoneyService = false;
			inline bool ShowCashSpent = false;
			inline bool NoSmoke = false;
			inline bool SmokeColored = false;
			inline bool FireColored = false;
			inline bool FovHacker = false;
			inline int Fov = 90;
			inline ImColor BombTimerCol = ImColor(255, 120, 0, 255);
			inline ImColor SmokeColor = ImColor(255, 0, 0, 255);
			inline ImColor FireColor = ImColor(0, 255, 0, 255);

			inline bool Jitter = false;
		}
	}
}
