/*
* PROGRAM: CS 202 Project 5
* AUTHOR: Saharath Kleips
* DATE: 02/22/2014
* PURPOSE: To recreate the basis structure of the Crazy Eights game with dynamic memory
*/

//	IMPORTS
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "strLib.h"
using namespace std;
//	END IMPORTS



//	STRUCTURES
/*
* Represents a Card within Crazy Eights
*/
struct Card
{
	char *suit;
	int rank;
	char *location;
};//END Card STRUCTURE

/*
* Represents a Player within Crazy Eights
*/
struct Player
{
	char *name;
	int *id;
	Card *hand;
};//END Player STRUCTURE
//	END STRUCTURES



//	CONSTANTS
const int NUM_CARDS = 52;
int NUM_PLAYERS; //Fake constant (just a global int) for the sake of dynamic amount of players originally used throughout the program
//	END CONSTANTS



//	FUNCTION PROTOTYPES
void initDeck(Card*);
void initCard(Card&);
void initPlayers(Player*);
void initPlayer(Player&);

void deallocateDeck(Card*);
void deallocateCard(Card&);
void deallocatePlayers(Player*);
void deallocatePlayer(Player&);

bool loadDeck(Card*, char*);
bool loadPlayers(Player*, char*);

void shuffleDeck(Card*, Card*);
void dealDeck(Card*, Card*, Player*);

void cardCopy(Card*, Card*, const char*);
void cardCopy(Card*, Card*);
void deckCopy(Card*, Card*, const char*);

void printDeck(Card*, int);
void printDeck(Card*);
void printPlayers(Player*);
//	END FUNCTION PROTOTYPES



/*
* Entry point for the function
*/
int main()
{
	bool exit = false;
	char userInput;
	char *fileName = new char[100];
	
	Card *unshuffled = new Card[NUM_CARDS];
	initDeck(unshuffled);
	Card *shuffled = new Card[NUM_CARDS];
	initDeck(shuffled);
	Card *stock = new Card[NUM_CARDS];
	initDeck(stock);
	Card *discard = new Card[NUM_CARDS];

	Player *players;
	Player *rootPlayer;

	//Grab Deck File Name
	do
	{
		cout << "Please enter the unshuffled deck's file name (100 MAX):" << endl;
		cin >> fileName;
	} while (loadDeck(unshuffled, fileName) == false);

	//Initialize player amount
	//TODO: Interaction with decimal numbers is weird - it tries every character (1.9 will not work, 1.8 will because 8 is possible)
	do
	{
		cout << "How many players wish to play (2-8)?:" << endl;
		cin >> userInput;
	} while ((userInput - '0') < 2 || (userInput - '0') > 8); //Loop until user input is between 2 & 8
	NUM_PLAYERS = userInput - '0';
	players = new Player[NUM_PLAYERS];
	initPlayers(players);
	rootPlayer = players;

	//Grab Player File Name
	do
	{
		cout << "Please enter the list of player's file name (100 MAX):" << endl;
		cin >> fileName;
	} while (loadPlayers(players, fileName) == false);
	delete[] fileName;
	fileName = NULL;	
	
	cout << "--- Functions have been pre-run to initialize outputs (Shuffled & Dealt). ---" << endl;
	shuffleDeck(shuffled, unshuffled);
	deckCopy(stock, shuffled, "stock");
	dealDeck(stock, discard, players);

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
		cout << "* 'H' to print the player's hands.  *" << endl;
//		cout << "* 'X' to shuffle the deck.          *" << endl;
		cout << "* 'Q' to quit.                      *" << endl;
		cout << "*************************************" << endl;
		cin >> userInput;
		cout << "*************************************" << endl;
		switch (toupper(userInput))
		{
			case 'U':
				printDeck(unshuffled);
				break;
			case 'S':
				printDeck(shuffled);
				break;
			case 'O':
				printDeck(stock);
				break;
			case 'D':
				printDeck(discard);
				break;
			case 'P':
				printPlayers(players);
				break;
			case 'H':
				for(int i = 0; i < NUM_PLAYERS; i++)
				{
					cout << (*players).name << endl;
					printDeck((*players).hand, 5);
					players++;
				}
				players = rootPlayer;
				break;
//			case 'X':
//				shuffleDeck(shuffled, unshuffled);
//				cout << "Shuffle success." << endl;
//				break;
			case 'Q':
				exit = true;
				break;
			default:
				cout << "\"" << userInput << "\" is an invalid input." << endl;
				break;
		}
	} while (exit == false);
	cout << "Goodbye!" << endl;

	deallocateDeck(unshuffled);
	deallocateDeck(shuffled);
	deallocateDeck(stock);
	deallocateDeck(discard);
	deallocatePlayers(players);
	return 0;
}//END main FUNCTION



