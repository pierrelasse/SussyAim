#pragma once

#include "../sacommon.hpp"
#include "../utils/yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ConfigSaver.hpp"
#include "../features/StyleChanger.h"
#include "../rendering/Resources/Language.h"
#include "Config.hpp"
#include "../features/Triggerbot.hpp"
#include "../features/Aimbot.hpp"

namespace MyConfigSaver
{
    void SaveConfig(const std::string &filename)
    {
        std::ofstream configFile(SussyAim::Cfg::dirConfigs + filename);
        if (!configFile.is_open())
        {
            std::cerr << "[Info] Error: Could not open the configuration file." << std::endl;
            return;
        }

        YAML::Emitter emitter;

        emitter << YAML::Comment("A SussyAim Config File\nVersion: 4.0");
        emitter << YAML::BeginMap;

        emitter << YAML::Key << "ESP";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "Enable" << YAML::Value << SussyAim::Cfg::ESP::enabled;
        emitter << YAML::Key << "BoneESP" << YAML::Value << SussyAim::Cfg::ESP::drawBones;
        emitter << YAML::Key << "BoxESP" << YAML::Value << SussyAim::Cfg::ESP::drawBox;
        emitter << YAML::Key << "BoxType" << YAML::Value << SussyAim::Cfg::ESP::boxType;
        emitter << YAML::Key << "SnapLine" << YAML::Value << SussyAim::Cfg::ESP::drawTracers;
        emitter << YAML::Key << "LinePos" << YAML::Value << SussyAim::Cfg::ESP::tracerPos;
        emitter << YAML::Key << "HealthBar" << YAML::Value << SussyAim::Cfg::ESP::drawHealthBar;
        emitter << YAML::Key << "AmmoBar" << YAML::Value << SussyAim::Cfg::ESP::ammoBar;
        emitter << YAML::Key << "WeaponESP" << YAML::Value << SussyAim::Cfg::ESP::drawWeapon;
        emitter << YAML::Key << "EyeRay" << YAML::Value << SussyAim::Cfg::ESP::drawEyeRay;
        emitter << YAML::Key << "PlayerName" << YAML::Value << SussyAim::Cfg::ESP::drawName;
        emitter << YAML::Key << "DistanceESP" << YAML::Value << SussyAim::Cfg::ESP::drawDistance;
        emitter << YAML::Key << "HealthNum" << YAML::Value << SussyAim::Cfg::ESP::drawHealth;
        emitter << YAML::Key << "HeadBox" << YAML::Value << SussyAim::Cfg::ESP::drawHeadBox;
        emitter << YAML::Key << "Preview" << YAML::Value << SussyAim::Cfg::ESP::displayPreview;
        emitter << YAML::Key << "VisCheck" << YAML::Value << SussyAim::Cfg::ESP::visibleCheck;
        emitter << YAML::Key << "FilledBox" << YAML::Value << SussyAim::Cfg::ESP::FilledBox;
        emitter << YAML::Key << "FilledVisBox" << YAML::Value << SussyAim::Cfg::ESP::FilledVisBox;
        emitter << YAML::Key << "MultiColor" << YAML::Value << SussyAim::Cfg::ESP::MultiColor;
        emitter << YAML::Key << "OutLine" << YAML::Value << SussyAim::Cfg::ESP::drawBoxOutline;
        emitter << YAML::Key << "HeadBoxStyle" << YAML::Value << SussyAim::Cfg::ESP::HeadBoxStyle;
        emitter << YAML::Key << "BoxRounding" << YAML::Value << SussyAim::Cfg::ESP::boxRounding;
        emitter << YAML::Key << "ShowScoped" << YAML::Value << SussyAim::Cfg::ESP::showScoped;
        emitter << YAML::Key << "ArmorBar" << YAML::Value << SussyAim::Cfg::ESP::ArmorBar;
        emitter << YAML::Key << "ArmorNum" << YAML::Value << SussyAim::Cfg::ESP::ShowArmorNum;
        emitter << YAML::Key << "MaxRenderDistance" << YAML::Value << SussyAim::Cfg::ESP::RenderDistance;
        emitter << YAML::Key << "LineThickness" << YAML::Value << SussyAim::Cfg::ESP::lineThickness;
        emitter << YAML::Key << "BoneColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << SussyAim::Cfg::ESP::BoneColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << SussyAim::Cfg::ESP::BoneColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << SussyAim::Cfg::ESP::BoneColor.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << SussyAim::Cfg::ESP::BoneColor.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "BoxColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << SussyAim::Cfg::ESP::FrameColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << SussyAim::Cfg::ESP::FrameColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << SussyAim::Cfg::ESP::FrameColor.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << SussyAim::Cfg::ESP::FrameColor.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "SnapLineColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << SussyAim::Cfg::ESP::tracerColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << SussyAim::Cfg::ESP::tracerColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << SussyAim::Cfg::ESP::tracerColor.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << SussyAim::Cfg::ESP::tracerColor.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "EyeRayColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << SussyAim::Cfg::ESP::EyeRayColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << SussyAim::Cfg::ESP::EyeRayColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << SussyAim::Cfg::ESP::EyeRayColor.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << SussyAim::Cfg::ESP::EyeRayColor.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "HeadBoxColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << SussyAim::Cfg::ESP::HeadBoxColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << SussyAim::Cfg::ESP::HeadBoxColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << SussyAim::Cfg::ESP::HeadBoxColor.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << SussyAim::Cfg::ESP::HeadBoxColor.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "VisibleColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << SussyAim::Cfg::ESP::VisibleColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << SussyAim::Cfg::ESP::VisibleColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << SussyAim::Cfg::ESP::VisibleColor.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << SussyAim::Cfg::ESP::VisibleColor.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "FilledColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << SussyAim::Cfg::ESP::FilledColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << SussyAim::Cfg::ESP::FilledColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << SussyAim::Cfg::ESP::FilledColor.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << SussyAim::Cfg::ESP::FilledColor.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "FilledColor2";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << SussyAim::Cfg::ESP::FilledColor2.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << SussyAim::Cfg::ESP::FilledColor2.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << SussyAim::Cfg::ESP::FilledColor2.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << SussyAim::Cfg::ESP::FilledColor2.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "FilledVisColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << SussyAim::Cfg::ESP::BoxFilledVisColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << SussyAim::Cfg::ESP::BoxFilledVisColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << SussyAim::Cfg::ESP::BoxFilledVisColor.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << SussyAim::Cfg::ESP::BoxFilledVisColor.Value.w;
        emitter << YAML::EndMap;

        emitter << YAML::Key << "Crosshairs";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "Enable" << YAML::Value << SussyAim::Cfg::Crosshair::ShowCrossHair;
        emitter << YAML::Key << "Size" << YAML::Value << SussyAim::Cfg::Crosshair::CrossHairSize;
        emitter << YAML::Key << "Dot" << YAML::Value << SussyAim::Cfg::Crosshair::drawDot;
        emitter << YAML::Key << "Crossline" << YAML::Value << SussyAim::Cfg::Crosshair::drawCrossline;
        emitter << YAML::Key << "tStyle" << YAML::Value << SussyAim::Cfg::Crosshair::tStyle;
        emitter << YAML::Key << "Circle" << YAML::Value << SussyAim::Cfg::Crosshair::drawCircle;
        emitter << YAML::Key << "Outline" << YAML::Value << SussyAim::Cfg::Crosshair::drawOutLine;
        emitter << YAML::Key << "DynamicGap" << YAML::Value << SussyAim::Cfg::Crosshair::DynamicGap;
        emitter << YAML::Key << "TeamCheck" << YAML::Value << SussyAim::Cfg::Crosshair::TeamCheck;
        emitter << YAML::Key << "Preset" << YAML::Value << SussyAim::Cfg::Crosshair::crosshairPreset;
        emitter << YAML::Key << "Gap" << YAML::Value << SussyAim::Cfg::Crosshair::Gap;
        emitter << YAML::Key << "H_Length" << YAML::Value << SussyAim::Cfg::Crosshair::HorizontalLength;
        emitter << YAML::Key << "V_Length" << YAML::Value << SussyAim::Cfg::Crosshair::VerticalLength;
        emitter << YAML::Key << "Thickness" << YAML::Value << SussyAim::Cfg::Crosshair::Thickness;
        emitter << YAML::Key << "DotSize" << YAML::Value << SussyAim::Cfg::Crosshair::DotSize;
        emitter << YAML::Key << "CircleRadius" << YAML::Value << SussyAim::Cfg::Crosshair::CircleRadius;
        emitter << YAML::Key << "CrosshairsColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << SussyAim::Cfg::Crosshair::CrossHairColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << SussyAim::Cfg::Crosshair::CrossHairColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << SussyAim::Cfg::Crosshair::CrossHairColor.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << SussyAim::Cfg::Crosshair::CrossHairColor.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "TargetedColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << SussyAim::Cfg::Crosshair::TargetedColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << SussyAim::Cfg::Crosshair::TargetedColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << SussyAim::Cfg::Crosshair::TargetedColor.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << SussyAim::Cfg::Crosshair::TargetedColor.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::EndMap;

        emitter << YAML::Key << "Misc";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "Bhop" << YAML::Value << SussyAim::Cfg::Misc::BunnyHop;
        emitter << YAML::Key << "HeadShootLine" << YAML::Value << SussyAim::Cfg::Menu::ShowHeadShootLine;
        emitter << YAML::Key << "HeadShootLineColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << SussyAim::Cfg::Menu::HeadShootLineColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << SussyAim::Cfg::Menu::HeadShootLineColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << SussyAim::Cfg::Menu::HeadShootLineColor.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << SussyAim::Cfg::Menu::HeadShootLineColor.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "WorkInSpec" << YAML::Value << SussyAim::Cfg::Misc::WorkInSpec;
        emitter << YAML::Key << "FovChanger" << YAML::Value << SussyAim::Cfg::Misc::fovChanger;
        emitter << YAML::Key << "FlashImmunity" << YAML::Value << SussyAim::Cfg::Misc::FlashImmunity;
        emitter << YAML::Key << "CheatList" << YAML::Value << SussyAim::Cfg::Misc::CheatList;
        emitter << YAML::Key << "Watermark" << YAML::Value << SussyAim::Cfg::Misc::WaterMark;
        emitter << YAML::Key << "HitSound" << YAML::Value << SussyAim::Cfg::Misc::HitSound;
        emitter << YAML::Key << "BombTimer" << YAML::Value << SussyAim::Cfg::Misc::bombTimer;
        emitter << YAML::Key << "TimerColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << SussyAim::Cfg::Misc::BombTimerCol.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << SussyAim::Cfg::Misc::BombTimerCol.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << SussyAim::Cfg::Misc::BombTimerCol.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << SussyAim::Cfg::Misc::BombTimerCol.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "FastStop" << YAML::Value << SussyAim::Cfg::Misc::FastStop;
        emitter << YAML::Key << "SpecList" << YAML::Value << SussyAim::Cfg::Misc::BunnyHop;
        emitter << YAML::Key << "Glow" << YAML::Value << SussyAim::Cfg::Misc::EnemySensor;
        emitter << YAML::Key << "RadarHack" << YAML::Value << SussyAim::Cfg::Misc::RadarHack;
        emitter << YAML::Key << "MoneyService";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "Enable" << YAML::Value << SussyAim::Cfg::Misc::MoneyService;
        emitter << YAML::Key << "ShowCashSpent" << YAML::Value << SussyAim::Cfg::Misc::ShowCashSpent;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "NoSmoke" << YAML::Value << SussyAim::Cfg::Misc::NoSmoke;
        emitter << YAML::Key << "TeamCheck" << YAML::Value << SussyAim::Cfg::Menu::TeamCheck;
        emitter << YAML::Key << "AntiRecord" << YAML::Value << SussyAim::Cfg::Menu::StreamProof;
        emitter << YAML::Key << "fakeDuck" << YAML::Value << SussyAim::Cfg::Misc::fakeDuck;
        emitter << YAML::Key << "SmokeColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "Enable" << YAML::Value << SussyAim::Cfg::Misc::SmokeColored;
        emitter << YAML::Key << "r" << YAML::Value << SussyAim::Cfg::Misc::SmokeColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << SussyAim::Cfg::Misc::SmokeColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << SussyAim::Cfg::Misc::SmokeColor.Value.z;
        emitter << YAML::EndMap;
        emitter << YAML::EndMap;

        emitter << YAML::Key << "Aimbot";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "Enable" << YAML::Value << SussyAim::Cfg::Aimbot::enabled;
        emitter << YAML::Key << "AimLock" << YAML::Value << SussyAim::Features::Aimbot::AimLock;
        emitter << YAML::Key << "ToggleMode" << YAML::Value << SussyAim::Cfg::Aimbot::AimToggleMode;
        emitter << YAML::Key << "Hotkey" << YAML::Value << SussyAim::Cfg::Aimbot::AimbotHotKey;
        emitter << YAML::Key << "Fov" << YAML::Value << SussyAim::Features::Aimbot::AimFov;
        emitter << YAML::Key << "FovCircle" << YAML::Value << SussyAim::Cfg::ESP::DrawFov;
        emitter << YAML::Key << "CircleColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << SussyAim::Cfg::Menu::FovCircleColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << SussyAim::Cfg::Menu::FovCircleColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << SussyAim::Cfg::Menu::FovCircleColor.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << SussyAim::Cfg::Menu::FovCircleColor.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "Smooth" << YAML::Value << SussyAim::Features::Aimbot::Smooth;
        emitter << YAML::Key << "AimPos" << YAML::Value << SussyAim::Cfg::Aimbot::AimPosition;
        emitter << YAML::Key << "VisibleCheck" << YAML::Value << SussyAim::Cfg::Aimbot::VisibleCheck;
        emitter << YAML::Key << "ScopeOnly" << YAML::Value << SussyAim::Features::Aimbot::ScopeOnly;
        emitter << YAML::Key << "AutoShot" << YAML::Value << SussyAim::Features::Aimbot::AutoShot;
        emitter << YAML::EndMap;

        emitter << YAML::Key << "Triggerbot";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "Enable" << YAML::Value << SussyAim::Cfg::Triggerbot::enabled;
        emitter << YAML::Key << "Hotkey" << YAML::Value << SussyAim::Cfg::Triggerbot::hotkey;
        emitter << YAML::Key << "Delay" << YAML::Value << SussyAim::Features::Triggerbot::TriggerDelay;
        emitter << YAML::Key << "FakeShot" << YAML::Value << SussyAim::Features::Triggerbot::FakeShotDelay;
        emitter << YAML::Key << "AutoMode" << YAML::Value << SussyAim::Cfg::Triggerbot::always;
        emitter << YAML::EndMap;

        emitter << YAML::Key << "Menu";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "Theme" << YAML::Value << SussyAim::Cfg::theme;
        emitter << YAML::EndMap;

        emitter << YAML::EndMap;

        configFile << emitter.c_str();
        configFile.close();
        std::cout << "[Info] Configuration saved to " << SussyAim::Cfg::dirConfigs + filename << std::endl;
    }

