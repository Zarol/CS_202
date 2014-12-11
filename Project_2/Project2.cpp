/*
* PROGRAM: CS 202 Project 2
* AUTHOR: Saharath Kleips
* DATE: 02/01/2014
* PURPOSE: To create the basis of the Crazy Eights card game. Support of 4 players, dealing cards, structures, file i/o, etc.
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

//GLOBAL VARIABLES
const int NUM_CARDS = 52;
//GLOBAL VARIABLES

//STRUCTURES
struct Card
{	
	char suit[8];
	int rank;
	char location[50];
};

struct Player
{
	char name[100];
	int id[5];
	Card hand[NUM_CARDS];
};
//END STRUCTURES

//FUNCTION PROTOTYPES
void initializeCards(Card c[]);
void initializePlayers(Player p[]);
void loadUnshuffled(Card c[]);
void loadPlayers(Player p[]);
void writeDeckToFile(Card c[]);
void shuffleDeck(Card s[], Card u[]);
void dealDeck(Card c[], Card d[], Player p[]);
void setCard(Card& c, char s[], int r, char l[]);
void setPlayer(Player& p, char n[], int i[], Card h[]);
void giveCard(Player& p, Card c); //Maybe combine giveCard and discardCard
void discardCard(Card d[], Card& c);
void deckCopy(Card d[], Card s[], char l[]);
void strCopy(char d[], char s[]);
void arrIntCopy(int d[], int s[], int si);
void printPlayer(Player p);
void printCard(Card c);
void printHand(Player p);
void menuSystem();
//END FUNCTION PROTOTYPES

/* NOTES:
* Deal 1 card to each player, 5 cards each
* first card of undealt is face up
* play is clockwise
* ---Play legal card or draw card
* ---If top card is not 8, play card that matches rank or suit
* ---Any eight on any card, must then nominate a suit
* ---If eight is top of pile, must play eight or any card of the suit nominated
* first player who removes all cards wins
* score pentalty according to cards left (-50 for eight, 10 for K/Q/J, spot cards at value)
* If pile is empty, game continues w/o drawing - can pass
* ---All pass results in game over and scored
*/

/*
* MAIN FUNCTION
*/
int main()
{
	menuSystem();
	return 0;
}
//END main FUNCTION

/*
* Allows the user to interface with the program.
*/
void menuSystem()
{
	bool exit = false;
	char userInput;

	//Overall Game Variables
	Card unshuffled[NUM_CARDS];
	initializeCards(unshuffled);
	Card shuffled[NUM_CARDS];
	initializeCards(shuffled);
	Card stock[NUM_CARDS];
	initializeCards(stock);
	Card discard[NUM_CARDS];
	initializeCards(discard);
	Player players[4];
	initializePlayers(players);
	
	//Initalizes all menu options so that "nothing" never shows up
	loadUnshuffled(unshuffled);
	loadPlayers(players);
	shuffleDeck(shuffled, unshuffled);
	char strStock[] = "stock";
	deckCopy(stock, shuffled, strStock);
	dealDeck(stock, discard, players);
	
	cout << "The deck has been pre-dealt to initialize outputs." << endl;
	do
	{
		cout << "****************************************************" << endl;
		cout << "*                   CRAZY EIGHTS                   *" << endl;
		cout << "****************************************************" << endl;
		cout << "* U to print the unshuffled deck.                  *" << endl;
		cout << "* S to print the shuffled deck.                    *" << endl;
		cout << "* O to print the stock deck.                       *" << endl;
		cout << "* C to print the discard deck.                     *" << endl;
		cout << "* W to write the shuffled deck to a file.          *" << endl;
		cout << "* X to shuffle the deck.                           *" << endl;
		cout << "* D to deal the cards. (Shuffle to deal new cards.)*" << endl;
		cout << "* P to print the player list.                      *" << endl;
		cout << "* H to print all player hands.                     *" << endl;
		cout << "* Q to Quit.                                       *" << endl;
		cout << "****************************************************" << endl;
		cin >> userInput;
		cout << "****************************************************" << endl;
		switch (toupper(userInput))
		{
			case 'U':
				for (int i = 0; i < NUM_CARDS; i++)
					printCard(unshuffled[i]);
				break;
			case 'S':
				for (int i = 0; i < NUM_CARDS; i++)
					printCard(shuffled[i]);
				break;
			case 'O':
				for (int i = 0; i < NUM_CARDS; i++)
					printCard(stock[i]);
				break;
			case 'C':
				for (int i = 0; i < NUM_CARDS; i++)
					printCard(discard[i]);
				break;
			case 'W':
				writeDeckToFile(shuffled);
				cout << "Shuffled deck successfully written to \"shuffled\"." << endl;
				break;
			case 'X':
				shuffleDeck(shuffled, unshuffled);
				cout << "Cards successfully shuffled." << endl;
				break;
			case 'D':
				initializeCards(stock);
				initializeCards(discard);
				deckCopy(stock, shuffled, strStock); //Resets the stock deck
				dealDeck(stock, discard, players);
				cout << "Cards successfully dealt." << endl;
				break;
			case 'P':
				for (int i = 0; i < 4; i++)
					printPlayer(players[i]);
				break;
			case 'H':
				for (int i = 0; i < 4; i++)
				{
					printPlayer(players[i]);
					printHand(players[i]);
				}
				break;
			case 'Q':
				cout << "Goodbye!" << endl;
				exit = true;
				break;
			default:
				cout << "\"" << userInput << "\"" << " is an invalid entry." << endl;
				break;
		}
	}
	while (exit == false);
}
//END menuSystem FUNCTION

