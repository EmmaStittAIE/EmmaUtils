#pragma once

#include <sstream>
#include <fstream>
#include <vector>

namespace FileHandling
{
	extern const std::string LoadFileToString(std::string filePath);
	extern const std::vector<char> LoadFileToByteArray(std::string filePath);
}