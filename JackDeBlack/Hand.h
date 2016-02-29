// BlackJack
// A simple (console) version of the casino game of blackjack; 1-7 players.
#ifndef HAND_HGUARD
#define HAND_HGUARD

#include "Card.h"
#include <vector>

class Hand 
{
	public:
		// Default constructor
		Hand();
	
		// Destroys(Empties) hand (and frees all the allocated memory)
		virtual	~Hand();

		// Adds a card to the hand
		void Add(Card *pCard);

		// Clears hand of all cards
		void Clear();

		// Gets hand total value and (Intelligently) treats aces as 1 or 11
		int GetTotal() const;
	
	protected:
		std::vector<Card*> m_Cards;
};

#endif