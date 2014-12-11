/*
* PROGRAM: CS 202 Project 8
* AUTHOR: Saharath Kleips
* DATE: 04/01/2014
* PURPOSE: To recreate the basic structure of the Crazy Eights game with overloaded operators, offset notation, and strings.
*/

#include <cstring>
using namespace std;
class Card
{
	public: 
		Card();
		Card(string, int, string);
		Card(const Card&);
		~Card();
		bool setSuit(string);
		string getSuit() const;
		bool setRank(int);
		int getRank() const;
		bool setLocation(string);
		string getLocation() const;
		void reset();
		
		Card operator=(const Card&);
		bool operator>(const Card&) const;
		bool operator<(const Card&) const;
		friend bool operator>=(const Card&, const Card&);
		friend bool operator<=(const Card&, const Card&);
		friend ifstream& operator>>(ifstream&, Card&);
		friend ostream& operator<<(ostream&, Card&);

	private:
		string suit;
		int rank;
		string location;
};

class Player
{
	public:
		Player();
		~Player();
		bool setName(string);
		string getName() const;
		bool setID(int*);
		int* getID() const;
		bool setHand(Card*);
		Card* getHand() const;

		friend ifstream& operator>>(ifstream&, Player&);
		friend ostream& operator<<(ostream&, Player&);
	private:
		string name;
		int *id;
		Card* hand;
};
