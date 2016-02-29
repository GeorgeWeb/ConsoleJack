// BlackJack
// A simple (console) version of the casino game of blackjack; 1-7 players.
#ifndef CARD_HGUARD
#define CARD_HGUARD

#include <iostream>

class Card
{
	public:
		// Enumeration for all 13 card ranks.
		enum rank
		{
			ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
		};

		// Enumeration for the four possible suits.
		enum suit
		{
			CLUBS, DIAMONDS, HEARTS, SPADES
		};

		// Overloading << operator so we can send Card object to standart output.
		friend std::ostream& operator<<(std::ostream& os, const Card& aCard);

		// Parametarised constructor
		Card(rank r = ACE, suit s = SPADES, bool ifu = true);

		// Return the value of a card.
		int GetValue() const;

		// Flips a card. Face up becomes face down and vice versa.
		void Flip();

	private:
		// Rank of the card (ace, 2, 3, and so on).
		rank m_Rank;

		// Suit of the card (clubs, diamonds, hearts, or spades).
		suit m_Suit;

		// Indicates if the card is face up. Affects how the card is displayed and the value it has.
		bool m_IsFaceUp;
};

#endif