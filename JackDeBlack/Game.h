#ifndef GAME_HGUARD
#define GAME_HGUARD

#include "Deck.h"
#include "House.h"
#include "Player.h"
#include <ctime>

class Game
{
public:
	// Parametarised constructor
	Game(const std::vector<std::string> &names);
	
	// Just a default destructor
	~Game();

	// Plays the game of blackjack
	void Play();
	
private:
	Deck m_Deck;
	House m_House;
	std::vector<Player> m_Players;
};

#endif