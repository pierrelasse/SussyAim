#pragma once

#include "../config/Config.hpp"
#include "../game/Entity.h"
#include "../utils/Format.h"
#include "../rendering/OS-ImGui/imgui/imgui.h"
#define IMGUI_DEFINE_MATH_OPERATORS
#include "../rendering/OS-ImGui/imgui/imgui_internal.h"
#include "../features/Triggerbot.hpp"
#include "../features/Aimbot.hpp"

namespace Render
{
    void DrawHeadCircle(const CEntity &Entity, ImColor Color)
    {
        Vec2 CenterPos;
        Vec3 Temp;
        BoneJointPos Head = Entity.GetBone().BonePosList[BONEINDEX::head];
        BoneJointPos Neck = Entity.GetBone().BonePosList[BONEINDEX::neck_0];

        CenterPos = Head.ScreenPos;
        float Radius = abs(Head.ScreenPos.y - Neck.ScreenPos.y) + 2;

        switch (SussyAim::Cfg::ESP::HeadBoxStyle)
        {
        case 1:
            Gui.CircleFilled(CenterPos, Radius + 1, Color & IM_COL32_A_MASK);
            Gui.CircleFilled(CenterPos, Radius, Color);
            break;
        default:
            Gui.Circle(CenterPos, Radius, Color, 1.2);
        }
    }

    void DrawHealth(int Health, ImVec2 Pos)
    {
        if (!SussyAim::Cfg::ESP::drawHealth)
            return;

        Gui.StrokeText(Format("%i", Health), Pos, ImColor(0, 220, 0, 255), 12, false);
    }

    void DrawDistance(const CEntity &LocalEntity, CEntity &Entity, ImVec4 Rect)
    {
        if (!SussyAim::Cfg::ESP::drawDistance)
            return;

        int distance = static_cast<int>(Entity.Pawn.Pos.DistanceTo(LocalEntity.Pawn.Pos) / 100);
        std::string dis_str = Format("%im", distance);
        Gui.StrokeText(dis_str, {Rect.x + Rect.z + 4, Rect.y}, ImColor(255, 204, 0, 255), 14, false);
    }

    void DrawFovCircle(const CEntity &LocalEntity)
    {
        if (!SussyAim::Cfg::ESP::DrawFov)
            return;

        Vec2 CenterPoint = Gui.Window.Size / 2;
        float Radius = tan(SussyAim::Features::Aimbot::AimFov / 180.f * M_PI / 2.f) / tan(LocalEntity.Pawn.Fov / 180.f * M_PI / 2.f) * Gui.Window.Size.x;
        Gui.Circle(CenterPoint, Radius, SussyAim::Cfg::Menu::FovCircleColor, 1);
    }

