#pragma once

#include "../config/Config.hpp"
#include "../rendering/renderer.hpp"
#include "Aimbot.hpp"
#include "Triggerbot.hpp"
#include "../config/ConfigMenu.hpp"
#include "../config/ConfigSaver.hpp"

#include "StyleChanger.h"
#include "../rendering/Resources/Images.h"

ID3D11ShaderResourceView *AS_Logo = NULL;
ID3D11ShaderResourceView *MenuButton1 = NULL;
ID3D11ShaderResourceView *MenuButton2 = NULL;
ID3D11ShaderResourceView *MenuButton3 = NULL;
ID3D11ShaderResourceView *MenuButton4 = NULL;
int LogoW = 0, LogoH = 0;
int LogoW2 = 0, LogoH2 = 0;
int buttonW = 0;
int buttonH = 0;

namespace ViewMenu
{
	void LoadImages()
	{
		if (AS_Logo == NULL)
		{
			std::cout << "[GUI] Loading images" << std::endl;
			Gui.LoadTextureFromMemory(Images::Logo, sizeof Images::Logo, &AS_Logo, &LogoW, &LogoH);
			Gui.LoadTextureFromMemory(Images::TabVisual, sizeof Images::TabVisual, &MenuButton1, &buttonW, &buttonH);
			Gui.LoadTextureFromMemory(Images::TabAimbot, sizeof Images::TabAimbot, &MenuButton2, &buttonW, &buttonH);
			Gui.LoadTextureFromMemory(Images::TabMisc, sizeof Images::TabMisc, &MenuButton3, &buttonW, &buttonH);
			Gui.LoadTextureFromMemory(Images::TabConfig, sizeof Images::TabConfig, &MenuButton4, &buttonW, &buttonH);
		}
	}

	// Components Settings
	// ########################################
	void AlignRight(float ContentWidth)
	{
		float ColumnContentWidth = ImGui::GetColumnWidth() - ImGui::GetStyle().ItemSpacing.x;
		float checkboxPosX = ImGui::GetColumnOffset() + ColumnContentWidth - ContentWidth;
		ImGui::SetCursorPosX(checkboxPosX);
	}
	void PutSwitch(const char *string, float CursorX, float ContentWidth, bool *v, bool ColorEditor = false, const char *lable = NULL, float col[4] = NULL, const char *Tip = NULL)
	{
		ImGui::PushID(string);
		float CurrentCursorX = ImGui::GetCursorPosX();
		ImGui::SetCursorPosX(CurrentCursorX + CursorX);
		ImGui::TextDisabled(string);
		if (Tip && ImGui::IsItemHovered())
			ImGui::SetTooltip(Tip);
		ImGui::SameLine();
		if (ColorEditor)
		{
			AlignRight(ContentWidth + ImGui::GetFrameHeight() + 8);
			ImGui::ColorEdit4(lable, col, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_AlphaPreview);
			ImGui::SameLine();
		}
		else
		{
			AlignRight(ContentWidth);
		}

		Gui.SwitchButton(string, v);
		ImGui::PopID();
	}
	void PutColorEditor(const char *text, const char *lable, float CursorX, float ContentWidth, float col[4], const char *Tip = NULL)
	{
		ImGui::PushID(text);
		float CurrentCursorX = ImGui::GetCursorPosX();
		ImGui::SetCursorPosX(CurrentCursorX + CursorX);
		ImGui::TextDisabled(text);
		if (Tip && ImGui::IsItemHovered())
			ImGui::SetTooltip(Tip);
		ImGui::SameLine();
		AlignRight(ContentWidth + ImGui::GetFrameHeight() + 8);
		ImGui::ColorEdit4(lable, col, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_AlphaPreview);
		ImGui::PopID();
	}
	void PutSliderFloat(const char *string, float CursorX, float *v, const void *p_min, const void *p_max, const char *format)
	{
		// if there is no fucking ID, all the sliders would be fucking forced to sync when you click on one of them ;3
		ImGui::PushID(string);
		float CurrentCursorX = ImGui::GetCursorPosX();
		float SliderWidth = ImGui::GetColumnWidth() - ImGui::GetStyle().ItemSpacing.x - CursorX;
		ImGui::SetCursorPosX(CurrentCursorX + CursorX);
		ImGui::TextDisabled(string);
		ImGui::SameLine();
		ImGui::TextDisabled(format, *v);
		ImGui::SetCursorPosX(CurrentCursorX + CursorX);
		ImGui::SetNextItemWidth(SliderWidth);
		Gui.SliderScalarEx2("", ImGuiDataType_Float, v, p_min, p_max, "", ImGuiSliderFlags_None);
		ImGui::PopID();
	}
	void PutSliderInt(const char *string, float CursorX, int *v, const void *p_min, const void *p_max, const char *format)
	{
		ImGui::PushID(string);
		float CurrentCursorX = ImGui::GetCursorPosX();
		float SliderWidth = ImGui::GetColumnWidth() - ImGui::GetStyle().ItemSpacing.x - CursorX;
		ImGui::SetCursorPosX(CurrentCursorX + CursorX);
		ImGui::TextDisabled(string);
		ImGui::SameLine();
		ImGui::TextDisabled(format, *v);
		ImGui::SetCursorPosX(CurrentCursorX + CursorX);
		ImGui::SetNextItemWidth(SliderWidth);
		Gui.SliderScalarEx2("", ImGuiDataType_Float, v, p_min, p_max, "", ImGuiSliderFlags_None);
		ImGui::PopID();
	}

