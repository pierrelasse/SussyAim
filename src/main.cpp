#include "settings.h"
#include "config/Config.hpp"
#include "game/Offsets.h"
#include "menu.hpp"
#include "utils/ColorConsole.hpp"

namespace fs = std::filesystem;

static void printProcessMgrAttachFail(HANDLE &hConsole, const char *message)
{
    std::cout << hue::red;
    std::cout << " FAIL" << std::endl;
    std::cout << hue::light_red;
    std::cout << "  " << message << std::endl;
}

static bool ensureDir(std::string &dir, const char *name)
{
    if (fs::exists(dir))
    {
        std::cout << "[Files] Folder '" << name << "': " << dir << std::endl;
        return false;
    }

    if (fs::create_directory(dir))
    {
        std::cout << hue::light_green;
        std::cout << "[Files] Created folder '" << name << "': " << dir << std::endl;
        return false;
    }

    std::cout << hue::light_red;
    std::cerr << "[Files] Error: Couldn't create folder '" << name << "' at: " << dir << std::endl;
    return true;
}

namespace SussyAim
{
    HANDLE hConsole;

    static void runSussyAim()
    {
        std::cout << hue::red;
        printf("   _____                              _\n");
        printf("  / ____|                       /\\   (_)\n");
        printf(" | (___  _   _ ___ ___ _   _   /  \\   _ _ __ ___\n");
        printf("  \\___ \\| | | / __/ __| | | | / /\\ \\ | | '_ ` _ \\\n");
        printf("  ____) | |_| \\__ \\__ \\ |_| |/ ____ \\| | | | | | |\n");
        printf(" |_____/ \\__,_|___/___/\\__, /_/    \\_\\_|_| |_| |_|\n");
        std::cout << hue::light_red;
        printf("   By pierrelasse");
        std::cout << hue::red;
        printf("      __/ |  ");
        std::cout << hue::light_red;
        printf("v%d.%d.%d\n    and AimStar ppl", G_VERSION_MAJOR, G_VERSION_MINOR, G_VERSION_PATCH);
        std::cout << hue::red;
        printf("    |___/\n\n");

        std::cout << hue::reset;

        printf("[ProcessMgr] Attaching to " G_PROGRAMFILENAME);
        switch (ProcessMgr.Attach(G_PROGRAMFILENAME))
        {
        case 1:
            printProcessMgrAttachFail(hConsole, "Please launch the game first!");
            return;
        case 2:
            printProcessMgrAttachFail(hConsole, "Failed to hook process, please run the cheat as Administrator (Right click the executable > Run as Adminstrator)");
            return;
        case 3:
            printProcessMgrAttachFail(hConsole, "Failed to get module address");
            return;
        default:
            std::cout << hue::light_green;
            printf(" OK\n");
        }
        std::cout << hue::reset;

        SussyAim::Cfg::dir = fs::current_path().string();
        for (char &c : SussyAim::Cfg::dir)
            if (c == '\\')
                c = '/';

        SussyAim::Cfg::dir += "/SussyAim/";
        if (ensureDir(SussyAim::Cfg::dir, "Root"))
            return;

        SussyAim::Cfg::dirConfigs = SussyAim::Cfg::dir + "configs/";
        if (ensureDir(SussyAim::Cfg::dirConfigs, "Configs"))
            return;

        SussyAim::Cfg::dirSounds = SussyAim::Cfg::dir + "sounds/";
        if (ensureDir(SussyAim::Cfg::dirSounds, "Sounds"))
            return;

        if (Offset::UpdateOffsets())
        {
        }
        else
        {
            std::cout << hue::light_red;
            std::cout << "[Offsets] Error: Failed to update offsets" << std::endl;
            return;
        }

        if (!gGame.InitAddress())
        {
            std::cout << hue::light_red;
            std::cout << "[gGame] Failed initializing addresses" << std::endl;
            return;
        }

        std::cout << "[ProcessMgr] Process ID: " << ProcessMgr.ProcessID << std::endl;
        std::cout << "[gGame] Client DLL Address: " << gGame.GetClientDLLAddress() << std::endl;

        std::cout << std::endl
                  << hue::light_green
                  << "[Init] Attached successfully!" << std::endl
                  << "[Init] Menu bind: INSERT" << std::endl
                  << std::endl;

#ifdef G_PRINTOFFSETS
        std::cout << hue::yellow;
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

        std::cout << hue::reset;
        try
        {
            std::cout << "[GUI] Attaching" << std::endl;
            Gui.AttachAnotherWindow("Counter-Strike 2", "SDL_app", SussyAim::tick);
        }
        catch (OSImGui::OSException &ex)
        {
            try
            {
                std::cout << "[GUI] Attaching china edition" << std::endl;
                Gui.AttachAnotherWindow("反恐精英：全球攻势", "SDL_app", SussyAim::tick);
            }
            catch (OSImGui::OSException &ex1)
            {
                std::cout << ex1.what() << std::endl;
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
        std::cout << hue::reset;
        std::cerr << "Std Exception caught: " << ex.what() << std::endl;
    }
    catch (...)
    {
        std::cout << hue::reset;
        std::cerr << "Unknown exception caught" << std::endl;
    }

    try
    {
        std::cout << hue::black_on_gray;
        printf("\nDone. Use Ctrl+C to exit\n");
        while (true)
        {
            std::this_thread::sleep_for(1h);
        }
    }
    catch (std::exception &ex)
    {
    }
    std::cout << hue::reset;

    return 0;
}