/*
* Initializes an array of Cards to their default values.
* PARAM: deck[] - The array of cards to be initialized
*/
void initializeCards(Card deck[])
{
	char suit[] = "suit";
	int rank = 0;
	char location[] = "location";
	for(int i = 0; i < NUM_CARDS; i++)
		setCard(deck[i], suit, rank, location);
}
//END initializeCards FUNCTION

/*
* Initializes an array of Players to their default values.
* PARAM: players[] - The array of players to be initialized
*/
void initializePlayers(Player players[])
{
	char name[] = "name";
	int id[] = {0,0,0,0,0};
	Card hand[NUM_CARDS];
	initializeCards(hand);
	for(int i = 0; i < 4; i++)
		setPlayer(players[i], name, id, hand);
}
//END initializePlayers FUNCTION

/*
* Loads a deck from a user-defined file into a struct array.
* PARAM: unshuffled[NUM_CARDS] - The unshuffled deck of cards
*/
void loadUnshuffled(Card unshuffled[NUM_CARDS])
{
	ifstream ifs;
	char userInput[100];
	
	//Grab file name
	do
	{
		cout << "Please input the unshuffled deck's file name..." << endl;
		cin >> userInput;
		ifs.open(userInput);
		if (ifs.is_open() == false)
			cout << "\"" << userInput << "\"" << " is an invalid file name." << endl;
	}
	while (ifs.is_open() == false);

	int rank;
	char suit[8];
	char location[11] = "unshuffled";
	for (int i = 0; i < NUM_CARDS; i++)
	{
		ifs >> suit;
		ifs >> rank;
		setCard(unshuffled[i], suit, rank, location);
	}
	ifs.close();
}
//END loadUnshuffled FUNCTION

/*
* Loads a player list from a user-defined file into a struct array.
* PARAM: players[4] - The list of players
*/
void loadPlayers(Player players[4])
{
	ifstream ifs;
	char userInput[100];

	//Grab file name
	do
	{
		cout << "Please input the list of player's file name..." << endl;
		cin >> userInput;
		ifs.open(userInput);
		if (ifs.is_open() == false)
			cout << "\"" << userInput << "\"" << " is an invalid file name." << endl;
	}
	while (ifs.is_open() == false);

	char name[100];
	int id[5];
	char temp[2];
	Card hand[NUM_CARDS];
	for (int i = 0; i < 4; i++)
	{
		ifs >> name;
		ifs.ignore(256, ' '); //Ignores characters until id
		for (int j = 0; j < 5; j++)
		{
			ifs.read(temp, 1); //Gets single numbers from the id
			id[j] = (temp[0]) - '0'; //Converts the character into an integer
		}
		setPlayer(players[i], name, id, hand);
	}
}
//END loadPlayers FUNCTION

/*
* Writes an array of Cards to a file.
* PARAM: deck[] - The array of Cards to be written.
*/
void writeDeckToFile(Card deck[])
{
	ofstream shuffled("shuffled");
	
	if( shuffled.is_open())
	{
		for (int i = 0; i < NUM_CARDS; i++)
		{
			shuffled << deck[i].suit;
			shuffled << ' ';
			shuffled << deck[i].rank;
			shuffled << '\n';
		}
		shuffled.close();
	}
	else
		cout << "ERROR: Unable to open file.";
}
//END writeDeckToFile FUNCTION

/*
* Randomly shuffles an array of Cards.
* PARAM: shuffled[] - The Card array for the newly shuffled cards
* 	 unshuffled[] - The Card array to shuffled
*/
void shuffleDeck(Card shuffled[], Card unshuffled[])
{
	initializeCards(shuffled);

	srand(time(NULL));
	int rng;
	bool shuffleSuccess = false;
	char location[] = "shuffled";

	//Traverse the unshuffled in-order, select a random index in the shuffled, if open - place, if not - select new index
	for (int i = 0; i < NUM_CARDS; i++)
	{
		while (shuffleSuccess == false)
		{
			rng = rand() % NUM_CARDS;
			if (shuffled[rng].rank == 0)
			{
				setCard(shuffled[rng], unshuffled[i].suit, unshuffled[i].rank, location);
				shuffleSuccess = true;
			}
		}
		shuffleSuccess = false;
	}
}
//END shuffleCards FUNCTION

