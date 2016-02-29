// BlackJack
// A simple (console) version of the casino game of blackjack; 1-7 players.
#ifndef PLAYER_HGUARD
#define PLAYER_HGUARD

#include "GenericPlayer.h"

// Derived (from GenericPlayer) class representing a human player
class Player : public GenericPlayer
{
	public:
		// Parametarised constructor
		Player(const std::string &name = "");

		// Just a default destructor
		virtual ~Player();

		// Returns whether or not the player wants another hit
		virtual bool IsHitting() const;

		// Announces that the player wins
		void Win() const;

		// Announces that the player losses
		void Lose() const;

		// Announces that the player pushes
		void Push() const;
};

#endif