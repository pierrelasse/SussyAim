#pragma once

#include "../sacommon.hpp"
#include "../game/Entity.h"
#include "../config/Config.hpp"

namespace SussyAim
{
	namespace Features
	{
		namespace BombTimer
		{
			inline bool isPlanted = false;
			inline std::time_t plantTime;

			uint64_t currentTimeMillis()
			{
				using namespace std::chrono;
				return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
			}

			int getBombSite(bool Planted)
			{
				if (Planted)
				{
					int site;
					uintptr_t cPlantedC4;
					ProcessMgr.ReadMemory(gGame.GetClientDLLAddress() + Offset::PlantedC4, cPlantedC4);
					if (!ProcessMgr.ReadMemory<uintptr_t>(gGame.GetClientDLLAddress() + Offset::PlantedC4, cPlantedC4))
						return 0;
					if (!ProcessMgr.ReadMemory<uintptr_t>(cPlantedC4, cPlantedC4))
						return 0;

					if (!ProcessMgr.ReadMemory<int>(cPlantedC4 + Offset::C4.m_nBombSite, site))
						return 0;

					return site;
				}
			}

			void render()
			{
				if (!SussyAim::Cfg::Misc::bombTimer)
					return;

				const unsigned long long plantedAddress = gGame.GetClientDLLAddress() + Offset::PlantedC4 - 0x8;
				bool isBombPlanted;
				ProcessMgr.ReadMemory(plantedAddress, isBombPlanted);
				if (!isBombPlanted)
					return;

				static const float windowWidth = 200.f;

				ImGui::SetNextWindowPos({(ImGui::GetIO().DisplaySize.x - 200.0f) / 2.0f, 80.0f}, ImGuiCond_Once);
				ImGui::SetNextWindowSize({windowWidth, 0}, ImGuiCond_Once);

				static const ImGuiWindowFlags flags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize;
				ImGui::Begin("Bomb Timer", nullptr, flags);

				bool IsBeingDefused;
				ProcessMgr.ReadMemory(Offset::PlantedC4 + Offset::C4.m_bBeingDefused, IsBeingDefused);
				float DefuseTime;
				ProcessMgr.ReadMemory(Offset::PlantedC4 + Offset::C4.m_flDefuseCountDown, DefuseTime);

				const auto time = currentTimeMillis();

				if (isBombPlanted && !isPlanted && (plantTime == NULL || time - plantTime > 60000))
				{
					isPlanted = true;
					plantTime = time;
				}

				float remaining = (40000 - (int64_t)time + plantTime) / (float)1000;

				ImGui::SetCursorPosX((ImGui::GetWindowSize().x - 180) * 0.5f);
				float barLength = remaining <= 0.f ? 0.f : remaining >= 40 ? 1.f
																		   : (remaining / 40.f);

				if (isPlanted && remaining >= 0)
				{
					std::ostringstream ss;
					ss.precision(3);
					ss << "Bomb on " << (!getBombSite(isBombPlanted) ? "A" : "B") << ": " << std::fixed << remaining << " s";
					Gui.MyText(std::move(ss).str().c_str(), true);
				}
				else
				{
					Gui.MyText("C4 not planted", true);
					barLength = 0.0f;
				}
				Gui.MyProgressBar(barLength, {180, 15}, "", SussyAim::Cfg::Misc::BombTimerCol);

				if (isPlanted && !isBombPlanted)
					isPlanted = false;

				ImGui::PopStyleColor();
				ImGui::End();
			}
		}
	}
}
