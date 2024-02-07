#pragma once

#define ICON_FA_EYE "\xef\x81\xae"

#include "../config/Config.hpp"
#include "../rendering/renderer.hpp"

namespace SussyAim
{
	namespace Features
	{
		namespace ESP
		{
			// https://www.unknowncheats.me/forum/counter-strike-2-a/608799-weapon-icon-esp.html
			const char *GunIcon(const std::string weapon)
			{
				std::map<std::string, const char *> gunIcons = {
					{"nova", "T"},
					{"ak47", "A"},
					{"awp", "C"},
					{"m4a4", "M"},
					{"deagle", "F"},
					{"mp9", "R"},
					{"famas", "H"},
					{"ump45", "b"},
					{"glock", "g"},
				};

				gunIcons["knife"] = "]";
				gunIcons["knife_t"] = "[";
				gunIcons["deagle"] = "A";
				gunIcons["elite"] = "B";
				gunIcons["fiveseven"] = "C";
				gunIcons["glock"] = "D";		//
				gunIcons["revolver"] = "J";		//
				gunIcons["hkp2000"] = "E";		//
				gunIcons["p250"] = "F";			//
				gunIcons["usp_silencer"] = "G"; //
				gunIcons["tec9"] = "H";			//
				gunIcons["cz75a"] = "I";		//
				gunIcons["mac10"] = "K";		//
				gunIcons["ump45"] = "L";
				gunIcons["bizon"] = "M"; //
				gunIcons["mp7"] = "N";	 //
				gunIcons["mp9"] = "R";
				gunIcons["p90"] = "O";
				gunIcons["galilar"] = "Q";
				gunIcons["famas"] = "R";
				gunIcons["m4a1_silencer"] = "T"; //
				gunIcons["m4a1"] = "S";			 //
				gunIcons["aug"] = "U";
				gunIcons["sg556"] = "V";
				gunIcons["ak47"] = "W";
				gunIcons["g3sg1"] = "X";
				gunIcons["scar20"] = "Y"; //
				gunIcons["awp"] = "Z";
				gunIcons["ssg08"] = "a"; //
				gunIcons["xm1014"] = "b";
				gunIcons["sawedoff"] = "c";
				gunIcons["mag7"] = "d";
				gunIcons["nova"] = "e";
				gunIcons["negev"] = "f";
				gunIcons["m249"] = "g";
				gunIcons["taser"] = "h";
				gunIcons["flashbang"] = "i";
				gunIcons["hegrenade"] = "j";
				gunIcons["smokegrenade"] = "k";
				gunIcons["molotov"] = "l"; //
				gunIcons["decoy"] = "m";
				gunIcons["incgrenade"] = "n";
				gunIcons["c4"] = "o";

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
			std::unordered_map<std::string, WeaponIconSize> weaponIconSizes = {
				{"knife", {20.0f, 20.0f, -8.0f, 0.0f}},
				{"deagle", {20.0f, 20.0f, -8.0f, 0.0f}},
				{"elite", {20.0f, 20.0f, 0.0f, 0.0f}},
				{"fiveseven", {20.0f, 20.0f, 0.0f, 0.0f}},
				{"glock", {20.0f, 20.0f, 0.0f, 0.0f}},
				{"revolver", {20.0f, 20.0f, -5.0f, 0.0f}},
				{"hkp2000", {20.0f, 20.0f, 0.0f, 0.0f}},
				{"p250", {20.0f, 20.0f, 0.0f, 0.0f}},
				{"usp_silencer", {20.0f, 20.0f, 0.0f, 0.0f}},
				{"tec9", {20.0f, 20.0f, 0.0f, 0.0f}},
				{"cz75a", {20.0f, 20.0f, 0.0f, 0.0f}},
				{"mac10", {20.0f, 20.0f, 0.0f, 0.0f}},
				{"ump45", {20.0f, 20.0f, -10.0f, 0.0f}},
				{"bizon", {20.0f, 20.0f, -10.0f, 0.0f}},
				{"mp7", {20.0f, 20.0f, -5.0f, 0.0f}},
				{"mp9", {20.0f, 20.0f, -10.0f, 0.0f}},
				{"p90", {20.0f, 20.0f, -10.0f, 0.0f}},
				{"galilar", {20.0f, 20.0f, -15.0f, 0.0f}},
				{"famas", {20.0f, 20.0f, -15.0f, 0.0f}},
				{"m4a1_silencer", {20.0f, 20.0f, -15.0f, 0.0f}},
				{"m4a1", {20.0f, 20.0f, -15.0f, 0.0f}},
				{"aug", {20.0f, 20.0f, -10.0f, 0.0f}},
				{"sg556", {20.0f, 20.0f, -15.0f, 0.0f}},
				{"ak47", {20.0f, 20.0f, -15.0f, 0.0f}},
				{"g3sg1", {20.0f, 20.0f, -15.0f, 0.0f}},
				{"scar20", {20.0f, 20.0f, -15.0f, 0.0f}},
				{"awp", {20.0f, 20.0f, -15.0f, 0.0f}},
				{"ssg08", {20.0f, 20.0f, -15.0f, 0.0f}},
				{"xm1014", {20.0f, 20.0f, -15.0f, 0.0f}},
				{"sawedoff", {20.0f, 20.0f, -15.0f, 0.0f}},
				{"mag7", {20.0f, 20.0f, -15.0f, 0.0f}},
				{"nova", {20.0f, 20.0f, -15.0f, 0.0f}},
				{"negev", {20.0f, 20.0f, -15.0f, 0.0f}},
				{"m249", {20.0f, 20.0f, -15.0f, 0.0f}},
				{"taser", {20.0f, 20.0f, 0.0f, 0.0f}},
				{"flashbang", {20.0f, 20.0f, 5.0f, 0.0f}},
				{"hegrenade", {20.0f, 20.0f, 5.0f, 0.0f}},
				{"smokegrenade", {20.0f, 20.0f, 5.0f, 0.0f}},
				{"molotov", {20.0f, 20.0f, 5.0f, 0.0f}},
				{"decoy", {20.0f, 20.0f, 5.0f, 0.0f}},
				{"incgrenade", {20.0f, 20.0f, 5.0f, 0.0f}},
				{"c4", {20.0f, 20.0f, 0.0f, 0.0f}},
			};

			ImVec4 GetBoxRect(const CEntity &Entity, int BoxType)
			{
				ImVec4 Rect;
				switch (BoxType)
				{
				case 0:
					Rect = Render::Get2DBox(Entity);
					break;
				case 1:
					Rect = Render::Get2DBoneRect(Entity);
					break;
				case 2:
					Rect = Render::Get2DBox(Entity);
					break;
				case 3:
					Rect = Render::Get2DBox(Entity);
					break;
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
				ProcessMgr.ReadMemory(ClippingWeapon + 0x360, WeaponData);
				ProcessMgr.ReadMemory(WeaponData + Offset::WeaponBaseData.szName, WeaponNameAddress);
				std::string weaponName = "Invalid Weapon Name";

				if (!WeaponNameAddress)
				{
					weaponName = "NULL";
				}
				else
				{
					weaponName = Entity.Pawn.WeaponName;
				}
				std::string weaponIcon = GunIcon(weaponName);
				return weaponIcon.c_str();
			}

			void RenderPlayerESP(const CEntity &LocalEntity, const CEntity &Entity, ImVec4 Rect, int LocalPlayerControllerIndex, int Index)
			{
				std::string weaponIcon = GunIcon(Entity.Pawn.WeaponName);

				if (SussyAim::Cfg::ESP::drawBones)
					Render::DrawBone(Entity, SussyAim::Cfg::ESP::BoneColor, 1.3f);
				if (SussyAim::Cfg::ESP::drawEyeRay)
					Render::ShowLosLine(Entity, 50.0f, SussyAim::Cfg::ESP::EyeRayColor, 1.3f);
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

						if (((Entity.Pawn.bSpottedByMask & (DWORD64(1) << LocalPlayerControllerIndex)) || (LocalEntity.Pawn.bSpottedByMask & (DWORD64(1) << Index))) && SussyAim::Cfg::ESP::visibleCheck)
						{
							Gui.Rectangle({Rect.x, Rect.y}, {Rect.z, Rect.w}, SussyAim::Cfg::ESP::VisibleColor, 1.3, SussyAim::Cfg::ESP::boxRounding);
						}
						else
						{
							Gui.Rectangle({Rect.x, Rect.y}, {Rect.z, Rect.w}, SussyAim::Cfg::ESP::FrameColor, 1.3, SussyAim::Cfg::ESP::boxRounding);
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
						if (((Entity.Pawn.bSpottedByMask & (DWORD64(1) << LocalPlayerControllerIndex)) || (LocalEntity.Pawn.bSpottedByMask & (DWORD64(1) << Index))) && SussyAim::Cfg::ESP::visibleCheck)
						{
							Gui.Line({Rect.x, Rect.y}, {Rect.x + Rect.z * 0.25f, Rect.y}, SussyAim::Cfg::ESP::VisibleColor, 1.3f);
							Gui.Line({Rect.x, Rect.y}, {Rect.x, Rect.y + Rect.w * 0.25f}, SussyAim::Cfg::ESP::VisibleColor, 1.3f);
							Gui.Line({Rect.x + Rect.z, Rect.y}, {Rect.x + Rect.z - Rect.z * 0.25f, Rect.y}, SussyAim::Cfg::ESP::VisibleColor, 1.3f);
							Gui.Line({Rect.x + Rect.z, Rect.y}, {Rect.x + Rect.z, Rect.y + Rect.w * 0.25f}, SussyAim::Cfg::ESP::VisibleColor, 1.3f);
							Gui.Line({Rect.x, Rect.y + Rect.w}, {Rect.x + Rect.z * 0.25f, Rect.y + Rect.w}, SussyAim::Cfg::ESP::VisibleColor, 1.3f);
							Gui.Line({Rect.x, Rect.y + Rect.w}, {Rect.x, Rect.y + Rect.w - Rect.w * 0.25f}, SussyAim::Cfg::ESP::VisibleColor, 1.3f);
							Gui.Line({Rect.x + Rect.z, Rect.y + Rect.w}, {Rect.x + Rect.z - Rect.z * 0.25f, Rect.y + Rect.w}, SussyAim::Cfg::ESP::VisibleColor, 1.3f);
							Gui.Line({Rect.x + Rect.z, Rect.y + Rect.w}, {Rect.x + Rect.z, Rect.y + Rect.w - Rect.w * 0.25f}, SussyAim::Cfg::ESP::VisibleColor, 1.3f);
						}
						else
						{
							Gui.Line({Rect.x, Rect.y}, {Rect.x + Rect.z * 0.25f, Rect.y}, SussyAim::Cfg::ESP::FrameColor, 1.3f);
							Gui.Line({Rect.x, Rect.y}, {Rect.x, Rect.y + Rect.w * 0.25f}, SussyAim::Cfg::ESP::FrameColor, 1.3f);
							Gui.Line({Rect.x + Rect.z, Rect.y}, {Rect.x + Rect.z - Rect.z * 0.25f, Rect.y}, SussyAim::Cfg::ESP::FrameColor, 1.3f);
							Gui.Line({Rect.x + Rect.z, Rect.y}, {Rect.x + Rect.z, Rect.y + Rect.w * 0.25f}, SussyAim::Cfg::ESP::FrameColor, 1.3f);
							Gui.Line({Rect.x, Rect.y + Rect.w}, {Rect.x + Rect.z * 0.25f, Rect.y + Rect.w}, SussyAim::Cfg::ESP::FrameColor, 1.3f);
							Gui.Line({Rect.x, Rect.y + Rect.w}, {Rect.x, Rect.y + Rect.w - Rect.w * 0.25f}, SussyAim::Cfg::ESP::FrameColor, 1.3f);
							Gui.Line({Rect.x + Rect.z, Rect.y + Rect.w}, {Rect.x + Rect.z - Rect.z * 0.25f, Rect.y + Rect.w}, SussyAim::Cfg::ESP::FrameColor, 1.3f);
							Gui.Line({Rect.x + Rect.z, Rect.y + Rect.w}, {Rect.x + Rect.z, Rect.y + Rect.w - Rect.w * 0.25f}, SussyAim::Cfg::ESP::FrameColor, 1.3f);
						}
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
						ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.0f, ImVec2{textPosition.x - 1, textPosition.y - 1}, ImColor(0, 0, 0, 255), weaponIcon.c_str());
						ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.0f, ImVec2{textPosition.x - 1, textPosition.y + 1}, ImColor(0, 0, 0, 255), weaponIcon.c_str());
						ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.0f, ImVec2{textPosition.x + 1, textPosition.y + 1}, ImColor(0, 0, 0, 255), weaponIcon.c_str());
						ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.0f, ImVec2{textPosition.x + 1, textPosition.y - 1}, ImColor(0, 0, 0, 255), weaponIcon.c_str());
						ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.0f, textPosition, ImColor(255, 255, 255, 255), weaponIcon.c_str());
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
					ImGui::GetWindowDrawList()->AddLine(lineStart, lineEnd, EyeC, 2.0f);
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
						ImGui::GetWindowDrawList()->AddCircle({centerPos.x + 44, centerPos.y + 17}, 12.0f, SussyAim::Cfg::ESP::HeadBoxColor, 0, 1.8f);
						break;
					case 1:
						ImGui::GetWindowDrawList()->AddCircleFilled({centerPos.x + 44, centerPos.y + 17}, 12.0f, SussyAim::Cfg::ESP::HeadBoxColor, 0);
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
						DrawPreviewBox(rectStartPos, rectEndPos, boxColor, SussyAim::Cfg::ESP::boxRounding, 1.0f, false);
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
						ImGui::GetWindowDrawList()->AddRectFilled(HBS, HBE, greenColor, 0.0f, ImDrawCornerFlags_All);
					}
				}

				if (SussyAim::Cfg::ESP::ammoBar)
				{
					ImU32 yellowColor = IM_COL32(255, 255, 0, 255);
					if (SussyAim::Cfg::ESP::boxType == 0 || SussyAim::Cfg::ESP::boxType == 2)
					{
						ImVec2 ABS(centerPos.x, centerPos.y + rectSize.y + 2);
						ImVec2 ABE(centerPos.x + rectSize.x, centerPos.y + rectSize.y + 5);
						ImGui::GetWindowDrawList()->AddRectFilled(ABS, ABE, yellowColor, 0.0f, ImDrawCornerFlags_All);
					}
					else
					{
						ImVec2 ABS(centerPos.x + 20, centerPos.y + rectSize.y);
						ImVec2 ABE(centerPos.x + rectSize.x - 30, centerPos.y + rectSize.y + 3);
						ImGui::GetWindowDrawList()->AddRectFilled(ABS, ABE, yellowColor, 0.0f, ImDrawCornerFlags_All);
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
						ImGui::GetWindowDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.0f, textPos, IM_COL32(255, 255, 255, 255), "W");
					}
					if (SussyAim::Cfg::Menu::HealthBarType == 0 || SussyAim::Cfg::Menu::HealthBarType == 1)
					{
						textPos = {centerPos.x + 27, centerPos.y + 150};
						ImGui::GetWindowDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.0f, textPos, IM_COL32(255, 255, 255, 255), "W");
					}
				}
			}
		}
	}
}
