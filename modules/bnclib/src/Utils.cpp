#include <ctime>
#include <map>
#include "Utils.h"

namespace bnc
{
/*
 * Definitions of the GameStatics class.
 */
 
bool GameStatics::isIsogram(const std::string& word)
{
	std::map<char, bool> used;
	
	for(const auto letter : word)
	{
		if(used[letter] == true)
		{
			return false;
		}
		
		used[letter] = true;
	}
	
	return true;
}

std::string GameStatics::generateNumberTask(const size_t size)
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	if(size >= 10)
	{
		throw std::runtime_error("Cannot generate number task. Size is too big.");
	}
	
	static std::string digits("0123456789");
	int swapCount = std::rand() % 50;
	for(int i = 0; i < swapCount; ++i)
	{
		std::swap(digits[rand() % 10], digits[rand() % 10]);
	}
	
	if(digits[0] == '0')
	{
		std::swap(digits[0], digits[1]);
	}
	
	return digits.substr(0, size);
}

} // end of namespace bnc
