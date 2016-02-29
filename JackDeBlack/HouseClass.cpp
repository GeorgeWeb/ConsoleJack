#include "House.h"

using namespace std;

House::House(const std::string &name) : GenericPlayer(name)
{}

House::~House()
{}

bool House::IsHitting() const
{
	return (GetTotal() < 17); // just cuz' it's faster than <= 16
}

void House::FlipFirstCard()
{
	if (!(m_Cards.empty()))
		m_Cards[0]->Flip();
	else
		cout << "No card to flip!" << endl;
}