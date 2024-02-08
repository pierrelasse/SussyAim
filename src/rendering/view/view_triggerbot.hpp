#pragma once

#include "methods.hpp"

using namespace SussyAim::view;

namespace SussyAim
{
	namespace view
	{
		namespace triggerbot
		{
			inline int DelayMin = 10, DelayMax = 1000;
			inline int DurationMin = 0, DurationMax = 1000;
			void render()
			{
				PutSwitch(Lang::TriggerText.Enable, 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Triggerbot::enabled);

				PutSwitch(Lang::TriggerText.Toggle, 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Triggerbot::always);
				if (!SussyAim::Cfg::Triggerbot::always)
				{
					ImGui::TextDisabled(Lang::TriggerText.HotKeyList);
					ImGui::SameLine();
					if (ImGui::Combo("###TriggerbotKey", &SussyAim::Cfg::Triggerbot::hotkey, "LALT\0RBUTTON\0XBUTTON1\0XBUTTON2\0CAPITAL\0SHIFT\0CONTROL\0"))
					{
						SussyAim::Features::Triggerbot::SetHotKey(SussyAim::Cfg::Triggerbot::hotkey);
					}
				}

				PutSliderInt(Lang::TriggerText.DelaySlider, 5.f, &SussyAim::Features::Triggerbot::TriggerDelay, &DelayMin, &DelayMax, "%d ms");
				PutSliderInt(Lang::TriggerText.FakeShotSlider, 5.f, &SussyAim::Features::Triggerbot::FakeShotDelay, &DurationMin, &DurationMax, "%d ms");
			}

			void renderItem()
			{
				if (ImGui::BeginTabItem(ICON_FA_HAND_POINTER " Triggerbot"))
				{
					render();
					ImGui::EndTabItem();
				}
			}
		}
	}
}
