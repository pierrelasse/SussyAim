// Settings
#define G_VERSION_MAJOR 2
#define G_VERSION_MINOR 5
#define G_VERSION_PATCH 4

#define G_PROGRAMFILENAME "cs2.exe"

//#define G_PRINTOFFSETS
//#define G_IMGUI_DEMO

// Settings End

#include "config/Config.hpp"
#include "game/Offsets.h"
#include "menu.hpp"

namespace fs = std::filesystem;

namespace SussyAim
{
    HANDLE hConsole;

    static void runSussyAim()
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        printf(R"(   _____                              _           
  / ____|                       /\   (_)          
 | (___  _   _ ___ ___ _   _   /  \   _ _ __ ___  
  \___ \| | | / __/ __| | | | / /\ \ | | '_ ` _ \ 
  ____) | |_| \__ \__ \ |_| |/ ____ \| | | | | | |
 |_____/ \__,_|___/___/\__, /_/    \_\_|_| |_| |_|
   By pierrelasse       __/ |  v%d.%d.%d
    and AimStar ppl    |___/%s)",
               G_VERSION_MAJOR, G_VERSION_MINOR, G_VERSION_PATCH, "\n\n");

        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

        std::cout << "[ProcessMgr] Attaching to " G_PROGRAMFILENAME;
        switch (ProcessMgr.Attach(G_PROGRAMFILENAME))
        {
        case 1:
            std::cout << " FAIL" << std::endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            std::cout << "  Please launch the game first!" << std::endl;
            return;
        case 2:
            std::cout << " FAIL" << std::endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            std::cout << "  Failed to hook process, please run the cheat as Administrator (Right click the executable > Run as Adminstrator)." << std::endl;
            return;
        case 3:
            std::cout << " FAIL" << std::endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            std::cout << "  Failed to get module address" << std::endl;
            return;
        default:
            std::cout << " OK" << std::endl;
        }

        SussyAim::Cfg::dir = fs::current_path().string();
        for (char &c : SussyAim::Cfg::dir)
            if (c == '\\')
                c = '/';

        SussyAim::Cfg::dir += "/SussyAim/";
        SussyAim::Cfg::dirConfigs = SussyAim::Cfg::dir + "configs/";
        SussyAim::Cfg::dirSounds = SussyAim::Cfg::dir + "sounds/";

        if (!Offset::UpdateOffsets())
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            std::cout << "[ERROR] Failed to update offsets" << std::endl;
            return;
        }

        if (!gGame.InitAddress())
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            std::cout << "[ERROR] Failed initializing addresses" << std::endl;
            return;
        }

        std::cout << "[Game] Process ID: " << ProcessMgr.ProcessID << std::endl;
        std::cout << "[Game] Client DLL Address: " << gGame.GetClientDLLAddress() << std::endl;

        if (fs::exists(SussyAim::Cfg::dir))
            std::cout << "[Info] Config folder: " << SussyAim::Cfg::dir << std::endl;
        else
        {
            if (fs::create_directory(SussyAim::Cfg::dir))
                std::cout << "[Info] Config folder created: " << SussyAim::Cfg::dir << std::endl;
            else
            {
                std::cerr << "[Info] Error: Failed to create the config directory." << std::endl;
                return;
            }
        }

        if (fs::exists(SussyAim::Cfg::dirConfigs))
            std::cout << "[Info] Configs folder: " << SussyAim::Cfg::dirConfigs << std::endl;
        else
        {
            if (fs::create_directory(SussyAim::Cfg::dirConfigs))
                std::cout << "[Info] Configs folder created: " << SussyAim::Cfg::dirConfigs << std::endl;
            else
            {
                std::cerr << "[Info] Error: Failed to create the file directory." << std::endl;
                return;
            }
        }

        if (fs::exists(SussyAim::Cfg::dirSounds))
            std::cout << "[Info] Hitsound folder: " << SussyAim::Cfg::dirSounds << std::endl;
        else
        {
            if (fs::create_directory(SussyAim::Cfg::dirSounds))
                std::cout << "[Info] Hitsound folder created: " << SussyAim::Cfg::dirSounds << std::endl;
            else
            {
                std::cerr << "[Info] Error: Failed to create the file directory." << std::endl;
                return;
            }
        }

        std::cout << std::endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        std::cout << "[Init] Initialized successfully!" << std::endl;
        std::cout << "[Init] Menu bind: INSERT" << std::endl;
        std::cout << std::endl;

#ifdef G_PRINTOFFSETS
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
        std::cout << "=======[ Offset List ]=======" << std::endl;
        std::cout << std::setw(23) << std::left << "EntityList:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::EntityList << std::endl;
        std::cout << std::setw(23) << std::left << "Matrix:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::Matrix << std::endl;
        std::cout << std::setw(23) << std::left << "LocalPlayerController:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::LocalPlayerController << std::endl;
        std::cout << std::setw(23) << std::left << "ViewAngles:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::ViewAngle << std::endl;
        std::cout << std::setw(23) << std::left << "LocalPlayerPawn:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::LocalPlayerPawn << std::endl;
        std::cout << std::setw(23) << std::left << "PlantedC4:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::PlantedC4 << std::endl;
        // std::cout << std::setw(23) << std::left << "ForceCrouch:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::ForceCrouch << std::endl;
        // std::cout << std::setw(23) << std::left << "ForceForward:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::ForceForward << std::endl;
        // std::cout << std::setw(23) << std::left << "ForceLeft:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::ForceLeft << std::endl;
        // std::cout << std::setw(23) << std::left << "ForceRight:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::ForceRight << std::endl;
        std::cout << std::endl;
#endif

        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        try
        {
            std::cout << "[GUI] Attaching" << std::endl;
            Gui.AttachAnotherWindow("Counter-Strike 2", "SDL_app", SussyAim::tick);
        }
        catch (OSImGui::OSException &e)
        {
            try
            {
                std::cout << "[GUI] Attaching china edition" << std::endl;
                Gui.AttachAnotherWindow("反恐精英：全球攻势", "SDL_app", SussyAim::tick);
            }
            catch (OSImGui::OSException &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
    }
}

int main()
{
    SussyAim::hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    try
    {
        SussyAim::runSussyAim();
    }
    catch (std::exception &ex)
    {
        std::cerr << "Std Exception caught: " << ex.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Unknown exception caught" << std::endl;
    }
    SetConsoleTextAttribute(SussyAim::hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

    try
    {
        std::cout << std::endl
                  << "Done. Use Ctrl+C to exit" << std::endl;
        while (true)
        {
            std::this_thread::sleep_for(1h);
        }
    }
    catch (std::exception &ex)
    {
    }

    return 0;
}