    void DrawCrossHair(ImDrawList *drawList, const ImVec2 &pos, ImU32 color) noexcept
    {
        int BorderWidth = 2;
        int DotSize = 1;
        int gap = SussyAim::Cfg::Crosshair::Gap / 2;

        int outlineGap = gap - 1;
        float Thickness = SussyAim::Cfg::Crosshair::Thickness;

        ImVec2 offset1{SussyAim::Cfg::Crosshair::DotSize, SussyAim::Cfg::Crosshair::DotSize};
        ImVec2 offset2{SussyAim::Cfg::Crosshair::DotSize + 1, SussyAim::Cfg::Crosshair::DotSize + 1};

        /*
        ===== Outline =====
        */
        if (SussyAim::Cfg::Crosshair::drawOutLine)
        {
            // dot
            if (SussyAim::Cfg::Crosshair::drawDot)
                drawList->AddRectFilled(ImVec2(pos.x - offset1.x, pos.y - offset1.y), ImVec2(pos.x + offset2.x, pos.y + offset2.y), color & IM_COL32_A_MASK);

            if (SussyAim::Cfg::Crosshair::drawCrossline)
            {
                // left
                drawList->AddRectFilled(ImVec2(pos.x - (outlineGap + BorderWidth + SussyAim::Cfg::Crosshair::HorizontalLength), pos.y - Thickness), ImVec2(pos.x - outlineGap, pos.y + 1 + Thickness), color & IM_COL32_A_MASK);
                // right
                drawList->AddRectFilled(ImVec2(pos.x + (outlineGap + DotSize), pos.y - Thickness), ImVec2(pos.x + (outlineGap + DotSize + BorderWidth + SussyAim::Cfg::Crosshair::HorizontalLength), pos.y + 1 + Thickness), color & IM_COL32_A_MASK);
                // top
                if (!SussyAim::Cfg::Crosshair::tStyle)
                    drawList->AddRectFilled(ImVec2(pos.x - Thickness, pos.y - (outlineGap + BorderWidth + SussyAim::Cfg::Crosshair::VerticalLength)), ImVec2(pos.x + 1 + Thickness, pos.y - outlineGap), color & IM_COL32_A_MASK);
                // bottom
                drawList->AddRectFilled(ImVec2(pos.x - Thickness, pos.y + outlineGap + DotSize), ImVec2(pos.x + 1 + Thickness, pos.y + (outlineGap + DotSize + BorderWidth + SussyAim::Cfg::Crosshair::VerticalLength)), color & IM_COL32_A_MASK);
            }

            // circle
            if (SussyAim::Cfg::Crosshair::drawCircle)
                drawList->AddCircle(ImVec2(pos.x, pos.y), SussyAim::Cfg::Crosshair::CircleRadius, color & IM_COL32_A_MASK, 0, 3.0f);
        }

        /*
        ===== Crosshair =====
        */
        // dot
        if (SussyAim::Cfg::Crosshair::drawDot)
            drawList->AddRectFilled(ImVec2(pos.x - offset1.x + DotSize, pos.y - offset1.y + DotSize), ImVec2(pos.x + offset1.x, pos.y + offset1.y), color);

        if (SussyAim::Cfg::Crosshair::drawCrossline)
        {
            // left
            drawList->AddRectFilled(ImVec2(pos.x - (gap + SussyAim::Cfg::Crosshair::HorizontalLength), pos.y - Thickness + 1), ImVec2(pos.x - gap, pos.y + Thickness), color);
            // right
            drawList->AddRectFilled(ImVec2(pos.x + gap + DotSize, pos.y - Thickness + 1), ImVec2(pos.x + (gap + DotSize + SussyAim::Cfg::Crosshair::HorizontalLength), pos.y + Thickness), color);
            // top
            if (!SussyAim::Cfg::Crosshair::tStyle)
                drawList->AddRectFilled(ImVec2(pos.x - Thickness + 1, pos.y - (gap + SussyAim::Cfg::Crosshair::VerticalLength)), ImVec2(pos.x + Thickness, pos.y - gap), color);
            // bottom
            drawList->AddRectFilled(ImVec2(pos.x - Thickness + 1, pos.y + gap + DotSize), ImVec2(pos.x + Thickness, pos.y + (gap + DotSize + SussyAim::Cfg::Crosshair::VerticalLength)), color);
        }

        // circle
        if (SussyAim::Cfg::Crosshair::drawCircle)
            drawList->AddCircle(ImVec2(pos.x, pos.y), SussyAim::Cfg::Crosshair::CircleRadius, color, 0, 1.0f);
    }

    void DrawCrossHair2D()
    {
        Vec2 SightPos = Gui.Window.Size / 2;
        Gui.Line({SightPos.x - SussyAim::Cfg::Crosshair::CrossHairSize, SightPos.y}, {SightPos.x + SussyAim::Cfg::Crosshair::CrossHairSize, SightPos.y}, SussyAim::Cfg::Crosshair::CrossHairColor, 1);
        Gui.Line({SightPos.x, SightPos.y - SussyAim::Cfg::Crosshair::CrossHairSize}, {SightPos.x, SightPos.y + SussyAim::Cfg::Crosshair::CrossHairSize}, SussyAim::Cfg::Crosshair::CrossHairColor, 1);
    }

