// BlackJack
// A simple (console) version of the casino game of blackjack; 1-7 players.
#ifndef GENERICPLAYER_HGUARD
#define GENERICPLAYER_HGUARD

#include "Hand.h"
#include <string>

// An abstract class representing what a general player structure should look like
class GenericPlayer : public Hand
{
	friend std::ostream &operator<<(std::ostream &os, const GenericPlayer &aGenericPlayer);
	
	public:
		// Parametarised constructor
		GenericPlayer(const std::string &name = "");

		// Just a default destructor
		virtual ~GenericPlayer();
	
		// Indicates whether or not a generic player wants to keep hitting
		virtual bool IsHitting() const = 0;

		// Returns if a generic player has busted (total > 21).
		bool IsBusted() const;

		// Bust generic player
		void Bust() const;

	protected:
		std::string m_Name;
};

#endif