/*
* PROGRAM: CS 202 Project 7
* AUTHOR: Saharath Kleips
* DATE: 03/25/2014
* PURPOSE: To recreate the basic structure of the Crazy Eights game with copy constructor and const functions
*/

#include <stdlib.h>
#include <iostream>
#include "Project7Classes.h"
#include "strLib.h"
using namespace std;

//START Player FUNCTIONS

/*
* Default Constructor for class Player.
*/
Player::Player()
{
	name = new char[strLen("name")];
	strCopy(name, "name");
	id = new int[5];
	int *rootID = id;
	for(int i = 0; i < 5; i++)
	{
		id = 0;
		id++;
	}
	id = rootID;
	hand = new Card[5];
}//END Constructor FUNCTION

/*
* Destructor for class Player.
*/
Player::~Player()
{
	if(name != NULL)
		delete[] name;
	name = NULL;
	if(id != NULL)
		delete[] id;
	id = NULL;
	if(hand != NULL)
		delete[] hand;
	hand = NULL;
}//END Destructor FUNCTION

/*
* Sets the name of a player.
* @PARAM: const char* - The new name of the player.
* @RETURN: bool - The player name is valid or invalid.
*/
bool Player::setName(const char *newName)
{
	if(name != NULL)
		delete[] name;
	name = new char[strLen(newName)];
	strCopy(name, newName);
	return true;
}//END setName FUNCTION

/*
* Returns the name of the player.
* @RETURN: char* - A pointer to a c-style string of the player's name.
*/
char* Player::getName() const
{
	return name;
}//END getName FUNCTION

/*
* Sets the ID of a player.
* @PARAM: int* - The new ID of the player.
* @RETURN: bool - The player ID is valid or invalid.
*/
bool Player::setID(int *newID)
{
	int *rootID = id;
	for(int i = 0; i < 5; i++)
	{
		*id = *newID;
		id++;
		newID++;
	}
	id = rootID;
	return true;
}//END setID FUNCTION

/*
* Returns the ID of the player.
* @RETURN: int* - A pointer to an array of integers of the player's ID.
*/
int* Player::getID() const
{
	return id;
}//END getID FUNCTION

/*
* Sets the hand of a player.
* @PARAM: Card* - The new hand of the player.
* @RETURN: bool - The hand is valid or invalid.
*/
bool Player::setHand(Card *newHand)
{
	Card *rootHand = hand;
	for(int i = 0; i < 5; i++)
	{
		(*hand).setCard((*newHand).getSuit(), (*newHand).getRank(), getName());
		hand++;
		newHand++;
	}
	hand = rootHand;
}//END setHand FUNCTION

/*
* Returns the hand of the player.
* @RETURN: Card* - A pointer to the player's hand.
*/
Card* Player::getHand() const
{
	return hand;
}//END getHand FUNCTION

/*
* Prints the Player's name and ID. 
*/
void Player::print()
{
	int *rootID = id;
	cout << name << " [";
	for(int i = 0; i < 5; i++)
	{
		cout << *id;
		id++;
	}
	cout << "]" << endl;
	id = rootID;
}//END print FUNCTION
//END Player FUNCTIONS

//START Card FUNCTIONS

/*
* Default Constructor for class Card.
*/
Card::Card()
{
	suit = new char[strLen("suit")];
	strCopy(suit, "suit");
	rank = 0;
	location = new char[strLen("location")];
	strCopy(location, "location");
}//END Constructor FUNCTION

/*
* Parameterized Constructor for class Card.
* @PARAM: const char* - The suit of the Card.
*	  int - The rank of the Card.
*	  const char* - The location of the Card.
*/
Card::Card(const char *newSuit, int newRank, const char *newLocation)
{
	suit = new char[strLen(newSuit)];
	strCopy(suit, newSuit);
	rank = newRank;
	location = new char[strLen(newLocation)];
	strCopy(location, newLocation);
}//END Constructor FUNCTION

/*
* Copy Constructor for class Card.
* @PARAM: const Card& - The card to be copied.
*/
Card::Card(const Card& newCard)
{
	suit = new char[strLen(newCard.suit)];
	strCopy(suit, newCard.suit);
	rank = newCard.rank;
	location = new char[strLen(newCard.location)];
	strCopy(location, newCard.location);
}//END Constructor FUNCTION

/*
* Destructor for class Card.
*/
Card::~Card()
{
	if(suit != NULL)
		delete[] suit;
	suit = NULL;
	rank = 0;
	if(location != NULL)
		delete[] location;
	location = NULL;
}//END Destructor for class Card

/*
* Sets the suit of a card.
* @PARAM: const char* - The new suit of the card.
* @RETURN: bool - The suit is valid or invalid.
*/
bool Card::setSuit(const char *newSuit)
{
	if(suit != NULL)
		delete[] suit;
	suit = new char[strLen(newSuit)];
	strCopy(suit, newSuit);

	return true;
}//END setSuit FUNCTION

/*
* Returns the suit of a card.
* @RETURN: char* - A pointer to a c-style string of the card's suit.
*/
char* Card::getSuit() const
{
	return suit;
}//END getSuit FUNCTION

/*
* Sets the rank of a card.
* @PARAM: int - The new rank of the card.
* @RETURN: bool - The rank is valid or invalid.
*/
bool Card::setRank(int newRank)
{
	if(newRank > 0 && newRank < 14)
	{
		rank = newRank;
		return true;
	}
	else
		return false;
}//END setRank FUNCTION

/*
* Returns the rank of the card.
* @RETURN: int - The rank of the card.
*/
int Card::getRank() const
{
	return rank;
}//END getRank FUNCTION

/*
* Sets the location of the card.
* @PARAM: const char* - The new location of the card.
* @RETURN: bool - The location is valid or invalid.
*/
bool Card::setLocation(const char *newLocation)
{
	if(location != NULL)
		delete[] location;
	location = new char[strLen(newLocation)];
	strCopy(location, newLocation);

	return true;
}//END setLocation FUNCTION

/*
* Returns the location of the card.
* @RETURN: char* - A pointer to a c-style string of the card's location.
*/
char* Card::getLocation() const
{
	return location;
}//END getLocation FUNCTION

/*
* Sets all of the Card's properties to new values.
* @PARAM: const char* - The new suit of the card.
*	  int - The new rank of the card.
*	  const char* - The new location of the card.
* @RETURN: bool - The new values are valid or invalid.
*/
bool Card::setCard(const char* newSuit, int newRank, const char* newLocation)
{
	if(setSuit(newSuit) == false)
		return false;
	if(setRank(newRank) == false)
		return false;
	if(setLocation(newLocation) == false)
		return false;

	return true;
}//END setCard FUNCTION

/*
* Sets all of the Card's properties to new values.
* @PARAM: Card - The Card to copy values from.
* @RETURN: bool - The new values are valid or invalid.
*/
bool Card::setCard(Card newCard)
{
	setCard(newCard.getSuit(), newCard.getRank(), newCard.getLocation());
}//END setCard FUNCTION

/*
* Prints out the Card's suit, rank, and location to the output stream.
*/
void Card::print() const
{
	cout << rank << " " << suit << " (" << location << ")" << endl;
}//END print FUNCTION
//END Card FUNCTIONS