    void LoadConfig(const std::string &filename)
    {
        try
        {
            YAML::Node config = YAML::LoadFile(SussyAim::Cfg::dirConfigs + filename);
            if (config["ESP"])
            {
                // If you want to make the new version compatible with the old configuration, you can add IsDefine(), like line 284.
                SussyAim::Cfg::ESP::enabled = config["ESP"]["Enable"].as<bool>();
                SussyAim::Cfg::ESP::drawBones = config["ESP"]["BoneESP"].as<bool>();
                SussyAim::Cfg::ESP::drawBox = config["ESP"]["BoxESP"].as<bool>();
                SussyAim::Cfg::ESP::boxType = config["ESP"]["BoxType"].as<int>();
                SussyAim::Cfg::ESP::drawTracers = config["ESP"]["SnapLine"].as<bool>();
                SussyAim::Cfg::ESP::tracerPos = config["ESP"]["LinePos"].as<int>();
                SussyAim::Cfg::ESP::drawHealthBar = config["ESP"]["HealthBar"].as<bool>();
                SussyAim::Cfg::ESP::ammoBar = config["ESP"]["AmmoBar"].IsDefined() ? config["ESP"]["AmmoBar"].as<bool>() : false;
                SussyAim::Cfg::ESP::drawWeapon = config["ESP"]["WeaponESP"].as<bool>();
                SussyAim::Cfg::ESP::drawEyeRay = config["ESP"]["EyeRay"].as<bool>();
                SussyAim::Cfg::ESP::drawName = config["ESP"]["PlayerName"].as<bool>();
                SussyAim::Cfg::ESP::drawDistance = config["ESP"]["DistanceESP"].as<bool>();
                SussyAim::Cfg::ESP::drawHealth = config["ESP"]["HealthNum"].as<bool>();
                SussyAim::Cfg::ESP::drawHeadBox = config["ESP"]["HeadBox"].as<bool>();
                SussyAim::Cfg::ESP::displayPreview = config["ESP"]["Preview"].as<bool>();
                SussyAim::Cfg::ESP::visibleCheck = config["ESP"]["VisCheck"].as<bool>();
                SussyAim::Cfg::ESP::FilledBox = config["ESP"]["FilledBox"].as<bool>();
                SussyAim::Cfg::ESP::FilledVisBox = config["ESP"]["FilledVisBox"].as<bool>();
                SussyAim::Cfg::ESP::MultiColor = config["ESP"]["MultiColor"].as<bool>();
                SussyAim::Cfg::ESP::drawBoxOutline = config["ESP"]["OutLine"].as<bool>();
                SussyAim::Cfg::ESP::boxRounding = config["ESP"]["BoxRounding"].as<float>();
                SussyAim::Cfg::ESP::showScoped = config["ESP"]["ShowScoped"].IsDefined() ? config["ESP"]["ShowScoped"].as<bool>() : false;
                SussyAim::Cfg::ESP::ArmorBar = config["ESP"]["ArmorBar"].IsDefined() ? config["ESP"]["ArmorBar"].as<bool>() : false;
                SussyAim::Cfg::ESP::ShowArmorNum = config["ESP"]["ArmorNum"].IsDefined() ? config["ESP"]["ArmorNum"].as<bool>() : false;
                if (config["ESP"]["MaxRenderDistance"].IsDefined())
                    SussyAim::Cfg::ESP::RenderDistance = config["ESP"]["MaxRenderDistance"].as<int>();
                if (config["ESP"]["lineThickness"].IsDefined())
                    SussyAim::Cfg::ESP::lineThickness = config["ESP"]["lineThickness"].as<float>();
                SussyAim::Cfg::ESP::BoneColor.Value.x = config["ESP"]["BoneColor"]["r"].as<float>();
                SussyAim::Cfg::ESP::BoneColor.Value.y = config["ESP"]["BoneColor"]["g"].as<float>();
                SussyAim::Cfg::ESP::BoneColor.Value.z = config["ESP"]["BoneColor"]["b"].as<float>();
                SussyAim::Cfg::ESP::BoneColor.Value.w = config["ESP"]["BoneColor"]["a"].as<float>();
                SussyAim::Cfg::ESP::FrameColor.Value.x = config["ESP"]["BoxColor"]["r"].as<float>();
                SussyAim::Cfg::ESP::FrameColor.Value.y = config["ESP"]["BoxColor"]["g"].as<float>();
                SussyAim::Cfg::ESP::FrameColor.Value.z = config["ESP"]["BoxColor"]["b"].as<float>();
                SussyAim::Cfg::ESP::FrameColor.Value.w = config["ESP"]["BoxColor"]["a"].as<float>();
                SussyAim::Cfg::ESP::tracerColor.Value.x = config["ESP"]["SnapLineColor"]["r"].as<float>();
                SussyAim::Cfg::ESP::tracerColor.Value.y = config["ESP"]["SnapLineColor"]["g"].as<float>();
                SussyAim::Cfg::ESP::tracerColor.Value.z = config["ESP"]["SnapLineColor"]["b"].as<float>();
                SussyAim::Cfg::ESP::tracerColor.Value.w = config["ESP"]["SnapLineColor"]["a"].as<float>();
                SussyAim::Cfg::ESP::HeadBoxColor.Value.x = config["ESP"]["HeadBoxColor"]["r"].as<float>();
                SussyAim::Cfg::ESP::HeadBoxColor.Value.y = config["ESP"]["HeadBoxColor"]["g"].as<float>();
                SussyAim::Cfg::ESP::HeadBoxColor.Value.z = config["ESP"]["HeadBoxColor"]["b"].as<float>();
                SussyAim::Cfg::ESP::HeadBoxColor.Value.w = config["ESP"]["HeadBoxColor"]["a"].as<float>();
                SussyAim::Cfg::ESP::EyeRayColor.Value.x = config["ESP"]["EyeRayColor"]["r"].as<float>();
                SussyAim::Cfg::ESP::EyeRayColor.Value.y = config["ESP"]["EyeRayColor"]["g"].as<float>();
                SussyAim::Cfg::ESP::EyeRayColor.Value.z = config["ESP"]["EyeRayColor"]["b"].as<float>();
                SussyAim::Cfg::ESP::EyeRayColor.Value.w = config["ESP"]["EyeRayColor"]["a"].as<float>();
                SussyAim::Cfg::ESP::VisibleColor.Value.x = config["ESP"]["VisibleColor"]["r"].as<float>();
                SussyAim::Cfg::ESP::VisibleColor.Value.y = config["ESP"]["VisibleColor"]["g"].as<float>();
                SussyAim::Cfg::ESP::VisibleColor.Value.z = config["ESP"]["VisibleColor"]["b"].as<float>();
                SussyAim::Cfg::ESP::VisibleColor.Value.w = config["ESP"]["VisibleColor"]["a"].as<float>();
                SussyAim::Cfg::ESP::FilledColor.Value.x = config["ESP"]["FilledColor"]["r"].as<float>();
                SussyAim::Cfg::ESP::FilledColor.Value.y = config["ESP"]["FilledColor"]["g"].as<float>();
                SussyAim::Cfg::ESP::FilledColor.Value.z = config["ESP"]["FilledColor"]["b"].as<float>();
                SussyAim::Cfg::ESP::FilledColor.Value.w = config["ESP"]["FilledColor"]["a"].as<float>();
                SussyAim::Cfg::ESP::FilledColor2.Value.x = config["ESP"]["FilledColor2"]["r"].as<float>();
                SussyAim::Cfg::ESP::FilledColor2.Value.y = config["ESP"]["FilledColor2"]["g"].as<float>();
                SussyAim::Cfg::ESP::FilledColor2.Value.z = config["ESP"]["FilledColor2"]["b"].as<float>();
                SussyAim::Cfg::ESP::FilledColor2.Value.w = config["ESP"]["FilledColor2"]["a"].as<float>();
                SussyAim::Cfg::ESP::BoxFilledVisColor.Value.x = config["ESP"]["FilledVisColor"]["r"].as<float>();
                SussyAim::Cfg::ESP::BoxFilledVisColor.Value.y = config["ESP"]["FilledVisColor"]["g"].as<float>();
                SussyAim::Cfg::ESP::BoxFilledVisColor.Value.z = config["ESP"]["FilledVisColor"]["b"].as<float>();
                SussyAim::Cfg::ESP::BoxFilledVisColor.Value.w = config["ESP"]["FilledVisColor"]["a"].as<float>();
            }
            if (config["Crosshairs"])
            {
                SussyAim::Cfg::Crosshair::ShowCrossHair = config["Crosshairs"]["Enable"].as<bool>();
                SussyAim::Cfg::Crosshair::CrossHairSize = config["Crosshairs"]["Size"].as<float>();
                SussyAim::Cfg::Crosshair::drawDot = config["Crosshairs"]["Dot"].as<bool>();
                SussyAim::Cfg::Crosshair::drawCrossline = config["Crosshairs"]["Crossline"].as<bool>();
                SussyAim::Cfg::Crosshair::tStyle = config["Crosshairs"]["tStyle"].as<bool>();
                SussyAim::Cfg::Crosshair::drawCircle = config["Crosshairs"]["Circle"].as<bool>();
                SussyAim::Cfg::Crosshair::drawOutLine = config["Crosshairs"]["Outline"].as<bool>();
                SussyAim::Cfg::Crosshair::DynamicGap = config["Crosshairs"]["DynamicGap"].as<bool>();
                SussyAim::Cfg::Crosshair::TeamCheck = config["Crosshairs"]["TeamCheck"].as<bool>();
                SussyAim::Cfg::Crosshair::crosshairPreset = config["Crosshairs"]["Preset"].as<int>();
                SussyAim::Cfg::Crosshair::Gap = config["Crosshairs"]["Gap"].as<int>();
                SussyAim::Cfg::Crosshair::HorizontalLength = config["Crosshairs"]["H_Length"].as<int>();
                SussyAim::Cfg::Crosshair::VerticalLength = config["Crosshairs"]["V_Length"].as<int>();
                SussyAim::Cfg::Crosshair::Thickness = config["Crosshairs"]["Thickness"].as<int>();
                SussyAim::Cfg::Crosshair::DotSize = config["Crosshairs"]["DotSize"].as<float>();
                SussyAim::Cfg::Crosshair::CircleRadius = config["Crosshairs"]["CircleRadius"].as<float>();
                SussyAim::Cfg::Crosshair::CrossHairColor.Value.x = config["Crosshairs"]["CrosshairsColor"]["r"].as<float>();
                SussyAim::Cfg::Crosshair::CrossHairColor.Value.y = config["Crosshairs"]["CrosshairsColor"]["g"].as<float>();
                SussyAim::Cfg::Crosshair::CrossHairColor.Value.z = config["Crosshairs"]["CrosshairsColor"]["b"].as<float>();
                SussyAim::Cfg::Crosshair::CrossHairColor.Value.w = config["Crosshairs"]["CrosshairsColor"]["a"].as<float>();
                SussyAim::Cfg::Crosshair::TargetedColor.Value.x = config["Crosshairs"]["TargetedColor"]["r"].as<float>();
                SussyAim::Cfg::Crosshair::TargetedColor.Value.y = config["Crosshairs"]["TargetedColor"]["g"].as<float>();
                SussyAim::Cfg::Crosshair::TargetedColor.Value.z = config["Crosshairs"]["TargetedColor"]["b"].as<float>();
                SussyAim::Cfg::Crosshair::TargetedColor.Value.w = config["Crosshairs"]["TargetedColor"]["a"].as<float>();
            }
            if (config["Misc"])
            {
                SussyAim::Cfg::Misc::BunnyHop = config["Misc"]["Bhop"].as<bool>();
                SussyAim::Cfg::Menu::ShowHeadShootLine = config["Misc"]["HeadShootLine"].as<bool>();
                SussyAim::Cfg::Menu::HeadShootLineColor.Value.x = config["Misc"]["HeadShootLineColor"]["r"].as<float>();
                SussyAim::Cfg::Menu::HeadShootLineColor.Value.y = config["Misc"]["HeadShootLineColor"]["g"].as<float>();
                SussyAim::Cfg::Menu::HeadShootLineColor.Value.z = config["Misc"]["HeadShootLineColor"]["b"].as<float>();
                SussyAim::Cfg::Menu::HeadShootLineColor.Value.w = config["Misc"]["HeadShootLineColor"]["a"].as<float>();
                SussyAim::Cfg::Misc::WorkInSpec = config["Misc"]["WorkInSpec"].as<bool>();
                SussyAim::Cfg::Misc::fovChanger = config["Misc"]["FovChanger"].IsDefined() ? config["Misc"]["FovChanger"].as<bool>() : false;
                SussyAim::Cfg::Misc::FlashImmunity = config["Misc"]["FlashImmunity"].IsDefined() ? config["Misc"]["FlashImmunity"].as<float>() : 0.f;
                SussyAim::Cfg::Misc::CheatList = config["Misc"]["CheatList"].IsDefined() ? config["Misc"]["CheatList"].as<bool>() : false;
                SussyAim::Cfg::Misc::WaterMark = config["Misc"]["Watermark"].as<bool>();
                SussyAim::Cfg::Misc::HitSound = config["Misc"]["HitSound"].as<bool>();
                SussyAim::Cfg::Misc::bombTimer = config["Misc"]["BombTimer"].as<bool>();
                SussyAim::Cfg::Misc::BombTimerCol.Value.x = config["Misc"]["TimerColor"]["r"].as<float>();
                SussyAim::Cfg::Misc::BombTimerCol.Value.y = config["Misc"]["TimerColor"]["g"].as<float>();
                SussyAim::Cfg::Misc::BombTimerCol.Value.z = config["Misc"]["TimerColor"]["b"].as<float>();
                SussyAim::Cfg::Misc::BombTimerCol.Value.w = config["Misc"]["TimerColor"]["a"].as<float>();
                SussyAim::Cfg::Misc::FastStop = config["Misc"]["FastStop"].as<bool>();
                SussyAim::Cfg::Misc::SpecList = config["Misc"]["SpecList"].as<bool>();
                SussyAim::Cfg::Misc::EnemySensor = config["Misc"]["Glow"].as<bool>();
                SussyAim::Cfg::Misc::RadarHack = config["Misc"]["RadarHack"].IsDefined() ? config["Misc"]["RadarHack"].as<bool>() : false;
                SussyAim::Cfg::Misc::MoneyService = config["Misc"]["MoneyService"]["Enable"].IsDefined() ? config["Misc"]["MoneyService"]["Enable"].as<bool>() : false;
                SussyAim::Cfg::Misc::ShowCashSpent = config["Misc"]["MoneyService"]["ShowCashSpent"].IsDefined() ? config["Misc"]["MoneyService"]["ShowCashSpent"].as<bool>() : false;
                SussyAim::Cfg::Misc::NoSmoke = config["Misc"]["NoSmoke"].IsDefined() ? config["Misc"]["NoSmoke"].as<bool>() : false;
                SussyAim::Cfg::Menu::TeamCheck = config["Misc"]["TeamCheck"].as<bool>();
                SussyAim::Cfg::Menu::StreamProof = config["Misc"]["AntiRecord"].as<bool>();
                SussyAim::Cfg::Misc::fakeDuck = config["Misc"]["fakeDuck"].IsDefined() ? config["Misc"]["fakeDuck"].as<bool>() : false;
                SussyAim::Cfg::Misc::SmokeColored = config["Misc"]["SmokeColor"]["Enable"].IsDefined() ? config["Misc"]["SmokeColor"]["Enable"].as<bool>() : false;
                SussyAim::Cfg::Misc::SmokeColor.Value.x = config["Misc"]["SmokeColor"]["r"].IsDefined() ? config["Misc"]["SmokeColor"]["r"].as<float>() : 255.f;
                SussyAim::Cfg::Misc::SmokeColor.Value.y = config["Misc"]["SmokeColor"]["g"].IsDefined() ? config["Misc"]["SmokeColor"]["g"].as<float>() : 0.f;
                SussyAim::Cfg::Misc::SmokeColor.Value.z = config["Misc"]["SmokeColor"]["b"].IsDefined() ? config["Misc"]["SmokeColor"]["b"].as<float>() : 0.f;
            }
            if (config["Aimbot"])
            {
                SussyAim::Cfg::Aimbot::enabled = config["Aimbot"]["Enable"].as<bool>();
                SussyAim::Cfg::Aimbot::always = config["Aimbot"]["AimLock"].IsDefined() ? config["Aimbot"]["AimLock"].as<bool>() : false;
                SussyAim::Cfg::Aimbot::AimToggleMode = config["Aimbot"]["ToggleMode"].as<bool>();
                SussyAim::Cfg::Aimbot::AimbotHotKey = config["Aimbot"]["Hotkey"].as<int>();
                SussyAim::Features::Aimbot::AimFov = config["Aimbot"]["Fov"].as<float>();
                SussyAim::Cfg::ESP::DrawFov = config["Aimbot"]["FovCircle"].as<bool>();
                SussyAim::Cfg::Menu::FovCircleColor.Value.x = config["Aimbot"]["CircleColor"]["r"].as<float>();
                SussyAim::Cfg::Menu::FovCircleColor.Value.y = config["Aimbot"]["CircleColor"]["g"].as<float>();
                SussyAim::Cfg::Menu::FovCircleColor.Value.z = config["Aimbot"]["CircleColor"]["b"].as<float>();
                SussyAim::Cfg::Menu::FovCircleColor.Value.w = config["Aimbot"]["CircleColor"]["a"].as<float>();
                SussyAim::Features::Aimbot::Smooth = config["Aimbot"]["Smooth"].as<float>();
                SussyAim::Cfg::Aimbot::AimPosition = config["Aimbot"]["AimPos"].as<int>();
                SussyAim::Cfg::Aimbot::VisibleCheck = config["Aimbot"]["VisibleCheck"].as<bool>();
                SussyAim::Features::Aimbot::AutoShot = config["Aimbot"]["AutoShot"].IsDefined() ? config["Aimbot"]["AutoShot"].as<bool>() : false;
            }
            if (config["Triggerbot"])
            {
                SussyAim::Cfg::Triggerbot::enabled = config["Triggerbot"]["Enable"].as<bool>();
                SussyAim::Cfg::Triggerbot::hotkey = config["Triggerbot"]["Hotkey"].as<int>();
                SussyAim::Features::Triggerbot::TriggerDelay = config["Triggerbot"]["Delay"].as<float>();
                SussyAim::Features::Triggerbot::FakeShotDelay = config["Triggerbot"]["FakeShot"].as<float>();
                SussyAim::Cfg::Triggerbot::always = config["Triggerbot"]["AutoMode"].as<bool>();
            }
            if (config["Menu"])
            {
                SussyAim::Cfg::theme = config["Menu"]["Theme"].as<int>();
            }

            SussyAim::Features::Aimbot::SetHotKey(SussyAim::Cfg::Aimbot::AimbotHotKey);
            StyleChanger::UpdateSkin(SussyAim::Cfg::theme);

            std::cout << "[Info] Configuration loaded from " << SussyAim::Cfg::dirConfigs + filename << std::endl;
        }
        catch (const std::exception &ex)
        {
            std::cerr << "Error loading config: " << ex.what() << std::endl;
        }
    }
}