    void LineToEnemy(ImVec4 Rect, ImColor Color, float Thickness)
    {
        if (!SussyAim::Cfg::ESP::drawTracers)
            return;

        switch (SussyAim::Cfg::ESP::tracerPos)
        {
        case 0:
            Gui.Line({Rect.x + Rect.z / 2, Rect.y}, {Gui.Window.Size.x / 2, 0}, Color, Thickness);
            break;
        case 1:
            Gui.Line({Rect.x + Rect.z / 2, Rect.y}, {Gui.Window.Size.x / 2, Gui.Window.Size.y / 2}, Color, Thickness);
            break;
        case 2:
            Gui.Line({Rect.x + Rect.z / 2, Rect.y}, {Gui.Window.Size.x / 2, Gui.Window.Size.y}, Color, Thickness);
            break;
        default:
            break;
        }
    }

    void DrawFov(const CEntity &LocalEntity, float Size, ImColor Color, float Thickness)
    {
        if (!SussyAim::Cfg::Menu::ShowFovLine)
            return;

        float Length;
        float radian;
        Vec2 LineEndPoint[2];
        Vec2 Pos = Gui.Window.Size / 2;

        radian = (LocalEntity.Pawn.Fov / 2) * M_PI / 180;

        LineEndPoint[0].y = Pos.y - Size;
        LineEndPoint[1].y = LineEndPoint[0].y;

        Length = Size * tan(radian);

        LineEndPoint[0].x = Pos.x - Length;
        LineEndPoint[1].x = Pos.x + Length;

        Gui.Line(Pos, LineEndPoint[0], Color, 1.5);
        Gui.Line(Pos, LineEndPoint[1], Color, 1.5);
    }

    void HeadShootLine(const CEntity &LocalEntity, ImColor Color)
    {
        if (!SussyAim::Cfg::Menu::ShowHeadShootLine)
            return;

        Vec2 Pos;
        Pos.x = Gui.Window.Size.x / 2;
        Pos.y = Gui.Window.Size.y / 2.0f - Gui.Window.Size.y / (2.0f * std::sin(LocalEntity.Pawn.Fov * M_PI / 180.0f) / std::sin(90.0f * M_PI / 180.0f)) * std::sin(LocalEntity.Pawn.ViewAngle.x * M_PI / 180.0f) / std::sin(90.0f * M_PI / 180.0f);

        // left
        Gui.RectangleFilled(Vec2{Pos.x - 21, Pos.y - 1}, Vec2{17, 3}, Color & IM_COL32_A_MASK);
        Gui.RectangleFilled(Vec2{Pos.x - 20, Pos.y}, Vec2{17, 3}, Color);

        // right
        Gui.RectangleFilled(Vec2{Pos.x + 5, Pos.y - 1}, Vec2{17, 3}, Color & IM_COL32_A_MASK);
        Gui.RectangleFilled(Vec2{Pos.x + 6, Pos.y}, Vec2{17, 3}, Color);
    }

    ImVec4 Get2DBox(const CEntity &Entity)
    {
        BoneJointPos Head = Entity.GetBone().BonePosList[BONEINDEX::head];

        Vec2 Size, Pos;
        Size.y = (Entity.Pawn.ScreenPos.y - Head.ScreenPos.y) * 1.09;
        Size.x = Size.y * 0.6;

        Pos = ImVec2(Entity.Pawn.ScreenPos.x - Size.x / 2, Head.ScreenPos.y - Size.y * 0.08);

        return ImVec4{Pos.x, Pos.y, Size.x, Size.y};
    }

    void DrawBone(const CEntity &Entity, ImColor Color, float Thickness)
    {
        BoneJointPos Previous, Current;
        for (auto i : BoneJointList::List)
        {
            Previous.Pos = Vec3(0, 0, 0);
            for (auto Index : i)
            {
                Current = Entity.GetBone().BonePosList[Index];
                if (Previous.Pos == Vec3(0, 0, 0))
                {
                    Previous = Current;
                    // pGame->View->Gui->Text(Current.Name.c_str(), Current.ScreenPos, ImColor(255, 255, 0, 255));
                    continue;
                }
                if (Previous.IsVisible && Current.IsVisible)
                {
                    Gui.Line(Previous.ScreenPos, Current.ScreenPos, Color, Thickness);
                    // pGame->View->Gui->Text(Current.Name.c_str(), Current.ScreenPos, ImColor(255, 255, 0, 255));
                }
                Previous = Current;
            }
        }
    }

