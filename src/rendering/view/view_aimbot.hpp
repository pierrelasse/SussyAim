#pragma once

#include "methods.hpp"

using namespace SussyAim::view;

namespace SussyAim
{
	namespace view
	{
		namespace aimbot
		{
			void render()
			{
				ImGui::Columns(2, nullptr, false);
				ImGui::SetCursorPos(ImVec2(15.f, 24.f));
				ImGui::SeparatorText(ICON_FA_USER " Aimbot");
				float FovMin = 0.f, FovMax = 50.f;
				float SmoothMin = 0.f, SmoothMax = 5.f;
				PutSwitch(Lang::AimbotText.Enable, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Aimbot::enabled);
				if (SussyAim::Cfg::Aimbot::enabled)
				{
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10.f);
					ImGui::TextDisabled(Lang::AimbotText.HotKeyList);
					ImGui::SameLine();
					if (ImGui::Combo("###AimKey", &SussyAim::Cfg::Aimbot::AimbotHotKey, "LALT\0LBUTTON\0RBUTTON\0XBUTTON1\0XBUTTON2\0CAPITAL\0SHIFT\0CONTROL\0MouseForward\0"))
					{
						ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10.f);
						ImGui::TextDisabled(Lang::AimbotText.HotKeyList);
						ImGui::SameLine();
						if (ImGui::Combo("###AimKey", &SussyAim::Cfg::Aimbot::AimbotHotKey, "LALT\0LBUTTON\0RBUTTON\0XBUTTON1\0XBUTTON2\0CAPITAL\0SHIFT\0CONTROL\0"))
						{
							SussyAim::Features::Aimbot::SetHotKey(SussyAim::Cfg::Aimbot::AimbotHotKey);
						}
						PutSwitch(Lang::AimbotText.Toggle, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Aimbot::AimToggleMode);
					}
					PutSwitch(Lang::AimbotText.AimLock, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Aimbot::always);
					PutSwitch(Lang::AimbotText.DrawFov, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::DrawFov, true, "###FOVcol", reinterpret_cast<float *>(&SussyAim::Cfg::Menu::FovCircleColor));
					PutSwitch(Lang::AimbotText.VisCheck, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Aimbot::VisibleCheck);
					PutSwitch(Lang::AimbotText.ScopeOnly, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Features::Aimbot::ScopeOnly);
					PutSwitch(Lang::AimbotText.AutoShot, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Features::Aimbot::AutoShot);
					PutSliderFloat(Lang::AimbotText.FovSlider, 10.f, &SussyAim::Features::Aimbot::AimFov, &FovMin, &FovMax, "%.1f");
					PutSliderFloat(Lang::AimbotText.SmoothSlider, 10.f, &SussyAim::Features::Aimbot::Smooth, &SmoothMin, &SmoothMax, "%.1f");
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10.f);
					ImGui::TextDisabled(Lang::AimbotText.BoneList);
					ImGui::SameLine();
					if (ImGui::Combo("###AimPos", &SussyAim::Cfg::Aimbot::AimPosition, "Head\0Neck\0Chest\0Penis\0"))
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
				}
				ImGui::NextColumn();
				ImGui::SetCursorPosY(24.f);
				ImGui::SeparatorText(ICON_FA_ARROW_ALT_CIRCLE_DOWN " RCS");
				PutSwitch("Enable RCS", 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Aimbot::RCS);

				ImGui::NewLine();
				ImGui::SeparatorText(ICON_FA_HAND_POINTER " Triggerbot");
				int DelayMin = 10, DelayMax = 1000;
				int DurationMin = 0, DurationMax = 1000;
				PutSwitch(Lang::TriggerText.Enable, 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Triggerbot::enabled);
				if (SussyAim::Cfg::Triggerbot::enabled)
				{
					if (!SussyAim::Cfg::Triggerbot::always)
					{
						ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5.f);
						ImGui::TextDisabled(Lang::TriggerText.HotKeyList);
						ImGui::SameLine();
						if (ImGui::Combo("###TriggerbotKey", &SussyAim::Cfg::Triggerbot::hotkey, "LALT\0RBUTTON\0XBUTTON1\0XBUTTON2\0CAPITAL\0SHIFT\0CONTROL\0"))
						{
							SussyAim::Features::Triggerbot::SetHotKey(SussyAim::Cfg::Triggerbot::hotkey);
						}
					}
					PutSwitch(Lang::TriggerText.Toggle, 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Triggerbot::always);
					PutSliderInt(Lang::TriggerText.DelaySlider, 5.f, &SussyAim::Features::Triggerbot::TriggerDelay, &DelayMin, &DelayMax, "%d ms");
					PutSliderInt(Lang::TriggerText.FakeShotSlider, 5.f, &SussyAim::Features::Triggerbot::FakeShotDelay, &DurationMin, &DurationMax, "%d ms");
				}

				ImGui::Columns(1);
			}
		}
	}
}
