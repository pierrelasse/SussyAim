#pragma once

#include "methods.hpp"

using namespace SussyAim::view;

namespace SussyAim
{
    namespace view
    {
        namespace menu
        {
            static bool showImGuiDemo = false;

            void render()
            {
                PutSwitch("ImGui Demo", 5.f, ImGui::GetFrameHeight() * 1.7, &showImGuiDemo);

                ImGui::Spacing();

                ImGui::TextDisabled(Lang::MiscText.ThemeList);
                ImGui::SameLine();
                if (ImGui::Combo("###Theme", &SussyAim::Cfg::theme, "Standard\0Custom\0"))
                    StyleChanger::UpdateSkin(SussyAim::Cfg::theme);
                if (SussyAim::Cfg::theme == 1)
                {
                    ImColor windowBgColor = ImGui::GetStyleColorVec4(ImGuiCol_WindowBg);
                    ImColor borderColor = ImGui::GetStyleColorVec4(ImGuiCol_Border);
                    ImColor childBgColor = ImGui::GetStyleColorVec4(ImGuiCol_ChildBg);
                    ImColor ButtonColor = ImGui::GetStyleColorVec4(ImGuiCol_Button);
                    ImColor ButtonHovered = ImGui::GetStyleColorVec4(ImGuiCol_ButtonHovered);
                    ImColor ButtonActive = ImGui::GetStyleColorVec4(ImGuiCol_ButtonActive);
                    ImColor FrameBgColor = ImGui::GetStyleColorVec4(ImGuiCol_FrameBg);
                    ImColor FrameHovered = ImGui::GetStyleColorVec4(ImGuiCol_FrameBgHovered);
                    ImColor FrameActive = ImGui::GetStyleColorVec4(ImGuiCol_FrameBgActive);
                    ImColor Header = ImGui::GetStyleColorVec4(ImGuiCol_Header);
                    ImColor HeaderActive = ImGui::GetStyleColorVec4(ImGuiCol_HeaderActive);
                    ImColor HeaderHovered = ImGui::GetStyleColorVec4(ImGuiCol_HeaderHovered);
                    ImColor ScrollBg = ImGui::GetStyleColorVec4(ImGuiCol_ScrollbarBg);
                    // ########################################
                    ImGui::SeparatorText("Theme Color Settings");
                    PutColorEditor("Button Border", "###ThemeCol1", 5.f, 0.f, reinterpret_cast<float *>(&SussyAim::Cfg::Menu::ButtonBorderColor));
                    PutColorEditor("Border", "###ThemeCol2", 5.f, 0.f, reinterpret_cast<float *>(&borderColor));
                    PutColorEditor("Button", "###ThemeCol3", 5.f, 0.f, reinterpret_cast<float *>(&ButtonColor));
                    PutColorEditor("Button Hovered", "###ThemeCol4", 5.f, 0.f, reinterpret_cast<float *>(&ButtonHovered));
                    PutColorEditor("Button Active", "###ThemeCol5", 5.f, 0.f, reinterpret_cast<float *>(&ButtonActive));
                    PutColorEditor("Child Window Bg", "###ThemeCol6", 5.f, 0.f, reinterpret_cast<float *>(&childBgColor));
                    PutColorEditor("Frame Bg", "###ThemeCol7", 5.f, 0.f, reinterpret_cast<float *>(&FrameBgColor));
                    PutColorEditor("Frame Bg Hovered", "###ThemeCol8", 5.f, 0.f, reinterpret_cast<float *>(&FrameHovered));
                    PutColorEditor("Frame Bg Active", "###ThemeCol9", 5.f, 0.f, reinterpret_cast<float *>(&FrameActive));
                    PutColorEditor("Header", "###ThemeCol10", 5.f, 0.f, reinterpret_cast<float *>(&Header));
                    PutColorEditor("Header Active", "###ThemeCol11", 5.f, 0.f, reinterpret_cast<float *>(&HeaderActive));
                    PutColorEditor("Header Hovered", "###ThemeCol12", 5.f, 0.f, reinterpret_cast<float *>(&HeaderHovered));
                    PutColorEditor("Scrollbar Bg", "###ThemeCol13", 5.f, 0.f, reinterpret_cast<float *>(&ScrollBg));
                    PutColorEditor("Window Bg", "###ThemeCol14", 5.f, 0.f, reinterpret_cast<float *>(&windowBgColor));

                    // Update Color
                    ImGui::GetStyle().Colors[ImGuiCol_Border] = borderColor;
                    ImGui::GetStyle().Colors[ImGuiCol_Button] = ButtonColor;
                    ImGui::GetStyle().Colors[ImGuiCol_ButtonActive] = ButtonActive;
                    ImGui::GetStyle().Colors[ImGuiCol_ButtonHovered] = ButtonHovered;
                    ImGui::GetStyle().Colors[ImGuiCol_FrameBg] = FrameBgColor;
                    ImGui::GetStyle().Colors[ImGuiCol_FrameBgHovered] = FrameHovered;
                    ImGui::GetStyle().Colors[ImGuiCol_FrameBgActive] = FrameActive;
                    ImGui::GetStyle().Colors[ImGuiCol_WindowBg] = windowBgColor;
                    ImGui::GetStyle().Colors[ImGuiCol_ChildBg] = childBgColor;
                    ImGui::GetStyle().Colors[ImGuiCol_Header] = Header;
                    ImGui::GetStyle().Colors[ImGuiCol_HeaderActive] = HeaderActive;
                    ImGui::GetStyle().Colors[ImGuiCol_HeaderHovered] = HeaderHovered;
                    ImGui::GetStyle().Colors[ImGuiCol_ScrollbarBg] = ScrollBg;
                }
            }

            void renderItem()
            {
                if (ImGui::BeginTabItem(ICON_FA_HEART " Menu"))
                {
                    render();
                    ImGui::EndTabItem();
                }
            }
        }
    }
}
