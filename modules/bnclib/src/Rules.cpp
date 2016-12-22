#include <string>
#include <stdexcept>

#include "Rules.h"
#include "Utils.h"

namespace bnc
{

/**
 * Definitions of the Game class.
 */

GameRules::GameRules(const uint8_t maxTurns, const std::string& task) noexcept
	: m_maxTurns(maxTurns)
	, m_task(task)
{
	m_currentTurn = 1;
}

std::string GameRules::calculateHint(std::string suggestion)
{
	size_t size = m_task.size();
	if(suggestion.size() != size)
	{
		std::string error = "Cannot calculate hint.\nSuggestion's size is incorrect.";
		throw std::runtime_error(error);
	}

	if (!bnc::GameStatics::isIsogram(suggestion))
	{
		std::string error = "Suggestion " + suggestion + " is not an isogram.";
		throw std::runtime_error(error);
	}

	BnC res{0, 0};
	for(size_t i = 0; i < size; ++i)
	{
		if(suggestion[i] == m_task[i])
		{
			++res.bulls;
		}
		else
		{
			for(size_t j = i + 1; j < size; ++j)
			{
				if(suggestion[i] == m_task[j])
				{
					++res.cows;
					break;
				}
			}
		}
	}

	std::string b = std::to_string(res.bulls);
	std::string c = std::to_string(res.cows);
	std::string result(b + "B" + c + "C");

	return result;
}

bool GameRules::isMoreTurns()
{
	return m_currentTurn <= m_maxTurns;
}

void GameRules::nextTurn()
{
	++m_currentTurn;
}

void GameRules::reset(const uint8_t maxTurns, const std::string& task)
{
	m_maxTurns = maxTurns;
	m_task = task;
	m_currentTurn = 1;
}

} // end of namespace bnc
