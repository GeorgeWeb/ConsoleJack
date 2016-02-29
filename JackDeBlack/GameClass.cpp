#include "Game.h"

using namespace std;

Game::Game(const vector<string> &names)
{
	// Create a vector of players from a vector of names
	vector<string>::const_iterator pName;
	for (pName = names.begin(); pName != names.end(); ++pName)
		m_Players.push_back(Player(*pName));

	// seed the random number generator (just using the old c way, even though I am aware of the new cpp11 one)
	srand(static_cast<unsigned int>(time(0)));
	m_Deck.Populate();
	m_Deck.Shuffle();
}

Game::~Game()
{}

void Game::Play()
{
	// Deal initial 2 cards to everyone
	vector<Player>::iterator pPlayer;
	for (int i = 0; i < 2; ++i)
	{
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			m_Deck.Deal(*pPlayer);
		}
		m_Deck.Deal(m_House);
	}

	// Hide house's first card
	m_House.FlipFirstCard();

	// Display everyone's hand
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
		cout << *pPlayer << endl;
	}
	cout << m_House << endl;

	// Deal additional cards to players
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
		m_Deck.AdditionalCards(*pPlayer);
	}

	// Reveal house's first card
	m_House.FlipFirstCard();
	cout << endl << m_House;

	// Deal additional cards to house
	m_Deck.AdditionalCards(m_House);

	if (m_House.IsBusted())
	{
		// Everyone still playing wins
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			pPlayer->Win();
		}
	}
	else
	{
		// Compare each player still playing to house
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			if (!pPlayer->IsBusted())
			{
				if (pPlayer->GetTotal() > m_House.GetTotal())
					pPlayer->Win();
				else if (pPlayer->GetTotal() < m_House.GetTotal())
					pPlayer->Lose();
				else
					pPlayer->Push();
			}
		}
	}

	// Remove everyone's cards
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
		pPlayer->Clear();
	}
	m_House.Clear();
}