//	INITIALIZE FUNCTIONS
/*
* Initalizes an array of Cards to their default values.
* PARAM: *ptrDeck - The pointer for the array of cards
*/
void initDeck(Card *ptrDeck)
{
	for(int i = 0; i < NUM_CARDS; i++)
	{
		initCard(*ptrDeck);
		ptrDeck++;
	}
}//END initDeck FUNCTION

/*
* Initalizes a Card.
* PARAM: &card - The Card to be initalized
*/
void initCard(Card &card)
{
	card.suit = new char[strLen("suit")];
	strCopy(card.suit, "suit");
	card.rank = 0;
	card.location = new char[strLen("location")];
	strCopy(card.location, "location");
}//END initCard FUNCTION

/*
* Initializes an array of 4 Players.
* PARAM: *ptrPlayers - The pointer for the array of Players
*/
void initPlayers(Player *ptrPlayers)
{
	for (int i = 0; i < NUM_PLAYERS; i++)
	{
		initPlayer(*ptrPlayers);
		ptrPlayers++;
	}
}//END initPlayers FUNCTION

/*
* Initializes a Player.
* PARAM: &player - The Player to be initialized
*/
void initPlayer(Player &player)
{
	player.name = new char[strLen("name")];
	strCopy(player.name, "name");
	player.id = new int[5];
	int *ptrID = player.id;
	for(int i = 0; i < 5; i++)
	{
		*ptrID = 0;
		ptrID++;
	}
	player.hand = new Card[5];
	Card *rootHand = player.hand;
	for(int i = 0; i < 5; i++)
	{
		initCard(*(player.hand));
		player.hand++;
	}
	player.hand = rootHand;
}//END initPlayer FUNCTION
//	END INITIALIZE FUNCTIONS



//	GARBAGE COLLECTION FUNCTIONS
/*
* Deallocates a dynamically sized array of Cards.
* PARAM: *ptrDeck - The pointer of the array of Cards
*/
void deallocateDeck(Card *ptrDeck)
{
	Card *ptrRoot = ptrDeck;
	for (int i = 0; i < NUM_CARDS; i++)
	{
		deallocateCard(*ptrDeck);
		ptrDeck++;
	}
	ptrDeck = ptrRoot;
	if(ptrDeck != NULL)
		delete[] ptrDeck;
	ptrDeck = NULL;
}//END deallocateDeck FUNCTION

/*
* Deallocates a dynamically allocated Card.
* PARAM: &card - The card to be deallocated
*/
void deallocateCard(Card &card)
{
	if(card.suit != NULL)
		delete[] card.suit;
	if(card.location != NULL)
		delete[] card.location;
	card.suit = NULL;
	card.location = NULL;
}//END deallocateCard FUNCTION

/*
* Deallocates a dynamically sized array of Players.
* PARAM: *ptrPlayers - The pointer of the array of Players
*/
void deallocatePlayers(Player *ptrPlayers)
{
	Player *ptrRoot = ptrPlayers;
	for (int i = 0; i < NUM_PLAYERS; i++)
	{
		deallocatePlayer(*ptrPlayers);
		ptrPlayers++;
	}
	ptrPlayers = ptrRoot;
	if(ptrPlayers != NULL)
		delete[] ptrPlayers;
	ptrPlayers = NULL;
}//END deallocatePlayers FUNCTION