    void ShowLosLine(const CEntity &Entity, const float Length, ImColor Color, float Thickness)
    {
        Vec2 StartPoint, EndPoint;
        Vec3 Temp;
        BoneJointPos Head = Entity.GetBone().BonePosList[BONEINDEX::head];

        StartPoint = Head.ScreenPos;

        float LineLength = cos(Entity.Pawn.ViewAngle.x * M_PI / 180) * Length;

        Temp.x = Head.Pos.x + cos(Entity.Pawn.ViewAngle.y * M_PI / 180) * LineLength;
        Temp.y = Head.Pos.y + sin(Entity.Pawn.ViewAngle.y * M_PI / 180) * LineLength;
        Temp.z = Head.Pos.z - sin(Entity.Pawn.ViewAngle.x * M_PI / 180) * Length;

        if (!gGame.View.WorldToScreen(Temp, EndPoint))
            return;

        Gui.Line(StartPoint, EndPoint, Color, Thickness);
    }

    ImVec4 Get2DBoneRect(const CEntity &Entity)
    {
        Vec2 Min, Max, Size;
        Min = Max = Entity.GetBone().BonePosList[0].ScreenPos;

        for (auto &BoneJoint : Entity.GetBone().BonePosList)
        {
            if (!BoneJoint.IsVisible)
                continue;
            Min.x = min(BoneJoint.ScreenPos.x, Min.x);
            Min.y = min(BoneJoint.ScreenPos.y, Min.y);
            Max.x = max(BoneJoint.ScreenPos.x, Max.x);
            Max.y = max(BoneJoint.ScreenPos.y, Max.y);
        }
        Size.x = Max.x - Min.x;
        Size.y = Max.y - Min.y;

        return ImVec4(Min.x, Min.y, Size.x, Size.y);
    }

    class HealthBar
    {
    private:
        using TimePoint_ = std::chrono::steady_clock::time_point;

    private:
        const int ShowBackUpHealthDuration = 500;
        float MaxHealth = 0.f;
        float CurrentHealth = 0.f;
        float LastestBackupHealth = 0.f;
        ImVec2 RectPos{};
        ImVec2 RectSize{};
        bool InShowBackupHealth = false;
        TimePoint_ BackupHealthTimePoint{};
        int MaxAmmo = 0;
        int CurrentAmmo = 0;
        int MaxArmor = 0;
        int CurrentArmor = 0;

    public:
        HealthBar() {}

        void HealthBarV(float MaxHealth, float CurrentHealth, ImVec2 Pos, ImVec2 Size, bool ShowNum);

        void ArmorBarV(bool HasHelmet, float MaxHealth, float CurrentHealth, ImVec2 Pos, ImVec2 Size, bool ShowNum);

        void AmmoBarH(float MaxAmmo, float CurrentAmmo, ImVec2 Pos, ImVec2 Size);

    private:
        ImColor Mix(ImColor Col_1, ImColor Col_2, float t);

        ImColor FirstStageColor = ImColor(0, 255, 0, 255);

        ImColor SecondStageColor = ImColor(255, 232, 0, 255);

        ImColor ThirdStageColor = ImColor(255, 39, 0, 255);

        ImColor BackupHealthColor = ImColor(255, 255, 255, 220);

        ImColor FrameColor = ImColor(45, 45, 45, 220);

        ImColor BackGroundColor = ImColor(0, 0, 0, 255);

        ImColor AmmoColor = ImColor(255, 255, 0, 255);

        ImColor ArmorColor = ImColor(0, 128, 255, 255);
        ImColor ArmorWithHelmetColor = ImColor(255, 0, 255, 255);
    };

