#pragma once

#include "methods.hpp"

using namespace SussyAim::view;

namespace SussyAim
{
	namespace view
	{
		namespace visual
		{
			void render()
			{
				ImGui::Columns(2, nullptr, false);
				// ImGui::SetCursorPos(ImVec2(15.f, 24.f));
				ImGui::SeparatorText(ICON_FA_EYE " ESP");
				float MinRounding = 0.f, MaxRouding = 5.f;
				int MinCombo = 0, MaxCombo = 2;
				PutSwitch(Lang::ESPtext.Toggle, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::enabled);
				if (SussyAim::Cfg::ESP::enabled)
				{
					const char *BoxTypes[] = {Lang::ESPtext.BoxType_Normal, Lang::ESPtext.BoxType_Edge, Lang::ESPtext.BoxType_Corner};
					const char *LinePos[] = {Lang::ESPtext.LinePos_1, Lang::ESPtext.LinePos_2, Lang::ESPtext.LinePos_3};
					PutSwitch(Lang::ESPtext.Box, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::drawBox, true, "###BoxCol", reinterpret_cast<float *>(&SussyAim::Cfg::ESP::FrameColor));
					if (SussyAim::Cfg::ESP::drawBox)
					{
						PutSwitch(Lang::ESPtext.Outline, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::drawBoxOutline);
						PutSliderInt(Lang::ESPtext.BoxType, 10.f, &SussyAim::Cfg::ESP::boxType, &MinCombo, &MaxCombo, BoxTypes[SussyAim::Cfg::ESP::boxType]);
						PutSliderFloat(Lang::ESPtext.BoxRounding, 10.f, &SussyAim::Cfg::ESP::boxRounding, &MinRounding, &MaxRouding, "%.1f");
					}
					PutSwitch(Lang::ESPtext.FilledBox, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::FilledBox, true, "###FilledBoxCol", reinterpret_cast<float *>(&SussyAim::Cfg::ESP::FilledColor));
					if (SussyAim::Cfg::ESP::FilledBox)
						PutSwitch(Lang::ESPtext.MultiColor, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::MultiColor, true, "###MultiCol", reinterpret_cast<float *>(&SussyAim::Cfg::ESP::FilledColor2));
					PutSwitch(Lang::ESPtext.HeadBox, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::drawHeadBox, true, "###HeadBoxCol", reinterpret_cast<float *>(&SussyAim::Cfg::ESP::HeadBoxColor));
					PutSwitch(Lang::ESPtext.Skeleton, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::drawBones, true, "###BoneCol", reinterpret_cast<float *>(&SussyAim::Cfg::ESP::BoneColor));
					PutSwitch(Lang::ESPtext.SnapLine, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::drawTracers, true, "###LineCol", reinterpret_cast<float *>(&SussyAim::Cfg::ESP::tracerColor));
					if (SussyAim::Cfg::ESP::drawTracers)
						PutSliderInt(Lang::ESPtext.LinePosList, 10.f, &SussyAim::Cfg::ESP::tracerPos, &MinCombo, &MaxCombo, LinePos[SussyAim::Cfg::ESP::tracerPos]);
					PutSwitch(Lang::ESPtext.EyeRay, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::drawEyeRay, true, "###LineCol", reinterpret_cast<float *>(&SussyAim::Cfg::ESP::EyeRayColor));
					PutSwitch(Lang::ESPtext.HealthBar, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::drawHealthBar);
					PutSwitch(Lang::ESPtext.HealthNum, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::drawHealth);
					PutSwitch(Lang::ESPtext.Weapon, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::drawWeapon);
					PutSwitch(Lang::ESPtext.Ammo, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::ammoBar);
					PutSwitch(Lang::ESPtext.Distance, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::drawDistance);
					PutSwitch(Lang::ESPtext.PlayerName, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::drawName);
					PutSwitch(Lang::ESPtext.ShowScoped, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::showScoped);
					PutSwitch(Lang::ESPtext.VisCheck, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::visibleCheck, true, "###VisibleCol", reinterpret_cast<float *>(&SussyAim::Cfg::ESP::VisibleColor));
				}

				ImGui::NextColumn();
				// ImGui::SetCursorPosY(24.f);
				ImGui::SeparatorText(ICON_FA_DOT_CIRCLE " Crosshairs");
				float DotMin = 1.f, DotMax = 50.f;
				int LengthMin = 1, LengthMax = 100;
				int GapMin = 1, GapMax = 50;
				int ThickMin = 1, ThickMax = 20;
				float CircleRmin = 1.f, CircleRmax = 50.f;
				PutSwitch(Lang::CrosshairsText.Toggle, 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Crosshair::ShowCrossHair, true, "###CrosshairsCol", reinterpret_cast<float *>(&SussyAim::Cfg::Crosshair::CrossHairColor));
				if (SussyAim::Cfg::Crosshair::ShowCrossHair)
				{
					PutSwitch(Lang::CrosshairsText.Dot, 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Crosshair::drawDot);
					if (SussyAim::Cfg::Crosshair::drawDot)
						PutSliderFloat(Lang::CrosshairsText.DotSizeSlider, 5.f, &SussyAim::Cfg::Crosshair::DotSize, &DotMin, &DotMax, "%.f px");
					PutSwitch(Lang::CrosshairsText.Outline, 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Crosshair::drawOutLine);
					PutSwitch(Lang::CrosshairsText.Crossline, 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Crosshair::drawCrossline);
					if (SussyAim::Cfg::Crosshair::drawCrossline)
					{
						PutSliderInt(Lang::CrosshairsText.hLengthSlider, 5.f, &SussyAim::Cfg::Crosshair::HorizontalLength, &LengthMin, &LengthMax, "%d px");
						PutSliderInt(Lang::CrosshairsText.vLengthSilder, 5.f, &SussyAim::Cfg::Crosshair::VerticalLength, &LengthMin, &LengthMax, "%d px");
						PutSliderInt(Lang::CrosshairsText.GapSlider, 5.f, &SussyAim::Cfg::Crosshair::Gap, &GapMin, &GapMax, "%d px");
						PutSliderInt(Lang::CrosshairsText.ThicknessSlider, 5.f, &SussyAim::Cfg::Crosshair::Thickness, &ThickMin, &ThickMax, "%d px");
					}
					PutSwitch(Lang::CrosshairsText.tStyle, 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Crosshair::tStyle);
					PutSwitch(Lang::CrosshairsText.Circle, 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Crosshair::drawCircle);
					if (SussyAim::Cfg::Crosshair::drawCircle)
						PutSliderFloat(Lang::CrosshairsText.RadiusSlider, 5.f, &SussyAim::Cfg::Crosshair::CircleRadius, &CircleRmin, &CircleRmax, "%.f px");
					PutSwitch(Lang::CrosshairsText.TargetCheck, 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Menu::TargetingCrosshairs, true, "###CircleCol", reinterpret_cast<float *>(&SussyAim::Cfg::Crosshair::TargetedColor));
					PutSwitch(Lang::CrosshairsText.TeamCheck, 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Crosshair::TeamCheck);
				}

				ImGui::Columns(1);
			}
		}
	}
}
