#include "Player.h"

Player::Player()
{
	name = "name";
	id = new int[5];
	for(int i = 0; i < 5; i++)
		id[i] = 0;
	hand = Stack<Card>();
}

Player::~Player()
{
	if(id != NULL)
		delete[] id;
	id = NULL;
}

bool Player::setName(string newName)
{
	name = newName;
	return true;
}

string Player::getName() const
{
	return name;
}

bool Player::setID(int *newID)
{
	for(int i = 0; i < 5; i++)
		id[i] = newID[i];
	return true;
}

int* Player::getID() const
{
	return id;
}

bool Player::giveCard(Card card)
{
	return hand.push(card);
}

bool Player::setHand(Stack<Card> newHand)
{
	hand = newHand;
	return true;
}

Stack<Card> Player::getHand() const
{
	return hand;
}

ifstream& operator>>(ifstream& ifs, Player& sourcePlayer)
{
	char temp;
	ifs >> sourcePlayer.name;
	for(int i = 0; i < 5; i++)
	{
		ifs >> temp;
		sourcePlayer.id[i] = temp - '0';
	}	
	return ifs;
}

ostream& operator<<(ostream& os, Player& sourcePlayer)
{
	os << sourcePlayer.name;
	os << " [";
	for(int i = 0; i < 5; i++)
		os << sourcePlayer.id[i];
	os << "]";
	return os;
}
