#pragma once

#include "../Resources/Language.h"
#include "../font/IconsFontAwesome5.h"
#include "../renderer.hpp"

namespace SussyAim
{
	namespace view
	{
		inline void AlignRight(float ContentWidth)
		{
			float ColumnContentWidth = ImGui::GetColumnWidth() - ImGui::GetStyle().ItemSpacing.x;
			float checkboxPosX = ImGui::GetColumnOffset() + ColumnContentWidth - ContentWidth;
			ImGui::SetCursorPosX(checkboxPosX);
		}

		inline bool PutSwitch(const char *string, float CursorX, float ContentWidth, bool *v, bool ColorEditor = false, const char *lable = NULL, float col[4] = NULL, const char *Tip = NULL)
		{
			ImGui::PushID(string);

			ImGui::Checkbox("", v);
			if (Tip && ImGui::IsItemHovered())
				ImGui::SetTooltip(Tip);

			if (ColorEditor)
			{
				ImGui::SameLine();
				ImGui::ColorEdit4("", col, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_AlphaPreview);
				if (Tip && ImGui::IsItemHovered())
					ImGui::SetTooltip(Tip);
			}

			ImGui::SameLine();
			ImGui::TextDisabled(string);
			if (ImGui::IsItemClicked())
				(*v) = !(*v);
			if (Tip && ImGui::IsItemHovered())
				ImGui::SetTooltip(Tip);

			ImGui::PopID();

			return v;
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
			if (format == nullptr) return;
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
