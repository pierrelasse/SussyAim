#pragma once

#include "methods.hpp"

using namespace SussyAim::view;

namespace SussyAim
{
	namespace view
	{
		namespace esp
		{
			inline const float MinRounding = 0.f, MaxRouding = 5.f;
			inline const int MinCombo = 0, MaxCombo = 2;

			void render()
			{
				static const char *BoxTypes[] = {Lang::ESPtext.BoxType_Normal, Lang::ESPtext.BoxType_Edge, Lang::ESPtext.BoxType_Corner};
				static const char *LinePos[] = {Lang::ESPtext.LinePos_1, Lang::ESPtext.LinePos_2, Lang::ESPtext.LinePos_3};

				PutSwitch("Enabled", 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::enabled);
				ImGui::Spacing();

				PutSwitch(Lang::ESPtext.Box, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::drawBox, true, "###BoxCol", reinterpret_cast<float *>(&SussyAim::Cfg::ESP::FrameColor));
				if (SussyAim::Cfg::ESP::drawBox)
				{
					PutSwitch(Lang::ESPtext.Outline, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::drawBoxOutline);
					PutSliderInt(Lang::ESPtext.BoxType, 10.f, &SussyAim::Cfg::ESP::boxType, &MinCombo, &MaxCombo, BoxTypes[SussyAim::Cfg::ESP::boxType]);
					PutSliderFloat(Lang::ESPtext.BoxRounding, 10.f, &SussyAim::Cfg::ESP::boxRounding, &MinRounding, &MaxRouding, "%.1f");
				}

				ImGui::Spacing();

				if (PutSwitch(Lang::ESPtext.FilledBox, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::FilledBox, true, "###FilledBoxCol", reinterpret_cast<float *>(&SussyAim::Cfg::ESP::FilledColor)))
					PutSwitch(Lang::ESPtext.MultiColor, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::MultiColor, true, "###MultiCol", reinterpret_cast<float *>(&SussyAim::Cfg::ESP::FilledColor2));

				ImGui::Spacing();

				PutSwitch(Lang::ESPtext.HeadBox, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::drawHeadBox, true, "###HeadBoxCol", reinterpret_cast<float *>(&SussyAim::Cfg::ESP::HeadBoxColor));

				ImGui::Spacing();

				PutSwitch(Lang::ESPtext.Skeleton, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::drawBones, true, "###BoneCol", reinterpret_cast<float *>(&SussyAim::Cfg::ESP::BoneColor));

				ImGui::Spacing();

				PutSwitch("Tracers", 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::drawTracers, true, "###LineCol", reinterpret_cast<float *>(&SussyAim::Cfg::ESP::tracerColor));
				if (SussyAim::Cfg::ESP::drawTracers)
					PutSliderInt(Lang::ESPtext.LinePosList, 10.f, &SussyAim::Cfg::ESP::tracerPos, &MinCombo, &MaxCombo, LinePos[SussyAim::Cfg::ESP::tracerPos]);

				ImGui::Spacing();

				PutSwitch(Lang::ESPtext.EyeRay, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::drawEyeRay, true, "###LineCol", reinterpret_cast<float *>(&SussyAim::Cfg::ESP::EyeRayColor));
				
				ImGui::Spacing();

				PutSwitch(Lang::ESPtext.PlayerName, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::drawName);
				PutSwitch(Lang::ESPtext.Distance, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::drawDistance);

				ImGui::Spacing();

				PutSwitch(Lang::ESPtext.Weapon, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::drawWeapon);
				PutSwitch(Lang::ESPtext.Ammo, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::ammoBar);
				PutSwitch(Lang::ESPtext.ShowScoped, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::showScoped);

				ImGui::Spacing();

				PutSwitch(Lang::ESPtext.VisCheck, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::visibleCheck, true, "###VisibleCol", reinterpret_cast<float *>(&SussyAim::Cfg::ESP::VisibleColor));

				ImGui::Spacing();

				if (SussyAim::Cfg::ESP::drawHealthBar)
					PutSwitch(Lang::ESPtext.HealthNum, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::drawHealth);

				PutSwitch(Lang::ESPtext.ShowArmorBar, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::ArmorBar);
				if (SussyAim::Cfg::ESP::ArmorBar)
					PutSwitch(Lang::ESPtext.ArmorNum, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::ESP::ShowArmorNum);
			}

			void renderItem()
			{
				if (ImGui::BeginTabItem(ICON_FA_EYE " ESP"))
				{
					render();
					ImGui::EndTabItem();
				}
			}
		}
	}
}
