#include "Offsets.h"
#include "Cheats.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <filesystem>
#include <cstdlib>
#include <KnownFolders.h>
#include <ShlObj.h>

namespace fs = std::filesystem;

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	std::cout << R"(   _____                              _           
  / ____|                       /\   (_)          
 | (___  _   _ ___ ___ _   _   /  \   _ _ __ ___  
  \___ \| | | / __/ __| | | | / /\ \ | | '_ ` _ \ 
  ____) | |_| \__ \__ \ |_| |/ ____ \| | | | | | |
 |_____/ \__,_|___/___/\__, /_/    \_\_|_| |_| |_|
                        __/ |                     
                       |___/
	)" << std::endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

	std::cout << "Attaching to cs2.exe";
	auto ProcessStatus = ProcessMgr.Attach("cs2.exe");
	std::cout << " OK" << std::endl;

	char documentsPath[MAX_PATH];
	if (SHGetFolderPathA(NULL, CSIDL_PERSONAL, NULL, 0, documentsPath) != S_OK) {
		std::cerr << "[Info] Error: Failed to get the Documents folder path." << std::endl;
		goto END;
	}
	MenuConfig::path = documentsPath;
	MenuConfig::path += "\\SussyAim";
	MenuConfig::SoundPath = MenuConfig::path + "\\Sounds";

	switch (ProcessStatus) {
	case 1:
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		std::cout << "[ERROR] Please launch the game first!" << std::endl;
		goto END;
	case 2:
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		std::cout << "[ERROR] Failed to hook process, please run the cheat as Administrator (Right click the executable > Run as Adminstrator)." << std::endl;
		goto END;
	case 3:
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		std::cout << "[ERROR] Failed to get module address." << std::endl;
		goto END;
	default:
		break;
	}

	if (!Offset::UpdateOffsets())
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		std::cout << "[ERROR] Failed to update offsets." << std::endl;
		goto END;
	}

	if (!gGame.InitAddress())
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		std::cout << "[ERROR] Failed to call InitAddress()." << std::endl;
		goto END;
	}

	std::cout << "[Game] Process ID: " << ProcessMgr.ProcessID << std::endl;
	std::cout << "[Game] Client DLL Address: " << gGame.GetClientDLLAddress() << std::endl;

	if (fs::exists(MenuConfig::path))
	{
		std::cout << "[Info] Config folder connected: " << MenuConfig::path << std::endl;
	}
	else
	{
		if (fs::create_directory(MenuConfig::path))
		{
			std::cout << "[Info] Config folder created: " << MenuConfig::path << std::endl;
		}
		else
		{
			std::cerr << "[Info] Error: Failed to create the config directory." << std::endl;
			goto END;
		}
	}

	if (fs::exists(MenuConfig::SoundPath))
		std::cout << "[Info] Hitsound folder connected: " << MenuConfig::SoundPath << std::endl;
	else
	{
		if (fs::create_directory(MenuConfig::SoundPath))
			std::cout << "[Info] Hitsound folder created: " << MenuConfig::SoundPath << std::endl;
		else
		{
			std::cerr << "[Info] Error: Failed to create the file directory." << std::endl;
			goto END;
		}
	}

	std::cout << std::endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	std::cout << "Initialized successfully!" << std::endl;
	std::cout << "Menu bind: INSERT" << std::endl;
	std::cout << std::endl;

	if (false) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
		std::cout << "=======[ Offset List ]=======" << std::endl;
		std::cout << std::setw(23) << std::left << "EntityList:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::EntityList << std::endl;
		std::cout << std::setw(23) << std::left << "Matrix:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::Matrix << std::endl;
		std::cout << std::setw(23) << std::left << "LocalPlayerController:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::LocalPlayerController << std::endl;
		std::cout << std::setw(23) << std::left << "ViewAngles:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::ViewAngle << std::endl;
		std::cout << std::setw(23) << std::left << "LocalPlayerPawn:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::LocalPlayerPawn << std::endl;
		std::cout << std::setw(23) << std::left << "PlantedC4:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::PlantedC4 << std::endl;
		std::cout << std::setw(23) << std::left << "ForceJump:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::ForceJump << std::endl;
		std::cout << std::setw(23) << std::left << "TestPointer:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::Pointer << std::endl;
		std::cout << std::endl;
	}

	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

	try
	{
		std::cout << "Attaching" << std::endl;
		Gui.AttachAnotherWindow("Counter-Strike 2", "SDL_app", Menu::Tick);
	}
	catch (OSImGui::OSException& e)
	{
		try
		{
			std::cout << "Attaching china edition" << std::endl;
			Gui.AttachAnotherWindow("反恐精英：全球攻势", "SDL_app", Menu::Tick);
		}
		catch (OSImGui::OSException& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

END:
	std::cout << "End" << std::endl;
	system("pause");
	return 0;
}