/*
* Deallocates a dynamically allocated Player.
* PARAM: &player - The player to be deallocated
*/
void deallocatePlayer(Player &player)
{
	if(player.name != NULL)
		delete[] player.name;
	if(player.id != NULL)
		delete[] player.id;
	player.name = NULL;
	player.id = NULL;
	
	Card *rootHand = player.hand;
	for(int i = 0; i < 5; i++)
	{
		deallocateCard(*(player.hand));
		player.hand++;
	}
	player.hand = rootHand;
	if(player.hand != NULL)
		delete[] player.hand;
}//END deallocatePlayer FUNCTION
//	END GARBAGE COLLECTION FUNCTIONS



//	FILE I/O FUNCTIONS
/*
* Loads an array of Cards from a file.
* PARAM: *ptrDeck - The array of Cards to be loaded
*	 *fileName - The name of the file to load
* RETURN: True - File could be opened
*	  False - File could not be opened
*/
bool loadDeck(Card *ptrDeck, char *fileName)
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

			(*ptrDeck).rank = rank;
			
			//Deallocate and reallocate with proper size
			deallocateCard(*ptrDeck);
			(*ptrDeck).suit = new char[strLen(suit)];
			strCopy((*ptrDeck).suit, suit);
			(*ptrDeck).location = new char[strLen("unshuffed")];
			strCopy((*ptrDeck).location, "unshuffled");

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
* PARAM: *ptrPlayers - The array of Players to be loaded
*	 *fileName - The name of the file to load
* RETURN: True - File could be opened
*	  False - File could not be opened
*/
bool loadPlayers(Player *ptrPlayers, char *fileName)
{
	ifstream ifs;
	ifs.open(fileName);

	char *name = new char[100];
	int *ptrID = (*ptrPlayers).id;
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
				*ptrID = (temp) - '0'; //Converts character to integer and stores it into the ID"Pointer: "
				ptrID++;
			}
			//Deallocate and reallocate with the new size.
			if ((*ptrPlayers).name != NULL)
				delete[] (*ptrPlayers).name;
			(*ptrPlayers).name = new char[strLen(name)];
			strCopy((*ptrPlayers).name, name);

			ptrPlayers++;
			ptrID = (*ptrPlayers).id;
		}
		ifs.close();
		return true;
	}

	delete[] name;
	name = NULL;
}//END loadPlayers FUNCTION



//	GAME FUNCTIONS
/*
* Shuffles an array of Cards into a new array of Cards
* PARAM: *ptrShuffled - The new array of shuffled Cards
*	 *ptrUnshuffled - The array of Cards
*/
void shuffleDeck(Card *ptrShuffled, Card *ptrUnshuffled)
{
	initDeck(ptrShuffled); //Prepares the deck to be shuffled
	srand(time(NULL)); //Initializes random seed
	int rng;
	bool shuffleSuccess = false;
	Card *rootShuffle = ptrShuffled;

	//Traverse unshuffled deck
	for(int i = 0; i < NUM_CARDS; i++)
	{
		while (shuffleSuccess == false)
		{
			rng = rand() % NUM_CARDS;
			for(int j = 0; j < rng; j++) //Sets shuffled pointer to random index
				ptrShuffled++;
			if ((*ptrShuffled).rank == 0) //Copy card if shuffled index is empty
			{
				if((*ptrShuffled).location != NULL)
					delete[] (*ptrShuffled).location;
				(*ptrShuffled).location = new char[strLen("shuffled")];
				cardCopy(ptrShuffled, ptrUnshuffled, "shuffled");
				shuffleSuccess = true; //Go to next unshuffled card
			}
			ptrShuffled = rootShuffle; //Resets the pointer to be shifted again
		}
		shuffleSuccess = false;
		ptrUnshuffled++;
	}
}//END shuffleDeck FUNCTIONS

