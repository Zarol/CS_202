/*
* PROGRAM: CS 202 Project 7
* AUTHOR: Saharath Kleips
* DATE: 03/25/2014
* PURPOSE: To recreate the basic structure of the Crazy Eights game with copy constructor and const functions
*/

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "strLib.h"
#include "Project7Classes.h"
using namespace std;

//      CONSTANTS
const int NUM_CARDS = 52;
int NUM_PLAYERS; //Fake constant (just a global int) for the sake of dynamic amount of players originally used throughout the program
//      END CONSTANTS

//	FUNCTION PROTOTYPES
bool loadDeck(Card*, const char*);
bool loadPlayers(Player*, const char*);

void shuffleDeck(Card*, Card*);
void dealDeck(Player*, Card*, Card*);

bool printDeck(Card*);
bool printHand(Card*);
bool printPlayers(Player*);
//	END FUNCTION PROTOTYPES

/*
* Entry point for Project 7
*/
int main()
{
	bool hasShuffled = false;
	bool exit = false;
	char userInput;
	char *fileName = new char[100];
	
	Card *unshuffled = new Card[NUM_CARDS];
	Card *shuffled = new Card[NUM_CARDS];
	Card *stock = new Card[NUM_CARDS];
	Card *discard = new Card[NUM_CARDS];

	Card *rootShuffled = shuffled;
	Card *rootStock = stock;

	Player *players;
	Player *rootPlayers = players;

	do
	{
		cout << "Please enter the unshuffled deck's fille name (100 MAX):" << endl;
		cin >> fileName;
	} while (loadDeck(unshuffled, fileName) == false);

	do
	{
		cout << "Please enter the number of players (2-8):" << endl;
		cin >> userInput;
	} while ((userInput - '0') < 2 || (userInput - '0') > 8);

	NUM_PLAYERS = userInput - '0';
	players = new Player[NUM_PLAYERS];
	
	do
	{
		cout << "Please enter the list of player's file name (100 MAX):" << endl;
		cin >> fileName;
	} while (loadPlayers(players, fileName) == false);
	delete[] fileName;
	fileName = NULL;

	cout << "WARNING: Pressing 'Z' before shuffling the deck WILL cause a SEGMENTATION FAULT." << endl;

        do
        {
                cout << "*************************************" << endl;
                cout << "*           CRAZY EIGHTS            *" << endl;
                cout << "*************************************" << endl;
                cout << "* 'U' to print the unshuffled deck. *" << endl;
                cout << "* 'S' to print the shuffled deck.   *" << endl;
                cout << "* 'O' to print the stock deck.      *" << endl;
                cout << "* 'D' to print the discard deck.    *" << endl;
                cout << "* 'P' to print the players.         *" << endl;
		cout << "* 'H' to print the player's hand.   *" << endl;
		cout << "* 'Z' to deal the deck.             *" << endl;
                cout << "* 'X' to shuffle the deck.          *" << endl;
                cout << "* 'Q' to quit.                      *" << endl;
                cout << "*************************************" << endl;
                cin >> userInput;
                cout << "*************************************" << endl;
                switch (toupper(userInput))
                {
                        case 'U':
                                if(printDeck(unshuffled) == true)
					cout << "The deck is empty, there seems to have been a problem loading the file." << endl;
                                break;
                        case 'S':
                                if(printDeck(shuffled) == true)
					cout << "The deck is empty, have you shuffled it?" << endl;
                                break;
                        case 'O':
                                if(printDeck(stock) == true)
					cout << "The deck is empty, have you shuffled it? Shuffling the deck copies the deck into the stock deck." << endl;
                                break;
                        case 'D':
                                if(printDeck(discard) == true)
					cout << "The deck is empty, have you dealt the cards? Dealing the card places a card from the stock deck to the discard deck." << endl;
                                break;
                        case 'P':
                                if(printPlayers(players) == true)
					cout << "The player list is empty, there seems to have been a problem loading the file." << endl;
                                break;
			case 'H':
				for(int i = 0; i < NUM_PLAYERS; i++)
				{
					cout << (*players).getName() << endl;
					if(printHand((*players).getHand()) == true)
						cout << "The player's hand is empty, have you dealt the deck?" << endl;
					players++;
				}
				players = rootPlayers;
				break;
			case 'Z':
				if(hasShuffled == true)
				{
					dealDeck(players, discard, stock);
					cout << "Dealt successfully." << endl;
				}
				else
					cout << "Deal option unavailabe. Have you shuffled the deck?" << endl;
				break;
                        case 'X':
                                shuffleDeck(shuffled, unshuffled);
				for(int i = 0; i < NUM_CARDS; i++)
				{
					(*stock).setCard((*shuffled).getSuit(), (*shuffled).getRank(), "stock");
					stock++;
					shuffled++;
				}
				shuffled = rootShuffled;
				stock = rootStock;
				hasShuffled = true;
                                cout << "Shuffle success. WARNING: Shuffling more than once will cause errors." << endl;
                                break;
                        case 'Q':
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

//      FILE I/O FUNCTIONS
/*
* Loads an array of Cards from a file.
* PARAM: Card* - The array of Cards to be loaded.
*        const char* - The name of the file to load.
* RETURN: bool - The file could be opened or could not be opened.
*/
bool loadDeck(Card *ptrDeck, const char *fileName)
{
        ifstream ifs;
        ifs.open(fileName);
 
        char *suit = new char[8];
        int rank;
        if (ifs.is_open() == false)
                return false;
        else
        {
                for(int i = 0; i < NUM_CARDS; i++)
                {
                        ifs >> suit;
                        ifs >> rank;
 
			(*ptrDeck).setCard(suit, rank, "unshuffled");
                        *ptrDeck++;
                }
                ifs.close();
                return true;
        }
       
        delete[] suit;
        suit = NULL;
}//END loadDeck FUNCTION
 
/*
* Loads an array of Players from a file.
* @PARAM: Player* - The array of Players to be loaded.
*        const char* - The name of the file to load.
* @RETURN: bool - The file could be opened or could not be opened.
*/
bool loadPlayers(Player *ptrPlayers, const char *fileName)
{
        ifstream ifs;
        ifs.open(fileName);
 
        char *name = new char[100];
        int *id = new int[5];
	int *rootID = id;
        char temp;
 
        if (ifs.is_open() == false)
                return false;
        else
        {
                for(int i = 0; i < NUM_PLAYERS; i++)
                {
                        ifs >> name;
                        for (int j = 0; j < 5; j++)
                        {
                                ifs >> temp;
                                *id = (temp) - '0'; //Converts character to integer and stores it into the ID pointer
                                id++;
                        }
			id = rootID;
 			(*ptrPlayers).setName(name);
			(*ptrPlayers).setID(id);
                        ptrPlayers++;
                }
                ifs.close();
                return true;
        }

        delete[] name;
	delete[] id;
        name = NULL;
	id = NULL;
}//END loadPlayers FUNCTION
//	END FILE I/O FUNCTIONS

//	MAIN GAME FUNCTIONS
/*
* Shuffles a deck of cards.
* @PARAM: Card* - The destination of the newly shuffled cards.
*	  Card* - The deck to shuffle (will not be modified).
*/
void shuffleDeck(Card *ptrDest, Card *ptrSource)
{
	srand(time(NULL));
	int rng;
	bool shuffleSuccess = false;
	Card *rootDest = ptrDest;

	for(int i = 0; i < NUM_CARDS; i++)
	{
		while (shuffleSuccess == false)
		{
			rng = rand() % NUM_CARDS;
			for(int j = 0; j < rng; j++)
				ptrDest++;
			if ((*ptrDest).getRank() == 0)
			{
				(*ptrDest).setCard((*ptrSource).getSuit(), (*ptrSource).getRank(), "shuffled");
				shuffleSuccess = true;
			}
			ptrDest = rootDest;
		}
		shuffleSuccess = false;
		ptrSource++;
	}
}//END shuffleDeck FUNCTION

//DAISHAWN WAS HERE.

/*
* Deals a deck of cards to their respective piles and hands.
* @PARAM:
*
*/
void dealDeck(Player* ptrPlayers, Card* ptrDiscard, Card* ptrStock)
{
	Player *rootPlayer = ptrPlayers;
	Card *rootStock = ptrStock;

	int roundsDealt = 0;
	for(int i = 0; i < NUM_PLAYERS * 5; i++)
	{
		if(i % NUM_PLAYERS == 0 && i != 0)
		{
			ptrPlayers = rootPlayer;
			roundsDealt++;
		}
		
		Card *handOffset = (*ptrPlayers).getHand();
		for(int j = 0; j < roundsDealt; j++)
		{
			handOffset++;
		}
		
		(*handOffset).setCard((*ptrStock).getSuit(), (*ptrStock).getRank(), (*ptrPlayers).getName());
		(*ptrStock).setRank(0);

		ptrPlayers++;
		ptrStock++;
	}

	(*ptrDiscard).setCard((*ptrStock).getSuit(), (*ptrStock).getRank(), "discard");
	(*ptrStock).setRank(0);
}//END dealDeck FUNCTION
//	END MAIN GAME FUNCTIONS

//	PRINT FUNCTIONS
/*
* Prints non-empty cards within a deck.
* @PARAM: Card* - The array of cards to be printed.
* @RETURN: bool - The array is empty or not empty.
*/
bool printDeck(Card *ptrDeck)
{
	bool empty = true;
	for(int i = 0; i < NUM_CARDS; i++)
	{
		if(ptrDeck != NULL && (*ptrDeck).getRank() != 0)
		{
			empty = false;
			(*ptrDeck).print();
		}
		ptrDeck++;
	}
	return empty;
}//END printDeck FUNCTION

/*
* Prints non-empty cards within a hand.
* @PARAM: Card* - The array of cards to be printed.
* @RETURN: bool - The array is empty or not empty.
*/
bool printHand(Card *ptrDeck)
{
	bool empty = true;
	for(int i = 0; i < 5; i++)
	{
		if(ptrDeck != NULL && (*ptrDeck).getRank() != 0)
		{
			empty = false;
			(*ptrDeck).print();
		}
		ptrDeck++;
	}
	return empty;
}//END printHand FUNCTION

/*
* Prints non-null Players within a Player array.
* @PARAM: Player* - The player array to print.
* @RETURN: bool - The array is empty or not empty.
*/
bool printPlayers(Player *ptrPlayers)
{
	bool empty = true;
	for(int i = 0; i < NUM_PLAYERS; i++)
	{
		if(ptrPlayers != NULL)
		{
			empty = false;
			(*ptrPlayers).print();
		}
		ptrPlayers++;
	}
	return empty;
}//END printPlayers FUNCTION
//	END PRINT FUNCTIONS
