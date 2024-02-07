#pragma once

#include "OS-ImGui/OS-ImGui_External.h"

namespace Styles
{
    inline void Style1()
    {
        // AimStar style from ImThemes
        ImGuiStyle &style = ImGui::GetStyle();

        style.Alpha = 1.0f;
        style.DisabledAlpha = 0.6000000238418579f;
        style.WindowPadding = ImVec2(6.0f, 3.0f);
        style.WindowRounding = 10.0f;
        style.WindowBorderSize = 1.0f;
        style.WindowMinSize = ImVec2(32.0f, 32.0f);
        style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
        style.WindowMenuButtonPosition = ImGuiDir_Left;
        style.ChildRounding = 10.0f;
        style.ChildBorderSize = 1.0f;
        style.PopupRounding = 5.0f;
        style.PopupBorderSize = 1.0f;
        style.FramePadding = ImVec2(5.0f, 1.0f);
        style.FrameRounding = 5.0f;
        style.FrameBorderSize = 1.0f;
        style.ItemSpacing = ImVec2(8.0f, 4.0f);
        style.ItemInnerSpacing = ImVec2(4.0f, 4.0f);
        style.CellPadding = ImVec2(4.0f, 2.0f);
        style.IndentSpacing = 21.0f;
        style.ColumnsMinSpacing = 6.0f;
        style.ScrollbarSize = 13.0f;
        style.ScrollbarRounding = 16.0f;
        style.GrabMinSize = 20.0f;
        style.GrabRounding = 5.0f;
        style.TabRounding = 4.0f;
        style.TabBorderSize = 1.0f;
        style.TabMinWidthForCloseButton = 0.0f;
        style.ColorButtonPosition = ImGuiDir_Right;
        style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
        style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

        style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 0.9999899864196777f, 0.9999899864196777f, 1.0f);
        style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.6909871101379395f, 0.6909801959991455f, 0.6909801959991455f, 1.0f);
        style.Colors[ImGuiCol_WindowBg] = ImVec4(0.15f, 0.1f, 0.1f, 0.95f);
        style.Colors[ImGuiCol_ChildBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.5021458864212036f);
        style.Colors[ImGuiCol_PopupBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.6909871101379395f);
        style.Colors[ImGuiCol_Border] = ImVec4(0.2f, 0.2f, 0.2f, 0.8f);
        style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
        style.Colors[ImGuiCol_FrameBg] = ImVec4(0.545064389705658f, 0.4210797846317291f, 0.0f, 0.5021458864212036f);
        style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(1.0f, 0.9999961853027344f, 0.9999899864196777f, 0.3133047223091125f);
        style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.3991416096687317f, 0.2261231392621994f, 0.0f, 0.7803921699523926f);
        style.Colors[ImGuiCol_TitleBg] = ImVec4(0.8240343332290649f, 0.6153732538223267f, 0.0f, 0.7882353067398071f);
        style.Colors[ImGuiCol_TitleBgActive] = ImVec4(1.0f, 0.6952775716781616f, 0.0f, 1.0f);
        style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.0f, 0.6952789425849915f, 0.0f, 0.5021458864212036f);
        style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.2000000029802322f, 0.2196078449487686f, 0.2666666805744171f, 0.4699999988079071f);
        style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.6223175525665283f, 0.4326825439929962f, 0.0f, 0.6309012770652771f);
        style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(1.0f, 0.9999956488609314f, 0.9999899864196777f, 1.0f);
        style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.8755365014076233f, 0.8755277395248413f, 0.8755320310592651f, 1.0f);
        style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.6781115531921387f, 0.6781047582626343f, 0.6781077980995178f, 1.0f);
        style.Colors[ImGuiCol_CheckMark] = ImVec4(0.9999899864196777f, 0.9999945759773254f, 1.0f, 1.0f);
        style.Colors[ImGuiCol_SliderGrab] = ImVec4(1.0f, 0.6180257201194763f, 0.0f, 1.0f);
        style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(1.0f, 0.7210299968719482f, 0.0f, 1.0f);
        style.Colors[ImGuiCol_Button] = ImVec4(1.0f, 0.892856776714325f, 0.0f, 0.5021458864212036f);
        style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.9964632391929626f, 1.0f, 0.1759656667709351f, 0.5965665578842163f);
        style.Colors[ImGuiCol_ButtonActive] = ImVec4(1.0f, 0.6695278882980347f, 0.0f, 0.501960813999176f);
        style.Colors[ImGuiCol_Header] = ImVec4(1.0f, 0.5150211453437805f, 0.0f, 0.7854077219963074f);
        style.Colors[ImGuiCol_HeaderHovered] = ImVec4(1.0f, 0.6431143879890442f, 0.266094446182251f, 0.7854077219963074f);
        style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.8369098901748657f, 0.4296424686908722f, 0.0f, 0.7843137383460999f);
        style.Colors[ImGuiCol_Separator] = ImVec4(0.2618025541305542f, 0.2618019878864288f, 0.2617999315261841f, 0.5f);
        style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.09803923219442368f, 0.4388959109783173f, 0.7490196228027344f, 0.7799999713897705f);
        style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.09803921729326248f, 0.4000000059604645f, 0.7490196228027344f, 1.0f);
        style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.4666666686534882f, 0.7686274647712708f, 0.8274509906768799f, 0.03999999910593033f);
        style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.4549019634723663f, 0.196078434586525f, 0.2980392277240753f, 1.0f);
        style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.4549019634723663f, 0.196078434586525f, 0.2980392277240753f, 1.0f);
        style.Colors[ImGuiCol_Tab] = ImVec4(1.0f, 0.1605149984359741f, 1.0f, 0.8619999885559082f);
        style.Colors[ImGuiCol_TabHovered] = ImVec4(0.991416335105896f, 0.5181589126586914f, 0.2510453462600708f, 0.8627451062202454f);
        style.Colors[ImGuiCol_TabActive] = ImVec4(0.716738224029541f, 0.2585869431495667f, 0.0f, 0.8627451062202454f);
        style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.06666667014360428f, 0.1019607856869698f, 0.1450980454683304f, 0.9724000096321106f);
        style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.1333333402872086f, 0.2588235437870026f, 0.4235294163227081f, 1.0f);
        style.Colors[ImGuiCol_PlotLines] = ImVec4(0.8588235378265381f, 0.929411768913269f, 0.886274516582489f, 0.6299999952316284f);
        style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.1974248886108398f, 1.0f, 0.0f, 1.0f);
        style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.8588235378265381f, 0.929411768913269f, 0.886274516582489f, 0.6299999952316284f);
        style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.4549019634723663f, 0.196078434586525f, 0.2980392277240753f, 1.0f);
        style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.2017146944999695f, 0.2017146944999695f, 0.2017167210578918f, 1.0f);
        style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(0.4034294486045837f, 0.4034294486045837f, 0.4034335017204285f, 1.0f);
        style.Colors[ImGuiCol_TableBorderLight] = ImVec4(9.999899930335232e-07f, 9.999899930335232e-07f, 9.999999974752427e-07f, 0.0f);
        style.Colors[ImGuiCol_TableRowBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
        style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(9.999999974752427e-07f, 9.999899930335232e-07f, 9.999899930335232e-07f, 0.2231759428977966f);
        style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.729613721370697f, 0.7296063899993896f, 0.7296098470687866f, 0.4300000071525574f);
        style.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.0f, 1.0f, 0.0f, 0.8999999761581421f);
        style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.2588235437870026f, 0.5882353186607361f, 0.9764705896377563f, 1.0f);
        style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.0f, 1.0f, 1.0f, 0.699999988079071f);
        style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.800000011920929f, 0.800000011920929f, 0.800000011920929f, 0.2000000029802322f);
        style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.800000011920929f, 0.800000011920929f, 0.800000011920929f, 0.3499999940395355f);
    }
}