    void HealthBar::HealthBarV(float MaxHealth, float CurrentHealth, ImVec2 Pos, ImVec2 Size, bool ShowNum)
    {
        auto InRange = [&](float value, float min, float max) -> bool
        {
            return value > min && value <= max;
        };

        ImDrawList *DrawList = ImGui::GetBackgroundDrawList();

        this->MaxHealth = MaxHealth;
        this->CurrentHealth = CurrentHealth;
        this->RectPos = Pos;
        this->RectSize = Size;

        float Proportion = CurrentHealth / MaxHealth;

        float Height = RectSize.y * Proportion;

        ImColor Color;

        DrawList->AddRectFilled(RectPos,
                                {RectPos.x + RectSize.x, RectPos.y + RectSize.y},
                                BackGroundColor, 5, 15);

        float Color_Lerp_t = pow(Proportion, 2.5);
        if (InRange(Proportion, 0.5, 1))
            Color = Mix(FirstStageColor, SecondStageColor, Color_Lerp_t * 3 - 1);
        else
            Color = Mix(SecondStageColor, ThirdStageColor, Color_Lerp_t * 4);

        DrawList->AddRectFilled({RectPos.x, RectPos.y + RectSize.y - Height},
                                {RectPos.x + RectSize.x, RectPos.y + RectSize.y},
                                Color, 0);

        DrawList->AddRect(RectPos,
                          {RectPos.x + RectSize.x, RectPos.y + RectSize.y},
                          FrameColor, 0, 15, 1);

        if (ShowNum)
        {
            if (CurrentHealth < MaxHealth)
            {
                std::string health_str = Format("%.f", CurrentHealth);
                Vec2 Pos = {RectPos.x, RectPos.y + RectSize.y - Height};
                Gui.StrokeText(health_str, Pos, ImColor(255, 255, 255), 13.f, true);
            }
        }
    }

    void HealthBar::ArmorBarV(bool HasHelmet, float MaxArmor, float CurrentArmor, ImVec2 Pos, ImVec2 Size, bool ShowNum)
    {
        auto InRange = [&](float value, float min, float max) -> bool
        {
            return value > min && value <= max;
        };

        ImDrawList *DrawList = ImGui::GetBackgroundDrawList();

        this->MaxArmor = MaxArmor;
        this->CurrentArmor = CurrentArmor;
        this->RectPos = Pos;
        this->RectSize = Size;

        float Proportion = CurrentArmor / MaxArmor;

        float Height = RectSize.y * Proportion;

        ImColor Color;

        DrawList->AddRectFilled(RectPos,
                                {RectPos.x + RectSize.x, RectPos.y + RectSize.y},
                                BackGroundColor, 5, 15);

        if (HasHelmet)
            Color = ArmorWithHelmetColor;
        else
            Color = ArmorColor;

        DrawList->AddRectFilled({RectPos.x, RectPos.y + RectSize.y - Height},
                                {RectPos.x + RectSize.x, RectPos.y + RectSize.y},
                                Color, 0);

        DrawList->AddRect(RectPos,
                          {RectPos.x + RectSize.x, RectPos.y + RectSize.y},
                          FrameColor, 0, 15, 1);

        if (ShowNum)
        {
            if (CurrentArmor < MaxArmor)
            {
                std::string armor_str = Format("%.f", CurrentArmor);
                Vec2 Pos = {RectPos.x, RectPos.y + RectSize.y - Height};
                Gui.StrokeText(armor_str, Pos, ImColor(255, 255, 255), 13.f, true);
            }
        }
    }

    void HealthBar::AmmoBarH(float MaxAmmo, float CurrentAmmo, ImVec2 Pos, ImVec2 Size)
    {
        ImDrawList *DrawList = ImGui::GetBackgroundDrawList();

        this->MaxAmmo = MaxAmmo;
        this->CurrentAmmo = CurrentAmmo;
        this->RectPos = Pos;
        this->RectSize = Size;

        float Proportion = CurrentAmmo / MaxAmmo;

        float Width = RectSize.x * Proportion;

        DrawList->AddRectFilled(RectPos,
                                {RectPos.x + RectSize.x, RectPos.y + RectSize.y},
                                BackGroundColor, 5, 15);

        DrawList->AddRectFilled(RectPos,
                                {RectPos.x + Width, RectPos.y + RectSize.y},
                                AmmoColor, 0);

        DrawList->AddRect(RectPos,
                          {RectPos.x + RectSize.x, RectPos.y + RectSize.y},
                          FrameColor, 0, 15, 1);
    }

