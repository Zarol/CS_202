/*
* PROGRAM: CS 202 Project 3
* AUTHOR: Saharath Kleips
* DATE: 02/09/2014
* PURPOSE: To recreate the basis structure of the Crazy Eights game with pointers
*/

//	IMPORTS
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;
//	END IMPORTS



//	STRUCTURES
/*
* Represents a Card within Crazy Eights
*/
struct Card
{
	char suit[8];
	int rank;
	char location[100];
};//END Card STRUCTURE

/*
* Represents a Player within Crazy Eights
*/
struct Player
{
	char name[100];
	int id[5];
};//END Player STRUCTURE
//	END STRUCTURES



//	CONSTANTS
const int NUM_CARDS = 52;
const int NUM_PLAYERS = 4;
//	END CONSTANTS



//	FUNCTION PROTOTYPES
void initDeck(Card*);
void initCard(Card&);
void initPlayers(Player*);
void initPlayer(Player&);

bool loadDeck(Card*, char*);
bool loadPlayers(Player*, char*);

void shuffleDeck(Card*, Card*);

void strCopy(char*, char*);
void cardCopy(Card*, Card*, char*);
void cardCopy(Card*, Card*);

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
	char fileName[100];
	
	bool exit2 = false;
	char userInput2;
	char writeFile[100];	

	Card unshuffled[NUM_CARDS];
	initDeck(unshuffled);
	Card shuffled[NUM_CARDS];
	initDeck(shuffled);

	Player players[NUM_PLAYERS];
	initPlayers(players);

	//Grab Deck File Name
	do
	{
		cout << "Please enter the unshuffled deck's file name (100 MAX):" << endl;
		cin >> fileName;
	} while (loadDeck(unshuffled, fileName) == false);
	//printDeck(unshuffled);
	
	//Grab Player File Name
	do
	{
		cout << "Please enter the list of player's file name (100 MAX):" << endl;
		cin >> fileName;
	} while (loadPlayers(players, fileName) == false);
	//printPlayers(players);
	
	
	cout << "--- Functions have been pre-run to initialize outputs. ---" << endl;
	shuffleDeck(shuffled, unshuffled);

	do
	{
		cout << "*************************************" << endl;
		cout << "*           CRAZY EIGHTS            *" << endl;
		cout << "*************************************" << endl;
		cout << "* 'U' to print the unshuffled deck. *" << endl;
		cout << "* 'S' to print the shuffled deck.   *" << endl;
		cout << "* 'P' to print the players.         *" << endl;
		cout << "* 'X' to shuffle the deck.          *" << endl;
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
			case 'P':
				printPlayers(players);
				break;
			case 'X':
				shuffleDeck(shuffled, unshuffled);
				cout << "Shuffle success." << endl;
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
	strCopy(card.suit, "suit");
	card.rank = 0;
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
	strCopy(player.name, "name");
	int *ptrID = player.id;
	for(int i = 0; i < 5; i++)
	{
		*ptrID = 0;
		ptrID++;
	}
}//END initPlayer FUNCTION
//	END INITIALIZE FUNCTIONS



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

	char suit[8];
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
			strCopy((*ptrDeck).suit, suit);
			strCopy((*ptrDeck).location, "unshuffled");
			*ptrDeck++;
		}
		ifs.close();
		return true;
	}
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

	char name[100];
	int *ptrID = (*ptrPlayers).id;
	char tempID;
	char tempSpace;

	if (ifs.is_open() == false)
		return false;
	else
	{
		for(int i = 0; i < NUM_PLAYERS; i++)
		{
			ifs >> name;
			for (int j = 0; j < 5; j++)
			{
				ifs >> tempID;
				*ptrID = (tempID) - '0'; //Converts character to integer and stores it into the ID
				ptrID++;
			}
			strCopy((*ptrPlayers).name, name);
			ptrPlayers++;
			ptrID = (*ptrPlayers).id;
		}
		ifs.close();
		return true;
	}
}//END loadPlayers FUNCTION
//	END FILE I/O FUNCTIONS



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
				cardCopy(ptrShuffled, ptrUnshuffled, "shuffled");
				shuffleSuccess = true; //Go to next unshuffled card
			}
			ptrShuffled = rootShuffle; //Resets the pointer to be shifted again
		}
		shuffleSuccess = false;
		ptrUnshuffled++;
	}
}//END shuffleDeck FUNCTIONS
//	END GAME FUNCTIONS



//	HELPER FUNCTIONS
/*
* Copies an array of characters.
* PARAM: *ptrDest - The pointer of the destination character array
*	 *ptrSource - The pointer of the source character array
*/
void strCopy(char *ptrDest, char *ptrSource)
{
	while( *ptrSource != '\0' )
	{
		*ptrDest = *ptrSource;
		ptrDest++;
		ptrSource++;
	}
	*ptrDest = '\0';
}//END strCopy FUNCTION

/*
* Copies a card to a new location.
* PARAM: *ptrDest - The pointer of the destination Card
*	 *ptrSource - The pointer of the source Card
*	 *location - The new location of the destination Card
*/
void cardCopy(Card *ptrDest, Card *ptrSource, char *location)
{
	(*ptrDest).rank = (*ptrSource).rank;
	strCopy((*ptrDest).suit, (*ptrSource).suit);
	strCopy((*ptrDest).location, location);
}//END cardCopy FUNCTION

/*
* Copies a card.
* PARAM: *ptrDest - The pointer of the destination Card
*	 *ptrSource - The pointer of the source Card
*/
void cardCopy(Card *ptrDest, Card *ptrSource)
{
	cardCopy(ptrDest, ptrSource, (*ptrSource).location);
}//END cardCopy FUNCTION
//	END HELPER FUNCTIONS



//	PRINT FUNCTIONS
/*
* Prints an array of Cards to the output stream.
* PARAM: *ptrDeck - The pointer of the array of cards
*/
void printDeck(Card *ptrDeck)
{
	for(int i = 0; i < NUM_CARDS; i++)
	{
		cout << (*ptrDeck).rank << " " << (*ptrDeck).suit << " (" << (*ptrDeck).location << ")" << endl;
		ptrDeck++;
	}
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
