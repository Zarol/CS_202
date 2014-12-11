/*
* PROGRAM: CS 202 Project 1
* AUTHOR: Saharath Kleips
* DATE: 01/25/2014
* PURPOSE: To load a deck of cards from a file, load it into a multi-dimensional array, shuffle the deck, and write it to a file.
*/

//NOTE TO SELF: Program originally organized C-Style, function prototypes added as afterthought -- DO NOT RE-USE.
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

//GLOBAL VARIABLES
const int ROW = 4;
const int COLUMN = 13;
const int STRING_SIZE = 15;
const int NUM_CARDS = 52;
//END GLOBAL VARIABLES

//FUNCTION PROTOTYPES
void loadDeckFromFile(char deck[ROW][COLUMN][STRING_SIZE]);
void writeDeckToFile(char deck[NUM_CARDS][STRING_SIZE]);
void emptyDeck(char shuffledDeck[NUM_CARDS][STRING_SIZE]);
void strCopy(char destination[], char source[]);
void shuffleDeck(char unshuffledDeck[ROW][COLUMN][STRING_SIZE], char shuffledDeck[NUM_CARDS][STRING_SIZE]);
void printDeck(char deck[ROW][COLUMN][STRING_SIZE]);
void printDeck(char deck[NUM_CARDS][STRING_SIZE]);
void menuSystem(char deck[ROW][COLUMN][STRING_SIZE], char shuffledDeck[NUM_CARDS][STRING_SIZE]);
//END FUNCTION PROTOTYPES

/*
* Loads a deck from a user-defined file into a 3D array.
* PARAM: deck[ROW][COLUMN][STRING_SIZE] - The array to be loaded.
*/
void loadDeckFromFile(char deck[ROW][COLUMN][STRING_SIZE])
{
	int spaceCount = 0;
	char currentChar;
	char userInput[100];
	ifstream unshuffled;
	
	//Grab file name
	while (unshuffled.is_open() == false)
	{
		cout << "Please input the file name..." << endl;
		cin >> userInput;
		unshuffled.open(userInput);
		if (unshuffled.is_open() == false)
			cout << "\"" << userInput << "\"" << " is an invalid file name." << endl;
	}
	
	//unshuffled.open("unshuffled");

	//Copy characters in file to 3-D array
	if (unshuffled.is_open())
	{
		for (int x = 0; x < ROW; x++)
			for (int y = 0; y < COLUMN; y++)
				for (int z = 0; z < STRING_SIZE; z++)
				{
					unshuffled.get(currentChar);
					if (currentChar == '\n')
						unshuffled.get(currentChar); //Ignore new line characters
					if (currentChar != '\n') //Possibly unnecessary
					{
						if (currentChar == ' ')
							spaceCount++;
						if (spaceCount >= 2)	//2 Spaces signify the end of value & suit combination
						{
							deck[x][y][z] = '\0';
							spaceCount = 0;
							break;
						}
						deck[x][y][z] = currentChar;
					}
				}
		unshuffled.close();
	}
	else
		cout << "ERROR: Unable to open file.";
}
//END loadDeckFromFile FUNCTION

/*
* Writes a deck to a file titled "shuffled.txt" from an array
* PARAM: deck[NUM_CARDS][STRING_SIZE] - The shuffled deck to be written to file.
*/
void writeDeckToFile(char deck[NUM_CARDS][STRING_SIZE])
{
	ofstream shuffled("shuffled");
	
	if( shuffled.is_open())
	{
		for( int x = 0; x < NUM_CARDS; x++ )
			for( int y = 0; y < STRING_SIZE; y++)
			{
				if (deck[x][y] == '\0')
				{
					shuffled << ' ';
					break;
				}
				shuffled << deck[x][y];
			}
		shuffled.close();
	}
	else
		cout << "ERROR: Unable to open file";
	
}
//END writeDeckToFile FUNCTION

/*
* Prepares the deck to be shuffled.
* PARAM: shuffledDeck[NUM_CARDS][STRING_SIZE] - The deck to be emptied
*/
void emptyDeck(char shuffledDeck[NUM_CARDS][STRING_SIZE])
{
	for (int x = 0; x < NUM_CARDS; x++)
		for (int y = 0; y < STRING_SIZE; y++)
			shuffledDeck[x][y] = '\0';
}
//END emptyDeck FUNCTION