    ImColor HealthBar::Mix(ImColor Col_1, ImColor Col_2, float t)
    {
        ImColor Col;
        Col.Value.x = t * Col_1.Value.x + (1 - t) * Col_2.Value.x;
        Col.Value.y = t * Col_1.Value.y + (1 - t) * Col_2.Value.y;
        Col.Value.z = t * Col_1.Value.z + (1 - t) * Col_2.Value.z;
        Col.Value.w = Col_1.Value.w;
        return Col;
    }

    void DrawHealthBar(DWORD Sign, float MaxHealth, float CurrentHealth, ImVec2 Pos, ImVec2 Size)
    {
        static std::map<DWORD, HealthBar> HealthBarMap;
        if (!HealthBarMap.count(Sign))
            HealthBarMap.insert({Sign, HealthBar()});

        if (HealthBarMap.count(Sign))
            HealthBarMap[Sign].HealthBarV(MaxHealth, CurrentHealth, Pos, Size, SussyAim::Cfg::ESP::drawHealth);
    }

    void DrawAmmoBar(DWORD Sign, float MaxAmmo, float CurrentAmmo, ImVec2 Pos, ImVec2 Size)
    {
        static std::map<DWORD, HealthBar> HealthBarMap;
        if (!HealthBarMap.count(Sign))
            HealthBarMap.insert({Sign, HealthBar()});

        if (HealthBarMap.count(Sign))
            HealthBarMap[Sign].AmmoBarH(MaxAmmo, CurrentAmmo, Pos, Size);
    }

    void DrawArmorBar(DWORD Sign, float MaxArmor, float CurrentArmor, bool HasHelmet, ImVec2 Pos, ImVec2 Size)
    {
        static std::map<DWORD, HealthBar> HealthBarMap;
        if (!HealthBarMap.count(Sign))
            HealthBarMap.insert({Sign, HealthBar()});

        if (HealthBarMap.count(Sign))
            HealthBarMap[Sign].ArmorBarV(HasHelmet, MaxArmor, CurrentArmor, Pos, Size, SussyAim::Cfg::ESP::ShowArmorNum);
    }

