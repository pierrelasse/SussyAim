#pragma once

#include "methods.hpp"

using namespace SussyAim::view;

namespace SussyAim
{
    namespace view
    {
        namespace fun
        {
            void render()
            {
                PutSwitch(Lang::MiscText.FakeDuck, 10.f, ImGui::GetFrameHeight() * 1.7, &SussyAim::Cfg::Misc::fakeDuck, false, 0, 0, "This can cause a BAN!11");
            }

            void renderItem()
            {
                if (ImGui::BeginTabItem(ICON_FA_FUTBOL " Fun"))
                {
                    render();
                    ImGui::EndTabItem();
                }
            }
        }
    }
}
