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
#include "view_crosshair.hpp"
#include "view_esp.hpp"
#include "view_fun.hpp"
#include "view_menu.hpp"
#include "view_misc.hpp"
#include "view_triggerbot.hpp"

namespace SussyAim
{
	namespace view
	{

		// void renderQuitButton()
		// {
		// 	static const ImVec4 nothingColor = ImVec4(0, 0, 0, 0);
		// 	ImGui::PushStyleColor(ImGuiCol_Button, nothingColor);
		// 	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, nothingColor);
		// 	ImGui::PushStyleColor(ImGuiCol_ButtonActive, nothingColor);
		// 	ImGui::PushStyleColor(ImGuiCol_Border, nothingColor);
		// 	if (ImGui::Button("[Quit]"))
		// 	{
		// 		std::cout << "[YourMom] Quitting..." << std::endl;
		// 		Gui.Quit();
		// 	}
		// 	ImGui::PopStyleColor(4);
		// }

		const char *format(const char *s, ...)
		{
			static char buffer[4096];
			va_list args;
			va_start(args, s);
			vsnprintf(buffer, sizeof(buffer), s, args);
			va_end(args);
			return buffer;
		}

		static void renderMainMenu()
		{
#ifdef G_IMGUI_DEMO
			if (SussyAim::view::menu::showImGuiDemo)
				ImGui::ShowDemoWindow();
#endif

			if (AS_Logo == NULL)
			{
				std::cout << "[GUI] Loading logo image" << std::endl;
				Gui.LoadTextureFromMemory(Images::Logo, sizeof Images::Logo, &AS_Logo, &LogoW, &LogoH);
			}

			ImColor BorderColor = SussyAim::Cfg::Menu::ButtonBorderColor;

			char TempText[256];
			ImGuiWindowFlags Flags = ImGuiWindowFlags_NoCollapse;
			ImGui::SetNextWindowPos({(ImGui::GetIO().DisplaySize.x - 851.0f) / 2.0f, (ImGui::GetIO().DisplaySize.y - 514.0f) / 2.0f}, ImGuiCond_Once);
			ImGui::SetNextWindowSize({851, 514}, ImGuiCond_Once);

			static const char *windowTitle = format("SussyAim v%d.%d.%d###main", G_VERSION_MAJOR, G_VERSION_MINOR, G_VERSION_PATCH);
			ImGui::Begin(windowTitle, nullptr, Flags);
			{
				ImGui::BeginGroup();
				{
					static ImTextureID ImageID = (void *)AS_Logo;
					static ImVec2 LogoSize = ImVec2(LogoW, LogoH);
					ImGui::Image(ImageID, LogoSize);

					ImGui::SameLine();

					ImGui::Text("Anti Capture: %s", SussyAim::Cfg::Menu::StreamProof ? "on" : "OFF");
				}
				ImGui::EndGroup();

				ImGui::BeginGroup();
				ImGui::BeginTabBar("main_a");
				{
					SussyAim::view::aimbot::renderItem();
					SussyAim::view::triggerbot::renderItem();
					SussyAim::view::esp::renderItem();
					SussyAim::view::crosshair::renderItem();
					SussyAim::view::misc::renderItem();
					SussyAim::view::fun::renderItem();
					SussyAim::view::config::renderItem();
					SussyAim::view::menu::renderItem();
				}
				ImGui::EndTabBar();
				ImGui::EndGroup();
			}
			ImGui::End();
		}
	}
}