    // Update crosshair preset
    void UpdateCrosshairPreset(int style)
    {
        switch (style)
        {
        case 1:
            SussyAim::Cfg::Crosshair::drawDot = true;
            SussyAim::Cfg::Crosshair::DotSize = 2;
            SussyAim::Cfg::Crosshair::drawOutLine = true;
            SussyAim::Cfg::Crosshair::drawCrossline = false;
            SussyAim::Cfg::Crosshair::drawCircle = false;
            SussyAim::Cfg::Menu::TargetingCrosshairs = true;
            break;
        case 2:
            SussyAim::Cfg::Crosshair::drawDot = true;
            SussyAim::Cfg::Crosshair::DotSize = 2;
            SussyAim::Cfg::Crosshair::drawOutLine = true;
            SussyAim::Cfg::Crosshair::drawCrossline = false;
            SussyAim::Cfg::Crosshair::drawCircle = true;
            SussyAim::Cfg::Crosshair::CircleRadius = 10.f;
            SussyAim::Cfg::Menu::TargetingCrosshairs = true;
            break;
        case 3:
            SussyAim::Cfg::Crosshair::drawDot = true;
            SussyAim::Cfg::Crosshair::DotSize = 1;
            SussyAim::Cfg::Crosshair::drawOutLine = true;
            SussyAim::Cfg::Crosshair::drawCrossline = true;
            SussyAim::Cfg::Crosshair::HorizontalLength = 5;
            SussyAim::Cfg::Crosshair::VerticalLength = 5;
            SussyAim::Cfg::Crosshair::Gap = 18;
            SussyAim::Cfg::Crosshair::tStyle = false;
            SussyAim::Cfg::Crosshair::drawCircle = true;
            SussyAim::Cfg::Crosshair::CircleRadius = 10.f;
            SussyAim::Cfg::Menu::TargetingCrosshairs = true;
            SussyAim::Cfg::Crosshair::Thickness = 1;
            break;
        case 4:
            SussyAim::Cfg::Crosshair::drawDot = true;
            SussyAim::Cfg::Crosshair::DotSize = 1;
            SussyAim::Cfg::Crosshair::drawOutLine = true;
            SussyAim::Cfg::Crosshair::drawCrossline = true;
            SussyAim::Cfg::Crosshair::HorizontalLength = 5;
            SussyAim::Cfg::Crosshair::VerticalLength = 5;
            SussyAim::Cfg::Crosshair::Gap = 1;
            SussyAim::Cfg::Crosshair::tStyle = false;
            SussyAim::Cfg::Crosshair::drawCircle = false;
            SussyAim::Cfg::Menu::TargetingCrosshairs = true;
            SussyAim::Cfg::Crosshair::Thickness = 1;
            break;
        case 5:
            SussyAim::Cfg::Crosshair::drawDot = false;
            SussyAim::Cfg::Crosshair::drawOutLine = true;
            SussyAim::Cfg::Crosshair::drawCrossline = true;
            SussyAim::Cfg::Crosshair::HorizontalLength = 7;
            SussyAim::Cfg::Crosshair::VerticalLength = 7;
            SussyAim::Cfg::Crosshair::Gap = 10;
            SussyAim::Cfg::Crosshair::tStyle = false;
            SussyAim::Cfg::Crosshair::drawCircle = false;
            SussyAim::Cfg::Menu::TargetingCrosshairs = true;
            SussyAim::Cfg::Crosshair::Thickness = 1;
            break;
        case 6:
            SussyAim::Cfg::Crosshair::drawDot = true;
            SussyAim::Cfg::Crosshair::DotSize = 2;
            SussyAim::Cfg::Crosshair::drawOutLine = true;
            SussyAim::Cfg::Crosshair::drawCrossline = true;
            SussyAim::Cfg::Crosshair::HorizontalLength = 8;
            SussyAim::Cfg::Crosshair::VerticalLength = 8;
            SussyAim::Cfg::Crosshair::Gap = 20;
            SussyAim::Cfg::Crosshair::tStyle = false;
            SussyAim::Cfg::Crosshair::drawCircle = false;
            SussyAim::Cfg::Menu::TargetingCrosshairs = true;
            SussyAim::Cfg::Crosshair::Thickness = 1;
            break;
        case 7:
            SussyAim::Cfg::Crosshair::drawDot = false;
            SussyAim::Cfg::Crosshair::drawOutLine = true;
            SussyAim::Cfg::Crosshair::drawCrossline = true;
            SussyAim::Cfg::Crosshair::HorizontalLength = 4;
            SussyAim::Cfg::Crosshair::VerticalLength = 4;
            SussyAim::Cfg::Crosshair::Gap = 13;
            SussyAim::Cfg::Crosshair::Thickness = 10;
            SussyAim::Cfg::Crosshair::tStyle = false;
            SussyAim::Cfg::Crosshair::drawCircle = false;
            SussyAim::Cfg::Menu::TargetingCrosshairs = true;
        default:
            break;
        }
    }

    // Get the center pos of screen
    ImVec2 GetScreenCenterImVec2()
    {
        int W = GetSystemMetrics(SM_CXSCREEN);
        int H = GetSystemMetrics(SM_CYSCREEN);

        float CenterX = static_cast<float>(W) / 2;
        float CenterY = static_cast<float>(H) / 2;

        return ImVec2(CenterX, CenterY);
    }

    // Convert RGBA to ImVec4
    // Why not use "ImColor()"? Because I forgot about this.
    ImVec4 rgba2ImVec(int r, int g, int b, int a)
    {
        ImVec4 color;
        color.x = static_cast<float>(r) / 255.0f;
        color.y = static_cast<float>(g) / 255.0f;
        color.z = static_cast<float>(b) / 255.0f;
        color.w = static_cast<float>(a) / 255.0f;

        return color;
    }
}