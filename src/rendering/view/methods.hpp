#pragma once

#include "../Resources/Language.h"
#include "../font/IconsFontAwesome5.h"
#include "../renderer.hpp"

namespace SussyAim
{
	namespace view
	{
		inline ID3D11ShaderResourceView *AS_Logo = NULL;
		inline ID3D11ShaderResourceView *MenuButton1 = NULL;
		inline ID3D11ShaderResourceView *MenuButton2 = NULL;
		inline ID3D11ShaderResourceView *MenuButton3 = NULL;
		inline ID3D11ShaderResourceView *MenuButton4 = NULL;
		inline int LogoW = 0, LogoH = 0;
		inline int LogoW2 = 0, LogoH2 = 0;
		inline int buttonW = 0, buttonH = 0;

		inline void AlignRight(float ContentWidth)
		{
			float ColumnContentWidth = ImGui::GetColumnWidth() - ImGui::GetStyle().ItemSpacing.x;
			float checkboxPosX = ImGui::GetColumnOffset() + ColumnContentWidth - ContentWidth;
			ImGui::SetCursorPosX(checkboxPosX);
		}

		inline void PutSwitch(const char *string, float CursorX, float ContentWidth, bool *v, bool ColorEditor = false, const char *lable = NULL, float col[4] = NULL, const char *Tip = NULL)
		{
			ImGui::PushID(string);
			float CurrentCursorX = ImGui::GetCursorPosX();
			ImGui::SetCursorPosX(CurrentCursorX + CursorX);
			ImGui::TextDisabled(string);
			if (Tip && ImGui::IsItemHovered())
				ImGui::SetTooltip(Tip);
			ImGui::SameLine();
			if (ColorEditor)
			{
				AlignRight(ContentWidth + ImGui::GetFrameHeight() + 8);
				ImGui::ColorEdit4(lable, col, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_AlphaPreview);
				ImGui::SameLine();
			}
			else
			{
				AlignRight(ContentWidth);
			}

			Gui.SwitchButton(string, v);
			ImGui::PopID();
		}

		inline void PutColorEditor(const char *text, const char *lable, float CursorX, float ContentWidth, float col[4], const char *Tip = NULL)
		{
			ImGui::PushID(text);
			float CurrentCursorX = ImGui::GetCursorPosX();
			ImGui::SetCursorPosX(CurrentCursorX + CursorX);
			ImGui::TextDisabled(text);
			if (Tip && ImGui::IsItemHovered())
				ImGui::SetTooltip(Tip);
			ImGui::SameLine();
			AlignRight(ContentWidth + ImGui::GetFrameHeight() + 8);
			ImGui::ColorEdit4(lable, col, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_AlphaPreview);
			ImGui::PopID();
		}

		inline void PutSliderFloat(const char *string, float CursorX, float *v, const void *p_min, const void *p_max, const char *format)
		{
			// if there is no fucking ID, all the sliders would be fucking forced to sync when you click on one of them ;3
			ImGui::PushID(string);
			float CurrentCursorX = ImGui::GetCursorPosX();
			float SliderWidth = ImGui::GetColumnWidth() - ImGui::GetStyle().ItemSpacing.x - CursorX;
			ImGui::SetCursorPosX(CurrentCursorX + CursorX);
			ImGui::TextDisabled(string);
			ImGui::SameLine();
			ImGui::TextDisabled(format, *v);
			ImGui::SetCursorPosX(CurrentCursorX + CursorX);
			ImGui::SetNextItemWidth(SliderWidth);
			Gui.SliderScalarEx2("", ImGuiDataType_Float, v, p_min, p_max, "", ImGuiSliderFlags_None);
			ImGui::PopID();
		}

		inline void PutSliderInt(const char *string, float CursorX, int *v, const void *p_min, const void *p_max, const char *format)
		{
			ImGui::PushID(string);
			float CurrentCursorX = ImGui::GetCursorPosX();
			float SliderWidth = ImGui::GetColumnWidth() - ImGui::GetStyle().ItemSpacing.x - CursorX;
			ImGui::SetCursorPosX(CurrentCursorX + CursorX);
			ImGui::TextDisabled(string);
			ImGui::SameLine();
			ImGui::TextDisabled(format, *v);
			ImGui::SetCursorPosX(CurrentCursorX + CursorX);
			ImGui::SetNextItemWidth(SliderWidth);
			Gui.SliderScalarEx2("", ImGuiDataType_Float, v, p_min, p_max, "", ImGuiSliderFlags_None);
			ImGui::PopID();
		}
	}
}
