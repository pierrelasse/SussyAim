#pragma once

#include "../config/Config.hpp"
#include "../rendering/renderer.hpp"

namespace SussyAim
{
	namespace Features
	{
		namespace ESP
		{
			const char *GunIcon(const std::string weapon)
			{
				// https://www.unknowncheats.me/forum/counter-strike-2-a/608799-weapon-icon-esp.html
				static const std::map<std::string, const char *> gunIcons = {
					{"nova", "T"},
					{"ak47", "A"},
					{"awp", "C"},
					{"m4a4", "M"},
					{"deagle", "F"},
					{"mp9", "R"},
					{"famas", "H"},
					{"ump45", "b"},
					{"glock", "g"},
					{"ct_knife", "]"},
					{"t_knife", "["},
					{"elite", "B"},
					{"fiveseven", "C"},
					{"revolver", "J"},
					{"hkp2000", "E"},
					{"p250", "F"},
					{"usp_silencer", "G"},
					{"tec9", "H"},
					{"cz75a", "I"},
					{"mac10", "K"},
					{"bizon", "M"},
					{"mp7", "N"},
					{"p90", "O"},
					{"galilar", "Q"},
					{"m4a1_silencer", "T"},
					{"m4a1", "S"},
					{"aug", "U"},
					{"sg556", "V"},
					{"g3sg1", "X"},
					{"scar20", "Y"},
					{"ssg08", "a"},
					{"xm1014", "b"},
					{"sawedoff", "c"},
					{"mag7", "d"},
					{"nova", "e"},
					{"negev", "f"},
					{"m249", "g"},
					{"taser", "h"},
					{"flashbang", "i"},
					{"hegrenade", "j"},
					{"smokegrenade", "k"},
					{"molotov", "l"},
					{"decoy", "m"},
					{"incgrenade", "n"},
					{"c4", "o"}};

				auto it = gunIcons.find(weapon);
				if (it != gunIcons.end())
				{
					return it->second;
				}

				return "";
			}

			struct WeaponIconSize
			{
				float width;
				float height;
				float offsetX;
				float offsetY;
			};
			static std::unordered_map<std::string, WeaponIconSize> weaponIconSizes = {
				{"t_knife", {20.0f, 20.0f, -8.0f, 0.0f}},
				{"ct_knife", {20.0f, 20.0f, -8.0f, 0.0f}},
				{"deagle", {20.f, 20.f, -8.f, 0.f}},
				{"elite", {20.f, 20.f, 0.f, 0.f}},
				{"fiveseven", {20.f, 20.f, 0.f, 0.f}},
				{"glock", {20.f, 20.f, 0.f, 0.f}},
				{"revolver", {20.f, 20.f, -5.f, 0.f}},
				{"hkp2000", {20.f, 20.f, 0.f, 0.f}},
				{"p250", {20.f, 20.f, 0.f, 0.f}},
				{"usp_silencer", {20.f, 20.f, 0.f, 0.f}},
				{"tec9", {20.f, 20.f, 0.f, 0.f}},
				{"cz75a", {20.f, 20.f, 0.f, 0.f}},
				{"mac10", {20.f, 20.f, 0.f, 0.f}},
				{"ump45", {20.f, 20.f, -10.f, 0.f}},
				{"bizon", {20.f, 20.f, -10.f, 0.f}},
				{"mp7", {20.f, 20.f, -5.f, 0.f}},
				{"mp9", {20.f, 20.f, -10.f, 0.f}},
				{"p90", {20.f, 20.f, -10.f, 0.f}},
				{"galilar", {20.f, 20.f, -15.f, 0.f}},
				{"famas", {20.f, 20.f, -15.f, 0.f}},
				{"m4a1_silencer", {20.f, 20.f, -15.f, 0.f}},
				{"m4a1", {20.f, 20.f, -15.f, 0.f}},
				{"aug", {20.f, 20.f, -10.f, 0.f}},
				{"sg556", {20.f, 20.f, -15.f, 0.f}},
				{"ak47", {20.f, 20.f, -15.f, 0.f}},
				{"g3sg1", {20.f, 20.f, -15.f, 0.f}},
				{"scar20", {20.f, 20.f, -15.f, 0.f}},
				{"awp", {20.f, 20.f, -15.f, 0.f}},
				{"ssg08", {20.f, 20.f, -15.f, 0.f}},
				{"xm1014", {20.f, 20.f, -15.f, 0.f}},
				{"sawedoff", {20.f, 20.f, -15.f, 0.f}},
				{"mag7", {20.f, 20.f, -15.f, 0.f}},
				{"nova", {20.f, 20.f, -15.f, 0.f}},
				{"negev", {20.f, 20.f, -15.f, 0.f}},
				{"m249", {20.f, 20.f, -15.f, 0.f}},
				{"taser", {20.f, 20.f, 0.f, 0.f}},
				{"flashbang", {20.f, 20.f, 5.f, 0.f}},
				{"hegrenade", {20.f, 20.f, 5.f, 0.f}},
				{"smokegrenade", {20.f, 20.f, 5.f, 0.f}},
				{"molotov", {20.f, 20.f, 5.f, 0.f}},
				{"decoy", {20.f, 20.f, 5.f, 0.f}},
				{"incgrenade", {20.f, 20.f, 5.f, 0.f}},
				{"c4", {20.f, 20.f, 0.f, 0.f}},
			};

