#include "Deck.h"
#include<iostream>
using namespace std;

Deck::Deck()
{
	m_Cards.reserve(52);
	Populate();
}

Deck::~Deck()
{}

void Deck::Populate()
{
	Clear();
	
	// Create a standard deck
	for (int s = Card::suit::CLUBS; s <= Card::suit::SPADES; ++s)
	{
		for (int r = Card::rank::ACE; r <= Card::rank::KING; ++r)
		{
			Add(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
		}
	}
}

void Deck::Shuffle()
{
	random_shuffle(m_Cards.begin(), m_Cards.end());
}

void Deck::Deal(Hand &aHand)
{
	if (!m_Cards.empty())
	{
		aHand.Add(m_Cards.back());
		m_Cards.pop_back();
	}
	else
		cout << "Out of cards. Unable to deal.";
}

void Deck::AdditionalCards(GenericPlayer &aGenericPlayer)
{
	cout << endl;

	// Continue to deal a card as long as generic player isn't busted and wants another hit
	while (!aGenericPlayer.IsBusted() && aGenericPlayer.IsHitting())
	{
		Deal(aGenericPlayer);
		cout << aGenericPlayer << endl;

		if (aGenericPlayer.IsBusted())
			aGenericPlayer.Bust();
	}
}