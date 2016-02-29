#include "Player.h"

using namespace std;

Player::Player(const string &name) : GenericPlayer(name) 
{}

Player::~Player()
{}

bool Player::IsHitting() const
{
	cout << m_Name << ", do you want a hit? (Y/N): ";
	char response; // a single char 'Y' or 'N'
	cin >> response;
	
	return (response == 'y' || response == 'Y');
}

void Player::Win() const
{
	cout << m_Name << " wins." << endl;
}

void Player::Lose() const
{
	cout << m_Name << " loses" << endl;
}

void Player::Push() const
{
	std::cout << m_Name << " pushes" << std::endl;
}