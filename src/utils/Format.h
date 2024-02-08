#pragma once

#include <string>

template <typename... Args>
inline std::string Format(const char *format, Args... args)
{
	const int len = std::snprintf(nullptr, 0, format, args...);
	if (len <= 0)
		return "";
	char *s = new char[len + 1];
	std::string res;
	std::snprintf(s, len + 1, format, args...);
	res = std::string(s);
	delete[] s;
	return res;
}
