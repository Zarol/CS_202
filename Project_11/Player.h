#ifndef PLAYER_H_
#define PLAYER_H_
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include "Card.h"
#include "Stack.h"

using namespace std;

class Player
{
	public:
		Player();
		~Player();
		bool setName(string);
		string getName() const;
		bool setID(int*);
		int* getID() const;
		bool giveCard(Card);
		bool setHand(Stack<Card>);
		Stack<Card> getHand() const;

		friend ifstream& operator>>(ifstream&, Player&);
		friend ostream& operator<<(ostream&, Player&);
	private:
		string name;
		int *id;
		Stack<Card> hand;
};
#endif
