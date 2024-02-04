#include "ConfigMenu.hpp"
#include "../MenuConfig.hpp"
#include "ConfigSaver.hpp"
#include "../TriggerBot.h"
#include "../AimBot.hpp"
#include <filesystem>
#include <string>
#include "../Font/IconsFontAwesome5.h"
#include "../Resources/Language.h"

namespace ConfigMenu {
	
	void RenderCFGmenu()
	{
		static char configNameBuffer[128] = "NewConfig";
		static char configAuthorBuffer[128] = "Author";
		static int selectedConfig = -1;

		const std::string configDir = MenuConfig::dir;
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
		ImGui::SameLine();
		if (ImGui::Button(Lang::ConfigText.Reset, { 126.f, 30.f }))
			ImGui::OpenPopup("##reallyReset");
		if (ImGui::BeginPopup("##reallyReset"))
		{
			ImGui::TextUnformatted("Are you sure?");
			if (ImGui::Button("No", { 45.0f, 0.0f }))
				ImGui::CloseCurrentPopup();
			ImGui::SameLine();
			if (ImGui::Button("Yes", { 45.0f, 0.0f }))
			{
				ConfigMenu::ResetToDefault();
				ImGui::CloseCurrentPopup();
			}
			ImGui::EndPopup();
		}
		ImGui::NextColumn();
		ImGui::SetCursorPosY(24.f);
		ImGui::SeparatorText(Lang::ConfigText.SeparateLine);
		ImGui::TextDisabled(Lang::ConfigText.AuthorName);
		ImGui::SetNextItemWidth(ComponentWidth + 10);
		ImGui::InputText("###ConfigNameInput", configAuthorBuffer, sizeof(configAuthorBuffer));
		ImGui::TextDisabled(Lang::ConfigText.ConfigName);
		ImGui::SetNextItemWidth(ComponentWidth + 10);
		ImGui::InputText("###AuthorNameInput", configNameBuffer, sizeof(configNameBuffer));
		ImGui::NewLine();
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() / 4);
		if (ImGui::Button(Lang::ConfigText.Create, { 126.f, 30.f }))
		{
			std::string configFileName = std::string(configNameBuffer) + ".yml";
			MyConfigSaver::SaveConfig(configFileName, std::string(configAuthorBuffer));
		}
		ImGui::NewLine();
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() / 4);
		if (ImGui::Button(Lang::ConfigText.OpenFolder, { 126.f, 30.f }))
		{
			Gui.OpenWebpage(configDir.c_str());
		}
	}

	void ResetToDefault() {
		MiscCFG::SmokeColored = false;
		MiscCFG::SmokeColor = ImColor(255, 0, 0, 255);
		MiscCFG::NoSmoke = false;
		MiscCFG::Jitter = false;
		ESPConfig::ammoBar = true;
		ESPConfig::drawBoxOutline = true;
		ESPConfig::drawHealth = false;
		ESPConfig::FilledColor = ImColor(255, 255, 255, 255);
		ESPConfig::FilledColor2 = ImColor(255, 255, 255, 255);
		ESPConfig::MultiColor = false;
		ESPConfig::BoxFilledVisColor = ImColor(0, 0, 255, 255);
		ESPConfig::FilledVisBox = false;
		MiscCFG::MoneyService = false;
		MiscCFG::ShowCashSpent = false;
		MiscCFG::FovHacker = false;
		MiscCFG::RadarHack = false;
		MiscCFG::SpecList = false;
		MiscCFG::BombTimerCol = ImColor(255, 120, 0, 255);
		MiscCFG::bombTimer = false;
		ESPConfig::VisibleColor = ImColor(255, 196, 0, 255);
		ESPConfig::visibleCheck = false;
		MiscCFG::EnemySensor = false;
		MenuConfig::AirJump = false;
		MenuConfig::Theme = 0;
		MenuConfig::WindowStyle = 0;
		ESPConfig::boxAlpha = 0.0f;
		ESPConfig::displayPreview = true;
		ESPConfig::drawHeadBox = true;
		ESPConfig::HeadBoxStyle = 0;
		ESPConfig::HeadBoxColor = ImColor(255, 255, 255, 255);
		ESPConfig::drawDistance = false;
		ESPConfig::drawBones = true;
		ESPConfig::drawBox = true;
		ESPConfig::drawHealthBar = true;
		ESPConfig::drawWeapon = true;
		ESPConfig::drawEyeRay = false;
		ESPConfig::drawName = true;
		ESPConfig::boxRounding = 0.0f;
		MenuConfig::AimBot = false;
		MenuConfig::AimAlways = false;
		MenuConfig::AimToggleMode = false;
		MenuConfig::AimPosition = 0;
		MenuConfig::AimPositionIndex = BONEINDEX::head;
		MenuConfig::BoxType = 0;
		MenuConfig::HealthBarType = 0;
		ESPConfig::BoneColor = ImColor(0, 255, 255, 255);
		ESPConfig::FrameColor = ImColor(255, 80, 0, 255);
		ESPConfig::EyeRayColor = ImVec4(255, 0, 0, 255);
		MenuConfig::ShowMenu = true;
		RadarCFG::ShowRadar = false;
		RadarCFG::RadarRange = 150;
		RadarCFG::ShowRadarCrossLine = true;
		RadarCFG::RadarCrossLineColor = ImColor(220, 220, 220, 255);
		RadarCFG::RadarType = 2;
		RadarCFG::RadarPointSizeProportion = 1.f;
		RadarCFG::RadarBgAlpha = 0.1f;
		RadarCFG::Proportion = 3300;
		MenuConfig::TriggerBot = false;
		MenuConfig::TriggerAlways = false;
		MenuConfig::TeamCheck = true;
		MenuConfig::StreamProof = true;
		MenuConfig::VisibleCheck = true;
		MenuConfig::ShowHeadShootLine = false;
		MenuConfig::HeadShootLineColor = ImColor(255, 255, 255, 200);
		MenuConfig::AimBotHotKey = 0;
		AimControl::SetHotKey(MenuConfig::AimBotHotKey);
		ESPConfig::drawTracers = false;
		MenuConfig::FovLineSize = 60.0f;
		TriggerBot::TriggerDelay = 90;
		TriggerBot::FakeShotDelay = 500;
		RCS::RCSBullet = 1;
		MenuConfig::TriggerHotKey = 0;
		TriggerBot::SetHotKey(MenuConfig::TriggerHotKey);
		AimControl::RCSScale = ImVec2(1.2f, 1.4f);
		AimControl::ScopeOnly = false;
		MenuConfig::FovLineColor = ImVec4(55, 55, 55, 220);
		ESPConfig::tracerColor = ImVec4(255, 255, 255, 220);
		CrosshairsCFG::ShowCrossHair = true;
		CrosshairsCFG::CrossHairColor = ImColor(0, 255, 0, 255);
		CrosshairsCFG::CrossHairSize = 75;
		CrosshairsCFG::drawDot = true;
		CrosshairsCFG::tStyle = false;
		CrosshairsCFG::HorizontalLength = 6;
		CrosshairsCFG::VerticalLength = 6;
		CrosshairsCFG::drawOutLine = true;
		CrosshairsCFG::Gap = 8;
		CrosshairsCFG::drawCrossline = true;
		CrosshairsCFG::drawCircle = false;
		MenuConfig::TargetingCrosshairs = false;
		CrosshairsCFG::TargetedColor = ImColor(255, 0, 0, 255);
		CrosshairsCFG::CircleRadius = 3.f;
		CrosshairsCFG::DynamicGap = false;
		CrosshairsCFG::DotSize = 1.0f;
		CrosshairsCFG::Thickness = 1;
		CrosshairsCFG::TeamCheck = true;
		MiscCFG::BunnyHop = false;
		MiscCFG::WorkInSpec = true;
		MiscCFG::NoFlash = false;
		MiscCFG::WaterMark = false;
		MiscCFG::CheatList = false;
		MiscCFG::HitSound = false;
		MiscCFG::FastStop = false;

		ESPConfig::enabled = false;
		ESPConfig::DrawFov = true;
		MenuConfig::FovCircleColor = ImColor(255, 255, 255, 255);
	}
}
