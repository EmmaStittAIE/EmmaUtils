#include "EmmaUtils/Rand.hpp"

#include <random>

const std::string Rand::GetRandomStringFromList(std::vector<std::string> listOfStrings)
{
	// Some <random> magic. Essentially, setup a seeded random generator, and give it minimum (inclusive) and maximum (exclusive) values
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, listOfStrings.size()-1);

	return listOfStrings[dist(mt)];
}
