#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include "Project11Classes.cpp"

using namespace std;

const int NUM_CARDS = 52;
int NUM_PLAYERS;

bool loadDeck(Queue<Card>*, string);
bool loadPlayers(Queue<Player>*, string);

void shuffleDeck(List<Card>*);
void dealDeck(Queue<Player>*, Stack<Card>*, Stack<Card>*);

int main()
{
	char userInput;
	string fileName;
	bool exit = false;
	
	Queue<Card>* unshuffled = new Queue<Card>();
	List<Card>* shuffled = new List<Card>();
	Stack<Card>* stock = new Stack<Card>(NUM_CARDS);
	Stack<Card>* discard = new Stack<Card>(NUM_CARDS);

	Queue<Player>* players = new Queue<Player>();

	do
	{
		cout << "Unshuffled Deck's File Name (100 MAX):" << endl;
		cin >> fileName;
	} while (loadDeck(unshuffled, fileName) == false);

	do
	{
		cout << "Number of Players (2-8):" << endl;
		cin >> userInput;
	} while ((userInput - '0') < 2 && (userInput - '0') > 8);

	NUM_PLAYERS = userInput - '0';

	do
	{
		cout << "Player File Name (100 MAX):" << endl;
		cin >> fileName;
	} while (loadPlayers(players, fileName) == false);

	
	Card temp;
	for(int i = 0; i < NUM_CARDS; i++)
	{
		unshuffled->dequeue(temp);
		shuffled->insertAfter(temp);
		unshuffled->enqueue(temp);
	}

	shuffled->gotoBeginning();
	for(int i = 0; i < NUM_CARDS; i++)
	{
		shuffled->getCursor(temp);
		temp.setLocation("shuffled");
		shuffled->replace(temp);
		shuffled->gotoNext();
	}

	cout << "NOTE: Shuffle first, deal second." << endl;
	cout << "NOTE: You may shuffle more than once, doing other things more than once might break the program." << endl;
	
	Player pTemp;
	Card sTemp;
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
				unshuffled->print();
				break;
			case 2:
				shuffled->print();
				break;
			case 3:
				stock->print();
				break;
			case 4:
				discard->print();
				break;
			case 5:
				players->print();
				break;
			case 6:
				for(int i = 0; i < NUM_PLAYERS; i++)
				{
					players->dequeue(pTemp);
					cout << pTemp << endl;
					pTemp.getHand().print();
					players->enqueue(pTemp);
				}
				break;
			case 7:
				shuffleDeck(shuffled);
				stock->clear();
				shuffled->gotoBeginning();			
				for(int i = 0; i < NUM_CARDS; i++)
				{
					shuffled->getCursor(temp);
					temp.setLocation("stock");
					stock->push(temp);
					shuffled->gotoNext();
				}
				cout << "Shuffle success." << endl;
				break;
			case 8:
				dealDeck(players, stock, discard);
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
	return 1;
}

bool loadDeck(Queue<Card>* deck, string fileName)
{
	ifstream ifs;
	ifs.open(fileName.c_str());

	Card temp;
	if(ifs.is_open() == false)
		return false;
	else
	{
		for(int i = 0; i < NUM_CARDS; i++)
		{
			ifs >> temp;
			temp.setLocation("unshuffled");
			deck->enqueue(temp);			
		}
		ifs.close();
		return true;
	}
}

bool loadPlayers(Queue<Player>* players, string fileName)
{
	ifstream ifs;
	ifs.open(fileName.c_str());
	
	if(ifs.is_open() == false)
		return false;
	else
	{
		for(int i = 0; i < NUM_PLAYERS; i++)
		{
			Player temp;
			ifs >> temp;
			cout << temp << endl;
			players->enqueue(temp);
		}
		ifs.close();
		return true;
	}
}

void shuffleDeck(List<Card>* deck)
{
	srand(time(NULL));
	int rng, rng2;
	Card temp, temp2;
	for(int i = 0; i < 1000000; i++)
	{
		rng = rand() % NUM_CARDS;
		rng2 = rand() % NUM_CARDS;
		deck->gotoBeginning();
		for(int j = 0; j < rng; j++)
			deck->gotoNext();
		deck->getCursor(temp);
		
		deck->gotoBeginning();
		for(int j = 0; j < rng2; j++)
			deck->gotoNext();
		deck->getCursor(temp2);
		deck->replace(temp);

		deck->gotoBeginning();
		for(int j = 0; j < rng; j++)
			deck->gotoNext();
		deck->replace(temp2);
	}
}

void dealDeck(Queue<Player>* players, Stack<Card>* stock, Stack<Card>* discard)
{
	Player pTemp;
	Card cTemp;
	for(int i = 0; i < 5 * NUM_PLAYERS; i++)
	{
		players->dequeue(pTemp);
		stock->pop(cTemp);
		cTemp.setLocation(pTemp.getName());
		pTemp.giveCard(cTemp);
		players->enqueue(pTemp);
	}
	stock->pop(cTemp);
	cTemp.setLocation("discard");
	discard->push(cTemp);
}