	void Render()
	{
		LoadImages();

		ImTextureID ImageID;
		ImVec2 LogoSize, LogoPos;
		ImageID = (void *)AS_Logo;
		LogoSize = ImVec2(LogoW, LogoH);
		LogoPos = SussyAim::Cfg::WCS.LogoPos;
		SussyAim::Cfg::Menu::ButtonBorderColor = SussyAim::Cfg::WCS.BorderColor_Yellow;

		ImColor BorderColor = SussyAim::Cfg::Menu::ButtonBorderColor;

		char TempText[256];
		ImGuiWindowFlags Flags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar;
		ImGui::SetNextWindowPos({(ImGui::GetIO().DisplaySize.x - 851.0f) / 2.0f, (ImGui::GetIO().DisplaySize.y - 514.0f) / 2.0f}, ImGuiCond_Once);
		ImGui::SetNextWindowSize({851, 514});
		ImGui::Begin("main", nullptr, Flags);
		{
			{
				static const ImVec4 nothingColor = ImVec4(0, 0, 0, 0);
				ImGui::PushStyleColor(ImGuiCol_Button, nothingColor);
				ImGui::PushStyleColor(ImGuiCol_ButtonHovered, nothingColor);
				ImGui::PushStyleColor(ImGuiCol_ButtonActive, nothingColor);
				ImGui::PushStyleColor(ImGuiCol_Border, nothingColor);
				if (ImGui::Button("[Quit]"))
				{
					std::cout << "[YourMom] Quitting..." << std::endl;
					Gui.Quit();
				}
				ImGui::PopStyleColor(4);
			}

			ImGui::SetCursorPos(LogoPos);
			ImGui::Image(ImageID, LogoSize);

			ImGui::SetCursorPos(SussyAim::Cfg::WCS.Button1Pos);
			ImGui::Image((void *)MenuButton1, ImVec2(buttonW, buttonH));
			if (ImGui::IsItemClicked())
			{
				SussyAim::Cfg::page = 0;
			}
			ImGui::GetWindowDrawList()->AddRect(
				ImVec2(SussyAim::Cfg::WCS.Button1Pos.x + ImGui::GetWindowPos().x, SussyAim::Cfg::WCS.Button1Pos.y + ImGui::GetWindowPos().y),
				ImVec2(SussyAim::Cfg::WCS.Button1Pos.x + buttonW + ImGui::GetWindowPos().x, SussyAim::Cfg::WCS.Button1Pos.y + buttonH + ImGui::GetWindowPos().y),
				BorderColor, 9.f, ImDrawFlags_RoundCornersAll, 2.f);

			ImGui::SetCursorPos(SussyAim::Cfg::WCS.Button2Pos);
			ImGui::Image((void *)MenuButton2, ImVec2(buttonW, buttonH));
			if (ImGui::IsItemClicked())
			{
				SussyAim::Cfg::page = 1;
			}
			ImGui::GetWindowDrawList()->AddRect(
				ImVec2(SussyAim::Cfg::WCS.Button2Pos.x + ImGui::GetWindowPos().x, SussyAim::Cfg::WCS.Button2Pos.y + ImGui::GetWindowPos().y),
				ImVec2(SussyAim::Cfg::WCS.Button2Pos.x + buttonW + ImGui::GetWindowPos().x, SussyAim::Cfg::WCS.Button2Pos.y + buttonH + ImGui::GetWindowPos().y),
				BorderColor, 9.f, ImDrawFlags_RoundCornersAll, 2.f);

			ImGui::SetCursorPos(SussyAim::Cfg::WCS.Button3Pos);
			ImGui::Image((void *)MenuButton3, ImVec2(buttonW, buttonH));
			if (ImGui::IsItemClicked())
			{
				SussyAim::Cfg::page = 2;
			}
			ImGui::GetWindowDrawList()->AddRect(
				ImVec2(SussyAim::Cfg::WCS.Button3Pos.x + ImGui::GetWindowPos().x, SussyAim::Cfg::WCS.Button3Pos.y + ImGui::GetWindowPos().y),
				ImVec2(SussyAim::Cfg::WCS.Button3Pos.x + buttonW + ImGui::GetWindowPos().x, SussyAim::Cfg::WCS.Button3Pos.y + buttonH + ImGui::GetWindowPos().y),
				BorderColor, 9.f, ImDrawFlags_RoundCornersAll, 2.f);

			ImGui::SetCursorPos(SussyAim::Cfg::WCS.Button4Pos);
			ImGui::Image((void *)MenuButton4, ImVec2(buttonW, buttonH));
			if (ImGui::IsItemClicked())
			{
				SussyAim::Cfg::page = 3;
			}
			ImGui::GetWindowDrawList()->AddRect(
				ImVec2(SussyAim::Cfg::WCS.Button4Pos.x + ImGui::GetWindowPos().x, SussyAim::Cfg::WCS.Button4Pos.y + ImGui::GetWindowPos().y),
				ImVec2(SussyAim::Cfg::WCS.Button4Pos.x + buttonW + ImGui::GetWindowPos().x, SussyAim::Cfg::WCS.Button4Pos.y + buttonH + ImGui::GetWindowPos().y),
				BorderColor, 9.f, ImDrawFlags_RoundCornersAll, 2.f);

			ImGui::SetCursorPos(SussyAim::Cfg::WCS.ChildPos);

			ImGui::BeginChild("Page", SussyAim::Cfg::WCS.ChildSize);
			{
				// Visual
				if (SussyAim::Cfg::page == 0)
				{
					ImGui::Columns(2, nullptr, false);
					ImGui::SetCursorPos(ImVec2(15.f, 24.f));
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
					ImGui::SetCursorPosY(24.f);
					ImGui::SeparatorText(ICON_FA_GRIN_ALT " ESP Preview");
					// ESP::RenderPreview({ ImGui::GetColumnWidth(), ImGui::GetCursorPosY() }, { ImGui::GetCursorPosX() - ImGui::GetColumnWidth() * 0.65f, ImGui::GetCursorPosY() - ImGui::GetFrameHeight() });
					SussyAim::Features::ESP::RenderPreview({ImGui::GetColumnWidth(), ImGui::GetCursorPosY()});
					// :P
					ImGui::NewLine();
					ImGui::NewLine();
					ImGui::NewLine();
					ImGui::NewLine();
					ImGui::NewLine();
					ImGui::NewLine();
					ImGui::NewLine();
					ImGui::NewLine();
					ImGui::NewLine();
					//

					// ImGui::SeparatorText(ICON_FA_COMPASS" External Radar");
					// float RadarPointSizeProportionMin = 0.8f, RadarPointSizeProportionMax = 2.f;
					// float ProportionMin = 500.f, ProportionMax = 3300.f;
					// float RadarRangeMin = 100.f, RadarRangeMax = 300.f;
					// float AlphaMin = 0.f, AlphaMax = 1.f;
					// PutSwitch(Lang::RadarText.Toggle, 5.f, ImGui::GetFrameHeight() * 1.7, &RadarCFG::ShowRadar);
					// if (RadarCFG::ShowRadar)
					// {
					// 	PutSwitch(Lang::RadarText.CustomCheck, 5.f, ImGui::GetFrameHeight() * 1.7, &RadarCFG::customRadar);
					// 	if (RadarCFG::customRadar)
					// 	{
					// 		PutSliderFloat(Lang::RadarText.SizeSlider, 5.f, &RadarCFG::RadarPointSizeProportion, &RadarPointSizeProportionMin, &RadarPointSizeProportionMax, "%1.f");
					// 		PutSliderFloat(Lang::RadarText.ProportionSlider, 5.f, &RadarCFG::Proportion, &ProportionMin, &ProportionMax, "%.1f");
					// 		PutSliderFloat(Lang::RadarText.RangeSlider, 5.f, &RadarCFG::RadarRange, &RadarRangeMin, &RadarRangeMax, "%.1f");
					// 		PutSliderFloat(Lang::RadarText.AlphaSlider, 5.f, &RadarCFG::RadarBgAlpha, &AlphaMin, &AlphaMax, "%.1f");
					// 	}
					// }

					ImGui::NewLine();
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

				// Aimbot
				else if (SussyAim::Cfg::page == 1)
				{
					ImGui::Columns(2, nullptr, false);
					ImGui::SetCursorPos(ImVec2(15.f, 24.f));
					ImGui::SeparatorText(ICON_FA_USER " Aimbot");
					float FovMin = 0.f, FovMax = 50.f;
					float SmoothMin = 0.f, SmoothMax = 5.f;
					PutSwitch(Lang::AimbotText.Enable, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Aimbot::enabled);
					if (SussyAim::Cfg::Aimbot::enabled)
					{
						ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10.f);
						ImGui::TextDisabled(Lang::AimbotText.HotKeyList);
						ImGui::SameLine();
						if (ImGui::Combo("###AimKey", &SussyAim::Cfg::Aimbot::AimbotHotKey, "LALT\0LBUTTON\0RBUTTON\0XBUTTON1\0XBUTTON2\0CAPITAL\0SHIFT\0CONTROL\0MouseForward\0"))
						{
							ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10.f);
							ImGui::TextDisabled(Lang::AimbotText.HotKeyList);
							ImGui::SameLine();
							if (ImGui::Combo("###AimKey", &SussyAim::Cfg::Aimbot::AimbotHotKey, "LALT\0LBUTTON\0RBUTTON\0XBUTTON1\0XBUTTON2\0CAPITAL\0SHIFT\0CONTROL\0"))
							{
								SussyAim::Features::Aimbot::SetHotKey(SussyAim::Cfg::Aimbot::AimbotHotKey);
							}
							PutSwitch(Lang::AimbotText.Toggle, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Aimbot::AimToggleMode);
						}
						PutSwitch(Lang::AimbotText.AimLock, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Aimbot::always);
						PutSwitch(Lang::AimbotText.DrawFov, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::DrawFov, true, "###FOVcol", reinterpret_cast<float *>(&SussyAim::Cfg::Menu::FovCircleColor));
						PutSwitch(Lang::AimbotText.VisCheck, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Aimbot::VisibleCheck);
						PutSwitch(Lang::AimbotText.ScopeOnly, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Features::Aimbot::ScopeOnly);
						PutSliderFloat(Lang::AimbotText.FovSlider, 10.f, &SussyAim::Features::Aimbot::AimFov, &FovMin, &FovMax, "%.1f");
						PutSliderFloat(Lang::AimbotText.SmoothSlider, 10.f, &SussyAim::Features::Aimbot::Smooth, &SmoothMin, &SmoothMax, "%.1f");
						ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10.f);
						ImGui::TextDisabled(Lang::AimbotText.BoneList);
						ImGui::SameLine();
						if (ImGui::Combo("###AimPos", &SussyAim::Cfg::Aimbot::AimPosition, "Head\0Neck\0Chest\0Penis\0"))
						{
							switch (SussyAim::Cfg::Aimbot::AimPosition)
							{
							case 0:
								SussyAim::Cfg::Aimbot::AimPositionIndex = BONEINDEX::head;
								break;
							case 1:
								SussyAim::Cfg::Aimbot::AimPositionIndex = BONEINDEX::neck_0;
								break;
							case 2:
								SussyAim::Cfg::Aimbot::AimPositionIndex = BONEINDEX::spine_1;
								break;
							case 3:
								SussyAim::Cfg::Aimbot::AimPositionIndex = BONEINDEX::pelvis;
								break;
							default:
								break;
							}
						}
					}
					ImGui::NextColumn();
					ImGui::SetCursorPosY(24.f);
					ImGui::SeparatorText(ICON_FA_ARROW_ALT_CIRCLE_DOWN " RCS");
					PutSwitch("Enable RCS", 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Aimbot::RCS);

					ImGui::NewLine();
					ImGui::SeparatorText(ICON_FA_HAND_POINTER " Triggerbot");
					int DelayMin = 10, DelayMax = 1000;
					int DurationMin = 0, DurationMax = 1000;
					PutSwitch(Lang::TriggerText.Enable, 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Triggerbot::enabled);
					if (SussyAim::Cfg::Triggerbot::enabled)
					{
						if (!SussyAim::Cfg::Triggerbot::always)
						{
							ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5.f);
							ImGui::TextDisabled(Lang::TriggerText.HotKeyList);
							ImGui::SameLine();
							if (ImGui::Combo("###TriggerbotKey", &SussyAim::Cfg::Triggerbot::hotkey, "LALT\0RBUTTON\0XBUTTON1\0XBUTTON2\0CAPITAL\0SHIFT\0CONTROL\0"))
							{
								SussyAim::Features::Triggerbot::SetHotKey(SussyAim::Cfg::Triggerbot::hotkey);
							}
						}
						PutSwitch(Lang::TriggerText.Toggle, 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Triggerbot::always);
						PutSliderInt(Lang::TriggerText.DelaySlider, 5.f, &SussyAim::Features::Triggerbot::TriggerDelay, &DelayMin, &DelayMax, "%d ms");
						PutSliderInt(Lang::TriggerText.FakeShotSlider, 5.f, &SussyAim::Features::Triggerbot::FakeShotDelay, &DurationMin, &DurationMax, "%d ms");
					}

					ImGui::Columns(1);
				}

