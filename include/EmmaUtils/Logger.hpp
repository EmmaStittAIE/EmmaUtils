#pragma once

#include <string>
#include <initializer_list>

enum LogType
{
	None,
	Info,
	Warning,
	Error,
	Fatal
};

namespace Logger
{
	extern void Log(std::initializer_list<std::string> messageText, LogType type);
}