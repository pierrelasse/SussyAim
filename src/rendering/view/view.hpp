#pragma once

#include "methods.hpp"
#include "../../config/Config.hpp"
#include "../../features/Aimbot.hpp"
#include "../../features/Triggerbot.hpp"
#include "../../config/ConfigMenu.hpp"
#include "../../config/ConfigSaver.hpp"
#include "../../features/StyleChanger.h"
#include "../Resources/Images.h"

#include "view_aimbot.hpp"
#include "view_config.hpp"
#include "view_misc.hpp"
#include "view_visual.hpp"

namespace SussyAim
{
	namespace view
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

		void renderQuitButton() {
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

		void render()
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
				renderQuitButton();

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
						SussyAim::view::visual::render();
					}

					// Aimbot
					else if (SussyAim::Cfg::page == 1)
					{
						SussyAim::view::aimbot::render();
					}

					// Misc
					else if (SussyAim::Cfg::page == 2)
					{
						SussyAim::view::misc::render();
					}

					// Config
					else if (SussyAim::Cfg::page == 3)
					{
						SussyAim::view::config::render();
					}
				}
				ImGui::EndChild();
			}
			ImGui::End();
		}
	}
}
