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
			inline const float recoilMin = 0.f, recoilMax = 2.f;
			inline const int BulletMin = 0, BulletMax = 5;

			void render()
			{
				PutSwitch("Enabled", 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Aimbot::enabled);

				ImGui::Spacing();

				ImGui::TextDisabled("Hotkey");
				ImGui::SameLine();
				if (ImGui::Combo("###AimKey", &SussyAim::Cfg::Aimbot::AimbotHotKey, "LALT\0LBUTTON\0RBUTTON\0XBUTTON1\0XBUTTON2\0CAPITAL\0SHIFT\0CONTROL\0"))
				{
					SussyAim::Features::Aimbot::SetHotKey(SussyAim::Cfg::Aimbot::AimbotHotKey);
				}
				PutSliderInt("Start Bullet", 10.f, &SussyAim::Features::Aimbot::AimBullet, &BulletMin, &BulletMax, "%d");
				PutSwitch(Lang::AimbotText.Toggle, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Aimbot::AimToggleMode);

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

				if (PutSwitch("Predict recoil", 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Aimbot::RCS, false, 0, 0, "Very op"))
				{
					PutSliderFloat(" -  Yaw: ", 5.f, &RCS::RCSScale.x, &recoilMin, &recoilMax, "%.2f");
					PutSliderFloat(" -  Pitch: ", 5.f, &RCS::RCSScale.y, &recoilMin, &recoilMax, "%.2f");

					float scalex = (2.22 - RCS::RCSScale.x) * .5f;
					float scaley = (2.12 - RCS::RCSScale.y) * .5f; // Simulate reasonable error values
					ImVec2 BulletPos = ImGui::GetCursorScreenPos();

					ImVec2 BulletPos0, BulletPos1, BulletPos2, BulletPos3, BulletPos4, BulletPos5, BulletPos6, BulletPos7, BulletPos8, BulletPos9, BulletPos10, BulletPos11, BulletPos12, BulletPos13, BulletPos14, BulletPos15;
					BulletPos.y += 123 * scaley;
					BulletPos0.x = BulletPos.x + 125;
					BulletPos0.y = BulletPos.y + 5;
					BulletPos1.x = BulletPos0.x - 3 * scalex;
					BulletPos1.y = BulletPos0.y - 5 * scaley;
					BulletPos2.x = BulletPos1.x + 2 * scalex;
					BulletPos2.y = BulletPos1.y - 10 * scaley;
					BulletPos3.x = BulletPos2.x + 4 * scalex;
					BulletPos3.y = BulletPos2.y - 11 * scaley;
					BulletPos4.x = BulletPos3.x - 3 * scalex;
					BulletPos4.y = BulletPos3.y - 31 * scaley;
					BulletPos5.x = BulletPos4.x - 1 * scalex;
					BulletPos5.y = BulletPos4.y - 20 * scaley;
					BulletPos6.x = BulletPos5.x - 2 * scalex;
					BulletPos6.y = BulletPos5.y - 17 * scaley;
					BulletPos7.x = BulletPos6.x - 15 * scalex;
					BulletPos7.y = BulletPos6.y - 9 * scaley;
					BulletPos8.x = BulletPos7.x + 7 * scalex;
					BulletPos8.y = BulletPos7.y - 8 * scaley;
					BulletPos9.x = BulletPos8.x + 33 * scalex;
					BulletPos9.y = BulletPos8.y + 2 * scaley;
					BulletPos10.x = BulletPos9.x + 1 * scalex;
					BulletPos10.y = BulletPos9.y - 16 * scaley;
					BulletPos11.x = BulletPos10.x - 9 * scalex;
					BulletPos11.y = BulletPos10.y + 20 * scaley;
					BulletPos12.x = BulletPos11.x - 3 * scalex;
					BulletPos12.y = BulletPos11.y - 9 * scaley;
					BulletPos13.x = BulletPos12.x + 15 * scalex;
					BulletPos13.y = BulletPos12.y - 5 * scaley;
					BulletPos14.x = BulletPos13.x + 10 * scalex;
					BulletPos14.y = BulletPos13.y - 4 * scaley;

					ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos0, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
					ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos1, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
					ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos2, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
					ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos3, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
					ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos4, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
					ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos5, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
					ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos6, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
					ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos7, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
					ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos8, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
					ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos9, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
					ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos10, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
					ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos11, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
					ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos12, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
					ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos13, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
					ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos14, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
				}
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
