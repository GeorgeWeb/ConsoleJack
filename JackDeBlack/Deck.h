// BlackJack
// A simple (console) version of the casino game of blackjack; 1-7 players.
#ifndef DECK_HGUARD
#define DECK_HGUARD

#include "GenericPlayer.h"
#include <algorithm>

// Derived (from Hand) class represents a deck of cards.
class Deck : public Hand
{
	public:
		// Default constructor
		Deck();

		// Default destructor
		virtual ~Deck();

		// Create a standard deck of 52 cards
		void Populate();

		// Shuffle cards
		void Shuffle();

		// Deal one card to a hand
		void Deal(Hand &hand);

		// Give additional cards to a generic player
		void AdditionalCards(GenericPlayer &aGenericPlayer);
};

#endif