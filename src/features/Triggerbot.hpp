#pragma once

#include "../sacommon.hpp"
#include "../game/Entity.h"

namespace SussyAim
{
    namespace Features
    {
        namespace Triggerbot
        {
            inline int TriggerDelay = 90;   // ms
            inline int FakeShotDelay = 200; // ms
            inline int HotKey = VK_LMENU;
            inline std::vector<int> HotKeyList{VK_LMENU, VK_RBUTTON, VK_XBUTTON1, VK_XBUTTON2, VK_CAPITAL, VK_LSHIFT, VK_LCONTROL};

            inline DWORD uHandle = 0;
            inline DWORD64 ListEntry = 0;
            inline DWORD64 PawnAddress = 0;
            inline CEntity Entity;
            inline bool AllowShoot = false;

            inline void SetHotKey(int Index)
            {
                HotKey = HotKeyList.at(Index);
            }

            void ReleaseMouseButton()
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(FakeShotDelay));
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            }

            void run(const CEntity &LocalEntity)
            {
                if (!ProcessMgr.ReadMemory<DWORD>(LocalEntity.Pawn.Address + Offset::Pawn.iIDEntIndex, uHandle))
                    return;
                if (uHandle == -1)
                    return;

                ListEntry = ProcessMgr.TraceAddress(gGame.GetEntityListAddress(), {0x8 * (uHandle >> 9) + 0x10, 0x0});
                if (ListEntry == 0)
                    return;

                if (!ProcessMgr.ReadMemory<DWORD64>(ListEntry + 0x78 * (uHandle & 0x1FF), PawnAddress))
                    return;

                if (!Entity.UpdatePawn(PawnAddress))
                    return;

                if (SussyAim::Cfg::Menu::TeamCheck)
                    AllowShoot = LocalEntity.Pawn.TeamID != Entity.Pawn.TeamID && Entity.Pawn.Health > 0;
                else
                    AllowShoot = Entity.Pawn.Health > 0;

                if (!AllowShoot)
                    return;

                static std::chrono::time_point LastTimePoint = std::chrono::steady_clock::now();
                auto CurTimePoint = std::chrono::steady_clock::now();
                if (CurTimePoint - LastTimePoint >= std::chrono::milliseconds(TriggerDelay))
                {
                    const bool isAlreadyShooting = GetAsyncKeyState(VK_LBUTTON) < 0;
                    if (!isAlreadyShooting)
                    {
                        mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                        std::thread TriggerThread(ReleaseMouseButton);
                        TriggerThread.detach();
                    }
                    LastTimePoint = CurTimePoint;
                }
            }

            void TargetCheck(const CEntity &LocalEntity) noexcept
            {
                if (!ProcessMgr.ReadMemory<DWORD>(LocalEntity.Pawn.Address + Offset::Pawn.iIDEntIndex, uHandle) || uHandle == -1)
                {
                    SussyAim::Cfg::Crosshair::isAim = false;
                }
                else
                {
                    ListEntry = ProcessMgr.TraceAddress(gGame.GetEntityListAddress(), {0x8 * (uHandle >> 9) + 0x10, 0x0});
                    if (ListEntry != 0)
                    {
                        if (ProcessMgr.ReadMemory<DWORD64>(ListEntry + 0x78 * (uHandle & 0x1FF), PawnAddress))
                        {
                            if (Entity.UpdatePawn(PawnAddress))
                            {
                                SussyAim::Cfg::Crosshair::isAim = SussyAim::Cfg::Crosshair::TeamCheck ? (LocalEntity.Pawn.TeamID != Entity.Pawn.TeamID) : true;
                                return;
                            }
                        }
                    }
                    SussyAim::Cfg::Crosshair::isAim = false;
                }
            }
        }
    }
}
