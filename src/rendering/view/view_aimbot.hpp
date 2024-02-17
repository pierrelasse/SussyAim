#pragma once

#include "methods.hpp"

using namespace SussyAim::view;

namespace SussyAim
{
	namespace view
	{
		namespace aimbot
		{
			inline const float FovMin = 0.f, FovMax = 50.f;
			inline const float SmoothMin = 0.4f, SmoothMax = 5.f;

			void render()
			{
				PutSwitch("Enabled", 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Aimbot::enabled);

				ImGui::Spacing();

				ImGui::TextDisabled("Hotkey");
				ImGui::SameLine();
				if (ImGui::Combo("###AimKey", &SussyAim::Cfg::Aimbot::AimbotHotKey, "LALT\0LBUTTON\0RBUTTON\0XBUTTON1\0XBUTTON2\0CAPITAL\0SHIFT\0CONTROL\0"))
				{
					ImGui::TextDisabled(Lang::AimbotText.HotKeyList);
					ImGui::SameLine();
					if (ImGui::Combo("###AimKey", &SussyAim::Cfg::Aimbot::AimbotHotKey, "LALT\0LBUTTON\0RBUTTON\0XBUTTON1\0XBUTTON2\0CAPITAL\0SHIFT\0CONTROL\0"))
					{
						SussyAim::Features::Aimbot::SetHotKey(SussyAim::Cfg::Aimbot::AimbotHotKey);
					}
					PutSwitch(Lang::AimbotText.Toggle, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Aimbot::AimToggleMode);
				}

				ImGui::Spacing();

				PutSwitch(Lang::AimbotText.AimLock, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Features::Aimbot::AimLock);
				PutSwitch(Lang::AimbotText.DrawFov, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::DrawFov, true, "###FOVcol", reinterpret_cast<float *>(&SussyAim::Cfg::Menu::FovCircleColor));
				PutSwitch(Lang::AimbotText.VisCheck, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Aimbot::VisibleCheck);
				PutSwitch(Lang::AimbotText.ScopeOnly, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Features::Aimbot::ScopeOnly);
				PutSwitch(Lang::AimbotText.AutoShot, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Features::Aimbot::AutoShot);
				PutSliderFloat(Lang::AimbotText.FovSlider, 10.f, &SussyAim::Features::Aimbot::AimFov, &FovMin, &FovMax, "%.1f");
				PutSliderFloat(Lang::AimbotText.SmoothSlider, 10.f, &SussyAim::Features::Aimbot::Smooth, &SmoothMin, &SmoothMax, "%.1f");

				ImGui::Spacing();

				ImGui::TextDisabled(Lang::AimbotText.BoneList);
				ImGui::SameLine();
				if (ImGui::Combo("###AimPos", &SussyAim::Cfg::Aimbot::AimPosition, "Head\0Neck\0Chest\0Pelvis\0"))
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

				ImGui::Spacing();

				PutSwitch("Predict recoil", 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Aimbot::RCS, false, 0, 0, "Very op");
			}

			void renderItem()
			{
				if (ImGui::BeginTabItem(ICON_FA_USER " Aimbot"))
				{
					render();
					ImGui::EndTabItem();
				}
			}
		}
	}
}
