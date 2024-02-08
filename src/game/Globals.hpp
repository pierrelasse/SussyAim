#pragma once

#include "../sacommon.hpp"
#include "../utils/ProcessManager.hpp"

template <typename T>
inline bool GetDataAddressWithOffset(const DWORD64 &Address, DWORD Offset, T &Data)
{
	if (Address == 0)
		return false;
	return ProcessMgr.ReadMemory<T>(Address + Offset, Data);
}
