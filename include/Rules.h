#pragma once

#include "stdint.h"

namespace bnc
{

/*
 * Structure for hints.
 */
struct BnC
{
	/** Bulls count. */
	uint8_t bulls;
	/** Cows count. */
	uint8_t cows;
};

/*
 * Class that represent game rules.
 */

class GameRules
{
	/*
	 * Construction and destruction.
	 */
public:
	/** Constructpor.*/
	
	/*
	 * Public interface.
	 */
public:
	/*
	 * Calculates hint.
	 * @param suggestion - player's.
	 * @return - hint, count of bulls and cows.
	 */
	BnC calculateHint(std::string suggestion);
	
	/*
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