void dealDeck(Card *ptrStock, Card *ptrDiscard, Player *ptrPlayers)
{
	Player *rootPlayer = ptrPlayers;
	Card *rootStock = ptrStock;
	//Reset Player Hands
	//for(int i = 0; i < NUM_PLAYERS; i++)
	//{
	//	if ((*ptrPlayers).hand != NULL)
	//		delete [](*ptrPlayers).hand;
	//	(*ptrPlayers).hand = new Card[5];
	//	ptrPlayers++;
	//}
	ptrPlayers = rootPlayer;
	
	int roundsDealt = 0;
	//Deal 1 card ot each player, 5 cards per player
	for(int i = 0; i < NUM_PLAYERS * 5; i++)
	{	
		//Reset back to first player to deal second card, third card, etc when last player is reached
		if (i % NUM_PLAYERS == 0 && i != 0)
		{
			ptrPlayers = rootPlayer;
			roundsDealt++;
		}

		//Offset the hand by what card they're at, i.e. getting first card, getting second card
		Card *rootHand = (*ptrPlayers).hand;
		for(int j = 0; j < roundsDealt; j++)
			(*ptrPlayers).hand++;

		//Copy the card into the hand, remove the card from the stock
		cardCopy((*ptrPlayers).hand, ptrStock, (*ptrPlayers).name);
		deallocateCard((*ptrStock));

		(*ptrPlayers).hand = rootHand;
		ptrPlayers++;
		ptrStock++;
		
		//Put top card into discard
		if (i == (NUM_PLAYERS * 5) - 1){
			initCard(*ptrDiscard);
			cardCopy(ptrDiscard, ptrStock, "discard");
			deallocateCard((*ptrStock));		
		}
	}
}
//	END GAME FUNCTIONS



//	HELPER FUNCTIONS
/*
* Copies a Card to a new location.
* PARAM: *ptrDest - The pointer of the destination Card
*	 *ptrSource - The pointer of the source Card
*	 *location - The new location of the destination Card
*/
void cardCopy(Card *ptrDest, Card *ptrSource, const char *location)
{
	(*ptrDest).rank = (*ptrSource).rank;
	strCopy((*ptrDest).suit, (*ptrSource).suit);
	strCopy((*ptrDest).location, location);
}//END cardCopy FUNCTION

/*
* Copies a Card.
* PARAM: *ptrDest - The pointer of the destination Card
*	 *ptrSource - The pointer of the source Card
*/
void cardCopy(Card *ptrDest, Card *ptrSource)
{
	cardCopy(ptrDest, ptrSource, (*ptrSource).location);
}//END cardCopy FUNCTION

/*
* Copies a deck of Cards.
* PARAM: *ptrDest - The pointer of the destination deck
*	 *ptrSource - The pointer of the source deck
*	 *location - The location of the destination deck
*/
void deckCopy(Card *ptrDest, Card *ptrSource, const char *location)
{
	for(int i = 0; i < NUM_CARDS; i++)
	{
		cardCopy(ptrDest, ptrSource, location);
		ptrDest++;
		ptrSource++;
	}
}//END deckCopy FUNCTION
//	END HELPER FUNCTIONS



//	PRINT FUNCTIONS
/*
* Prints an array of Cards to the output stream.
* PARAM: *ptrDeck - The pointer of the array of cards
*	 length - The amount of cards in the deck
*/
void printDeck(Card *ptrDeck, int length)
{
	for(int i = 0; i < length; i++)
	{
		if ((*ptrDeck).suit != NULL)	//Only prints non-empty cards
			cout << (*ptrDeck).rank << " " << (*ptrDeck).suit << " (" << (*ptrDeck).location << ")" << endl;
		ptrDeck++;
	}
}//END printDeck FUNCTION

/*
* Prints an array of 52 Cards to the output stream.
* PARAM: *ptrDeck - The pointer of the array of cards
*/
void printDeck(Card *ptrDeck)
{
	printDeck(ptrDeck, NUM_CARDS);
}//END printDeck FUNCTION

/*
* Prints an array of Players to the output stream.
* PARAM: *ptrPlayers - The pointer of the array of Players
*/
void printPlayers(Player *ptrPlayers)
{
	int *ptrID = (*ptrPlayers).id;
	for(int i = 0; i < NUM_PLAYERS; i++)
	{
		cout << (*ptrPlayers).name << " (";
		for(int j = 0; j < 5; j++)
		{
			cout << *ptrID;
			ptrID++;
		}
		cout << ")" << endl;
		ptrPlayers++;
		ptrID = (*ptrPlayers).id;
	}
}//END printPlayers FUNCTION
//	END PRINT FUNCTIONS
