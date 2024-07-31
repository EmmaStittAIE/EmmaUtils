#include "EmmaUtils/Logger.hpp"

#include <iostream>
#include <format>
#include <chrono>
using namespace std::chrono;

void Logger::Log(std::initializer_list<std::string> messageText, LogType type)
{
	std::string concatMessage;
	for (std::string messagePart : messageText)
	{
		concatMessage += messagePart;
	}

	// ugh i hate chrono
	std::string timeString = "[" +
							 std::format("{:%T}", zoned_time{current_zone(), system_clock::now()}).erase(8, std::string::npos)
							 + "] ";

	switch (type)
	{
	case None:
		std::cout << timeString << concatMessage << std::endl;
		break;
	case Info:
		std::cout << timeString << "Info: " << concatMessage << std::endl;
		break;
	case Warning:
		std::cerr << timeString << "Warning: " << concatMessage << std::endl;
		break;
	case Error:
		std::cerr << timeString << "Error: " << concatMessage << std::endl;
		break;
	case Fatal:
		std::cerr << timeString << "Fatal Error: " << concatMessage << std::endl;
		break;
	}
}