				// Misc
				else if (SussyAim::Cfg::page == 2)
				{
					int FovMin = 60, FovMax = 140;

					ImGui::Columns(2, nullptr, false);
					ImGui::SetCursorPos(ImVec2(15.f, 24.f));
					ImGui::SeparatorText(ICON_FA_SUN " Misc");

					PutSwitch(Lang::MiscText.HeadshotLine, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Menu::ShowHeadShootLine);
					PutSwitch(Lang::MiscText.SpecCheck, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::WorkInSpec);
					PutSliderInt(Lang::MiscText.fovChanger, 10.f, &SussyAim::Cfg::Misc::Fov, &FovMin, &FovMax, "%d");
					PutSwitch(Lang::MiscText.NoFlash, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::NoFlash);
					PutSwitch(Lang::MiscText.FastStop, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::FastStop);
					PutSwitch(Lang::MiscText.NoSmoke, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::NoSmoke);
					PutSwitch(Lang::MiscText.SmokeColor, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::SmokeColored, true, "###SmokeColor", reinterpret_cast<float *>(&SussyAim::Cfg::Misc::SmokeColor));
					PutSwitch(Lang::MiscText.HitSound, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::HitSound);
					PutSwitch(Lang::MiscText.bmbTimer, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::bombTimer, true, "###bmbTimerCol", reinterpret_cast<float *>(&SussyAim::Cfg::Misc::BombTimerCol));
					PutSwitch(Lang::MiscText.Bhop, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::BunnyHop);
					// PutSwitch(Lang::MiscText.SpecList, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::SpecList);
					PutSwitch(Lang::MiscText.RadarHack, 10.f, ImGui::GetFrameHeight() * 1.7f, &SussyAim::Cfg::Misc::RadarHack);
					if (SussyAim::Cfg::Misc::RadarHack)
					{
						ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10.f);
						ImGui::TextColored(ImColor(255, 50, 0, 255), Lang::MiscText.VisCheckDisable);
					}
					PutSwitch(Lang::MiscText.MoneyService, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::MoneyService);
					if (SussyAim::Cfg::Misc::MoneyService)
						PutSwitch(Lang::MiscText.ShowCashSpent, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::ShowCashSpent);
					PutSwitch(Lang::MiscText.EnemySensor, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::EnemySensor);
					PutSwitch(Lang::MiscText.Watermark, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::WaterMark);
					PutSwitch(Lang::MiscText.TeamCheck, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Menu::TeamCheck);