			ImVec4 GetBoxRect(const CEntity &Entity, int BoxType)
			{
				ImVec4 Rect;
				switch (BoxType)
				{
				case 0:
				case 2:
				case 3:
					Rect = Render::Get2DBox(Entity);
					break;
				case 1:
				case 4:
					Rect = Render::Get2DBoneRect(Entity);
					break;
				default:
					break;
				}

				return Rect;
			}

			const char *RenderWeaponIcon(const CEntity &Entity)
			{
				uintptr_t ClippingWeapon, WeaponData, WeaponNameAddress;
				ProcessMgr.ReadMemory(Entity.Pawn.Address + Offset::Pawn.pClippingWeapon, ClippingWeapon);
				ProcessMgr.ReadMemory(ClippingWeapon + Offset::WeaponBaseData.WeaponDataPTR, WeaponData);
				ProcessMgr.ReadMemory(WeaponData + Offset::WeaponBaseData.szName, WeaponNameAddress);
				const std::string weaponName = WeaponNameAddress ? Entity.Pawn.WeaponName : "NULL";
				return GunIcon(weaponName);
			}

			void RenderPlayerESP(const CEntity &LocalEntity, const CEntity &Entity, ImVec4 Rect, int LocalPlayerControllerIndex, int Index)
			{
				std::string weaponIcon = GunIcon(Entity.Pawn.WeaponName);

				if (SussyAim::Cfg::ESP::drawBones)
					Render::DrawBone(Entity, SussyAim::Cfg::ESP::BoneColor, SussyAim::Cfg::ESP::lineThickness);
				if (SussyAim::Cfg::ESP::drawEyeRay)
					Render::ShowLosLine(Entity, 50.f, SussyAim::Cfg::ESP::EyeRayColor, SussyAim::Cfg::ESP::lineThickness);
				if (SussyAim::Cfg::ESP::drawHeadBox)
					Render::DrawHeadCircle(Entity, SussyAim::Cfg::ESP::HeadBoxColor);

				if (SussyAim::Cfg::ESP::FilledBox)
				{
					float Rounding = SussyAim::Cfg::ESP::boxRounding;
					if (SussyAim::Cfg::ESP::boxType == 2 || SussyAim::Cfg::ESP::boxType == 3)
						Rounding = 0.f;
					ImColor FlatBoxCol = SussyAim::Cfg::ESP::FilledColor;
					ImColor FlatBoxCol2 = SussyAim::Cfg::ESP::FilledColor2;
					ImColor FlatBoxVisCol = SussyAim::Cfg::ESP::BoxFilledVisColor;
					if (SussyAim::Cfg::ESP::FilledVisBox)
					{
						if ((Entity.Pawn.bSpottedByMask & (DWORD64(1) << LocalPlayerControllerIndex)) ||
							(LocalEntity.Pawn.bSpottedByMask & (DWORD64(1) << LocalPlayerControllerIndex)))
						{

							Gui.RectangleFilled({Rect.x, Rect.y}, {Rect.z, Rect.w}, FlatBoxVisCol, Rounding);
						}
						else
						{
							Gui.RectangleFilled({Rect.x, Rect.y}, {Rect.z, Rect.w}, FlatBoxCol, Rounding);
						}
					}
					else
					{
						if (SussyAim::Cfg::ESP::MultiColor)
						{
							Gui.RectangleFilledGraident({Rect.x, Rect.y}, {Rect.z, Rect.w}, SussyAim::Cfg::ESP::FrameColor, FlatBoxCol, FlatBoxCol2, Rounding);
						}
						else
						{
							Gui.RectangleFilled({Rect.x, Rect.y}, {Rect.z, Rect.w}, FlatBoxCol, Rounding);
						}
					}
				}
				if (SussyAim::Cfg::ESP::drawBox)
				{
					if (SussyAim::Cfg::ESP::boxType == 0 || SussyAim::Cfg::ESP::boxType == 1)
					{
						if (SussyAim::Cfg::ESP::drawBoxOutline)
							Gui.Rectangle({Rect.x, Rect.y}, {Rect.z, Rect.w}, SussyAim::Cfg::ESP::FrameColor & IM_COL32_A_MASK, 3, SussyAim::Cfg::ESP::boxRounding);

						if (SussyAim::Cfg::ESP::visibleCheck && ((Entity.Pawn.bSpottedByMask & (DWORD64(1) << LocalPlayerControllerIndex)) || (LocalEntity.Pawn.bSpottedByMask & (DWORD64(1) << Index))))
						{
							Gui.Rectangle({Rect.x, Rect.y}, {Rect.z, Rect.w}, SussyAim::Cfg::ESP::VisibleColor, SussyAim::Cfg::ESP::lineThickness, SussyAim::Cfg::ESP::boxRounding);
						}
						else
						{
							Gui.Rectangle({Rect.x, Rect.y}, {Rect.z, Rect.w}, SussyAim::Cfg::ESP::FrameColor, SussyAim::Cfg::ESP::lineThickness, SussyAim::Cfg::ESP::boxRounding);
						}
					}
					else if (SussyAim::Cfg::ESP::boxType == 2 || SussyAim::Cfg::ESP::boxType == 3)
					{
						// Outline
						Gui.Line({Rect.x, Rect.y}, {Rect.x + Rect.z * 0.25f, Rect.y}, SussyAim::Cfg::ESP::FrameColor & IM_COL32_A_MASK, 3);
						Gui.Line({Rect.x, Rect.y}, {Rect.x, Rect.y + Rect.w * 0.25f}, SussyAim::Cfg::ESP::FrameColor & IM_COL32_A_MASK, 3);
						Gui.Line({Rect.x + Rect.z, Rect.y + Rect.w}, {Rect.x + Rect.z - Rect.z * 0.25f, Rect.y + Rect.w}, SussyAim::Cfg::ESP::FrameColor & IM_COL32_A_MASK, 3);
						Gui.Line({Rect.x + Rect.z, Rect.y + Rect.w}, {Rect.x + Rect.z, Rect.y + Rect.w - Rect.w * 0.25f}, SussyAim::Cfg::ESP::FrameColor & IM_COL32_A_MASK, 3);
						Gui.Line({Rect.x, Rect.y + Rect.w}, {Rect.x + Rect.z * 0.25f, Rect.y + Rect.w}, SussyAim::Cfg::ESP::FrameColor & IM_COL32_A_MASK, 3);
						Gui.Line({Rect.x, Rect.y + Rect.w}, {Rect.x, Rect.y + Rect.w - Rect.w * 0.25f}, SussyAim::Cfg::ESP::FrameColor & IM_COL32_A_MASK, 3);
						Gui.Line({Rect.x + Rect.z, Rect.y}, {Rect.x + Rect.z - Rect.z * 0.25f, Rect.y}, SussyAim::Cfg::ESP::FrameColor & IM_COL32_A_MASK, 3);
						Gui.Line({Rect.x + Rect.z, Rect.y}, {Rect.x + Rect.z, Rect.y + Rect.w * 0.25f}, SussyAim::Cfg::ESP::FrameColor & IM_COL32_A_MASK, 3);

						// Main Box Lines
						ImColor mainBoxColor = SussyAim::Cfg::ESP::visibleCheck && ((Entity.Pawn.bSpottedByMask & (DWORD64(1) << LocalPlayerControllerIndex)) || (LocalEntity.Pawn.bSpottedByMask & (DWORD64(1) << Index))) ? SussyAim::Cfg::ESP::VisibleColor : SussyAim::Cfg::ESP::FrameColor;
						Gui.Line({Rect.x, Rect.y}, {Rect.x + Rect.z * 0.25f, Rect.y}, mainBoxColor, SussyAim::Cfg::ESP::lineThickness);
						Gui.Line({Rect.x, Rect.y}, {Rect.x, Rect.y + Rect.w * 0.25f}, mainBoxColor, SussyAim::Cfg::ESP::lineThickness);
						Gui.Line({Rect.x + Rect.z, Rect.y}, {Rect.x + Rect.z - Rect.z * 0.25f, Rect.y}, mainBoxColor, SussyAim::Cfg::ESP::lineThickness);
						Gui.Line({Rect.x + Rect.z, Rect.y}, {Rect.x + Rect.z, Rect.y + Rect.w * 0.25f}, mainBoxColor, SussyAim::Cfg::ESP::lineThickness);
						Gui.Line({Rect.x, Rect.y + Rect.w}, {Rect.x + Rect.z * 0.25f, Rect.y + Rect.w}, mainBoxColor, SussyAim::Cfg::ESP::lineThickness);
						Gui.Line({Rect.x, Rect.y + Rect.w}, {Rect.x, Rect.y + Rect.w - Rect.w * 0.25f}, mainBoxColor, SussyAim::Cfg::ESP::lineThickness);
						Gui.Line({Rect.x + Rect.z, Rect.y + Rect.w}, {Rect.x + Rect.z - Rect.z * 0.25f, Rect.y + Rect.w}, mainBoxColor, SussyAim::Cfg::ESP::lineThickness);
						Gui.Line({Rect.x + Rect.z, Rect.y + Rect.w}, {Rect.x + Rect.z, Rect.y + Rect.w - Rect.w * 0.25f}, mainBoxColor, SussyAim::Cfg::ESP::lineThickness);
					}
				}

				Render::LineToEnemy(Rect, SussyAim::Cfg::ESP::tracerColor, 1.2);

				if (SussyAim::Cfg::ESP::drawWeapon)
				{
					if (SussyAim::Cfg::Menu::HealthBarType == 0 || SussyAim::Cfg::Menu::HealthBarType == 1)
					{
						WeaponIconSize iconSize = weaponIconSizes[Entity.Pawn.WeaponName];
						ImVec2 textPosition = {Rect.x + (Rect.z - iconSize.width) / 2 + iconSize.offsetX, Rect.y + Rect.w + 1 + iconSize.offsetY};
						if (SussyAim::Cfg::ESP::ammoBar)
							textPosition.y += 5;
						// Gui.StrokeText(Entity.Pawn.WeaponName, { Rect.x + Rect.z / 2,Rect.y + Rect.w + 10}, ImColor(255, 255, 255, 255), 14, true);
						ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.f, ImVec2{textPosition.x - 1, textPosition.y - 1}, ImColor(0, 0, 0, 255), weaponIcon.c_str());
						ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.f, ImVec2{textPosition.x - 1, textPosition.y + 1}, ImColor(0, 0, 0, 255), weaponIcon.c_str());
						ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.f, ImVec2{textPosition.x + 1, textPosition.y + 1}, ImColor(0, 0, 0, 255), weaponIcon.c_str());
						ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.f, ImVec2{textPosition.x + 1, textPosition.y - 1}, ImColor(0, 0, 0, 255), weaponIcon.c_str());
						ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.f, textPosition, ImColor(255, 255, 255, 255), weaponIcon.c_str());
					}
				}

				if (SussyAim::Cfg::ESP::showScoped)
				{
					bool isScoped;
					ImVec2 IconPos = {Rect.x, Rect.y};
					ProcessMgr.ReadMemory<bool>(Entity.Pawn.Address + Offset::Pawn.isScoped, isScoped);
					if (isScoped)
					{
						ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 13.f, ImVec2{IconPos.x - 1, IconPos.y - 1}, ImColor(0, 0, 0, 255), "s");
						ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 13.f, ImVec2{IconPos.x - 1, IconPos.y + 1}, ImColor(0, 0, 0, 255), "s");
						ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 13.f, ImVec2{IconPos.x + 1, IconPos.y + 1}, ImColor(0, 0, 0, 255), "s");
						ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 13.f, ImVec2{IconPos.x + 1, IconPos.y - 1}, ImColor(0, 0, 0, 255), "s");
						ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 13.f, IconPos, ImColor(0, 200, 255, 255), "s");
					}
				}

				if (SussyAim::Cfg::ESP::drawName)
				{
					if (SussyAim::Cfg::Menu::HealthBarType == 0)
						Gui.StrokeText(Entity.Controller.PlayerName, {Rect.x + Rect.z / 2, Rect.y - 14}, ImColor(255, 255, 255, 255), 14, true);
					else
						Gui.StrokeText(Entity.Controller.PlayerName, {Rect.x + Rect.z / 2, Rect.y - 13 - 14}, ImColor(255, 255, 255, 255), 14, true);
				}
			}

			void DrawPreviewBox(const ImVec2 &startPos, const ImVec2 &endPos, ImColor boxColor, float rounding, float thickness, bool filled)
			{
				if (filled)
				{
					ImGui::GetWindowDrawList()->AddRectFilled(startPos, endPos, boxColor, rounding, ImDrawCornerFlags_All);
				}
				else
				{
					ImGui::GetWindowDrawList()->AddRect(startPos, endPos, boxColor, rounding, ImDrawCornerFlags_All, thickness);
				}
			}

			void RenderPreview(ImVec2 windowSize)
			{
				if (!SussyAim::Cfg::ESP::displayPreview)
					return;

				ImVec2 rectSize(100, 150);
				ImVec2 rectPos((windowSize.x - rectSize.x) * 0.45f, (windowSize.y - rectSize.y) * 0.3f);
				ImVec2 centerPos = ImGui::GetCursorScreenPos();
				centerPos.x += rectPos.x;
				centerPos.y += rectPos.y * -1.20f;

				if (SussyAim::Cfg::ESP::drawEyeRay)
				{
					ImU32 EyeC = SussyAim::Cfg::ESP::EyeRayColor;
					ImVec2 lineStart(centerPos.x + 44, centerPos.y + 15);
					ImVec2 lineEnd(centerPos.x - 10, centerPos.y + 20);
					ImGui::GetWindowDrawList()->AddLine(lineStart, lineEnd, EyeC, 2.f);
				}

				if (SussyAim::Cfg::ESP::drawBones)
				{
					ImU32 boneColor = SussyAim::Cfg::ESP::BoneColor;
					ImVec2 SpineStart(centerPos.x + 50, centerPos.y + 25);
					ImVec2 SpineEnd(centerPos.x + 60, centerPos.y + 55);
					ImGui::GetWindowDrawList()->AddLine(SpineStart, SpineEnd, boneColor, 1.8f); // Neck to Spine
					ImVec2 PelvisStart(centerPos.x + 60, centerPos.y + 55);
					ImVec2 PelvisEnd(centerPos.x + 62, centerPos.y + 65);
					ImGui::GetWindowDrawList()->AddLine(PelvisStart, PelvisEnd, boneColor, 1.8f); // Spine to Pelvis
					ImVec2 UL_LegStart(centerPos.x + 62, centerPos.y + 65);
					ImVec2 UL_LegEnd(centerPos.x + 65, centerPos.y + 70);
					ImGui::GetWindowDrawList()->AddLine(UL_LegStart, UL_LegEnd, boneColor, 1.8f); // Left Leg_Up
					ImVec2 ML_LegStart(centerPos.x + 65, centerPos.y + 70);
					ImVec2 ML_LegEnd(centerPos.x + 60, centerPos.y + 100);
					ImGui::GetWindowDrawList()->AddLine(ML_LegStart, ML_LegEnd, boneColor, 1.8f); // Left Leg_Mid
					ImVec2 DL_LegStart(centerPos.x + 60, centerPos.y + 100);
					ImVec2 DL_LegEnd(centerPos.x + 68, centerPos.y + 145);
					ImGui::GetWindowDrawList()->AddLine(DL_LegStart, DL_LegEnd, boneColor, 1.8f); // Left Leg_Down
					ImVec2 UR_LegStart(centerPos.x + 62, centerPos.y + 65);
					ImVec2 UR_LegEnd(centerPos.x + 35, centerPos.y + 100);
					ImGui::GetWindowDrawList()->AddLine(UR_LegStart, UR_LegEnd, boneColor, 1.8f); // Right Leg_Up
					ImVec2 DR_LegStart(centerPos.x + 35, centerPos.y + 100);
					ImVec2 DR_LegEnd(centerPos.x + 47, centerPos.y + 130);
					ImGui::GetWindowDrawList()->AddLine(DR_LegStart, DR_LegEnd, boneColor, 1.8f); // Right Leg_Down
					ImVec2 L_ScapulaStart(centerPos.x + 50, centerPos.y + 25);
					ImVec2 L_ScapulaEnd(centerPos.x + 60, centerPos.y + 30);
					ImGui::GetWindowDrawList()->AddLine(L_ScapulaStart, L_ScapulaEnd, boneColor, 1.8f); // Left Scapula
					ImVec2 UL_ArmStart(centerPos.x + 60, centerPos.y + 30);
					ImVec2 UL_ArmEnd(centerPos.x + 45, centerPos.y + 55);
					ImGui::GetWindowDrawList()->AddLine(UL_ArmStart, UL_ArmEnd, boneColor, 1.8f); // Left Arm_Up
					ImVec2 DL_ArmStart(centerPos.x + 45, centerPos.y + 55);
					ImVec2 DL_ArmEnd(centerPos.x + 25, centerPos.y + 45);
					ImGui::GetWindowDrawList()->AddLine(DL_ArmStart, DL_ArmEnd, boneColor, 1.8f); // Left Arm_Down
					ImVec2 R_ScapulaStart(centerPos.x + 50, centerPos.y + 25);
					ImVec2 R_ScapulaEnd(centerPos.x + 40, centerPos.y + 30);
					ImGui::GetWindowDrawList()->AddLine(R_ScapulaStart, R_ScapulaEnd, boneColor, 1.8f); // Right Scapula
					ImVec2 UR_ArmStart(centerPos.x + 40, centerPos.y + 30);
					ImVec2 UR_ArmEnd(centerPos.x + 27, centerPos.y + 53);
					ImGui::GetWindowDrawList()->AddLine(UR_ArmStart, UR_ArmEnd, boneColor, 1.8f); // Right Arm_Up
					ImVec2 DR_ArmStart(centerPos.x + 27, centerPos.y + 53);
					ImVec2 DR_ArmEnd(centerPos.x + 20, centerPos.y + 45);
					ImGui::GetWindowDrawList()->AddLine(DR_ArmStart, DR_ArmEnd, boneColor, 1.8f); // Right Arm_Down
				}

				if (SussyAim::Cfg::ESP::drawHeadBox)
				{
					switch (SussyAim::Cfg::ESP::HeadBoxStyle)
					{
					case 0:
						ImGui::GetWindowDrawList()->AddCircle({centerPos.x + 44, centerPos.y + 17}, 12.f, SussyAim::Cfg::ESP::HeadBoxColor, 0, 1.8f);
						break;
					case 1:
						ImGui::GetWindowDrawList()->AddCircleFilled({centerPos.x + 44, centerPos.y + 17}, 12.f, SussyAim::Cfg::ESP::HeadBoxColor, 0);
					default:
						break;
					}
				}

				if (SussyAim::Cfg::ESP::FilledBox)
				{
					ImVec2 rectStartPos;
					ImVec2 rectEndPos;
					ImColor filledBoxColor = {SussyAim::Cfg::ESP::FilledColor.Value.x, SussyAim::Cfg::ESP::FilledColor.Value.y, SussyAim::Cfg::ESP::FilledColor.Value.z, SussyAim::Cfg::ESP::FilledColor.Value.w};
					ImColor filledBoxColor2 = {SussyAim::Cfg::ESP::FilledColor2.Value.x, SussyAim::Cfg::ESP::FilledColor2.Value.y, SussyAim::Cfg::ESP::FilledColor2.Value.z, SussyAim::Cfg::ESP::FilledColor2.Value.w};

					rectStartPos = centerPos;
					rectEndPos = {rectStartPos.x + rectSize.x, rectStartPos.y + rectSize.y};

					if (SussyAim::Cfg::ESP::boxType == 0 || SussyAim::Cfg::ESP::boxType == 2)
					{
						if (SussyAim::Cfg::ESP::MultiColor)
							ImGui::GetWindowDrawList()->AddRectFilledMultiColorRounded(rectStartPos, rectEndPos, ImGui::GetColorU32(ImGuiCol_ChildBg), filledBoxColor, filledBoxColor, filledBoxColor2, filledBoxColor2, SussyAim::Cfg::ESP::boxRounding, ImDrawCornerFlags_All);
					}
					else if (SussyAim::Cfg::ESP::boxType == 1)
					{
						rectStartPos = {centerPos.x + 20, centerPos.y + 15};
						rectEndPos = {rectStartPos.x + 50, rectStartPos.y + 132};
						if (SussyAim::Cfg::ESP::MultiColor)
							ImGui::GetWindowDrawList()->AddRectFilledMultiColorRounded(rectStartPos, rectEndPos, ImGui::GetColorU32(ImGuiCol_ChildBg), filledBoxColor, filledBoxColor, filledBoxColor2, filledBoxColor2, SussyAim::Cfg::ESP::boxRounding, ImDrawCornerFlags_All);
					}
				}

				if (SussyAim::Cfg::ESP::drawBox)
				{
					ImVec2 rectStartPos;
					ImVec2 rectEndPos;
					ImColor boxColor = SussyAim::Cfg::ESP::FrameColor;

					rectStartPos = centerPos;
					rectEndPos = {rectStartPos.x + rectSize.x, rectStartPos.y + rectSize.y};

					switch (SussyAim::Cfg::ESP::boxType)
					{
					case 0:
						DrawPreviewBox(rectStartPos, rectEndPos, boxColor, SussyAim::Cfg::ESP::boxRounding, 1.3f, false);
						break;
					case 1:
						// DrawPreviewBox(rectStartPos, rectEndPos, boxColor, SussyAim::Cfg::ESP::BoxRounding, 1.3f, false);
						rectStartPos = {centerPos.x + 20, centerPos.y + 15};
						rectEndPos = {rectStartPos.x + 50, rectStartPos.y + 132};
						DrawPreviewBox(rectStartPos, rectEndPos, boxColor, SussyAim::Cfg::ESP::boxRounding, 1.f, false);
						break;
					case 2:
						ImGui::GetWindowDrawList()->AddLine(rectStartPos, {rectStartPos.x + rectSize.x * 0.25f, rectStartPos.y}, boxColor, 1.3f);
						ImGui::GetWindowDrawList()->AddLine(rectStartPos, {rectStartPos.x, rectStartPos.y + rectSize.y * 0.25f}, boxColor, 1.3f);
						ImGui::GetWindowDrawList()->AddLine({rectStartPos.x + rectSize.x, rectStartPos.y + rectSize.y}, {rectStartPos.x + rectSize.x * 0.75f, rectStartPos.y + rectSize.y}, boxColor, 1.3f);
						ImGui::GetWindowDrawList()->AddLine({rectStartPos.x + rectSize.x, rectStartPos.y + rectSize.y}, {rectStartPos.x + rectSize.x, rectStartPos.y + rectSize.y * 0.75f}, boxColor, 1.3f);
						ImGui::GetWindowDrawList()->AddLine({rectStartPos.x, rectStartPos.y + rectSize.y}, {rectStartPos.x + rectSize.x * 0.25f, rectStartPos.y + rectSize.y}, boxColor, 1.3f);
						ImGui::GetWindowDrawList()->AddLine({rectStartPos.x, rectStartPos.y + rectSize.y}, {rectStartPos.x, rectStartPos.y + rectSize.y * 0.75f}, boxColor, 1.3f);
						ImGui::GetWindowDrawList()->AddLine({rectStartPos.x + rectSize.x, rectStartPos.y}, {rectStartPos.x + rectSize.x * 0.75f, rectStartPos.y}, boxColor, 1.3f);
						ImGui::GetWindowDrawList()->AddLine({rectStartPos.x + rectSize.x, rectStartPos.y}, {rectStartPos.x + rectSize.x, rectStartPos.y + rectSize.y * 0.25f}, boxColor, 1.3f);
						break;
					case 3:
						ImGui::GetWindowDrawList()->AddLine(rectStartPos, {rectStartPos.x + rectSize.x * 0.25f, rectStartPos.y}, boxColor, 1.3f);
						ImGui::GetWindowDrawList()->AddLine(rectStartPos, {rectStartPos.x, rectStartPos.y + rectSize.y * 0.25f}, boxColor, 1.3f);
						ImGui::GetWindowDrawList()->AddLine({rectStartPos.x + rectSize.x, rectStartPos.y + rectSize.y}, {rectStartPos.x + rectSize.x * 0.75f, rectStartPos.y + rectSize.y}, boxColor, 1.3f);
						ImGui::GetWindowDrawList()->AddLine({rectStartPos.x + rectSize.x, rectStartPos.y + rectSize.y}, {rectStartPos.x + rectSize.x, rectStartPos.y + rectSize.y * 0.75f}, boxColor, 1.3f);
						ImGui::GetWindowDrawList()->AddLine({rectStartPos.x, rectStartPos.y + rectSize.y}, {rectStartPos.x + rectSize.x * 0.25f, rectStartPos.y + rectSize.y}, boxColor, 1.3f);
						ImGui::GetWindowDrawList()->AddLine({rectStartPos.x, rectStartPos.y + rectSize.y}, {rectStartPos.x, rectStartPos.y + rectSize.y * 0.75f}, boxColor, 1.3f);
						ImGui::GetWindowDrawList()->AddLine({rectStartPos.x + rectSize.x, rectStartPos.y}, {rectStartPos.x + rectSize.x * 0.75f, rectStartPos.y}, boxColor, 1.3f);
						ImGui::GetWindowDrawList()->AddLine({rectStartPos.x + rectSize.x, rectStartPos.y}, {rectStartPos.x + rectSize.x, rectStartPos.y + rectSize.y * 0.25f}, boxColor, 1.3f);
						break;
					}
				}

				if (SussyAim::Cfg::ESP::drawHealthBar)
				{
					ImU32 greenColor = IM_COL32(0, 255, 0, 255);
					ImVec2 HBPos = centerPos;
					ImVec2 HBSize = rectSize;
					if (SussyAim::Cfg::ESP::boxType == 1 || SussyAim::Cfg::ESP::boxType == 3)
					{
						HBPos = {centerPos.x + 20, centerPos.y + 15};
						HBSize = {rectSize.x - 2, rectSize.y - 18};
					}
					if (SussyAim::Cfg::Menu::HealthBarType == 0)
					{
						ImVec2 HBS(HBPos.x - 6, HBPos.y);
						ImVec2 HBE(HBPos.x - 3, HBPos.y + HBSize.y);
						ImGui::GetWindowDrawList()->AddRectFilled(HBS, HBE, greenColor, 0.f, ImDrawCornerFlags_All);
					}
				}

				if (SussyAim::Cfg::ESP::ArmorBar)
				{
					ImU32 blueColor = IM_COL32(0, 128, 255, 255);
					ImVec2 ABPos = centerPos;
					ImVec2 ABSize = rectSize;

					if (SussyAim::Cfg::ESP::boxType == 1 || SussyAim::Cfg::ESP::boxType == 3)
					{
						ABPos = {centerPos.x + 20, centerPos.y + 15};
						ABSize = {rectSize.x - 2, rectSize.y - 18};
					}

					if (SussyAim::Cfg::ESP::drawHealthBar)
					{
						ABPos.x -= 4;
						ABSize.x -= 4;
					}
					ImVec2 ABS(ABPos.x - 6, ABPos.y);
					ImVec2 ABE(ABPos.x - 3, ABPos.y + ABSize.y);
					ImGui::GetWindowDrawList()->AddRectFilled(ABS, ABE, blueColor, 0.0f, ImDrawCornerFlags_All);
				}

				if (SussyAim::Cfg::ESP::ammoBar)
				{
					ImU32 yellowColor = IM_COL32(255, 255, 0, 255);
					if (SussyAim::Cfg::ESP::boxType == 0 || SussyAim::Cfg::ESP::boxType == 2)
					{
						ImVec2 ABS(centerPos.x, centerPos.y + rectSize.y + 2);
						ImVec2 ABE(centerPos.x + rectSize.x, centerPos.y + rectSize.y + 5);
						ImGui::GetWindowDrawList()->AddRectFilled(ABS, ABE, yellowColor, 0.f, ImDrawCornerFlags_All);
					}
					else
					{
						ImVec2 ABS(centerPos.x + 20, centerPos.y + rectSize.y);
						ImVec2 ABE(centerPos.x + rectSize.x - 30, centerPos.y + rectSize.y + 3);
						ImGui::GetWindowDrawList()->AddRectFilled(ABS, ABE, yellowColor, 0.f, ImDrawCornerFlags_All);
					}
				}

				if (SussyAim::Cfg::ESP::drawTracers)
				{
					ImVec2 LineStart, LineEnd;
					LineStart = {centerPos.x + rectSize.x / 2, centerPos.y};
					switch (SussyAim::Cfg::ESP::tracerPos)
					{
					case 0:
						LineEnd = {LineStart.x, LineStart.y - 50};
						break;
					case 1:
						LineEnd = {Gui.Window.Size.x / 2, Gui.Window.Size.y / 2};
						break;
					case 2:
						LineEnd = {LineStart.x, LineStart.y + 200};
						break;
					}
					ImGui::GetWindowDrawList()->AddLine(LineStart, LineEnd, SussyAim::Cfg::ESP::tracerColor, 1.8f);
				}

				if (SussyAim::Cfg::ESP::drawName)
				{
					if (SussyAim::Cfg::ESP::boxType == 1 || SussyAim::Cfg::ESP::boxType == 3)
					{
						centerPos.x -= 3;
						centerPos.y += 15;
					}
					if (SussyAim::Cfg::Menu::HealthBarType == 0 || SussyAim::Cfg::Menu::HealthBarType == 2)
					{
						ImVec2 textPos(centerPos.x + 30, centerPos.y - 18);
						ImGui::GetWindowDrawList()->AddText(textPos, IM_COL32(255, 255, 255, 255), "Player");
					}
					if (SussyAim::Cfg::Menu::HealthBarType == 1)
					{
						ImVec2 textPos(centerPos.x + 30, centerPos.y - 22);
						ImGui::GetWindowDrawList()->AddText(textPos, IM_COL32(255, 255, 255, 255), "Player");
					}
				}

				if (SussyAim::Cfg::ESP::drawDistance)
				{
					ImVec2 textPos(centerPos.x + 105, centerPos.y);
					if (SussyAim::Cfg::ESP::boxType == 1 || SussyAim::Cfg::ESP::boxType == 3)
					{
						textPos = {textPos.x - 27, textPos.y};
					}
					ImGui::GetWindowDrawList()->AddText(textPos, IM_COL32(255, 204, 0, 255), "20m");
				}

				if (SussyAim::Cfg::ESP::drawWeapon)
				{
					ImVec2 textPos(0, 0);
					if (SussyAim::Cfg::ESP::ammoBar)
						centerPos.y += 5;
					if (SussyAim::Cfg::ESP::boxType == 1 || SussyAim::Cfg::ESP::boxType == 3)
					{
						centerPos.y -= 17;
					}
					if (SussyAim::Cfg::Menu::HealthBarType == 2)
					{
						textPos = {centerPos.x + 27, centerPos.y + 155};
						ImGui::GetWindowDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.f, textPos, IM_COL32(255, 255, 255, 255), "W");
					}
					if (SussyAim::Cfg::Menu::HealthBarType == 0 || SussyAim::Cfg::Menu::HealthBarType == 1)
					{
						textPos = {centerPos.x + 27, centerPos.y + 150};
						ImGui::GetWindowDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.f, textPos, IM_COL32(255, 255, 255, 255), "W");
					}

					if (SussyAim::Cfg::ESP::showScoped)
					{
						if (SussyAim::Cfg::ESP::boxType == 1)
						{
							centerPos.y += 2;
							centerPos.x += 25;
						}
						ImGui::GetWindowDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.f, centerPos, IM_COL32(200, 255, 255, 255), "s");
					}
				}
			}
		}
	}
}
