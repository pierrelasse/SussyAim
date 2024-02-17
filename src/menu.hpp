#pragma once

#include "sacommon.hpp"
#include "config/Config.hpp"

#include "features/Aimbot.hpp"
#include "features/BombTimer.hpp"
#include "features/ESP.hpp"
#include "features/HitSounds.hpp"

#include "rendering/view/view.hpp"

namespace SussyAim
{
    inline DWORD currentTick;
    inline DWORD lastTick = 0;

    void updateShowMenu()
    {
        currentTick = GetTickCount();
        if (currentTick - lastTick >= 150 && (GetAsyncKeyState(VK_INSERT) & 0x8000))
        {
            SussyAim::Cfg::Menu::ShowMenu = !SussyAim::Cfg::Menu::ShowMenu;
            lastTick = currentTick;
        }
    }

    void RenderCrossHair(ImDrawList *drawList) noexcept
    {
        if (!SussyAim::Cfg::Crosshair::ShowCrossHair)
            return;

        if (SussyAim::Cfg::Crosshair::isAim && SussyAim::Cfg::Menu::TargetingCrosshairs)
            Render::DrawCrossHair(drawList, ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2), ImGui::ColorConvertFloat4ToU32(SussyAim::Cfg::Crosshair::TargetedColor));
        else
            Render::DrawCrossHair(drawList, ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2), ImGui::ColorConvertFloat4ToU32(SussyAim::Cfg::Crosshair::CrossHairColor));
    }

    void tick()
    {
        updateShowMenu();
        SussyAim::view::renderMainMenu();

        // Update matrix
        if (!ProcessMgr.ReadMemory(gGame.GetMatrixAddress(), gGame.View.Matrix, 64))
            return;

        gGame.UpdateEntityListEntry();

        DWORD64 LocalControllerAddress = 0;
        DWORD64 LocalPawnAddress = 0;

        if (!ProcessMgr.ReadMemory(gGame.GetLocalControllerAddress(), LocalControllerAddress))
            return;
        if (!ProcessMgr.ReadMemory(gGame.GetLocalPawnAddress(), LocalPawnAddress))
            return;

        // LocalEntity
        CEntity LocalEntity, ServerEntity;
        static int LocalPlayerControllerIndex = 1;
        LocalEntity.UpdateClientData();
        if (!LocalEntity.UpdateController(LocalControllerAddress))
            return;
        if (!LocalEntity.UpdatePawn(LocalPawnAddress)) // && !SussyAim::Cfg::Misc::WorkInSpec
            return;

        // HealthBar Map
        static std::map<DWORD64, Render::HealthBar> HealthBarMap;

        // Aimbot data
        float DistanceToSight = 0;
        float MaxAimDistance = 100000;
        Vec3 HeadPos{0, 0, 0};
        Vec3 AimPos{0, 0, 0};
        Vec2 Angles{0, 0};

        for (int i = 0; i < 64; i++)
        {
            CEntity Entity;
            DWORD64 EntityAddress = 0;

            if (!ProcessMgr.ReadMemory<DWORD64>(gGame.GetEntityListEntry() + (i + 1) * 0x78, EntityAddress))
                continue;

            if (EntityAddress == LocalEntity.Controller.Address)
            {
                LocalPlayerControllerIndex = i;
                continue;
            }

            if (!Entity.UpdateController(EntityAddress))
                continue;

            if (!Entity.UpdatePawn(Entity.Pawn.Address))
                continue;

            std::vector<std::string> spectators;
            if (SussyAim::Cfg::Misc::SpecList && !SussyAim::Cfg::Menu::ShowMenu)
            {
                int spectatorCount = 0;
                uint32_t m_hPawn;
                uintptr_t pCSPlayerPawn, m_pObserverServices;
                ProcessMgr.ReadMemory<uint32_t>(Entity.Controller.Address + 0x5BC, m_hPawn);
                ProcessMgr.ReadMemory<uintptr_t>(gGame.GetEntityListEntry() + 120 * (m_hPawn & 0x1FF), pCSPlayerPawn);
                ProcessMgr.ReadMemory<uintptr_t>(pCSPlayerPawn + Offset::PlayerController.m_pObserverServices, m_pObserverServices);

                if (m_pObserverServices)
                {
                    uint32_t m_hObserverTarget;
                    uintptr_t list_entry, pController;
                    ProcessMgr.ReadMemory<uint32_t>(m_pObserverServices + Offset::PlayerController.m_hObserverTarget, m_hObserverTarget);
                    ProcessMgr.ReadMemory<uintptr_t>(EntityAddress + 0x8 * ((m_hObserverTarget & 0x7FFF) >> 9) + 0x10, list_entry);
                    ProcessMgr.ReadMemory<uintptr_t>(gGame.GetEntityListEntry() + 120 * (m_hObserverTarget & 0x1FF), pController);

                    if (pController == LocalEntity.Pawn.Address)
                    {
                        spectators.push_back(Entity.Controller.PlayerName);
                    }
                }
            }

            // It not work rn.
            // SpecList::SpectatorWindowList(spectators);
            if (SussyAim::Cfg::Menu::TeamCheck && Entity.Controller.TeamID == LocalEntity.Controller.TeamID)
                continue;

            Misc::MoneyService(Entity);

            if (!Entity.IsAlive())
                continue;
            //		if (SussyAim::Cfg::Menu::VisibleCheck && (!Entity.Pawn.bSpottedByMask > 0))
            //			continue;

            if (!Entity.IsInScreen())
                continue;

            // Bone Debug
            /*	for (int BoneIndex = 0; BoneIndex < Entity.BoneData.BonePosList.size(); BoneIndex++)
                {
                    Vec2 ScreenPos{};
                    if (gGame.View.WorldToScreen(Entity.BoneData.BonePosList[BoneIndex].Pos, ScreenPos))
                    {
                        Gui.Text(std::to_string(BoneIndex), ScreenPos, ImColor(255, 255, 255, 255));
                    }
                }*/
            DistanceToSight = Entity.GetBone().BonePosList[BONEINDEX::head].ScreenPos.DistanceTo({Gui.Window.Size.x / 2, Gui.Window.Size.y / 2});

            if (DistanceToSight < MaxAimDistance)
            {
                MaxAimDistance = DistanceToSight;

                if (!SussyAim::Cfg::Aimbot::VisibleCheck ||
                    Entity.Pawn.bSpottedByMask & (DWORD64(1) << (LocalPlayerControllerIndex)) ||
                    LocalEntity.Pawn.bSpottedByMask & (DWORD64(1) << (i)))
                {
                    AimPos = Entity.GetBone().BonePosList[SussyAim::Cfg::Aimbot::AimPositionIndex].Pos;
                    if (SussyAim::Cfg::Aimbot::AimPositionIndex == BONEINDEX::head)
                        AimPos.z -= 1.f;
                }
            }

            if (SussyAim::Cfg::ESP::enabled)
            {
                ImVec4 Rect = SussyAim::Features::ESP::GetBoxRect(Entity, SussyAim::Cfg::ESP::boxType);
                int distance = static_cast<int>(Entity.Pawn.Pos.DistanceTo(LocalEntity.Pawn.Pos) / 100);

                if (SussyAim::Cfg::ESP::ammoBar && Entity.Pawn.Ammo != -1)
                {
                    ImVec2 AmmoBarPos = {Rect.x, Rect.y + Rect.w + 2};
                    ImVec2 AmmoBarSize = {Rect.z, 4};
                    Render::DrawAmmoBar(EntityAddress, Entity.Pawn.MaxAmmo, Entity.Pawn.Ammo, AmmoBarPos, AmmoBarSize);
                }

                if (distance <= SussyAim::Cfg::ESP::RenderDistance)
                {
                    SussyAim::Features::ESP::RenderPlayerESP(LocalEntity, Entity, Rect, LocalPlayerControllerIndex, i);
                    Render::DrawDistance(LocalEntity, Entity, Rect);

                    if (SussyAim::Cfg::ESP::drawHealthBar)
                    {
                        ImVec2 HealthBarPos = {Rect.x - 6.f, Rect.y};
                        ImVec2 HealthBarSize = {4, Rect.w};
                        Render::DrawHealthBar(EntityAddress, 100, Entity.Pawn.Health, HealthBarPos, HealthBarSize);
                    }

                    // Draw Ammo
                    // When player is using knife or nade, Ammo = -1.
                    if (SussyAim::Cfg::ESP::ammoBar && Entity.Pawn.Ammo != -1)
                    {
                        ImVec2 AmmoBarPos = {Rect.x, Rect.y + Rect.w + 2};
                        ImVec2 AmmoBarSize = {Rect.z, 4};
                        Render::DrawAmmoBar(EntityAddress, Entity.Pawn.MaxAmmo, Entity.Pawn.Ammo, AmmoBarPos, AmmoBarSize);
                    }

                    // Draw Armor
                    // It is meaningless to render a empty bar
                    if (SussyAim::Cfg::ESP::ArmorBar && Entity.Pawn.Armor > 0)
                    {
                        bool HasHelmet;
                        ImVec2 ArmorBarPos;
                        ProcessMgr.ReadMemory(Entity.Controller.Address + Offset::PlayerController.HasHelmet, HasHelmet);
                        if (SussyAim::Cfg::ESP::drawHealthBar)
                            ArmorBarPos = {Rect.x - 10.f, Rect.y};
                        else
                            ArmorBarPos = {Rect.x - 6.f, Rect.y};
                        ImVec2 ArmorBarSize = {4.f, Rect.w};
                        Render::DrawArmorBar(EntityAddress, 100, Entity.Pawn.Armor, HasHelmet, ArmorBarPos, ArmorBarSize);
                    }
                }
            }
            // SpecList::GetSpectatorList(Entity, LocalEntity, EntityAddress);
        }

        if (SussyAim::Cfg::Triggerbot::enabled && (SussyAim::Cfg::Triggerbot::always || GetAsyncKeyState(SussyAim::Cfg::Triggerbot::hotkey)))
            SussyAim::Features::Triggerbot::run(LocalEntity);

        if (SussyAim::Cfg::Misc::HitSound)
            SussyAim::Features::HitSounds::run(LocalEntity);

        Misc::FlashImmunity(LocalEntity);
        Misc::FastStop();
        Misc::NadeManager(gGame);
        Misc::FovChanger(LocalEntity);
        Misc::Watermark(LocalEntity);
        Misc::FakeDuck(LocalEntity);
        Misc::BunnyHop(LocalEntity);
        Misc::CheatList();
        Misc::ForceScope(LocalEntity);

        // Fov line
        Render::DrawFov(LocalEntity, SussyAim::Cfg::Menu::FovLineSize, SussyAim::Cfg::Menu::FovLineColor, 1);

        // HeadShoot Line
        Render::HeadShootLine(LocalEntity, SussyAim::Cfg::Menu::HeadShootLineColor);

        // CrossHair
        SussyAim::Features::Triggerbot::TargetCheck(LocalEntity);
        Misc::AirCheck(LocalEntity);
        RenderCrossHair(ImGui::GetBackgroundDrawList());

        SussyAim::Features::BombTimer::render();

        RCS::RecoilControl(LocalEntity);

        {
            if (!SussyAim::Cfg::Aimbot::enabled)
                return;

            Render::DrawFovCircle(LocalEntity);

            if (SussyAim::Cfg::Aimbot::always)
            {
                if (AimPos != Vec3(0, 0, 0))
                {
                    SussyAim::Features::Aimbot::run(LocalEntity, LocalEntity.Pawn.CameraPos, AimPos);
                }
            }
            else
            {
                if (GetAsyncKeyState(SussyAim::Features::Aimbot::HotKey))
                {
                    if (AimPos != Vec3(0, 0, 0))
                    {
                        SussyAim::Features::Aimbot::run(LocalEntity, LocalEntity.Pawn.CameraPos, AimPos);
                    }
                }
            }

            if (SussyAim::Cfg::Aimbot::AimToggleMode && (GetAsyncKeyState(SussyAim::Features::Aimbot::HotKey) & 0x8000) && currentTick - lastTick >= 200)
            {
                SussyAim::Features::Aimbot::switchToggle();
                lastTick = currentTick;
            }
        }
    }
}