					ImGui::NewLine();
					ImGui::SeparatorText(ICON_FA_FUTBOL " Fun");
					PutSwitch(Lang::MiscText.FakeDuck, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::Jitter);
					if (SussyAim::Cfg::Misc::Jitter)
					{
						ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10.f);
						ImGui::TextColored(ImColor(255, 50, 0, 255), "This might cause BAN");
					}

					ImGui::NextColumn();
					ImGui::SetCursorPosY(24.f);
					ImGui::SeparatorText(ICON_FA_HEART " Menu Settings");
					PutSwitch(Lang::MiscText.AntiRecord, 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Menu::StreamProof);
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5.f);
					ImGui::TextDisabled(Lang::MiscText.ThemeList);
					ImGui::SameLine();
					if (ImGui::Combo("###Theme", &SussyAim::Cfg::theme, "Standard\0Custom\0"))
						StyleChanger::UpdateSkin(SussyAim::Cfg::theme);
					if (SussyAim::Cfg::theme == 1)
					{
						ImColor windowBgColor = ImGui::GetStyleColorVec4(ImGuiCol_WindowBg);
						ImColor borderColor = ImGui::GetStyleColorVec4(ImGuiCol_Border);
						ImColor childBgColor = ImGui::GetStyleColorVec4(ImGuiCol_ChildBg);
						ImColor ButtonColor = ImGui::GetStyleColorVec4(ImGuiCol_Button);
						ImColor ButtonHovered = ImGui::GetStyleColorVec4(ImGuiCol_ButtonHovered);
						ImColor ButtonActive = ImGui::GetStyleColorVec4(ImGuiCol_ButtonActive);
						ImColor FrameBgColor = ImGui::GetStyleColorVec4(ImGuiCol_FrameBg);
						ImColor FrameHovered = ImGui::GetStyleColorVec4(ImGuiCol_FrameBgHovered);
						ImColor FrameActive = ImGui::GetStyleColorVec4(ImGuiCol_FrameBgActive);
						ImColor Header = ImGui::GetStyleColorVec4(ImGuiCol_Header);
						ImColor HeaderActive = ImGui::GetStyleColorVec4(ImGuiCol_HeaderActive);
						ImColor HeaderHovered = ImGui::GetStyleColorVec4(ImGuiCol_HeaderHovered);
						ImColor ScrollBg = ImGui::GetStyleColorVec4(ImGuiCol_ScrollbarBg);
						// ########################################
						ImGui::SeparatorText("Theme Color Settings");
						PutColorEditor("Button Border", "###ThemeCol1", 5.f, 0.f, reinterpret_cast<float *>(&SussyAim::Cfg::Menu::ButtonBorderColor));
						PutColorEditor("Border", "###ThemeCol2", 5.f, 0.f, reinterpret_cast<float *>(&borderColor));
						PutColorEditor("Button", "###ThemeCol3", 5.f, 0.f, reinterpret_cast<float *>(&ButtonColor));
						PutColorEditor("Button Hovered", "###ThemeCol4", 5.f, 0.f, reinterpret_cast<float *>(&ButtonHovered));
						PutColorEditor("Button Active", "###ThemeCol5", 5.f, 0.f, reinterpret_cast<float *>(&ButtonActive));
						PutColorEditor("Child Window Bg", "###ThemeCol6", 5.f, 0.f, reinterpret_cast<float *>(&childBgColor));
						PutColorEditor("Frame Bg", "###ThemeCol7", 5.f, 0.f, reinterpret_cast<float *>(&FrameBgColor));
						PutColorEditor("Frame Bg Hovered", "###ThemeCol8", 5.f, 0.f, reinterpret_cast<float *>(&FrameHovered));
						PutColorEditor("Frame Bg Active", "###ThemeCol9", 5.f, 0.f, reinterpret_cast<float *>(&FrameActive));
						PutColorEditor("Header", "###ThemeCol10", 5.f, 0.f, reinterpret_cast<float *>(&Header));
						PutColorEditor("Header Active", "###ThemeCol11", 5.f, 0.f, reinterpret_cast<float *>(&HeaderActive));
						PutColorEditor("Header Hovered", "###ThemeCol12", 5.f, 0.f, reinterpret_cast<float *>(&HeaderHovered));
						PutColorEditor("Scrollbar Bg", "###ThemeCol13", 5.f, 0.f, reinterpret_cast<float *>(&ScrollBg));
						PutColorEditor("Window Bg", "###ThemeCol14", 5.f, 0.f, reinterpret_cast<float *>(&windowBgColor));

						// Update Color
						ImGui::GetStyle().Colors[ImGuiCol_Border] = borderColor;
						ImGui::GetStyle().Colors[ImGuiCol_Button] = ButtonColor;
						ImGui::GetStyle().Colors[ImGuiCol_ButtonActive] = ButtonActive;
						ImGui::GetStyle().Colors[ImGuiCol_ButtonHovered] = ButtonHovered;
						ImGui::GetStyle().Colors[ImGuiCol_FrameBg] = FrameBgColor;
						ImGui::GetStyle().Colors[ImGuiCol_FrameBgHovered] = FrameHovered;
						ImGui::GetStyle().Colors[ImGuiCol_FrameBgActive] = FrameActive;
						ImGui::GetStyle().Colors[ImGuiCol_WindowBg] = windowBgColor;
						ImGui::GetStyle().Colors[ImGuiCol_ChildBg] = childBgColor;
						ImGui::GetStyle().Colors[ImGuiCol_Header] = Header;
						ImGui::GetStyle().Colors[ImGuiCol_HeaderActive] = HeaderActive;
						ImGui::GetStyle().Colors[ImGuiCol_HeaderHovered] = HeaderHovered;
						ImGui::GetStyle().Colors[ImGuiCol_ScrollbarBg] = ScrollBg;
					}

					ImGui::Columns(1);
				}

				// Config
				else if (SussyAim::Cfg::page == 3)
				{
					ImGui::Columns(2, nullptr, false);
					ConfigMenu::RenderCFGmenu();

					ImGui::Columns(1);
				}
			}
			ImGui::EndChild();
		}
		ImGui::End();
	}
}