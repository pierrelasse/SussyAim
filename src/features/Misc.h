#pragma once

#include "../sacommon.hpp"

#include "Aimbot.hpp"
#include "../game/Entity.h"
#include "../config/Config.hpp"
#include "../rendering/OS-ImGui/imgui/imgui.h"
#include "../game/GlobalVars.h"

#pragma comment(lib, "winmm.lib")

namespace Misc
{
	inline bool Zoom = false;

	struct Vector3
	{
		float x, y, z;
		Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
	};

	// Convert std::string into std::wstring
	static inline std::wstring STR2LPCWSTR(const std::string &str)
	{
		int size = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);
		std::wstring result(size, L'\0');
		MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, &result[0], size);
		return result;
	}

	static inline void CheatText(const char *Cheat, bool config)
	{
		if (config)
			ImGui::Text(Cheat);
	}

	static inline void getCurrentTime(struct tm *ptm)
	{
		time_t now = time(NULL);
		localtime_s(ptm, &now);
	}

	// Thanks @PedroGoncalves for the suggestion
	static inline void StopKeyEvent(int WalkKey, bool *KeyStatus, int StopKey, float duration)
	{
		if (GetAsyncKeyState(WalkKey) & 0x8000)
		{
			*KeyStatus = true;
		}
		else
		{
			if (*KeyStatus)
			{
				keybd_event(StopKey, MapVirtualKey(StopKey, 0), KEYEVENTF_SCANCODE, 0);
				Sleep(50);
				keybd_event(StopKey, MapVirtualKey(StopKey, 0), KEYEVENTF_KEYUP, 0);
				*KeyStatus = false;
			}
		}
	}

	static inline uintptr_t GetSmokeEntity(int i, uintptr_t EntityListEntry)
	{
		uintptr_t Entity = EntityListEntry + 0x78 * (i + 1);
		return Entity;
	}

	inline bool AirCheck(const CEntity &Local)
	{
		const bool hasFlagInAir = Local.Pawn.HasFlag(PlayerPawn::Flags::IN_AIR);
		return hasFlagInAir;
	}
	inline bool CrouchCheck(const CEntity &Local)
	{
		const bool hasFlagDucking = Local.Pawn.HasFlag(PlayerPawn::Flags::IN_CROUCH);
		return hasFlagDucking;
	}

	void Watermark(const CEntity& LocalPlayer) noexcept;
	void FlashImmunity(const CEntity &aLocalPlayer) noexcept;
	void FastStop() noexcept;
	void NadeManager(CGame Game) noexcept;
	void RadarHack(const CEntity &EntityList) noexcept;
	void FovChanger(const CEntity &aLocalPlayer) noexcept;
	void MoneyService(const CEntity &EntityList) noexcept;
	void FakeDuck(const CEntity &EntityList) noexcept;
	void BunnyHop(const CEntity &Local) noexcept;
	void CheatList() noexcept;
	void ForceScope(const CEntity &aLocalPlayer) noexcept;
}
