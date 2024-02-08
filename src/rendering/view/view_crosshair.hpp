#pragma once

#include "methods.hpp"

using namespace SussyAim::view;

namespace SussyAim
{
    namespace view
    {
        namespace crosshair
        {
            inline float DotMin = 1.f, DotMax = 50.f;
            inline int LengthMin = 1, LengthMax = 100;
            inline int GapMin = 1, GapMax = 50;
            inline int ThickMin = 1, ThickMax = 20;
            inline float CircleRmin = 1.f, CircleRmax = 50.f;

            void render()
            {
                PutSwitch("Enabled", 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Crosshair::ShowCrossHair, true, "###CrosshairsCol", reinterpret_cast<float *>(&SussyAim::Cfg::Crosshair::CrossHairColor));

                ImGui::Spacing();

                if (SussyAim::Cfg::Crosshair::ShowCrossHair)
                {
                    PutSwitch(Lang::CrosshairsText.Dot, 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Crosshair::drawDot);
                    if (SussyAim::Cfg::Crosshair::drawDot)
                        PutSliderFloat(Lang::CrosshairsText.DotSizeSlider, 5.f, &SussyAim::Cfg::Crosshair::DotSize, &DotMin, &DotMax, "%.f px");
                    PutSwitch(Lang::CrosshairsText.Outline, 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Crosshair::drawOutLine);
                    PutSwitch(Lang::CrosshairsText.Crossline, 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Crosshair::drawCrossline);
                    if (SussyAim::Cfg::Crosshair::drawCrossline)
                    {
                        PutSliderInt(Lang::CrosshairsText.hLengthSlider, 5.f, &SussyAim::Cfg::Crosshair::HorizontalLength, &LengthMin, &LengthMax, "%d px");
                        PutSliderInt(Lang::CrosshairsText.vLengthSilder, 5.f, &SussyAim::Cfg::Crosshair::VerticalLength, &LengthMin, &LengthMax, "%d px");
                        PutSliderInt(Lang::CrosshairsText.GapSlider, 5.f, &SussyAim::Cfg::Crosshair::Gap, &GapMin, &GapMax, "%d px");
                        PutSliderInt(Lang::CrosshairsText.ThicknessSlider, 5.f, &SussyAim::Cfg::Crosshair::Thickness, &ThickMin, &ThickMax, "%d px");
                    }
                    PutSwitch(Lang::CrosshairsText.tStyle, 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Crosshair::tStyle);
                    PutSwitch(Lang::CrosshairsText.Circle, 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Crosshair::drawCircle);
                    if (SussyAim::Cfg::Crosshair::drawCircle)
                        PutSliderFloat(Lang::CrosshairsText.RadiusSlider, 5.f, &SussyAim::Cfg::Crosshair::CircleRadius, &CircleRmin, &CircleRmax, "%.f px");
                    PutSwitch(Lang::CrosshairsText.TargetCheck, 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Menu::TargetingCrosshairs, true, "###CircleCol", reinterpret_cast<float *>(&SussyAim::Cfg::Crosshair::TargetedColor));
                    PutSwitch(Lang::CrosshairsText.TeamCheck, 5.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Crosshair::TeamCheck);
                }
            }

            void renderItem()
            {
                if (ImGui::BeginTabItem(ICON_FA_DOT_CIRCLE " Crosshair"))
                {
                    render();
                    ImGui::EndTabItem();
                }
            }
        }
    }
}
