#pragma once

#include "methods.hpp"
#include "../../config/ConfigSaver.hpp"

using namespace SussyAim::view;

namespace SussyAim
{
	namespace view
	{
		namespace config
		{
			void render()
			{
				ImGui::Columns(2, nullptr, false);
				
				static char configNameBuffer[128] = "NewConfig";
				static int selectedConfig = -1;

				const std::string configDir = SussyAim::Cfg::dir;
				static std::vector<std::string> configFiles;
				std::vector<const char*> configFilesCStr;

				configFiles.clear();
				for (const auto& entry : std::filesystem::directory_iterator(configDir))
				{
					if (entry.is_regular_file() && entry.path().extension() == ".yml")
					{
						configFiles.push_back(entry.path().filename().string());
					}
				}
				for (const auto& file : configFiles)
				{
					configFilesCStr.push_back(file.c_str());
				}

				float CursorX = 10.f;
				float CurrentCursorX = ImGui::GetCursorPosX();
				float ComponentWidth = ImGui::GetColumnWidth() - ImGui::GetStyle().ItemSpacing.x - CursorX * 2;

				ImGui::SetCursorPos(ImVec2(15.f, 24.f));
				ImGui::SeparatorText(Lang::ConfigText.FeatureName);

				ImGui::SetCursorPosX(CurrentCursorX + CursorX);
				ImGui::TextDisabled(Lang::ConfigText.MyConfigs);
				ImGui::SetCursorPosX(CurrentCursorX + CursorX);
				ImGui::SetNextItemWidth(ComponentWidth);
				ImGui::ListBox("##ConfigFiles", &selectedConfig, configFilesCStr.data(), configFilesCStr.size());
				ImGui::SetCursorPosX(CurrentCursorX + CursorX);
				if (ImGui::Button(Lang::ConfigText.Load, { 126.f, 30.f }) && selectedConfig >= 0 && selectedConfig < configFiles.size())
				{
					std::string selectedConfigFile = configFiles[selectedConfig];
					MyConfigSaver::LoadConfig(selectedConfigFile);
				}
				ImGui::SameLine();
				if (ImGui::Button(Lang::ConfigText.Save, { 126.f, 30.f }) && selectedConfig >= 0 && selectedConfig < configFiles.size())
				{
					std::string selectedConfigFile = configFiles[selectedConfig];
					MyConfigSaver::SaveConfig(selectedConfigFile);
				}

				ImGui::SetCursorPosX(CurrentCursorX + CursorX);
				if (ImGui::Button(Lang::ConfigText.Delete, { 126.f, 30.f }) && selectedConfig >= 0 && selectedConfig < configFiles.size())
					ImGui::OpenPopup("##reallyDelete");
				if (ImGui::BeginPopup("##reallyDelete"))
				{
					ImGui::TextUnformatted("Are you sure?");
					if (ImGui::Button("No", { 45.0f, 0.0f }))
						ImGui::CloseCurrentPopup();
					ImGui::SameLine();
					if (ImGui::Button("Yes", { 45.0f, 0.0f }))
					{
						// Delete
						std::string selectedConfigFile = configFiles[selectedConfig];
						std::string fullPath = configDir + "\\" + selectedConfigFile;
						if (std::remove(fullPath.c_str()) == 0)
						{
							configFiles.erase(configFiles.begin() + selectedConfig);
							selectedConfig = -1;
						}
						ImGui::CloseCurrentPopup();
					}
					ImGui::EndPopup();
				}
				// ImGui::SameLine();
				// if (ImGui::Button(Lang::ConfigText.Reset, { 126.f, 30.f }))
				// 	ImGui::OpenPopup("##reallyReset");
				// if (ImGui::BeginPopup("##reallyReset"))
				// {
				// 	ImGui::TextUnformatted("Are you sure?");
				// 	if (ImGui::Button("No", { 45.0f, 0.0f }))
				// 		ImGui::CloseCurrentPopup();
				// 	ImGui::SameLine();
				// 	if (ImGui::Button("Yes", { 45.0f, 0.0f }))
				// 	{
				// 		ConfigMenu::ResetToDefault();
				// 		ImGui::CloseCurrentPopup();
				// 	}
				// 	ImGui::EndPopup();
				// }
				ImGui::NextColumn();
				ImGui::SetCursorPosY(24.f);
				ImGui::SeparatorText(Lang::ConfigText.SeparateLine);
				// ImGui::TextDisabled(Lang::ConfigText.AuthorName);
				// ImGui::SetNextItemWidth(ComponentWidth + 10);
				// ImGui::InputText("###ConfigNameInput", configAuthorBuffer, sizeof(configAuthorBuffer));
				ImGui::TextDisabled(Lang::ConfigText.ConfigName);
				ImGui::SetNextItemWidth(ComponentWidth + 10);
				ImGui::InputText("###AuthorNameInput", configNameBuffer, sizeof(configNameBuffer));
				ImGui::NewLine();
				ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() / 4);
				if (ImGui::Button(Lang::ConfigText.Create, { 126.f, 30.f }))
				{
					std::string configFileName = std::string(configNameBuffer) + ".yml";
					MyConfigSaver::SaveConfig(configFileName);
				}
				ImGui::NewLine();
				ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() / 4);
				if (ImGui::Button(Lang::ConfigText.OpenFolder, { 126.f, 30.f }))
				{
					Gui.OpenWebpage(configDir.c_str());
				}

				ImGui::Columns(1);
			}
		}
	}
}
