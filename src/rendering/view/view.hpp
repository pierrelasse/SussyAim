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
#include "view_triggerbot.hpp"
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

		void renderQuitButton()
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

		const char *format(const char *s, ...)
		{
			static char buffer[4096];
			va_list args;
			va_start(args, s);
			vsnprintf(buffer, sizeof(buffer), s, args);
			va_end(args);
			return buffer;
		}

		static void render()
		{
			LoadImages();

			ImColor BorderColor = SussyAim::Cfg::Menu::ButtonBorderColor;

			char TempText[256];
			ImGuiWindowFlags Flags = ImGuiWindowFlags_NoCollapse;
			ImGui::SetNextWindowPos({(ImGui::GetIO().DisplaySize.x - 851.0f) / 2.0f, (ImGui::GetIO().DisplaySize.y - 514.0f) / 2.0f}, ImGuiCond_Once);
			ImGui::SetNextWindowSize({851, 514}, ImGuiCond_Once);

			static const char *windowTitle = format("SussyAim v%d.%d.%d###main", G_VERSION_MAJOR, G_VERSION_MINOR, G_VERSION_PATCH);
			ImGui::Begin(windowTitle, nullptr, Flags);
			{
				// renderQuitButton();

				ImGui::BeginGroup();
				{
					static ImTextureID ImageID = (void *)AS_Logo;
					static ImVec2 LogoSize = ImVec2(LogoW, LogoH);
					ImGui::Image(ImageID, LogoSize);
				}
				ImGui::EndGroup();

				ImGui::BeginGroup();
				ImGui::BeginTabBar("main_a");
				{
					if (ImGui::BeginTabItem("Aimbot"))
					{
						SussyAim::view::aimbot::render();
						ImGui::EndTabItem();
					}
					if (ImGui::BeginTabItem("Triggerbot"))
					{
						SussyAim::view::triggerbot::render();
						ImGui::EndTabItem();
					}
					if (ImGui::BeginTabItem("Visual"))
					{
						SussyAim::view::visual::render();
						ImGui::EndTabItem();
					}
					if (ImGui::BeginTabItem("Misc"))
					{
						SussyAim::view::misc::render();
						ImGui::EndTabItem();
					}
					if (ImGui::BeginTabItem("Config"))
					{
						SussyAim::view::config::render();
						ImGui::EndTabItem();
					}
				}
				ImGui::EndTabBar();
				ImGui::EndGroup();

				// ImGui::SetCursorPos(SussyAim::Cfg::WCS.Button1Pos);
				// ImGui::Image((void *)MenuButton1, ImVec2(buttonW, buttonH));
				// if (ImGui::IsItemClicked())
				// {
				// 	SussyAim::Cfg::page = 0;
				// }
				// ImGui::GetWindowDrawList()->AddRect(
				// 	ImVec2(SussyAim::Cfg::WCS.Button1Pos.x + ImGui::GetWindowPos().x, SussyAim::Cfg::WCS.Button1Pos.y + ImGui::GetWindowPos().y),
				// 	ImVec2(SussyAim::Cfg::WCS.Button1Pos.x + buttonW + ImGui::GetWindowPos().x, SussyAim::Cfg::WCS.Button1Pos.y + buttonH + ImGui::GetWindowPos().y),
				// 	BorderColor, 9.f, ImDrawFlags_RoundCornersAll, 2.f);

				// ImGui::SetCursorPos(SussyAim::Cfg::WCS.Button2Pos);
				// ImGui::Image((void *)MenuButton2, ImVec2(buttonW, buttonH));
				// if (ImGui::IsItemClicked())
				// {
				// 	SussyAim::Cfg::page = 1;
				// }
				// ImGui::GetWindowDrawList()->AddRect(
				// 	ImVec2(SussyAim::Cfg::WCS.Button2Pos.x + ImGui::GetWindowPos().x, SussyAim::Cfg::WCS.Button2Pos.y + ImGui::GetWindowPos().y),
				// 	ImVec2(SussyAim::Cfg::WCS.Button2Pos.x + buttonW + ImGui::GetWindowPos().x, SussyAim::Cfg::WCS.Button2Pos.y + buttonH + ImGui::GetWindowPos().y),
				// 	BorderColor, 9.f, ImDrawFlags_RoundCornersAll, 2.f);

				// ImGui::SetCursorPos(SussyAim::Cfg::WCS.Button3Pos);
				// ImGui::Image((void *)MenuButton3, ImVec2(buttonW, buttonH));
				// if (ImGui::IsItemClicked())
				// {
				// 	SussyAim::Cfg::page = 2;
				// }
				// ImGui::GetWindowDrawList()->AddRect(
				// 	ImVec2(SussyAim::Cfg::WCS.Button3Pos.x + ImGui::GetWindowPos().x, SussyAim::Cfg::WCS.Button3Pos.y + ImGui::GetWindowPos().y),
				// 	ImVec2(SussyAim::Cfg::WCS.Button3Pos.x + buttonW + ImGui::GetWindowPos().x, SussyAim::Cfg::WCS.Button3Pos.y + buttonH + ImGui::GetWindowPos().y),
				// 	BorderColor, 9.f, ImDrawFlags_RoundCornersAll, 2.f);

				// ImGui::SetCursorPos(SussyAim::Cfg::WCS.Button4Pos);
				// ImGui::Image((void *)MenuButton4, ImVec2(buttonW, buttonH));
				// if (ImGui::IsItemClicked())
				// {
				// 	SussyAim::Cfg::page = 3;
				// }
				// ImGui::GetWindowDrawList()->AddRect(
				// 	ImVec2(SussyAim::Cfg::WCS.Button4Pos.x + ImGui::GetWindowPos().x, SussyAim::Cfg::WCS.Button4Pos.y + ImGui::GetWindowPos().y),
				// 	ImVec2(SussyAim::Cfg::WCS.Button4Pos.x + buttonW + ImGui::GetWindowPos().x, SussyAim::Cfg::WCS.Button4Pos.y + buttonH + ImGui::GetWindowPos().y),
				// 	BorderColor, 9.f, ImDrawFlags_RoundCornersAll, 2.f);

				// ImGui::SetCursorPos(SussyAim::Cfg::WCS.ChildPos);

				// ImGui::BeginChild("Page", SussyAim::Cfg::WCS.ChildSize);
				// switch (SussyAim::Cfg::page)
				// {
				// case 0:
				// 	SussyAim::view::visual::render();
				// 	break;
				// case 1:
				// 	SussyAim::view::aimbot::render();
				// 	break;
				// case 2:
				// 	SussyAim::view::misc::render();
				// 	break;
				// case 3:
				// 	SussyAim::view::config::render();
				// 	break;
				// }
				// ImGui::EndChild();
			}
			ImGui::End();
		}
	}
}
