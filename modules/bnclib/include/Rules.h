#pragma once

#include "stdint.h"

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
	 * @return - hint, count of bulls and cows.
	 */
	BnC calculateHint(std::string suggestion);
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

} // end of namespace bnc
