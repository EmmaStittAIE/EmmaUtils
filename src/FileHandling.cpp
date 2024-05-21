#include "FileHandling.hpp"

#include "Logger.hpp"

const std::string FileHandling::LoadFileToString(std::string filePath)
{
	std::stringstream fileContent;

	std::ifstream file;
	file.open(filePath, file.in);

	if (file.fail())
	{
		throw std::runtime_error("File at path \"" + filePath + "\" could not be read.");
	}

	while (!(file.peek() == EOF))
	{
		fileContent << (char)file.get();
	}

	return fileContent.str();
}

