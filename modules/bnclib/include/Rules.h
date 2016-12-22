#pragma once

#include "stdint.h"
#include <string>

namespace bnc
{

/**
 * Structure for hints.
 */
struct BnC
{
	/** Bulls count. */
	uint8_t bulls;
	/** Cows count. */
	uint8_t cows;
};

/**
 * Class that represent game rules.
 */

class GameRules
{
	/**
	 * Construction and destruction.
	 */
public:
	/** Constructor.*/
	GameRules() = default;
	/** Constructor.*/
	GameRules(const uint8_t maxTurns, const std::string& task) noexcept ;
	
	/**
	 * Public interface.
	 */
public:
	/**
	 * Calculates hint.
	 * @param suggestion - player's.
	 * @return - hint, count of bulls and cows in nBmC format, where n is count of bulls, m - cows.
	 */
	std::string calculateHint(std::string suggestion);
	/**
	 * Returns true if player have more turns.
	 */
	bool isMoreTurns();
	/** Increments current turn.*/
	void nextTurn();
	/**
	 * Initialize members for the new game.
	 */
	void reset(const uint8_t maxTurns, const std::string& task);

	/** Setters and getters.*/
public:
	/**
	 * @return current turn.
	 */
	uint8_t getCurrentTurn() const;

	/**
	 * @return max turns.
	 */
	uint8_t getMaxTurns() const;
	
	/**
	 * Private data members.
	 */
private:
	/** Current turn.*/
	uint8_t m_currentTurn;
	/** Max turns.*/
	uint8_t m_maxTurns;
	/** Hidden word.*/
	std::string m_task;
};

/**
 * Inline implementations.
 */

inline uint8_t GameRules::getCurrentTurn() const
{
	return m_currentTurn;
}

inline uint8_t GameRules::getMaxTurns() const
{
	return m_maxTurns;
}

} // end of namespace bnc
