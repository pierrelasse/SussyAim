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
			inline char configNameBuffer[128] = "My config";
			inline int selectedConfig = -1;
			inline std::vector<std::string> configFiles;

			void updateConfigFiles()
			{
				configFiles.clear();
				for (const auto &entry : std::filesystem::directory_iterator(SussyAim::Cfg::dirConfigs))
				{
					if (entry.is_regular_file() && entry.path().extension() == ".yml")
					{
						configFiles.push_back(entry.path().filename().string());
					}
				}
			}

			void deleteSelectedConfig()
			{
				if (selectedConfig == -1)
					return;

				std::string selectedConfigFile = configFiles[selectedConfig];
				std::string fullPath = SussyAim::Cfg::dirConfigs + selectedConfigFile;

				if (std::remove(fullPath.c_str()) == 0)
				{
					configFiles.erase(configFiles.begin() + selectedConfig);
					selectedConfig = -1;
				}
			}

			void renderConfigs()
			{
				ImGui::SeparatorText(Lang::ConfigText.FeatureName);

				ImGui::BeginListBox("##configFiles");
				{
					int i = 0;
					for (const auto &file : configFiles)
					{
						if (ImGui::Selectable(file.substr(0, file.length() - 4).c_str(), i == selectedConfig))
							selectedConfig = i;
						i++;
					}
				}
				ImGui::EndListBox();

				const bool isConfigSelected = selectedConfig >= 0 && selectedConfig < configFiles.size();
				if (!isConfigSelected)
				{
					ImGui::BeginDisabled();
				}
				{
					if (ImGui::Button("Load"))
					{
						std::string selectedConfigFile = configFiles[selectedConfig];
						MyConfigSaver::LoadConfig(selectedConfigFile);
					}

					ImGui::SameLine();

					if (ImGui::Button("Save"))
					{
						std::string selectedConfigFile = configFiles[selectedConfig];
						MyConfigSaver::SaveConfig(selectedConfigFile);
					}

					ImGui::SameLine();

					if (ImGui::Button("Delete"))
						ImGui::OpenPopup("##reallyDelete");
					if (ImGui::BeginPopup("##reallyDelete"))
					{
						ImGui::TextUnformatted("Are you sure?");

						const ImVec2 buttonSize = {45.0f, 0.0f};

						ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(255 / 255.f, 54 / 255.f, 54 / 255.f, 1.f));
						if (ImGui::Button("Yes", buttonSize))
						{
							deleteSelectedConfig();
							ImGui::CloseCurrentPopup();
						}
						ImGui::PopStyleColor();

						ImGui::SameLine();

						ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(139 / 255.f, 255 / 255.f, 90 / 255.f, 1.f));
						if (ImGui::Button("No", buttonSize))
							ImGui::CloseCurrentPopup();
						ImGui::PopStyleColor();

						ImGui::EndPopup();
					}
				}
				if (!isConfigSelected)
				{
					ImGui::EndDisabled();
				}

				if (ImGui::Button("Open configs folder"))
				{
					Gui.OpenWebpage(SussyAim::Cfg::dirConfigs.c_str());
				}
			}

			void renderNewConfig()
			{
				ImGui::SeparatorText(Lang::ConfigText.SeparateLine);

				// ImGui::TextDisabled(Lang::ConfigText.ConfigName);
				ImGui::InputText("###nameInput", configNameBuffer, sizeof(configNameBuffer));

				ImGui::SameLine();

				if (ImGui::Button("Create"))
				{
					std::string configFileName = std::string(configNameBuffer) + ".yml";
					MyConfigSaver::SaveConfig(configFileName);
				}
			}

			void render()
			{
				ImGui::Columns(2, nullptr, false);

				try
				{
					updateConfigFiles();
				}
				catch (std::exception &ex)
				{
					std::cerr << "[Configs] Could not update config files: " << ex.what() << std::endl;
					ImGui::Columns(1);
					return;
				}

				renderConfigs();

				ImGui::NextColumn();
				renderNewConfig();

				ImGui::Columns(1);
			}

			void renderItem()
			{
				if (ImGui::BeginTabItem(ICON_FA_COGS " Config"))
				{
					render();
					ImGui::EndTabItem();
				}
			}
		}
	}
}
