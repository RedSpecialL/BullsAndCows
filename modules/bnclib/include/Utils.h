#pragma once

namespace bnc
{
/**
 * Class contains helper functions.
 */
class GameStatics
{
	/**
	 * Public interface.
	 */
public:
	/**
	 * Checks is the word an isogram.
	 * @param word - word to check.
	 * @return true if word is an isogram.
	 */
	static bool isIsogram(const std::string& word);
	/**
	 * Generates string of numbers that is an isogram.
	 * @param size - size in the task.
	 * @return the isogram string of numbers with specified size.
	 */
	static std::string generateNumberTask(const size_t size);
};

} // end of namespace bnc