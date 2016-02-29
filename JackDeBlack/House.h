// BlackJack
// A simple (console) version of the casino game of blackjack; 1-7 players.
#ifndef HOUSE_HGUARD
#define HOUSE_HGUARD

#include "GenericPlayer.h"

class House : public GenericPlayer
{
	public:
		House(const std::string &name = "House");

		virtual ~House();

		// Indicates whether house is hitting it will always hit on 16 or less
		virtual bool IsHitting() const;

		// Flips over first card
		void FlipFirstCard();
};

#endif