/*
* PROGRAM: CS 202 Project 8
* AUTHOR: Saharath Kleips
* DATE: 04/01/2014
* PURPOSE: To recreate the basic structure of the Crazy Eights game with overloaded operators, offset notation, and strings.
*/

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include "Project8Classes.h"
using namespace std;

//	CONSTANTS
const int NUM_CARDS = 52;
int NUM_PLAYERS;
//	END CONSTANTS

//	FUNCTION PROTOTYPES
bool loadDeck(Card*, string);
bool loadPlayers(Player*, string);

void shuffleDeck(Card*);
void dealDeck(Player*, Card*, Card*);
//	END FUNCTION PROTOTYPES

/*
* Entry point for Project 8
*/
int main()
{
	char userInput;
	string fileName;
	bool exit = false;

	Card *unshuffled = new Card[NUM_CARDS];
	Card *shuffled = new Card[NUM_CARDS];
	Card *stock = new Card[NUM_CARDS];
	Card *discard = new Card[NUM_CARDS];

	Player *players;

	do
	{
		cout << "Please enter the unshuffled deck's file name (100 MAX):" << endl;
		cin >> fileName;
	} while (loadDeck(unshuffled, fileName) == false);

	do
	{
		cout << "Please enter the number of players (2-8):" << endl;
		cin >> userInput;
	} while ((userInput - '0') < 2 && (userInput - '0') > 8);

	NUM_PLAYERS = userInput - '0';
	players = new Player[NUM_PLAYERS];

	do
	{
		cout << "Please enter the list of player's file name (100 MAX):" << endl;
		cin >> fileName;
	} while (loadPlayers(players, fileName) == false);

	for(int i = 0; i < NUM_CARDS; i++)
	{
		shuffled[i] = unshuffled[i];
		shuffled[i].setLocation("shuffled");
	}	

	cout << "NOTE: Please shuffle and deal the deck to initialize outputs." << endl;
	cout << "NOTE: You can shuffle more than once." << endl;
	cout << "NOTE: Always shuffle before dealing." << endl;	

	do
	{
		cout << "*****************************" << endl;
		cout << "*       CRAZY EIGHTS        *" << endl;
		cout << "*****************************" << endl;
		cout << "* 1. Print unshuffled deck. *" << endl;
		cout << "* 2. Print shuffled deck.   *" << endl;
		cout << "* 3. Print stock deck.      *" << endl;
		cout << "* 4. Print discard deck.    *" << endl;
		cout << "* 5. Print players.         *" << endl;
		cout << "* 6. Print player's hands.  *" << endl;
		cout << "* 7. Shuffle the deck.      *" << endl;
		cout << "* 8. Deal deck.             *" << endl;
		cout << "* 0. Quit                   *" << endl;
		cout << "*****************************" << endl;
		cout << "Enter a number: ";
		cin >> userInput;
		cout << "*****************************" << endl;

		switch (userInput - '0')
		{
			case 1:
				for(int i = 0; i < NUM_CARDS; i++)
					cout << unshuffled[i] << endl;
				break;
			case 2:
				for(int i = 0; i < NUM_CARDS; i++)
					cout << shuffled[i] << endl;
				break;
			case 3:
				for(int i = 0; i < NUM_CARDS; i++)
					cout << stock[i] << endl;
				break;
			case 4:
				for(int i = 0; i < NUM_CARDS; i++)
					cout << discard[i] << endl;
				break;
			case 5:
				for(int i = 0; i < NUM_PLAYERS; i++)
					cout << players[i] << endl;
				break;
			case 6:
				for(int i = 0; i < NUM_PLAYERS; i++)
				{
					cout << players[i] << endl;
					for(int j = 0; j < 5; j++)
						cout << "	" << players[i].getHand()[j] << endl;
				}
				break;
			case 7:
				shuffleDeck(shuffled);
				for(int i = 0; i < NUM_CARDS; i++)
				{
					stock[i] = shuffled[i];
					stock[i].setLocation("stock");
				}
				cout << "Shuffle success." << endl;
				break;
			case 8:
				dealDeck(players, discard, stock);
				cout << "Deal success." << endl;
				break;
			case 0:
				exit = true;
				break;
			default:
				cout << "\"" << userInput << "\" is an invalid input." << endl;
				break;
		}
	} while (exit == false);

	cout << "Goodbye!" << endl;
	return 0;
}

bool loadDeck(Card *ptrDeck, string fileName)
{
	ifstream ifs;
	ifs.open(fileName.c_str());
	
	if(ifs.is_open() == false)
		return false;
	else
	{
		for(int i = 0; i < NUM_CARDS; i++)
		{
			ifs >> ptrDeck[i];
			ptrDeck[i].setLocation("unshuffled");
		}
		ifs.close();
		return true;
	}
}

bool loadPlayers(Player *ptrPlayers, string fileName)
{
	ifstream ifs;
	ifs.open(fileName.c_str());

	if(ifs.is_open() == false)
		return false;
	else
	{
		for(int i = 0; i < NUM_PLAYERS; i++)
			ifs >> ptrPlayers[i];
		ifs.close();
		return true;
	}
}

void shuffleDeck(Card* deck)
{
	srand(time(NULL));
	int rng, rng2;
	Card temp, temp2;
	for(int i = 0; i < 1000000; i++)
	{
		rng = rand() % NUM_CARDS;
		temp = deck[rng];
		rng2 = rand() % NUM_CARDS;
		temp2 = deck[rng2];
		deck[rng] = temp2;
		deck[rng2] = temp;
	}
}

void dealDeck(Player* ptrPlayers, Card* ptrDiscard, Card* ptrStock)
{
	int cardsDealt = 0;
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < NUM_PLAYERS; j++)
		{
			ptrPlayers[j].getHand()[i] = ptrStock[cardsDealt];
			ptrPlayers[j].getHand()[i].setLocation(ptrPlayers[j].getName());
			ptrStock[i+j].reset();
			if(i == 4 && j == NUM_PLAYERS - 1)
			{
				ptrDiscard[0] = ptrStock[cardsDealt+1];
				ptrDiscard[0].setLocation("discard");
				ptrStock[cardsDealt+1].reset();
			}
			cardsDealt++;		
		}
	}
}