/*
* Copies a 1-D character array (string) into another 1-D character array.
* PARAM: destination[] - The newly copied array.
	 source[] - The array to be copied.
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
* Randomly shuffles a shuffles a deck into a 2D array.
* PARAM: deck[ROW][COLUMN][STRING_SIZE] - Deck to be shuffled
*	 shuffledDeck[NUM_CARDS][STRING_SIZE] - Newly shuffled deck
*/
void shuffleDeck(char unshuffledDeck[ROW][COLUMN][STRING_SIZE], char shuffledDeck[NUM_CARDS][STRING_SIZE])
{
	emptyDeck(shuffledDeck);
	srand(time(NULL));
	int rng;
	bool shuffleSuccess = false;
	//Traverse 3-D unshuffled
	for (int x = 0; x < ROW; x++)
		for (int y = 0; y < COLUMN; y++)
		{
			while (shuffleSuccess == false)
			{
				rng = rand() % NUM_CARDS; //Select index in 2-D array
				if ( shuffledDeck[rng][0] == '\0' ) //Checks if card does not exist in index
				{
					//Copy card in unshuffled to shuffled
					//for (int z = 0; z < STRING_SIZE; z++)
					//{
					//	shuffledDeck[rng][z] = unshuffledDeck[x][y][z];
					//}
					strCopy(shuffledDeck[rng], unshuffledDeck[x][y]);
					shuffleSuccess = true;
				}
			}
			shuffleSuccess = false;		
		}
}
//END shuffleDeck FUNCTION

/*
* Prints a 3-D array to the output stream.
* PARAM: deck[ROW][COLUMN][STRING_SIZE] - The array to be printed.
*/
void printDeck(char deck[ROW][COLUMN][STRING_SIZE])
{
	for (int x = 0; x < ROW; x++)
		for (int y = 0; y < COLUMN; y++)
		{
			for (int z = 0; z < STRING_SIZE; z++)
			{
				if (deck[x][y][z] != '\0')
					cout << deck[x][y][z];
				else
					break;
			}
			cout << endl;
		}
}
//END printDeck FUNCTION

/*
* Prints 2-D array to the output stream.
* PARAM: deck[NUM_CARDS][STRING_SIZE] - The array to be printed
*/
void printDeck(char deck[NUM_CARDS][STRING_SIZE])
{
	for (int x = 0; x < NUM_CARDS; x++)
	{
		for (int y = 0; y < STRING_SIZE; y++)
		{
			if (deck[x][y] != '\0')
				cout << deck[x][y];
			else
				break;
		}
		
		cout << endl;
	}
}
//END printDeck FUNCTION

/*
* Allows for the user to interface with the program.
* PARAM: deck[ROW][COLUMN][STRING_SIZE] - The unshuffled deck of cards
*	 shuffledDeck[NUM_CARDS][STRING_SIZE] - The shuffled deck of cards
*/
void menuSystem(char deck[ROW][COLUMN][STRING_SIZE], char shuffledDeck[NUM_CARDS][STRING_SIZE])
{
	bool exit = false;
	char userInput;

	loadDeckFromFile(deck);
	shuffleDeck(deck, shuffledDeck);
	
	do
	{
		cout << "**************************************************" << endl;
		cout << "* Type 'P' to print the unshuffled deck.         *" << endl;
		cout << "* Type 'L' to print the shuffled deck.           *" << endl;
		cout << "* Type 'S' to shuffle the deck.                  *" << endl;
		cout << "* Type 'W' to write the shuffled deck to a file. *" << endl;
		cout << "* Type 'Q' to quit.                              *" << endl;
		cout << "**************************************************" << endl;
		cin >> userInput;
		switch (toupper(userInput))
		{
			case 'P':
				cout << endl;
				printDeck(deck);
				cout << endl;
				break;
			case 'L':
				cout << endl;
				printDeck(shuffledDeck);
				cout << endl;
				break;
			case 'S':
				shuffleDeck(deck, shuffledDeck);
				cout << "Shuffle success." << endl << endl;
				break;
			case 'W':
				writeDeckToFile(shuffledDeck);
				cout << "Written successfully into \"shuffled.\"" << endl << endl;
				break;
			case 'Q':
				cout << "Goodbye!";
				exit = true;
				break;
			default: 
				cout << "Invalid entry." << endl;
				break;
		}
	}
	while (exit == false);
}
//END menuSystem FUNCTION

//MAIN FUNCTION
int main()
{
	char deckOfCards[ROW][COLUMN][STRING_SIZE] = {};
	char shuffledDeck[NUM_CARDS][STRING_SIZE] = {};	
	menuSystem(deckOfCards, shuffledDeck);
	cout << endl;
}
//END MAIN FUNCTION
