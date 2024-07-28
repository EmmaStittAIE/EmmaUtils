#include "EmmaUtils/FileHandling.hpp"

#include <cstring>

#include "EmmaUtils/Logger.hpp"

const std::string FileHandling::LoadFileToString(std::string filePath)
{
	std::stringstream fileContent;

	std::ifstream file(filePath, std::ios_base::in);

	if (file.fail())
	{
		throw std::runtime_error("File at path \"" + filePath + "\" could not be read: " + std::strerror(errno));
	}

	while (!(file.peek() == EOF))
	{
		fileContent << (char)file.get();
	}

	file.close();

	return fileContent.str();
}

const std::vector<char> FileHandling::LoadFileToByteArray(std::string filePath)
{
	std::ifstream file(filePath,  std::ios_base::in | std::ios_base::ate | std::ios_base::binary);

	if (file.fail())
	{
		throw std::runtime_error("File at path \"" + filePath + "\" could not be read: " + std::strerror(errno));
	}

	std::size_t bufferSize = (std::size_t)file.tellg();
	std::vector<char> buffer(bufferSize);

	file.seekg(0);
	file.read(buffer.data(), bufferSize);

	file.close();

	return buffer;
}