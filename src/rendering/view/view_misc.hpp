#pragma once

#include "methods.hpp"

using namespace SussyAim::view;

namespace SussyAim
{
	namespace view
	{
		namespace misc
		{
			void render()
			{
				int FovMin = 60, FovMax = 140;

				ImGui::Columns(2, nullptr, false);
				// ImGui::SetCursorPos(ImVec2(15.f, 24.f));
				ImGui::SeparatorText(ICON_FA_SUN " Misc");

				PutSwitch(Lang::MiscText.HeadshotLine, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Menu::ShowHeadShootLine);
				PutSwitch(Lang::MiscText.SpecCheck, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::WorkInSpec);
				PutSliderInt(Lang::MiscText.fovChanger, 10.f, &SussyAim::Cfg::Misc::Fov, &FovMin, &FovMax, "%d");
				PutSwitch(Lang::MiscText.NoFlash, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::NoFlash);
				PutSwitch(Lang::MiscText.FastStop, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::FastStop);
				PutSwitch("Force Scope", 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::ForceScope);
				PutSwitch(Lang::MiscText.NoSmoke, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::NoSmoke);
				PutSwitch(Lang::MiscText.SmokeColor, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::SmokeColored, true, "###SmokeColor", reinterpret_cast<float *>(&SussyAim::Cfg::Misc::SmokeColor));
				PutSwitch(Lang::MiscText.HitSound, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::HitSound);
				PutSwitch(Lang::MiscText.bmbTimer, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::bombTimer, true, "###bmbTimerCol", reinterpret_cast<float *>(&SussyAim::Cfg::Misc::BombTimerCol));
				PutSwitch("Cheat List", 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::CheatList);
				PutSwitch(Lang::MiscText.Bhop, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::BunnyHop);
				// PutSwitch(Lang::MiscText.SpecList, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::SpecList);
				PutSwitch(Lang::MiscText.RadarHack, 10.f, ImGui::GetFrameHeight() * 1.7f, &SussyAim::Cfg::Misc::RadarHack);
				if (SussyAim::Cfg::Misc::RadarHack)
				{
					// ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10.f);
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
					// ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10.f);
					ImGui::TextColored(ImColor(255, 50, 0, 255), "This might cause BAN");
				}

				ImGui::NextColumn();
				// ImGui::SetCursorPosY(24.f);
				ImGui::SeparatorText(ICON_FA_HEART " Menu Settings");
				PutSwitch(Lang::MiscText.AntiRecord, 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Menu::StreamProof);
				// ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5.f);
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
		}
	}
}
