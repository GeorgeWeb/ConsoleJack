// BlackJack
// A simple (console) version of the casino game of blackjack; 1-7 players.
#include "Card.h"

using namespace std;

Card::Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{}

int Card::GetValue() const
{
	// if a card is face down, its value is 0
	int value = 0;

	if (m_IsFaceUp)
		// value is number showing on card and is equal to 10 for face cards
		value = (value > 10) ? 10 : m_Rank;

	return value;
}

void Card::Flip() 
{
	m_IsFaceUp = !m_IsFaceUp;
}