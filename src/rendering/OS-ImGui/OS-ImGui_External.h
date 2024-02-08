#pragma once
#include "OS-ImGui_Base.h"

namespace OSImGui
{
	class OSImGui_External : public OSImGui_Base
	{
	private:
		WindowType Type = NEW;

	public:
		void AttachAnotherWindow(std::string DestWindowName, std::string DestWindowClassName, std::function<void()> CallBack);

	private:
		void MainLoop();
		bool UpdateWindowData();
		bool CreateMyWindow();
		bool PeekEndMessage();
	};
}
