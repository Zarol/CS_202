#include "Card.h"

using namespace std;

Card::Card()
{
	suit = "suit";
	rank = 0;
	location = "location";
}

Card::Card(string newSuit, int newRank, string newLocation)
{
	suit = newSuit;
	rank = newRank;
	location = newLocation;
}

Card::Card(const Card& newCard)
{
	suit = newCard.suit;
	rank = newCard.rank;
	location = newCard.location;
}

Card::~Card()
{
}

bool Card::setSuit(string newSuit)
{
	suit = newSuit;
	return true;
}

string Card::getSuit() const
{
	return suit;
}

bool Card::setRank(int newRank)
{
	if(newRank > 0 && newRank < 14)
	{
		rank = newRank;
		return true;
	}
	else
		return false;
}

int Card::getRank() const
{
	return rank;
}

bool Card::setLocation(string newLocation)
{
	location = newLocation;
	return true;
}

string Card::getLocation() const
{
	return location;
}

void Card::reset()
{
	suit = "suit";
	rank = 0;
	location = "location";
}

Card Card::operator=(const Card& sourceCard)
{
	suit = sourceCard.suit;
	rank = sourceCard.rank;
	location = sourceCard.location;
	return *this;
}

bool Card::operator>(const Card& sourceCard) const
{
	if(rank > sourceCard.rank)
		return true;
	else
		return false;
}

bool Card::operator<(const Card& sourceCard) const
{ 
	if(rank < sourceCard.rank)
		return true;
	else
		return false;
}


bool operator>=(const Card& sourceCard, const Card& compareCard)
{
	if(sourceCard.rank >= compareCard.rank)
		return true;
	else
		return false;
}

bool operator<=(const Card& sourceCard, const Card& compareCard)
{
	if(sourceCard.rank <= compareCard.rank)
		return true;
	else
		return false;
}

ifstream& operator>>(ifstream& ifs, Card& destCard)
{
	ifs >> destCard.suit;
	ifs >> destCard.rank;
	return ifs;
}

ostream& operator<<(ostream& os, Card& sourceCard)
{
	os << sourceCard.suit;
	os << " ";
	os << sourceCard.rank;
	os << " ";
	os << sourceCard.location;
	return os;
}
