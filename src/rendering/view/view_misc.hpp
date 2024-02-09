#pragma once

#include "methods.hpp"

using namespace SussyAim::view;

namespace SussyAim
{
	namespace view
	{
		namespace misc
		{
			inline const float FlashMin = 0.f, FlashMax = 255.f;
			inline const int FovMin = 1, FovMax = 179;

			void render()
			{
				PutSwitch(Lang::MiscText.HeadshotLine, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Menu::ShowHeadShootLine);
				PutSwitch(Lang::MiscText.SpecCheck, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::WorkInSpec);

				PutSwitch("Fov changer", 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::fovChanger);
				ImGui::SameLine();
				ImGui::SliderInt("###fovChangerValue", &SussyAim::Cfg::Misc::Fov, FovMin, FovMax, SussyAim::Cfg::Misc::Fov == 90 ? "Default (%d)" : "%d");

				PutSliderFloat("Max flash alpha", 10.f, &SussyAim::Cfg::Misc::FlashImmunity, &FlashMin, &FlashMax, SussyAim::Cfg::Misc::FlashImmunity == 0.f ? "Off" : "-%.f/-255");

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
					ImGui::TextColored(ImColor(255, 50, 0, 255), Lang::MiscText.VisCheckDisable);
				}
				PutSwitch(Lang::MiscText.MoneyService, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::MoneyService);
				if (SussyAim::Cfg::Misc::MoneyService)
					PutSwitch(Lang::MiscText.ShowCashSpent, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::ShowCashSpent);
				PutSwitch(Lang::MiscText.EnemySensor, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::EnemySensor);
				PutSwitch(Lang::MiscText.Watermark, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::WaterMark);
				PutSwitch(Lang::MiscText.TeamCheck, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Menu::TeamCheck);
			}

			void renderItem()
			{
				if (ImGui::BeginTabItem(ICON_FA_SUN " Misc"))
				{
					render();
					ImGui::EndTabItem();
				}
			}
		}
	}
}
