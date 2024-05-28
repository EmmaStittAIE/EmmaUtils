#include "EmmaUtils/FileHandling.hpp"

#include <cstring>

#include "EmmaUtils/Logger.hpp"

const std::string FileHandling::LoadFileToString(std::string filePath)
{
	std::stringstream fileContent;

	std::ifstream file;
	file.open(filePath, file.in);

	if (file.fail())
	{
		throw std::runtime_error("File at path \"" + filePath + "\" could not be read: " + std::strerror(errno));
	}

	while (!(file.peek() == EOF))
	{
		fileContent << (char)file.get();
	}

	return fileContent.str();
}