/*
* Deals a deck of cards per Crazy Eight's rules.
* PARAM: stock[] - The array of Cards to be dealt
*	 discard[] - The array of discarded Cards
*	 players[] - The array of Players playing
*/
void dealDeck(Card stock[], Card discard[], Player players[])
{
	//Clear previous hands
	for(int i = 0; i < 4; i++)
		initializeCards(players[i].hand);

	char suit[] = "suit";
	int rank = 0;
	char location[] = "location";
	//Deal 1 card to each player, 5 cards per player
	int pSelect = 0;
	for(int i = 0; i < 20; i++)
	{
		if (pSelect == 4)
			pSelect = 0;
		giveCard(players[pSelect], stock[i]);
		setCard(stock[i], suit, rank, location);
		pSelect++;
		if ( i == 19 )
			discardCard(discard, stock[i + 1]); //Places the top card into the discard to start the game
	}
}
//END dealDeck FUNCTION

/*
* Sets a Card structure.
* PARAM: destination - The Card to be set.
	 suit[] - The suit of the Card.
	 rank - The rank of the Card.
	 location[] - The location of the card.
*/
void setCard(Card& destination, char suit[], int rank, char location[])
{
	destination.rank = rank;
	strCopy(destination.suit, suit);
	strCopy(destination.location, location);
}
//END setCard FUNCTION

/*
* Sets a Player structure
* PARAM: destination - The Player to be set.
* 	 name[] - The name of the Player.
*	 id[] - The id of the Player.
*	 hand[] - The Card array of the Player. 
*/
void setPlayer(Player& destination, char name[], int id[], Card hand[])
{
	strCopy(destination.name, name);
	arrIntCopy(destination.id, id, 5);
	deckCopy(destination.hand, hand, destination.name);
}
//END setPlayer FUNCTION

/*
* Gives a card to a specific player.
* PARAM: player - The player to be given the card
*	 card - The card to be given
*/
void giveCard(Player& player, Card card)
{
	int i = 0;
	//Puts a card at the next empty spot
	while (player.hand[i].rank != 0)
		i++;
	setCard(player.hand[i], card.suit, card.rank, player.name);
	
	char suit[] = "suit";
	int rank = 0;
	char location[] = "location";
	setCard(card, suit, rank, location); //Removes card from previous location
}
//END giveCard FUNCTION

/*
* Places a card into the discard pile and defaults the card.
* PARAM: discard[] - The discard deck
*	 card - The card to be placed into the discard deck and defaulted
*/
void discardCard(Card discard[], Card& card)
{
	int i = 0;
	char strDiscard[] = "discard";
	while (discard[i].rank != 0)
		i++;
	setCard(discard[i], card.suit, card.rank, strDiscard);
	char suit[] = "suit";
	int rank = 0;
	char location[] = "location";
	setCard(card, suit, rank, location); //Defaults the card
}
//END discardCard FUNCTION

/*
* Preforms a deep copy of two Card structure arrays.
* PARAM: destination[] - The newly copied array of Card.
*	 source[] - The array of Card to be copied.
*	 location[] - The new loaction of the deck.
*/
void deckCopy(Card destination[], Card source[], char location[])
{
	for (int i = 0; i < NUM_CARDS; i++)
		setCard(destination[i], source[i].suit, source[i].rank, location);
}
//END deckCopy FUNCTION

/*
* Preforms a deep copy of two 1-D character arrays.
* PARAM: destination[] - The newly copied array.
* 	 source[] - The array to be copied.
*/
void strCopy(char destination[], char source[])
{
	int index = 0;
	while (source[index] != '\0')
	{
		destination[index] = source[index];
		index++;
	}
	destination[index] = '\0';
}
//END strCopy FUNCTION

/*
* Preforms a deep copy of two 1-D int arrays.
* PARAM: destination[] - The newly copied array.
*	 source[] - The array to be copied.
*	 size - The size of the arrays.
*/
void arrIntCopy(int destination[], int source[], int size)
{
	for (int i = 0; i < size; i++)
		destination[i] = source[i];
}
//END arrIntCopy FUNCTION

/*
* Prints out the Player's name and id.
* PARAM: player - The Player to be printed
*/
void printPlayer(Player player)
{
	cout << player.name << " : ";
	for (int i = 0; i < 5; i++)
		cout << player.id[i];
	cout << endl;
}
//END printPlayer FUNCTION

/*
* Prints out the Card's suit and rank.
* PARAM: card - The Card to be printed
*/
void printCard(Card card)
{
	cout << card.suit << " " << card.rank << " (" << card.location << ")" << endl;
}
//END printCard FUNCTION

/*
* Prints out a Player's hand.
* PARAM: player - The player whose hand will be printed
*/
void printHand(Player player)
{
	int i = 0;
	while(player.hand[i].rank != 0)
	{
		printCard(player.hand[i]);
		i++;
	}
	cout << endl;
}
//END printHand FUNCTION
